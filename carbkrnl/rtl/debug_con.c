﻿


#include <carbsup.h>
#include "../hal/halp.h"
#include "../ke/ki.h"
#include "../mm/mi.h"
#include "../rtl/ldr/ldrp.h"

VOID
RtlDebugConsoleUpdate(

);

UCHAR Font8x16[ 4096 ] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x22, 0x22, 0x22, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x12, 0x12, 0x12, 0x7e, 0x24, 0x24, 0x7e, 0x48, 0x48, 0x48, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x3e, 0x49, 0x48, 0x38, 0x0e, 0x09, 0x49, 0x3e, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x31, 0x4a, 0x4a, 0x34, 0x08, 0x08, 0x16, 0x29, 0x29, 0x46, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x22, 0x22, 0x14, 0x18, 0x29, 0x45, 0x42, 0x46, 0x39, 0x00, 0x00,
    0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x04, 0x00,
    0x00, 0x00, 0x00, 0x20, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x20, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x49, 0x2a, 0x1c, 0x2a, 0x49, 0x08, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x7f, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x08, 0x08, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20, 0x40, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x42, 0x46, 0x4a, 0x52, 0x62, 0x42, 0x24, 0x18, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0x28, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x02, 0x0c, 0x10, 0x20, 0x40, 0x40, 0x7e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x02, 0x1c, 0x02, 0x02, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x0c, 0x14, 0x24, 0x44, 0x44, 0x7e, 0x04, 0x04, 0x04, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x7c, 0x02, 0x02, 0x02, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x20, 0x40, 0x40, 0x7c, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7e, 0x02, 0x02, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x3e, 0x02, 0x02, 0x02, 0x04, 0x38, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x08, 0x08, 0x10, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x08, 0x10, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x10, 0x08, 0x04, 0x08, 0x10, 0x20, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x02, 0x04, 0x08, 0x08, 0x00, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x22, 0x4a, 0x56, 0x52, 0x52, 0x52, 0x4e, 0x20, 0x1e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x24, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7c, 0x42, 0x42, 0x42, 0x7c, 0x42, 0x42, 0x42, 0x42, 0x7c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x78, 0x44, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x44, 0x78, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x40, 0x40, 0x4e, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x44, 0x44, 0x38, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x42, 0x44, 0x48, 0x50, 0x60, 0x60, 0x50, 0x48, 0x44, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x66, 0x66, 0x5a, 0x5a, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x42, 0x62, 0x62, 0x52, 0x52, 0x4a, 0x4a, 0x46, 0x46, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7c, 0x42, 0x42, 0x42, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x5a, 0x66, 0x3c, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7c, 0x42, 0x42, 0x42, 0x7c, 0x48, 0x44, 0x44, 0x42, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x40, 0x30, 0x0c, 0x02, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7f, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x41, 0x41, 0x41, 0x22, 0x22, 0x22, 0x14, 0x14, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x5a, 0x5a, 0x66, 0x66, 0x42, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x24, 0x24, 0x18, 0x18, 0x24, 0x24, 0x42, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x41, 0x41, 0x22, 0x22, 0x14, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7e, 0x02, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x40, 0x7e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0e, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x20, 0x10, 0x10, 0x08, 0x08, 0x04, 0x02, 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x70, 0x00,
    0x00, 0x00, 0x18, 0x24, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00,
    0x00, 0x20, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x02, 0x3e, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x5c, 0x62, 0x42, 0x42, 0x42, 0x42, 0x62, 0x5c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x3a, 0x46, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x7e, 0x40, 0x40, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0c, 0x10, 0x10, 0x10, 0x7c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x3a, 0x44, 0x44, 0x44, 0x38, 0x20, 0x3c, 0x42, 0x42, 0x3c,
    0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x5c, 0x62, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x0c, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x48, 0x30,
    0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x44, 0x48, 0x50, 0x60, 0x50, 0x48, 0x44, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0x62, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0x62, 0x42, 0x42, 0x42, 0x42, 0x62, 0x5c, 0x40, 0x40,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3a, 0x46, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3a, 0x02, 0x02,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0x62, 0x42, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x40, 0x30, 0x0c, 0x02, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x7c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x24, 0x24, 0x24, 0x18, 0x18, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x26, 0x1a, 0x02, 0x02, 0x3c,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x7e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0c, 0x10, 0x10, 0x08, 0x08, 0x10, 0x20, 0x10, 0x08, 0x08, 0x10, 0x10, 0x0c,
    0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x00, 0x00, 0x00, 0x30, 0x08, 0x08, 0x10, 0x10, 0x08, 0x04, 0x08, 0x10, 0x10, 0x08, 0x08, 0x30,
    0x00, 0x00, 0x00, 0x31, 0x49, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x73, 0xca, 0x4b, 0xca, 0x73, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x71, 0xca, 0x73, 0xc2, 0x42, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x49, 0xca, 0x7a, 0xca, 0x49, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x73, 0xca, 0x73, 0xca, 0x72, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x4b, 0xea, 0x5b, 0xca, 0x4b, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x74, 0xa6, 0x25, 0xa4, 0x74, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x4b, 0xea, 0x5b, 0xca, 0x4b, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x39, 0xc2, 0x31, 0x88, 0x73, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x79, 0xc2, 0x79, 0xc0, 0x7b, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x4b, 0xc9, 0x79, 0xc9, 0x49, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x25, 0xa4, 0x3c, 0xa4, 0x24, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x45, 0xc4, 0x44, 0xa8, 0x10, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x72, 0xca, 0x72, 0xc2, 0x43, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x72, 0xca, 0x72, 0xc2, 0x43, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x0e, 0x89, 0x0e, 0x8a, 0x09, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x39, 0xc2, 0x31, 0x88, 0x73, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x39, 0xc2, 0x31, 0x88, 0x73, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x71, 0xca, 0x4a, 0xca, 0x71, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x72, 0xca, 0x72, 0xc2, 0x41, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x72, 0xca, 0x72, 0xc2, 0x41, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x3b, 0xc1, 0x31, 0x89, 0x71, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x39, 0xc2, 0x42, 0xc2, 0x39, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x22, 0xb6, 0x2a, 0xa2, 0x22, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x3b, 0xc2, 0x33, 0x8a, 0x72, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x7b, 0xc2, 0x7b, 0xc2, 0x7a, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x39, 0xc2, 0x32, 0x8a, 0x71, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x33, 0xc4, 0x25, 0x94, 0x63, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x39, 0xc2, 0x32, 0x8a, 0x71, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x39, 0xc2, 0x41, 0xc0, 0x3b, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x0e, 0x90, 0x0c, 0x82, 0x1c, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x31, 0xca, 0x49, 0xc8, 0x33, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x1c, 0x92, 0x1c, 0x90, 0x10, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0xaa, 0x00, 0x80, 0x00, 0x80, 0x33, 0xca, 0x7b, 0xca, 0x4a, 0x80, 0x00, 0x80, 0x00, 0x80, 0x55,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x3e, 0x49, 0x48, 0x48, 0x49, 0x3e, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0e, 0x10, 0x10, 0x10, 0x7c, 0x10, 0x10, 0x10, 0x3e, 0x61, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x3c, 0x24, 0x42, 0x42, 0x24, 0x3c, 0x42, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x41, 0x22, 0x14, 0x08, 0x7f, 0x08, 0x7f, 0x08, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x40, 0x3c, 0x42, 0x42, 0x3c, 0x02, 0x42, 0x3c, 0x00, 0x00,
    0x24, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x99, 0xa5, 0xa1, 0xa1, 0xa5, 0x99, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x1c, 0x02, 0x1e, 0x22, 0x1e, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x12, 0x24, 0x24, 0x48, 0x24, 0x24, 0x12, 0x12, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x02, 0x02, 0x02, 0x00, 0x00,
    0xaa, 0x00, 0x80, 0x3a, 0xc2, 0x33, 0x8a, 0x72, 0x80, 0x00, 0x80, 0x03, 0x80, 0x00, 0x80, 0x55,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0xb9, 0xa5, 0xa5, 0xb9, 0xa9, 0xa5, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x7f, 0x08, 0x08, 0x08, 0x00, 0x7f, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x38, 0x44, 0x04, 0x18, 0x20, 0x40, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x38, 0x44, 0x04, 0x38, 0x04, 0x44, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x66, 0x59, 0x40, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x3f, 0x7a, 0x7a, 0x7a, 0x3a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x30,
    0x00, 0x00, 0x00, 0x10, 0x30, 0x50, 0x10, 0x10, 0x10, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1c, 0x22, 0x22, 0x22, 0x1c, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x48, 0x24, 0x24, 0x12, 0x24, 0x24, 0x48, 0x48, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x22, 0x62, 0x24, 0x28, 0x28, 0x12, 0x16, 0x2a, 0x4e, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x22, 0x62, 0x24, 0x28, 0x28, 0x14, 0x1a, 0x22, 0x44, 0x4e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x62, 0x12, 0x24, 0x18, 0x68, 0x12, 0x16, 0x2a, 0x4e, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x20, 0x40, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x30, 0x0c, 0x00, 0x00, 0x18, 0x24, 0x24, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x0c, 0x30, 0x00, 0x00, 0x18, 0x24, 0x24, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x18, 0x24, 0x00, 0x00, 0x18, 0x24, 0x24, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x32, 0x4c, 0x00, 0x00, 0x18, 0x24, 0x24, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x24, 0x24, 0x00, 0x00, 0x18, 0x24, 0x24, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x18, 0x24, 0x18, 0x00, 0x18, 0x24, 0x24, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1f, 0x28, 0x48, 0x48, 0x7f, 0x48, 0x48, 0x48, 0x48, 0x4f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x42, 0x3c, 0x08, 0x30,
    0x30, 0x0c, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00,
    0x0c, 0x30, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00,
    0x18, 0x24, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00,
    0x24, 0x24, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00,
    0x18, 0x06, 0x00, 0x00, 0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x0c, 0x30, 0x00, 0x00, 0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x18, 0x24, 0x00, 0x00, 0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x24, 0x24, 0x00, 0x00, 0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x78, 0x44, 0x42, 0x42, 0xf2, 0x42, 0x42, 0x42, 0x44, 0x78, 0x00, 0x00,
    0x32, 0x4c, 0x00, 0x00, 0x42, 0x62, 0x62, 0x52, 0x52, 0x4a, 0x4a, 0x46, 0x46, 0x42, 0x00, 0x00,
    0x30, 0x0c, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x0c, 0x30, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x18, 0x24, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x32, 0x4c, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x24, 0x24, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x24, 0x18, 0x24, 0x42, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x3a, 0x44, 0x46, 0x4a, 0x4a, 0x52, 0x52, 0x62, 0x22, 0x5c, 0x40, 0x00,
    0x30, 0x0c, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x0c, 0x30, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x18, 0x24, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x24, 0x24, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x0c, 0x30, 0x00, 0x00, 0x41, 0x41, 0x22, 0x22, 0x14, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x40, 0x40, 0x78, 0x44, 0x42, 0x42, 0x44, 0x78, 0x40, 0x40, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x38, 0x44, 0x44, 0x48, 0x58, 0x44, 0x42, 0x42, 0x52, 0x4c, 0x00, 0x00,
    0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x3c, 0x42, 0x02, 0x3e, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x30, 0x00, 0x00, 0x3c, 0x42, 0x02, 0x3e, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x24, 0x00, 0x00, 0x3c, 0x42, 0x02, 0x3e, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x32, 0x4c, 0x00, 0x00, 0x3c, 0x42, 0x02, 0x3e, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x24, 0x24, 0x00, 0x00, 0x3c, 0x42, 0x02, 0x3e, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x18, 0x24, 0x18, 0x00, 0x00, 0x3c, 0x42, 0x02, 0x3e, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x49, 0x09, 0x3f, 0x48, 0x48, 0x49, 0x3e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x3c, 0x08, 0x30,
    0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x7e, 0x40, 0x40, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x30, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x7e, 0x40, 0x40, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x24, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x7e, 0x40, 0x40, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x24, 0x24, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x7e, 0x40, 0x40, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x30, 0x00, 0x00, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x24, 0x00, 0x00, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x00, 0x00, 0x24, 0x24, 0x00, 0x00, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
    0x00, 0x00, 0x32, 0x0c, 0x14, 0x22, 0x02, 0x3e, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x32, 0x4c, 0x00, 0x00, 0x5c, 0x62, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00,
    0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x30, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x24, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x32, 0x4c, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x24, 0x24, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x3c, 0x46, 0x4a, 0x4a, 0x52, 0x52, 0x62, 0x3c, 0x40, 0x00,
    0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x30, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x24, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x24, 0x24, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x30, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x26, 0x1a, 0x02, 0x02, 0x3c,
    0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x5c, 0x62, 0x42, 0x42, 0x42, 0x42, 0x62, 0x5c, 0x40, 0x40,
    0x00, 0x00, 0x24, 0x24, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x26, 0x1a, 0x02, 0x02, 0x3c,
};

