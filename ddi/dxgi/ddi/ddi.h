﻿


#pragma once

#pragma pack( push, 1 )

#ifdef DXINTERNAL
#define DXAPI DLLEXPORT
#else
#define DXAPI DLLIMPORT
#endif

EXTERN ULONG64 DdAdapterCount;

//
// D3DDDI = DIRECT 3D DISPLAY DEVICE INTERFACE
// D3DHAL = DIRECT 3D HARDWARE ABSTRACTION LAYER
//

#define D3DHAL_VERSION_01_00 0x0100 // 1.0

//
// pretty much all of this is ripped from svga3d_reg.h
// they probably ripped it from directx anyways 
//

typedef enum _D3DDDI_SURFACE_FLAGS {
    D3DDDI_SURFACE_CUBEMAP = ( 1 << 0 ),
    D3DDDI_SURFACE_HINT_STATIC = ( 1 << 1 ),
    D3DDDI_SURFACE_HINT_DYNAMIC = ( 1 << 2 ),
    D3DDDI_SURFACE_HINT_INDEXBUFFER = ( 1 << 3 ),
    D3DDDI_SURFACE_HINT_VERTEXBUFFER = ( 1 << 4 ),
    D3DDDI_SURFACE_HINT_TEXTURE = ( 1 << 5 ),
    D3DDDI_SURFACE_HINT_RENDERTARGET = ( 1 << 6 ),
    D3DDDI_SURFACE_HINT_DEPTHSTENCIL = ( 1 << 7 ),
    D3DDDI_SURFACE_HINT_WRITEONLY = ( 1 << 8 ),
    D3DDDI_SURFACE_MASKABLE_ANTIALIAS = ( 1 << 9 ),
    D3DDDI_SURFACE_AUTOGENMIPMAPS = ( 1 << 10 ),
} D3DDDI_SURFACE_FLAGS, *PD3DDDI_SURFACE_FLAGS;

typedef enum _D3DDDI_SURFACE_FORMAT {
    D3DDDI_FORMAT_INVALID = 0,

    D3DDDI_X8R8G8B8 = 1,
    D3DDDI_A8R8G8B8 = 2,

    D3DDDI_R5G6B5 = 3,
    D3DDDI_X1R5G5B5 = 4,
    D3DDDI_A1R5G5B5 = 5,
    D3DDDI_A4R4G4B4 = 6,

    D3DDDI_Z_D32 = 7,
    D3DDDI_Z_D16 = 8,
    D3DDDI_Z_D24S8 = 9,
    D3DDDI_Z_D15S1 = 10,

    D3DDDI_LUMINANCE8 = 11,
    D3DDDI_LUMINANCE4_ALPHA4 = 12,
    D3DDDI_LUMINANCE16 = 13,
    D3DDDI_LUMINANCE8_ALPHA8 = 14,

    D3DDDI_DXT1 = 15,
    D3DDDI_DXT2 = 16,
    D3DDDI_DXT3 = 17,
    D3DDDI_DXT4 = 18,
    D3DDDI_DXT5 = 19,

    D3DDDI_BUMPU8V8 = 20,
    D3DDDI_BUMPL6V5U5 = 21,
    D3DDDI_BUMPX8L8V8U8 = 22,
    D3DDDI_BUMPL8V8U8 = 23,

    D3DDDI_ARGB_S10E5 = 24,   /* 16-bit floating-point ARGB */
    D3DDDI_ARGB_S23E8 = 25,   /* 32-bit floating-point ARGB */

    D3DDDI_A2R10G10B10 = 26,

    /* signed formats */
    D3DDDI_V8U8 = 27,
    D3DDDI_Q8W8V8U8 = 28,
    D3DDDI_CxV8U8 = 29,

    /* mixed formats */
    D3DDDI_X8L8V8U8 = 30,
    D3DDDI_A2W10V10U10 = 31,

    D3DDDI_ALPHA8 = 32,

    /* Single- and dual-component floating point formats */
    D3DDDI_R_S10E5 = 33,
    D3DDDI_R_S23E8 = 34,
    D3DDDI_RG_S10E5 = 35,
    D3DDDI_RG_S23E8 = 36,

    /*
     * Any surface can be used as a buffer object, but D3DDDI_BUFFER is
     * the most efficient format to use when creating new surfaces
     * expressly for index or vertex data.
     */

    D3DDDI_BUFFER = 37,

    D3DDDI_Z_D24X8 = 38,

    D3DDDI_V16U16 = 39,

    D3DDDI_G16R16 = 40,
    D3DDDI_A16B16G16R16 = 41,

    /* Packed Video formats */
    D3DDDI_UYVY = 42,
    D3DDDI_YUY2 = 43,

    /* Planar video formats */
    D3DDDI_NV12 = 44,

    /* Video format with alpha */
    D3DDDI_AYUV = 45,

    D3DDDI_BC4_UNORM = 108,
    D3DDDI_BC5_UNORM = 111,

    /* Advanced D3D9 depth formats. */
    D3DDDI_Z_DF16 = 118,
    D3DDDI_Z_DF24 = 119,
    D3DDDI_Z_D24S8_INT = 120,

    D3DDDI_FORMAT_MAX
} D3DDDI_SURFACE_FORMAT, *PD3DDDI_SURFACE_FORMAT;

