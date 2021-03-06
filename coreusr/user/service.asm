


BITS    64
SECTION .text

%MACRO  SYSTEM_SERVICE 2
GLOBAL  %1
EXPORT  %1
%1:
    mov     r10, rcx
    mov     eax, %2
    syscall 
    ret
%ENDMACRO

SYSTEM_SERVICE NtSendMessage, 0x10000000
SYSTEM_SERVICE NtReceiveMessage, 0x10000001
SYSTEM_SERVICE NtCreateWindow, 0x10000002
SYSTEM_SERVICE NtGetWindowInfo, 0x10000003
SYSTEM_SERVICE NtSetWindowInfo, 0x10000004
SYSTEM_SERVICE NtRegisterClass, 0x10000005
SYSTEM_SERVICE NtUnregisterClass, 0x10000006
SYSTEM_SERVICE NtDefaultWindowProc, 0x10000007
SYSTEM_SERVICE NtGetWindowProc, 0x10000008
SYSTEM_SERVICE NtBeginPaint, 0x10000009
SYSTEM_SERVICE NtEndPaint, 0x1000000A
SYSTEM_SERVICE NtGetDC, 0x1000000B
SYSTEM_SERVICE NtBlt, 0x1000000C
SYSTEM_SERVICE NtBltBits, 0x1000000D
SYSTEM_SERVICE NtWaitMessage, 0x1000000E
SYSTEM_SERVICE NtSetPixel, 0x1000000F
SYSTEM_SERVICE NtClearDC, 0x10000010
SYSTEM_SERVICE NtSendParentMessage, 0x10000011
SYSTEM_SERVICE NtGetWindowByName, 0x10000012
SYSTEM_SERVICE NtSetParent, 0x10000013