ULONG32         DisplayWidth;
ULONG32         DisplayHeight;
ULONG32         BitsPerPixel;
ULONG32         Framebuffer;
DLLEXPORT PULONG32        MappedFramebuffer = NULL;
BOOLEAN         Ready = FALSE;

ULONG64         CharScrolled = 0;
#pragma section(".bss")
__declspec( allocate( ".bss" ) )
WCHAR           CharBuffer[ 65535 ];//8192 ];

#if 1
BOOLEAN
RtlDebugConsoleKeyboardIrq(
    _In_ PKINTERRUPT Interrupt
)
{
    Interrupt;

    UCHAR Scancode;

    Scancode = __inbyte( 0x60 );

    //RtlDebugPrint( L"char press code: %ul\n", ( ULONG )Scancode );

    if ( Scancode == 0x11 ) {
        RtlDebugScroll( -3 );
    }

    if ( Scancode == 0x1f ) {
        RtlDebugScroll( 3 );
    }

    return FALSE; // act as a layer on top.
}
#endif

VOID
RtlDebugConsoleInit(
    _In_ ULONG32 Width,
    _In_ ULONG32 Height,
    _In_ ULONG32 Bpp,
    _In_ ULONG32 Fb
)
{
    DisplayWidth = Width;
    DisplayHeight = Height;
    BitsPerPixel = Bpp;
    Framebuffer = Fb;

    PMM_SECTION_OBJECT Section;
    OBJECT_ATTRIBUTES FrameAttributes = { RTL_CONSTANT_STRING( L"\\Device\\Framebuffer" ), { 0 }, OBJ_PERMANENT_OBJECT };

    MmCreateSectionSpecifyAddress(
        &Section,
        &FrameAttributes,
        SEC_WRITE | SEC_WRITECOMBINE,
        Framebuffer,
        DisplayWidth * DisplayHeight * ( BitsPerPixel / 8 ) );
    MmMapViewOfSection(
        Section,
        PsInitialSystemProcess,
        &MappedFramebuffer, 0, 0,
        PAGE_READ | PAGE_WRITE );
#if 0
    KIRQL PreviousIrql;
    PIO_INTERRUPT InterruptObject;
    OBJECT_ATTRIBUTES Interrupt = { 0 };
    KeRaiseIrql( DISPATCH_LEVEL, &PreviousIrql );
    IoConnectInterrupt( &InterruptObject,
        ( KSERVICE_ROUTINE )RtlDebugConsoleKeyboardIrq,
                        NULL,
                        0x40,
                        DISPATCH_LEVEL,
                        &Interrupt );

    KAPIC_REDIRECT Redirect;
    Redirect.Lower = 0;
    Redirect.Upper = 0;

    Redirect.InterruptVector = 0x40;
    Redirect.DeliveryMode = DeliveryModeEdge;
    Redirect.DestinationMode = DestinationModePhysical;
    Redirect.Destination = KeQueryCurrentProcessor( )->ApicId;

    HalApicRedirectIrq( 1, &Redirect );

    KeLowerIrql( PreviousIrql );
#endif
    Ready = TRUE;

}