typedef enum _D3DDDI_CLEAR_FLAG {
    D3DDDI_CLEAR_COLOR = 0x1,
    D3DDDI_CLEAR_DEPTH = 0x2,
    D3DDDI_CLEAR_STENCIL = 0x4
} D3DDDI_CLEAR_FLAG, *PD3DDDI_CLEAR_FLAG;

typedef enum _D3DDDI_RENDER_TARGET_TYPE {
    D3DDDI_RT_DEPTH = 0,
    D3DDDI_RT_STENCIL = 1,
    D3DDDI_RT_COLOR0 = 2,
    D3DDDI_RT_COLOR1 = 3,
    D3DDDI_RT_COLOR2 = 4,
    D3DDDI_RT_COLOR3 = 5,
    D3DDDI_RT_COLOR4 = 6,
    D3DDDI_RT_COLOR5 = 7,
    D3DDDI_RT_COLOR6 = 8,
    D3DDDI_RT_COLOR7 = 9,
    D3DDDI_RT_MAX,
    D3DDDI_RT_INVALID = ( ( ULONG32 )-1 ),
} D3DDDI_RENDER_TARGET_TYPE, *PD3DDDI_RENDER_TARGET_TYPE;

typedef enum _D3DDDI_RENDER_STATE_NAME {
    D3DDDI_RS_INVALID = 0,
    D3DDDI_RS_ZENABLE = 1,     /* D3DDDIBOOLEAN */
    D3DDDI_RS_ZWRITEENABLE = 2,     /* D3DDDIBOOLEAN */
    D3DDDI_RS_ALPHATESTENABLE = 3,     /* D3DDDIBOOLEAN */
    D3DDDI_RS_DITHERENABLE = 4,     /* D3DDDIBOOLEAN */
    D3DDDI_RS_BLENDENABLE = 5,     /* D3DDDIBOOLEAN */
    D3DDDI_RS_FOGENABLE = 6,     /* D3DDDIBOOLEAN */
    D3DDDI_RS_SPECULARENABLE = 7,     /* D3DDDIBOOLEAN */
    D3DDDI_RS_STENCILENABLE = 8,     /* D3DDDIBOOLEAN */
    D3DDDI_RS_LIGHTINGENABLE = 9,     /* D3DDDIBOOLEAN */
    D3DDDI_RS_NORMALIZENORMALS = 10,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_POINTSPRITEENABLE = 11,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_POINTSCALEENABLE = 12,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_STENCILREF = 13,    /* ULONG32 */
    D3DDDI_RS_STENCILMASK = 14,    /* ULONG32 */
    D3DDDI_RS_STENCILWRITEMASK = 15,    /* ULONG32 */
    D3DDDI_RS_FOGSTART = 16,    /* float */
    D3DDDI_RS_FOGEND = 17,    /* float */
    D3DDDI_RS_FOGDENSITY = 18,    /* float */
    D3DDDI_RS_POINTSIZE = 19,    /* float */
    D3DDDI_RS_POINTSIZEMIN = 20,    /* float */
    D3DDDI_RS_POINTSIZEMAX = 21,    /* float */
    D3DDDI_RS_POINTSCALE_A = 22,    /* float */
    D3DDDI_RS_POINTSCALE_B = 23,    /* float */
    D3DDDI_RS_POINTSCALE_C = 24,    /* float */
    D3DDDI_RS_FOGCOLOR = 25,    /* D3DDDIColor */
    D3DDDI_RS_AMBIENT = 26,    /* D3DDDIColor */
    D3DDDI_RS_CLIPPLANEENABLE = 27,    /* D3DDDIClipPlanes */
    D3DDDI_RS_FOGMODE = 28,    /* D3DDDIFogMode */
    D3DDDI_RS_FILLMODE = 29,    /* D3DDDIFillMode */
    D3DDDI_RS_SHADEMODE = 30,    /* D3DDDIShadeMode */
    D3DDDI_RS_LINEPATTERN = 31,    /* D3DDDILinePattern */
    D3DDDI_RS_SRCBLEND = 32,    /* D3DDDIBlendOp */
    D3DDDI_RS_DSTBLEND = 33,    /* D3DDDIBlendOp */
    D3DDDI_RS_BLENDEQUATION = 34,    /* D3DDDIBlendEquation */
    D3DDDI_RS_CULLMODE = 35,    /* D3DDDIFace */
    D3DDDI_RS_ZFUNC = 36,    /* D3DDDICmpFunc */
    D3DDDI_RS_ALPHAFUNC = 37,    /* D3DDDICmpFunc */
    D3DDDI_RS_STENCILFUNC = 38,    /* D3DDDICmpFunc */
    D3DDDI_RS_STENCILFAIL = 39,    /* D3DDDIStencilOp */
    D3DDDI_RS_STENCILZFAIL = 40,    /* D3DDDIStencilOp */
    D3DDDI_RS_STENCILPASS = 41,    /* D3DDDIStencilOp */
    D3DDDI_RS_ALPHAREF = 42,    /* float (0.0 .. 1.0) */
    D3DDDI_RS_FRONTWINDING = 43,    /* D3DDDIFrontWinding */
    D3DDDI_RS_COORDINATETYPE = 44,    /* D3DDDICoordinateType */
    D3DDDI_RS_ZBIAS = 45,    /* float */
    D3DDDI_RS_RANGEFOGENABLE = 46,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_COLORWRITEENABLE = 47,    /* D3DDDIColorMask */
    D3DDDI_RS_VERTEXMATERIALENABLE = 48,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_DIFFUSEMATERIALSOURCE = 49,    /* D3DDDIVertexMaterial */
    D3DDDI_RS_SPECULARMATERIALSOURCE = 50,    /* D3DDDIVertexMaterial */
    D3DDDI_RS_AMBIENTMATERIALSOURCE = 51,    /* D3DDDIVertexMaterial */
    D3DDDI_RS_EMISSIVEMATERIALSOURCE = 52,    /* D3DDDIVertexMaterial */
    D3DDDI_RS_TEXTUREFACTOR = 53,    /* D3DDDIColor */
    D3DDDI_RS_LOCALVIEWER = 54,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_SCISSORTESTENABLE = 55,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_BLENDCOLOR = 56,    /* D3DDDIColor */
    D3DDDI_RS_STENCILENABLE2SIDED = 57,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_CCWSTENCILFUNC = 58,    /* D3DDDICmpFunc */
    D3DDDI_RS_CCWSTENCILFAIL = 59,    /* D3DDDIStencilOp */
    D3DDDI_RS_CCWSTENCILZFAIL = 60,    /* D3DDDIStencilOp */
    D3DDDI_RS_CCWSTENCILPASS = 61,    /* D3DDDIStencilOp */
    D3DDDI_RS_VERTEXBLEND = 62,    /* D3DDDIVertexBlendFlags */
    D3DDDI_RS_SLOPESCALEDEPTHBIAS = 63,    /* float */
    D3DDDI_RS_DEPTHBIAS = 64,    /* float */


    /*
     * Output Gamma Level
     *
     * Output gamma effects the gamma curve of colors that are output from the
     * rendering pipeline.  A value of 1.0 specifies a linear color space. If the
     * value is <= 0.0, gamma correction is ignored and linear color space is
     * used.
     */

    D3DDDI_RS_OUTPUTGAMMA = 65,    /* float */
    D3DDDI_RS_ZVISIBLE = 66,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_LASTPIXEL = 67,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_CLIPPING = 68,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_WRAP0 = 69,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP1 = 70,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP2 = 71,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP3 = 72,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP4 = 73,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP5 = 74,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP6 = 75,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP7 = 76,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP8 = 77,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP9 = 78,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP10 = 79,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP11 = 80,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP12 = 81,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP13 = 82,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP14 = 83,    /* D3DDDIWrapFlags */
    D3DDDI_RS_WRAP15 = 84,    /* D3DDDIWrapFlags */
    D3DDDI_RS_MULTISAMPLEANTIALIAS = 85,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_MULTISAMPLEMASK = 86,    /* ULONG32 */
    D3DDDI_RS_INDEXEDVERTEXBLENDENABLE = 87,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_TWEENFACTOR = 88,    /* float */
    D3DDDI_RS_ANTIALIASEDLINEENABLE = 89,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_COLORWRITEENABLE1 = 90,    /* D3DDDIColorMask */
    D3DDDI_RS_COLORWRITEENABLE2 = 91,    /* D3DDDIColorMask */
    D3DDDI_RS_COLORWRITEENABLE3 = 92,    /* D3DDDIColorMask */
    D3DDDI_RS_SEPARATEALPHABLENDENABLE = 93,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_SRCBLENDALPHA = 94,    /* D3DDDIBlendOp */
    D3DDDI_RS_DSTBLENDALPHA = 95,    /* D3DDDIBlendOp */
    D3DDDI_RS_BLENDEQUATIONALPHA = 96,    /* D3DDDIBlendEquation */
    D3DDDI_RS_TRANSPARENCYANTIALIAS = 97,    /* D3DDDITransparencyAntialiasType */
    D3DDDI_RS_LINEAA = 98,    /* D3DDDIBOOLEAN */
    D3DDDI_RS_LINEWIDTH = 99,    /* float */
    D3DDDI_RS_MAX
} D3DDDI_RENDER_STATE_NAME, *PD3DDDI_RENDER_STATE_NAME;

