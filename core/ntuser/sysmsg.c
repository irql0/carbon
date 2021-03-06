﻿


#include <carbsup.h>
#include "usersup.h"
#include "ntuser.h"

#ifdef OLD_SYS_MSG
PKUSER_MESSAGE SystemMessageQueue = NULL;
KSPIN_LOCK     SystemMessageQueueLock = { 0 };
HANDLE         SystemMessageEvent;
#else
IO_QUEUE       SystemMessageQueue;
KEVENT         SystemMessageEvent;
#endif

VOID
NtSystemMessageThread(

);

VOID
NtInitializeSystemMessages(

)
{
    HANDLE ThreadHandle;
    OBJECT_ATTRIBUTES Thread = { { 0 }, { 0 }, OBJ_KERNEL_HANDLE };

    IoQueueCreate( &SystemMessageQueue, 128, sizeof( KUSER_MESSAGE ) );

    KeInitializeEvent( &SystemMessageEvent, FALSE );

    ZwCreateThread( &ThreadHandle,
                    0,
                    THREAD_ALL_ACCESS,
                    ( PKSTART_ROUTINE )NtSystemMessageThread,
                    NULL,
                    THREAD_SYSTEM,
                    &Thread,
                    0,
                    NULL );
    ZwClose( ThreadHandle );
}

VOID
NtSendSystemMessage(
    _In_ ULONG32 MessageId,
    _In_ ULONG64 Param1,
    _In_ ULONG64 Param2
)
{
    KUSER_MESSAGE Message;
    Message.MessageId = MessageId;
    Message.Param1 = Param1;
    Message.Param2 = Param2;

    IoQueueEnqueue( &SystemMessageQueue, &Message );
    KeSignalEvent( &SystemMessageEvent, TRUE );
}

VOID
NtReceiveSystemMessage(
    _In_ PKUSER_MESSAGE Buffer
)
{
    KeWaitForSingleObject( &SystemMessageEvent, WAIT_TIMEOUT_INFINITE );

    NT_ASSERT( IoQueueDequeue( &SystemMessageQueue, Buffer ) );

    if ( SystemMessageQueue.QueueHead == SystemMessageQueue.QueueTail ) {

        KeSignalEvent( &SystemMessageEvent, FALSE );
    }
}