VOID
RtlDebugDisplayChar(
    _In_ WCHAR   Char,
    _In_ ULONG64 CharX,
    _In_ ULONG64 CharY
)
{
    ULONG64 i;
    ULONG64 j;
    UCHAR   Line;

    LONG64  x;
    LONG64  y;

    y = CharY - CharScrolled;
    x = CharX;

    if ( y < 0 ) {

        return;
    }

    y *= 16;
    x *= 8;

    for ( i = 0; i < 16; i++ ) {
        Line = Font8x16[ Char * 16 + i ];
        for ( j = 0; j <= 8; j++ ) {
            if ( ( Line >> ( 8 - j - 1 ) ) & 1 ) {

                if ( ( DisplayWidth * DisplayHeight * ( BitsPerPixel / 8 ) ) > ( ( y + i ) * DisplayWidth + x + j ) * 4 ) {
                    MappedFramebuffer[ ( y + i ) * DisplayWidth + x + j ] = 0xFFE0E0E0;
                }
            }
        }
    }

}

VOID
RtlDebugConsoleUpdate(

)
{
    ULONG64 CharX;
    ULONG64 CharY;

    if ( !Ready ) {

        return;
    }

    RtlZeroMemory( MappedFramebuffer, DisplayWidth * DisplayHeight * ( BitsPerPixel / 8 ) );

    CharX = 0;
    CharY = 0;

    for ( ULONG64 i = 0; CharBuffer[ i ] != 0; i++ ) {

        switch ( CharBuffer[ i ] ) {
        case '\n':
            CharY++;
        case '\r':
            CharX = 0;
            break;
        case '\t':
            CharX += ( 4 - ( CharX % 4 ) );
            break;
        case ' ':
            CharX++;
            break;
        default:
            RtlDebugDisplayChar( CharBuffer[ i ], CharX, CharY );
            CharX++;
            break;
        }
    }
}