typedef enum {
    D3DDDI_SHADEMODE_INVALID = 0,
    D3DDDI_SHADEMODE_FLAT = 1,
    D3DDDI_SHADEMODE_SMOOTH = 2,
    D3DDDI_SHADEMODE_PHONG = 3,     /* Not supported */
    D3DDDI_SHADEMODE_MAX
} D3DDDI_SHADE_MODE;

typedef struct _D3DHAL_DATA_GET_CAPS {
    ULONG64 Caps0;
} D3DHAL_DATA_GET_CAPS, *PD3DHAL_DATA_GET_CAPS;

typedef struct _D3DHAL_DATA_SURFACE_CREATE {
    ULONG32               SurfaceId;
    D3DDDI_SURFACE_FLAGS  Flags;
    D3DDDI_SURFACE_FORMAT Format;
    // only supporting 2d surfaces atm (CHANGE BEFORE DEVELOPING MORE)
    ULONG32               Width;
    ULONG32               Height;
    ULONG32               Depth;

} D3DHAL_DATA_SURFACE_CREATE, *PD3DHAL_DATA_SURFACE_CREATE;

typedef struct _D3DHAL_DATA_SURFACE_DESTROY {
    ULONG32 SurfaceId;
} D3DHAL_DATA_SURFACE_DESTROY, *PD3DHAL_DATA_SURFACE_DESTROY;

