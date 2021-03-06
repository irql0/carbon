﻿


#include <carbsup.h>
#include "../hal/halp.h"
#include "ki.h"

PKPCB*  KiLogicalProcessor = NULL;
ULONG64 KiLogicalProcessorCount = 0;

PKPCB
KiCreatePcb(

)
{
    PKPCB Processor;

    if ( KiLogicalProcessor == NULL ) {

        KiLogicalProcessor = ( PKPCB* )MmAllocatePoolWithTag( NonPagedPool, sizeof( PKPCB ) * HalLocalApicCount, KE_TAG );
    }

    Processor = MmAllocatePoolWithTag( NonPagedPoolZeroed, sizeof( KPCB ), KE_TAG );
    Processor->ProcessorNumber = KiLogicalProcessorCount;

#define KeEnableOnPresent( Feature, Fatal )                                                         \
    if ( KeProcessorFeatureEnabled( NULL, Feature ) ) {                                             \
                                                                                                    \
        Processor->ProcessorFeatures[ ( Feature ) / 64 ] |= ( 1ull << ( ( Feature ) % 64 ) );       \
    }                                                                                               \
    else if ( Fatal ) {                                                                             \
                                                                                                    \
        KeBugCheck( STATUS_UNSUPPORTED_PROCESSOR );                                                 \
    }

    KeEnableOnPresent( KPF_NX_ENABLED, FALSE );
    KeEnableOnPresent( KPF_PCID_ENABLED, FALSE );
    KeEnableOnPresent( KPF_SMEP_ENABLED, FALSE );
    KeEnableOnPresent( KPF_FXSR_ENABLED, TRUE ); // uh? 
    KeEnableOnPresent( KPF_SC_ENABLED, TRUE );
    KeEnableOnPresent( KPF_SSE3_ENABLED, FALSE );

#undef KeEnableOnPresent

    KiLogicalProcessor[ KiLogicalProcessorCount++ ] = Processor;

    return Processor;
}

PKPCB
KeQueryProcessorByNumber(
    _In_ ULONG64 ProcessorNumber
)
{
    if ( ProcessorNumber > KiLogicalProcessorCount ) {
        return NULL;
    }
    return KiLogicalProcessor[ ProcessorNumber ];
}

ULONG64
KeQueryProcessorCount(

)
{
    return KiLogicalProcessorCount;
}

BOOLEAN
KeProcessorFeatureEnabled(
    _In_ PKPCB              Processor,
    _In_ KPROCESSOR_FEATURE Feature
)
{

    int IdRegisters[ 4 ];
    int IdRegisters1[ 4 ];

    if ( Feature > KPF_MAXIMUM ) {

        return FALSE;
    }

    if ( Processor == NULL ) {

        //
        // early api's call this and set appropriate bits
        //

        switch ( Feature ) { // 4.1.4 vol 3a
        case KPF_NX_ENABLED:
            KiSafeCpuid( IdRegisters, 0x80000001, 0 );
            return ( IdRegisters[ CPUID_EDX ] >> 20 ) & 1;
        case KPF_PCID_ENABLED:
            KiSafeCpuid( IdRegisters, 1, 0 );
            KiSafeCpuid( IdRegisters1, 7, 0 );
            return ( ( IdRegisters[ CPUID_ECX ] >> 17 ) & 1 ) && ( ( IdRegisters1[ CPUID_EBX ] >> 10 ) & 1 );
        case KPF_SMEP_ENABLED:
            KiSafeCpuid( IdRegisters, 7, 0 );
            return ( IdRegisters[ CPUID_EBX ] >> 7 ) & 1;
        case KPF_SMAP_ENABLED:
            KiSafeCpuid( IdRegisters, 7, 0 );
            return ( IdRegisters[ CPUID_EBX ] >> 20 ) & 1;
        case KPF_PKU_ENABLED:
            KiSafeCpuid( IdRegisters, 7, 0 );
            return ( IdRegisters[ CPUID_ECX ] >> 3 ) & 1;
        case KPF_PAGE1GB_ENABLED:
            KiSafeCpuid( IdRegisters, 0x80000001, 0 );
            return ( IdRegisters[ CPUID_EDX ] >> 26 ) & 1;
        case KPF_PAT_ENABLED:
            KiSafeCpuid( IdRegisters, 1, 0 );
            return ( IdRegisters[ CPUID_EDX ] >> 16 ) & 1;
        case KPF_PGE_ENABLED:
            KiSafeCpuid( IdRegisters, 1, 0 );
            return ( IdRegisters[ CPUID_EDX ] >> 13 ) & 1;
        case KPF_FXSR_ENABLED:
            KiSafeCpuid( IdRegisters, 1, 0 );
            return ( IdRegisters[ CPUID_EDX ] >> 24 ) & 1;
        case KPF_SC_ENABLED:
            KiSafeCpuid( IdRegisters, 0x80000001, 0 );
            return ( IdRegisters[ CPUID_EDX ] >> 11 ) & 1;
        case KPF_SSE3_ENABLED:
            KiSafeCpuid( IdRegisters, 1, 0 );
            return IdRegisters[ CPUID_ECX ] & 1;
        default:
            __assume( 0 );
        }
    }

    return Processor->ProcessorFeatures[ Feature / 64 ] & ( 1ull << ( Feature % 64 ) );
}