VOID
NtSystemMessageThread(

)
{
    // jon is bussin
    KUSER_MESSAGE SystemMessage;
    KIRQL PreviousIrql;

    STATIC ULONG32 PressX = 0;
    STATIC ULONG32 PressY = 0;
    STATIC BOOLEAN PressSet = FALSE;
    STATIC PKWND   PressWindow = NULL;

    ULONG32 PressXDist = 0;
    ULONG32 PressYDist = 0;

    while ( TRUE ) {

        NtReceiveSystemMessage( &SystemMessage );

        switch ( SystemMessage.MessageId ) {
        case WM_LMOUSEDOWN:;

            //
            // make it just check against the class to see 
            // if it can move, or the flags
            //

            if ( !PressSet ) {
                PressWindow = NtWindowFromPoint(
                    ( ULONG32 )SystemMessage.Param1,
                    ( ULONG32 )SystemMessage.Param2 );

                if ( PressWindow == RootWindow &&
                     FocusWindow != RootWindow ) {

                    FocusWindow = RootWindow;

                    NtBroadcastDirectMessage( WM_PAINT,
                                              0,
                                              0 );
                }
                else if ( FocusWindow != PressWindow->Parent ) {
                    // add move flag check

                    KeAcquireSpinLock( &RootWindow->LinkLock, &PreviousIrql );
                    FocusWindow = PressWindow->Parent;
                    NtRemoveWindow( FocusWindow );
                    NtInsertWindow( FocusWindow );
                    KeReleaseSpinLock( &RootWindow->LinkLock, PreviousIrql );

                    NtSendDirectMessage( FocusWindow,
                                         WM_FOCUS,
                                         0,
                                         0 );

                    NtBroadcastDirectMessage( WM_PAINT,
                                              0,
                                              0 );
                }

                PressX = ( ULONG32 )SystemMessage.Param1;
                PressY = ( ULONG32 )SystemMessage.Param2;
                PressSet = TRUE;

                if ( PressWindow->Parent == PressWindow ) {
                    NtSendDirectMessage( PressWindow,
                                         WM_LMOUSEDOWN,
                                         PressX - PressWindow->FrontContext->ClientArea.Left,
                                         PressY - PressWindow->FrontContext->ClientArea.Top );
                }
                else {
                    NtSendDirectMessage( PressWindow,
                                         WM_LMOUSEDOWN,
                                         PressX -
                                         PressWindow->FrontContext->ClientArea.Left -
                                         PressWindow->Parent->FrontContext->ClientArea.Left,
                                         PressY -
                                         PressWindow->FrontContext->ClientArea.Top -
                                         PressWindow->Parent->FrontContext->ClientArea.Top );
                }
            }

            break;
        case WM_LMOUSEUP:;

            if ( PressSet ) {

                if ( FocusWindow != RootWindow &&
                     FocusWindow == PressWindow ) {
                    PressXDist = ( ULONG32 )SystemMessage.Param1 - PressX;
                    PressYDist = ( ULONG32 )SystemMessage.Param2 - PressY;

                    FocusWindow->FrontContext->ClientArea.Left += PressXDist;
                    FocusWindow->FrontContext->ClientArea.Right += PressXDist;
                    FocusWindow->FrontContext->ClientArea.Top += PressYDist;
                    FocusWindow->FrontContext->ClientArea.Bottom += PressYDist;

                    FocusWindow->BackContext->ClientArea = FocusWindow->FrontContext->ClientArea;

                    NtBroadcastDirectMessage( WM_PAINT,
                                              0,
                                              0 );
                }

                if ( PressWindow->Parent == PressWindow ) {
                    NtSendDirectMessage( PressWindow,
                                         WM_LMOUSEUP,
                                         SystemMessage.Param1 - PressWindow->FrontContext->ClientArea.Left,
                                         SystemMessage.Param2 - PressWindow->FrontContext->ClientArea.Top );
                }
                else {
                    NtSendDirectMessage( PressWindow,
                                         WM_LMOUSEUP,
                                         SystemMessage.Param1 -
                                         PressWindow->FrontContext->ClientArea.Left -
                                         PressWindow->Parent->FrontContext->ClientArea.Left,
                                         SystemMessage.Param2 -
                                         PressWindow->FrontContext->ClientArea.Top -
                                         PressWindow->Parent->FrontContext->ClientArea.Top );
                }

                PressSet = FALSE;
            }
            break;
        case WM_RMOUSEDOWN:;
        case WM_RMOUSEUP:;
            if ( PressWindow != NULL ) {

                if ( PressWindow->Parent == PressWindow ) {
                    NtSendDirectMessage( PressWindow,
                                         SystemMessage.MessageId,
                                         SystemMessage.Param1 - PressWindow->FrontContext->ClientArea.Left,
                                         SystemMessage.Param2 - PressWindow->FrontContext->ClientArea.Top );
                }
                else {
                    NtSendDirectMessage( PressWindow,
                                         SystemMessage.MessageId,
                                         SystemMessage.Param1 -
                                         PressWindow->FrontContext->ClientArea.Left -
                                         PressWindow->Parent->FrontContext->ClientArea.Left,
                                         SystemMessage.Param2 -
                                         PressWindow->FrontContext->ClientArea.Top -
                                         PressWindow->Parent->FrontContext->ClientArea.Top );
                }
            }
            break;
        case WM_KEYDOWN:;
        case WM_KEYUP:;
        case WM_VSCROLL:;
        case WM_HSCROLL:;
            if ( PressWindow != NULL ) {

                NtSendDirectMessage( PressWindow,
                                     SystemMessage.MessageId,
                                     SystemMessage.Param1,
                                     SystemMessage.Param2 );
            }
            break;
        default:

            break;
        }

    }
}