typedef struct _D3DHAL_DATA_CONTEXT_CREATE {
    ULONG32 ContextId;
} D3DHAL_DATA_CONTEXT_CREATE, *PD3DHAL_DATA_CONTEXT_CREATE;

typedef struct _D3DHAL_DATA_CONTEXT_DESTROY {
    ULONG32 ContextId;
} D3DHAL_DATA_CONTEXT_DESTROY, *PD3DHAL_DATA_CONTEXT_DESTROY;

typedef struct _D3DHAL_DATA_SET_RENDER_TARGET {
    ULONG32                   ContextId;
    D3DDDI_RENDER_TARGET_TYPE Type;

    ULONG32                   SurfaceId;
    ULONG32                   Face;
    ULONG32                   Mipmap;

} D3DHAL_DATA_SET_RENDER_TARGET, *PD3DHAL_DATA_SET_RENDER_TARGET;

typedef struct _D3DHAL_DATA_SET_RENDER_STATE {
    ULONG32                      ContextId;
    ULONG32                      StateCount;
    struct {
        D3DDDI_RENDER_STATE_NAME State;
        union {
            ULONG32              Long;
            FLOAT                Float;
        };
    } States[ 1 ];
} D3DHAL_DATA_SET_RENDER_STATE, *PD3DHAL_DATA_SET_RENDER_STATE;

