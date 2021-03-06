﻿
#pragma once

//http://pdf.datasheetcatalog.com/datasheet/StandardMicrosystems/mXsstsv.pdf

#define I8042_REG_OUTPUT                    0x60
#define I8042_REG_STATUS                    0x64
#define I8042_REG_COMMAND                   0x64

#define I8042_CMD_WRITE_BYTE                0xD4

#define I8042_CMD_ACK                       0xFA
#define I8042_CMD_RESET                     0xFF
#define I8042_CMD_RESEND                    0xFE
#define I8042_CMD_SET_DEFAULTS              0xF6
#define I8042_CMD_DISABLE_PACKET_STREAMING  0xF5
#define I8042_CMD_ENABLE_PACKET_STREAMING   0xF4
#define I8042_CMD_SET_SAMPLE_RATE           0xF3
#define I8042_CMD_GET_MOUSE_ID              0xF2
#define I8042_CMD_REQUEST_SINGLE_PACKET     0xEB
#define I8042_CMD_REQUEST_STATUS            0xE9
#define I8042_CMD_SET_RESOLUTION            0xE8
#define I8042_CMD_SET_REMOTE_MODE           0xF0
#define I8042_CMD_SET_WRAP_MODE             0xEE
#define I8042_CMD_RESET_WRAP_MODE           0xEC
#define I8042_CMD_SET_STREAM_MODE           0xEA
#define I8042_CMD_SET_SCALING21             0xE7
#define I8042_CMD_SET_SCALING11             0xE6

#define I8042_ST_OUT_FULL                   0x01
#define I8042_ST_IN_FULL                    0x02
#define I8042_ST_SYSTEM                     0x04
#define I8042_ST_COMMAND                    0x08 // 1 = command, 0 = data
#define I8042_ST_INHIBIT                    0x10
#define I8042_ST_AUX_OUT_FULL               0x20
#define I8042_ST_TIMEOUT                    0x40
#define I8042_ST_PARITY_ERR                 0x80

typedef enum _I8042_MOUSE_TYPE {
    I8042MouseStandard = 0,
    I8042MouseScroll = 3,
    I8042Mouse5Button = 4,
} I8042_MOUSE_TYPE, *PI8042_MOUSE_TYPE;

#define KEY_FLAG_CTRL   0x80
#define KEY_FLAG_SHIFT  0x40
#define KEY_FLAG_ALT    0x20

ULONG64
I8042ScanToVirtual(
    _In_ PUCHAR  Scancodes,
    _In_ ULONG32 Codes
);

BOOLEAN
I8042KeyboardInterrupt(
    _In_ PKINTERRUPT Interrupt
);

BOOLEAN
I8042MouseInterrupt(
    _In_ PKINTERRUPT Interrupt
);

FORCEINLINE
VOID
I8042MouseWait(
    _In_ BOOLEAN Write
)
{
    ULONG32 TimeOut = 100000;

    if ( Write ) {
        while ( TimeOut-- ) {
            if ( ( __inbyte( I8042_REG_STATUS ) & I8042_ST_OUT_FULL ) == 1 )
                return;
        }
    }
    else {
        while ( TimeOut-- ) {
            if ( ( __inbyte( I8042_REG_STATUS ) & I8042_ST_IN_FULL ) == 0 )
                return;
        }
    }
}

FORCEINLINE
VOID
I8042MouseWrite(
    _In_ UCHAR Value
)
{
    I8042MouseWait( 1 );
    __outbyte( I8042_REG_STATUS, I8042_CMD_WRITE_BYTE );
    I8042MouseWait( 1 );
    __outbyte( I8042_REG_OUTPUT, Value );
}

FORCEINLINE
UCHAR
I8042MouseRead(

)
{
    I8042MouseWait( 0 );
    return __inbyte( I8042_REG_OUTPUT );
}

VOID
I8042MouseSetSampleRate(
    _In_ UCHAR SampleRate
);