VOID
RtlDebugScroll(
    _In_ LONG64 Scroll
)
{
    LONG64 Scrolled;

    Scrolled = CharScrolled;

    if ( Scrolled + Scroll < 0 ) {
        CharScrolled = 0;
    }
    else {
        CharScrolled = Scrolled + Scroll;
    }

    RtlDebugConsoleUpdate( );
}

VOID
RtlDebugPrint(
    _In_ PWSTR Format,
    _In_ ...
)
{
    Format;
    //return;
#if 1
    //STATIC KSPIN_LOCK SpinLock;
    //KIRQL PreviousIrql;

    //KeAcquireSpinLock( &SpinLock, &PreviousIrql ); // be careful with scheduler and printing.

    WCHAR Buffer[ 256 ];
    VA_LIST ArgumentList;
    __crt_va_start( ArgumentList, Format );
    RtlFormatBufferFromArgumentList( Buffer, Format, ArgumentList );
    __crt_va_end( ArgumentList );

    lstrcatW( CharBuffer, Buffer );

    RtlDebugConsoleUpdate( );

#if 0
    if ( KeQueryCurrentProcessor( ) != NULL &&
         !KeQueryCurrentProcessor( )->InService ) {
        VOID( *_KdPrint )(
            _In_ PWSTR Format,
            _In_ ...
            );
        UNICODE_STRING Kd = RTL_CONSTANT_STRING( L"KDCOM.SYS" );

        if ( KdDebuggerEnabled ) {

            LdrGetExportAddressByName(
                ( PVOID )MiFindVadByShortName( PsInitialSystemProcess, &Kd )->Start,
                "KdPrint", ( PVOID* )&_KdPrint );

            _KdPrint( Buffer );
        }
    }
#endif
    //KeReleaseSpinLock( &SpinLock, PreviousIrql );
#endif
}