typedef struct _D3DHAL_DATA_SET_TEXTURE_STATE {
    ULONG32 ContextId;
    //svga

} D3DHAL_DATA_SET_TEXTURE_STATE, *PD3DHAL_DATA_SET_TEXTURE_STATE;

typedef struct _D3DHAL_DATA_SET_TRANSFORM {
    ULONG32 ContextId;
    //svga
    float* Transform;

} D3DHAL_DATA_SET_TRANSFORM, *PD3DHAL_DATA_SET_TRANSFORM;

typedef struct _D3DHAL_DATA_SET_MATERIAL {
    ULONG32 ContextId;
    //svga

} D3DHAL_DATA_SET_MATERIAL, *PD3DHAL_DATA_SET_MATERIAL;

typedef struct _D3DHAL_DATA_SET_LIGHT_DATA {
    ULONG32 ContextId;
    ULONG32 Index;
    //svga

} D3DHAL_DATA_SET_LIGHT_DATA, *PD3DHAL_DATA_SET_LIGHT_DATA;

typedef struct _D3DHAL_DATA_SET_LIGHT_ENABLED {
    ULONG32 ContextId;
    ULONG32 Index;
    BOOLEAN Enabled;

} D3DHAL_DATA_SET_LIGHT_ENABLED, *PD3DHAL_DATA_SET_LIGHT_ENABLED;

typedef struct _D3DHAL_DATA_SHADER_CREATE {
    ULONG32 ContextId;
    ULONG32 ShaderId;
    // svga

} D3DHAL_DATA_SHADER_CREATE, *PD3DHAL_DATA_SHADER_CREATE;

typedef struct _D3DHAL_DATA_SHADER_DESTROY {
    ULONG32 ContextId;
    ULONG32 ShaderId;
    // svga

} D3DHAL_DATA_SHADER_DESTROY, *PD3DHAL_DATA_SHADER_DESTROY;

typedef struct _D3DHAL_DATA_PRESENT {
    ULONG32 SurfaceId;
    ULONG32 x;
    ULONG32 y;
    ULONG32 w;
    ULONG32 h;
    // change for more rects (same for d3dclear)
} D3DHAL_DATA_PRESENT, *PD3DHAL_DATA_PRESENT;

typedef struct _D3DHAL_DATA_CLEAR {
    ULONG32           ContextId;
    D3DDDI_CLEAR_FLAG Flags;
    ULONG32 Colour;
    FLOAT   Depth;
    ULONG32 Stencil;
    ULONG32 x;
    ULONG32 y;
    ULONG32 w;
    ULONG32 h;
} D3DHAL_DATA_CLEAR, *PD3DHAL_DATA_CLEAR;

typedef struct _D3DHAL_DATA_DRAW_PRIMITIVES {
    ULONG32 ContextId;
    // svga

} D3DHAL_DATA_DRAW_PRIMITIVES, *PD3DHAL_DATA_DRAW_PRIMITIVES;

typedef struct _D3DHAL_DATA_BLT {
    ULONG32 SourceSurfaceId;
    ULONG32 DestinationSurfaceId;
    // svga

} D3DHAL_DATA_BLT, *PD3DHAL_DATA_BLT;

