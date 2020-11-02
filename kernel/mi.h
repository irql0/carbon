#pragma once

#define KERNEL_IMAGE_BASE			0xFFFF800000000000

#define PML4T_SIZE					0x1000000000000
#define PDPT_SIZE					0x8000000000
#define PDT_SIZE					0x40000000
#define PT_SIZE						0x200000
#define PAGE_SIZE					0x1000

typedef enum _PAGE_ENTRY_FLAGS {
	EntryPresent = 0x01,
	EntryWriteable = 0x02,
	EntryUser = 0x04,
	EntryWriteThrough = 0x08,
	EntryNotCacheable = 0x10,
	EntryAccessed = 0x20,
	EntryDirty = 0x40,
	EntryPAT = 0x80,
	EntryCpuGlobal = 0x100,
	EntryLv4Global = 0x200,
	EntryFrame = ~0xFFF
} PAGE_ENTRY_FLAGS;

typedef struct _PHYSICAL_REGION_DESCRIPTOR {
	LIST_ENTRY	RegionLinks;
	KSPIN_LOCK	RegionLock;

	ULONG64		RegionBase;
	ULONG64		RegionLength;

	ULONG64		Bitmap[ 0 ];

} PHYSICAL_REGION_DESCRIPTOR, *PPHYSICAL_REGION_DESCRIPTOR;

typedef struct _PAGE_TABLE_ALLOCATION_ENTRY {
	LIST_ENTRY	AllocationLinks;
	KSPIN_LOCK	AllocationLock;

	ULONG64		BaseVirtual;
	ULONG64		BasePhysical;
	ULONG64		Bitmap[ 8 ];

} PAGE_TABLE_ALLOCATION_ENTRY, *PPAGE_TABLE_ALLOCATION_ENTRY;

typedef struct _ADDRESS_SPACE_DESCRIPTOR {
	LIST_ENTRY	TableLinks;
	KSPIN_LOCK	TableLock;

	ULONG64*	BaseVirtual;
	ULONG64		BasePhysical;

	ULONG64		MemoryUsage;

	PLIST_ENTRY PageTableAllocationHead;

	ULONG64		Flags;
	PKPROCESS	Process;

} ADDRESS_SPACE_DESCRIPTOR, *PADDRESS_SPACE_DESCRIPTOR;

VOID FORCEINLINE MiVirtualToIndex(
	__in		ULONG64 Virtual,
	__out_opt	USHORT	*Pml4tIndex,
	__out_opt	USHORT	*PdptIndex,
	__out_opt	USHORT	*PdtIndex,
	__out_opt	USHORT	*PtIndex
) {
	Virtual &= ~0xFFFF000000000000;

	USHORT Pml4, Pdpt, Pdt, Pt;

	Pml4 = ( USHORT )( Virtual / PDPT_SIZE );
	Virtual -= ( ( ULONG64 )Pml4 * PDPT_SIZE );

	Pdpt = ( USHORT )( Virtual / PDT_SIZE );
	Virtual -= ( ( ULONG64 )Pdpt * PDT_SIZE );

	Pdt = ( USHORT )( Virtual / PT_SIZE );
	Virtual -= ( ( ULONG64 )Pdt * PT_SIZE );

	Pt = ( USHORT )( Virtual / PAGE_SIZE );
	Virtual -= ( ( ULONG64 )Pt * PAGE_SIZE );

	if ( Pml4tIndex ) *Pml4tIndex = Pml4;	
	if ( PdptIndex ) *PdptIndex = Pdpt;
	if ( PdtIndex ) *PdtIndex = Pdt;
	if ( PtIndex ) *PtIndex = Pt;
}

ULONG64 FORCEINLINE MiIndexToVirtual(
	__in USHORT Pml4tIndex,
	__in USHORT PdptIndex,
	__in USHORT PdtIndex,
	__in USHORT PtIndex
) {
	ULONG64 Virtual = 0;

	Virtual += ( ( ULONG64 )PtIndex * PAGE_SIZE );
	Virtual += ( ( ULONG64 )PdtIndex * PT_SIZE );
	Virtual += ( ( ULONG64 )PdptIndex * PDT_SIZE );
	Virtual += ( ( ULONG64 )Pml4tIndex * PDPT_SIZE );

	if ( Virtual >= 0x0000800000000000 ) Virtual |= 0xFFFF000000000000;

	return Virtual;
}

PULONG64 FORCEINLINE MiCurrentDirectory() {
	
	//obsolete.
	return ( ULONG64* )__readcr3( );
}

ULONG64 FORCEINLINE MiFlagsToEntryFlags(
	__in ULONG64 Flags
) {
	ULONG64 PteFlags = EntryPresent;

	if ( Flags & PAGE_EXECUTE );
	
	if ( Flags & PAGE_READ );
	
	if ( Flags & PAGE_WRITE )
		PteFlags |= EntryWriteable;
	
	if ( Flags & PAGE_USER )
		PteFlags |= EntryUser;
	
	if ( Flags & PAGE_GLOBAL )
		PteFlags |= EntryCpuGlobal;

	return PteFlags;
}

/* phys.c */

ULONG64 MiAllocatePhysical(
	__in ULONG64 PageCount
);

VOID MiMarkPhysical(
	__in ULONG64 Address,
	__in ULONG64 PageCount,
	__in BOOLEAN Marking
);

/* table.c */

PVOID MiPageTableToVirtual(
	__in PULONG64 PageTable
);

/* ads.c */

VOID MiAllocateAddressSpace(
	__in PADDRESS_SPACE_DESCRIPTOR AddressSpace
);

VOID MiFreeAddressSpace(
	__in PADDRESS_SPACE_DESCRIPTOR AddressSpace
);

PADDRESS_SPACE_DESCRIPTOR MiGetAddressSpace();

VOID MiSetAddressSpace(
	__in PADDRESS_SPACE_DESCRIPTOR AddressSpace
);

VOID MiEnterKernelSpace(
	__out PADDRESS_SPACE_DESCRIPTOR *PreviousAddressSpace
);

VOID MiLeaveKernelSpace(
	__in PADDRESS_SPACE_DESCRIPTOR PreviousAddressSpace
);

VOID MiInsertAddressSpace(
	__in PADDRESS_SPACE_DESCRIPTOR AddressSpace
);

VOID MiRemoveAddressSpace(
	__in PADDRESS_SPACE_DESCRIPTOR AddressSpace
);

/* virt.c */

ULONG64 MiAllocateVirtualAt(
	__in ULONG64 Virtual,
	__in ULONG64 PageCount,
	__in ULONG64 Flags
);

ULONG64 MiAllocateVirtual(
	__in ULONG64 PageCount,
	__in ULONG64 Flags
);

VOID MiMarkVirtual(
	__in ULONG64 Address,
	__in ULONG64 PageCount,
	__in ULONG64 Flags
);

/* initmm.c */

ULONG64 MiInitMemoryManager(
	__in PE820MM MemoryMap
);

/* tlb.c */

VOID MiInvalidateTlbEntry(
	__in ULONG64 Address
);