typedef struct _D3DHAL_DATA_STRETCH_BLT {
    ULONG32 SourceSurfaceId;
    ULONG32 DestinationSurfaceId;
    // svga

} D3DHAL_DATA_STRETCH_BLT, *PD3DHAL_DATA_STRETCH_BLT;

typedef struct _D3DHAL_DATA_SET_ZRANGE {
    ULONG32 ContextId;
    FLOAT   Minimum;
    FLOAT   Maximum;

} D3DHAL_DATA_SET_ZRANGE, *PD3DHAL_DATA_SET_ZRANGE;

typedef struct _D3DHAL_DATA_SET_VIEWPORT {
    ULONG32 ContextId;
    ULONG32 x;
    ULONG32 y;
    ULONG32 w;
    ULONG32 h;
} D3DHAL_DATA_SET_VIEWPORT, *PD3DHAL_DATA_SET_VIEWPORT;

// add DC to all
typedef NTSTATUS( *PD3DHAL_GET_CAPS )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_GET_CAPS );
typedef NTSTATUS( *PD3DHAL_SURFACE_CREATE )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SURFACE_CREATE );
typedef NTSTATUS( *PD3DHAL_SURFACE_DESTROY )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SURFACE_DESTROY );
typedef NTSTATUS( *PD3DHAL_CONTEXT_CREATE )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_CONTEXT_CREATE );
typedef NTSTATUS( *PD3DHAL_CONTEXT_DESTROY )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_CONTEXT_DESTROY );
typedef NTSTATUS( *PD3DHAL_SET_RENDER_TARGET )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SET_RENDER_TARGET );
typedef NTSTATUS( *PD3DHAL_SET_RENDER_STATE )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SET_RENDER_STATE );
typedef NTSTATUS( *PD3DHAL_SET_TEXTURE_STATE )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SET_TEXTURE_STATE );
typedef NTSTATUS( *PD3DHAL_SET_TRANSFORM )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SET_TRANSFORM );
typedef NTSTATUS( *PD3DHAL_SET_MATERIAL )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SET_MATERIAL );
typedef NTSTATUS( *PD3DHAL_SET_LIGHT_DATA )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SET_LIGHT_DATA );
typedef NTSTATUS( *PD3DHAL_SET_LIGHT_ENABLED )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SET_LIGHT_ENABLED );
typedef NTSTATUS( *PD3DHAL_SHADER_CREATE )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SHADER_CREATE );
typedef NTSTATUS( *PD3DHAL_SHADER_DESTROY )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SHADER_DESTROY );
typedef NTSTATUS( *PD3DHAL_PRESENT )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_PRESENT );
typedef NTSTATUS( *PD3DHAL_CLEAR )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_CLEAR );
typedef NTSTATUS( *PD3DHAL_DRAW_PRIMITIVES )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_DRAW_PRIMITIVES );
typedef NTSTATUS( *PD3DHAL_BLT )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_BLT );
typedef NTSTATUS( *PD3DHAL_STRETCH_BLT )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_STRETCH_BLT );
typedef NTSTATUS( *PD3DHAL_SET_ZRANGE )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SET_ZRANGE );
typedef NTSTATUS( *PD3DHAL_SET_VIEWPORT )(
    _In_ PDEVICE_OBJECT,
    _In_ PD3DHAL_DATA_SET_VIEWPORT );
typedef NTSTATUS( *PD3DHAL_SUBMIT_COMMAND )(
    _In_ PDEVICE_OBJECT
    );

typedef VOID( *PDDI_INITIALIZE_DC )(
    _In_ PDEVICE_OBJECT,
    _In_ PDC
    );
typedef VOID( *PDDI_RELEASE_DC )(
    _In_ PDEVICE_OBJECT,
    _In_ PDC
    );
typedef VOID( *PDDI_BLT_DC )(
    _In_ PDEVICE_OBJECT,
    _In_ PDC,
    _In_ ULONG32,
    _In_ ULONG32,
    _In_ ULONG32,
    _In_ ULONG32,
    _In_ PDC,
    _In_ ULONG32,
    _In_ ULONG32
    );
typedef VOID( *PDDI_SET_PIXEL_DC )(
    _In_ PDEVICE_OBJECT,
    _In_ PDC,
    _In_ ULONG32,
    _In_ ULONG32,
    _In_ ULONG32
    );
typedef VOID( *PDDI_BLT_BITS_DC )(
    _In_ PDEVICE_OBJECT,
    _In_ PVOID,
    _In_ ULONG32,
    _In_ ULONG32,
    _In_ ULONG32,
    _In_ ULONG32,
    _In_ PDC,
    _In_ ULONG32,
    _In_ ULONG32
    );
typedef VOID( *PDDI_CLEAR_DC )(
    _In_ PDEVICE_OBJECT,
    _In_ PDC,
    _In_ ULONG32,
    _In_ ULONG32,
    _In_ ULONG32,
    _In_ ULONG32,
    _In_ ULONG32
    );
typedef NTSTATUS( *PDDI_SET_MODE )(
    _In_  PDEVICE_OBJECT,
    _Out_ ULONG32,
    _Out_ ULONG32,
    _Out_ ULONG32
    );
typedef VOID( *PDDI_GET_MODE )(
    _In_  PDEVICE_OBJECT,
    _Out_ ULONG32*,
    _Out_ ULONG32*,
    _Out_ ULONG32*
    );

typedef struct _D3DHAL {
    ULONG64                   D3dHalVersion;
    PD3DHAL_GET_CAPS          D3dHalGetCaps;
    PD3DHAL_SURFACE_CREATE    D3dHalSurfaceCreate;
    PD3DHAL_SURFACE_DESTROY   D3dHalSurfaceDestroy;
    PD3DHAL_CONTEXT_CREATE    D3dHalContextCreate;
    PD3DHAL_CONTEXT_DESTROY   D3dHalContextDestroy;
    PD3DHAL_SET_RENDER_TARGET D3dHalSetRenderTarget;
    PD3DHAL_SET_RENDER_STATE  D3dHalSetRenderState;
    PD3DHAL_SET_TEXTURE_STATE D3dHalSetTextureState;
    PD3DHAL_SET_TRANSFORM     D3dHalSetTransform;
    PD3DHAL_SET_MATERIAL      D3dHalSetMaterial;
    PD3DHAL_SET_LIGHT_DATA    D3dHalSetLightData;
    PD3DHAL_SET_LIGHT_ENABLED D3dHalSetLightEnabled;
    PD3DHAL_SHADER_CREATE     D3dHalShaderCreate;
    PD3DHAL_SHADER_DESTROY    D3dHalShaderDestroy;
    PD3DHAL_PRESENT           D3dHalPresent;
    PD3DHAL_CLEAR             D3dHalClear;
    PD3DHAL_BLT               D3dHalBlt;
    PD3DHAL_STRETCH_BLT       D3dHalStretchBlt;
    PD3DHAL_SET_ZRANGE        D3dHalSetZRange;
    PD3DHAL_SET_VIEWPORT      D3dHalSetViewport;
    PD3DHAL_SUBMIT_COMMAND    D3dHalSubmitCommand;

    PDDI_INITIALIZE_DC        NtDdiInitializeDC;
    PDDI_RELEASE_DC           NtDdiReleaseDC;
    PDDI_BLT_DC               NtDdiBltDC;
    PDDI_SET_PIXEL_DC         NtDdiSetPixelDC;
    PDDI_BLT_BITS_DC          NtDdiBltBitsDC;
    PDDI_CLEAR_DC             NtDdiClearDC;

    PDDI_SET_MODE             NtDdiSetMode;
    PDDI_GET_MODE             NtDdiGetMode;

} D3DHAL, *PD3DHAL;

DXAPI
ULONG32
DdCreateUniqueId(

);

DXAPI
NTSTATUS
DdCreateAdapter(
    _In_  PDEVICE_OBJECT  DeviceObject,
    _Out_ PDEVICE_OBJECT* DdiDeviceObject
);

#define DdGetAdapterD3dHal( adapter ) ( ( PD3DHAL )( ( adapter )->DeviceExtension ) )

#pragma pack( pop )
