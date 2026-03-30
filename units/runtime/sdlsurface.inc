//from "sdl_surface.h"

const
  {**
   *  Surface flags
   *
   *  These are the currently supported flags for the ::SDL_surface.
   *
   *  Used internally (read-only).
   *}

  SDL_SWSURFACE    = 0;          {**< Just here for compatibility *}
  SDL_PREALLOC     = $00000001;  {**< Surface uses preallocated memory *}
  SDL_RLEACCEL     = $00000002;  {**< Surface is RLE encoded *}
  SDL_DONTFREE     = $00000004;  {**< Surface is referenced internally *}
  SDL_SIMD_ALIGNED = $00000008;  {**< Surface uses aligned memory *}

type
  {**
   *  A collection of pixels used in software blitting.
   *
   *  This structure should be treated as read-only, except for \c pixels,
   *  which, if not NULL, contains the raw pixel data for the surface.
   *}
  PPSDL_BlitMap = ^PSDL_BlitMap;
  PSDL_BlitMap = type Pointer;

  PPSDL_Surface = ^PSDL_Surface;
  PSDL_Surface = ^TSDL_Surface;
  TSDL_Surface = record
    flags: cuint32;              {**< Read-only *}
    format: PSDL_PixelFormat;    {**< Read-only *}
    w, h: cint;                  {**< Read-only *}
    pitch: cint;                 {**< Read-only *}
    pixels: Pointer;             {**< Read-write *}

    {** Application data associated with the surface *}
    userdata: Pointer;           {**< Read-write *}

    {** information needed for surfaces requiring locks *}
    locked: cint;                {**< Read-only *}
    //lock_data: Pointer;        {**< Read-only *} // field gone in or before 2.0.14?

    {** list of BlitMap that hold a reference to this surface *}
    list_blitmap: Pointer;       {**< Private *}

    {** clipping information *}
    clip_rect: TSDL_Rect;        {**< Read-only *}

    {** info for fast blit mapping to other surfaces *}
    map: PSDL_BlitMap;           {**< Private *}

    {** Reference count -- used when freeing surface *}
    refcount: cint;              {**< Read-mostly *}
  end;

// Evaluates to true if the surface needs to be locked before access.
function SDL_MUSTLOCK(Const S:PSDL_Surface):Boolean;

type
  {**
   *  The type of function used for surface blitting functions.
   *}
   PPSDL_Blit = ^PSDL_Blit;
   PSDL_Blit = ^TSDL_Blit;
   TSDL_Blit = function(src: PSDL_Surface; srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect): cint;

type
  {**
  * \brief The formula used for converting between YUV and RGB
  *}
  TSDL_YUV_CONVERSION_MODE = type Integer;

const
  SDL_YUV_CONVERSION_JPEG      = TSDL_YUV_CONVERSION_MODE(0); {**< Full range JPEG *}
  SDL_YUV_CONVERSION_BT601     = TSDL_YUV_CONVERSION_MODE(1); {**< BT.601 (the default) *}
  SDL_YUV_CONVERSION_BT709     = TSDL_YUV_CONVERSION_MODE(2); {**< BT.709 *}
  SDL_YUV_CONVERSION_AUTOMATIC = TSDL_YUV_CONVERSION_MODE(3); {**< BT.601 for SD content, BT.709 for HD content *}

type
  TSDL_CreateRGBSurfaceWithFormat_func = function(flags: cuint32; width, height, depth: cint; format: cuint32):PSDL_Surface; cdecl;

type
  TSDL_CreateRGBSurface_func = function(flags: cuint32; width: cint; height: cint; depth: cint; Rmask: cuint32; Gmask: cuint32; Bmask: cuint32; Amask: cuint32): PSDL_Surface; cdecl;
var
 {**
 *  Allocate and free an RGB surface.
 *
 *  If the depth is 4 or 8 bits, an empty palette is allocated for the surface.
 *  If the depth is greater than 8 bits, the pixel format is set using the
 *  flags '[RGB]mask'.
 *
 *  If the function runs out of memory, it will return NULL.
 *
 *  \param flags The \c flags are obsolete and should be set to 0.
 *  \param width The width in pixels of the surface to create.
 *  \param height The height in pixels of the surface to create.
 *  \param depth The depth in bits of the surface to create.
 *  \param Rmask The red mask of the surface to create.
 *  \param Gmask The green mask of the surface to create.
 *  \param Bmask The blue mask of the surface to create.
 *  \param Amask The alpha mask of the surface to create.
 *}
  SDL_CreateRGBSurface : TSDL_CreateRGBSurface_func = Nil;

{* !!! FIXME for 2.1: why does this ask for depth? Format provides that. *}
  SDL_CreateRGBSurfaceWithFormat : TSDL_CreateRGBSurfaceWithFormat_func = Nil;

type
  TSDL_CreateRGBSurfaceFrom_func = function(pixels: Pointer; width: cint; height: cint; depth: cint; pitch: cint; Rmask: cuint32; Gmask: cuint32; Bmask: cuint32; Amask: cuint32): PSDL_Surface; cdecl;
var
  SDL_CreateRGBSurfaceFrom : TSDL_CreateRGBSurfaceFrom_func = Nil;

type
  TSDL_CreateRGBSurfaceWithFormatFrom_func = function(pixels: Pointer; width, height, depth, pitch: cint; format: cuint32):PSDL_Surface; cdecl;
var
  SDL_CreateRGBSurfaceWithFormatFrom : TSDL_CreateRGBSurfaceWithFormatFrom_func = Nil;

type
  TSDL_FreeSurface_proc = procedure(surface: PSDL_Surface); cdecl;
var
  SDL_FreeSurface : TSDL_FreeSurface_proc = Nil;

type
  TSDL_SetSurfacePalette_func = function(surface: PSDL_Surface; palette: PSDL_Palette): cint; cdecl;
var
  {**
   *  Set the palette used by a surface.
   *
   *  0, or -1 if the surface format doesn't use a palette.
   *
   *  A single palette can be shared with many surfaces.
   *}
  SDL_SetSurfacePalette : TSDL_SetSurfacePalette_func = Nil;

type
  TSDL_LockSurface_func = function(surface: PSDL_Surface): cint; cdecl;
var
  {** SDL_LockSurface() *}
  SDL_LockSurface : TSDL_LockSurface_func = Nil;

type
  TSDL_UnlockSurface_proc = procedure(surface: PSDL_Surface); cdecl;
var
  {**
   *  Sets up a surface for directly accessing the pixels.
   *
   *  Between calls to SDL_LockSurface() / SDL_UnlockSurface(), you can write
   *  to and read from surface.pixels, using the pixel format stored in
   *  surface.format. Once you are done accessing the surface, you should
   *  use SDL_UnlockSurface() to release it.
   *
   *  Not all surfaces require locking.  If SDL_MUSTLOCK(surface) evaluates
   *  to 0, then you can read and write to the surface at any time, and the
   *  pixel format of the surface will not change.
   *
   *  No operating system or library calls should be made between lock/unlock
   *  pairs, as critical system locks may be held during this time.
   *
   *  SDL_LockSurface() returns 0, or -1 if the surface couldn't be locked.
   *
   *  SDL_UnlockSurface()
   *}
  SDL_UnlockSurface : TSDL_UnlockSurface_proc = Nil;

type
  TSDL_LoadBMP_RW_func = function(src: PSDL_RWops; freesrc: cint): PSDL_Surface; cdecl;
var
  {**
   *  Load a surface from a seekable SDL data stream (memory or file).
   *
   *  If freesrc is non-zero, the stream will be closed after being read.
   *
   *  The new surface should be freed with SDL_FreeSurface().
   *
   *  the new surface, or NULL if there was an error.
   *}
  SDL_LoadBMP_RW : TSDL_LoadBMP_RW_func = Nil;


  {**
   *  Load a surface from a file.
   *
   *  Convenience macro.
   *}

function SDL_LoadBMP(_file: PAnsiChar): PSDL_Surface;

type
  TSDL_SaveBMP_RW_func = function(surface: PSDL_Surface; dst: PSDL_RWops; freedst: cint): cint; cdecl;
var
 {**
 *  Save a surface to a seekable SDL data stream (memory or file).
 *
 *  Surfaces with a 24-bit, 32-bit and paletted 8-bit format get saved in the
 *  BMP directly. Other RGB formats with 8-bit or higher get converted to a
 *  24-bit surface or, if they have an alpha mask or a colorkey, to a 32-bit
 *  surface before they are saved. YUV and paletted 1-bit and 4-bit formats are
 *  not supported.
 *
 *  If \c freedst is non-zero, the stream will be closed after being written.
 *
 *  \return 0 if successful or -1 if there was an error.
 *}
  SDL_SaveBMP_RW : TSDL_SaveBMP_RW_func = Nil;


  {**
   *  Save a surface to a file.
   *
   *  Convenience macro.
   *}
{ TODO : Check: Why AnsiString instead of PAnsiChar used here? Compare SDL_LoadBMP macro. }
function SDL_SaveBMP(const surface: PSDL_Surface; const filename:AnsiString): cint;

type
  TSDL_SetSurfaceRLE_func = function(surface: PSDL_Surface; flag: cint): cint; cdecl;
var
  {**
   *  Sets the RLE acceleration hint for a surface.
   *
   *  0 on success, or -1 if the surface is not valid
   *  
   *  If RLE is enabled, colorkey and alpha blending blits are much faster,
   *  but the surface must be locked before directly accessing the pixels.
   *}
  SDL_SetSurfaceRLE : TSDL_SetSurfaceRLE_func = Nil;


type
  TSDL_HasSurfaceRLE_func = function(surface: PSDL_Surface): TSDL_Bool; cdecl;
var
{**
 *  \brief Returns whether the surface is RLE enabled
 *
 *  \return SDL_TRUE if the surface is RLE enabled, or SDL_FALSE if the surface is NULL or not RLE enabled
 *}
  SDL_HasSurfaceRLE : TSDL_HasSurfaceRLE_func = Nil;


type
  TSDL_SetColorKey_func = function(surface: PSDL_Surface; flag: cint; key: cuint32): cint; cdecl;
var
  {**
   *  Sets the color key (transparent pixel) in a blittable surface.
   *
   *  surface The surface to update
   *  flag Non-zero to enable colorkey and 0 to disable colorkey
   *  key The transparent pixel in the native surface format
   *
   *  0 on success, or -1 if the surface is not valid
   *
   *  You can pass SDL_RLEACCEL to enable RLE accelerated blits.
   *}
  SDL_SetColorKey : TSDL_SetColorKey_func = Nil;


type
  TSDL_HasColorKey_func = function(surface: PSDL_Surface): TSDL_Bool; cdecl;
var
{**
 *  \brief Returns whether the surface has a color key
 *
 *  \return SDL_TRUE if the surface has a color key, or SDL_FALSE if the surface is NULL or has no color key
 *}
  SDL_HasColorKey : TSDL_HasColorKey_func = Nil;


type
  TSDL_GetColorKey_func = function(surface: PSDL_Surface; key: pcuint32): cint; cdecl;
var
  {**
   *  Gets the color key (transparent pixel) in a blittable surface.
   *
   *  surface The surface to update
   *  key A pointer filled in with the transparent pixel in the native
   *      surface format
   *
   *  0 on success, or -1 if the surface is not valid or colorkey is not
   *  enabled.
   *}
  SDL_GetColorKey : TSDL_GetColorKey_func = Nil;

type
  TSDL_SetSurfaceColorMod_func = function(surface: PSDL_Surface; r: cuint8; g: cuint8; b: cuint8): cint; cdecl;
var
  {**
   *  Set an additional color value used in blit operations.
   *
   *  surface The surface to update.
   *  r The red color value multiplied into blit operations.
   *  g The green color value multiplied into blit operations.
   *  b The blue color value multiplied into blit operations.
   *
   *  0 on success, or -1 if the surface is not valid.
   *
   *  SDL_GetSurfaceColorMod()
   *}
  SDL_SetSurfaceColorMod : TSDL_SetSurfaceColorMod_func = Nil;

type
  TSDL_GetSurfaceColorMod_func = function(surface: PSDL_Surface; r: pcuint8; g: pcuint8; b: pcuint8): cint; cdecl;
var
 {**
   *  Get the additional color value used in blit operations.
   *
   *  surface The surface to query.
   *  r A pointer filled in with the current red color value.
   *  g A pointer filled in with the current green color value.
   *  b A pointer filled in with the current blue color value.
   *
   *  0 on success, or -1 if the surface is not valid.
   *
   *  SDL_SetSurfaceColorMod()
   *}
  SDL_GetSurfaceColorMod : TSDL_GetSurfaceColorMod_func = Nil;


type
  TSDL_SetSurfaceAlphaMod_func = function(surface: PSDL_Surface; alpha: cuint8): cint; cdecl;
var
  {**
   *  Set an additional alpha value used in blit operations.
   *
   *  surface The surface to update.
   *  alpha The alpha value multiplied into blit operations.
   *
   *  0 on success, or -1 if the surface is not valid.
   *
   *  SDL_GetSurfaceAlphaMod()
   *}
  SDL_SetSurfaceAlphaMod : TSDL_SetSurfaceAlphaMod_func = Nil;


type
  TSDL_GetSurfaceAlphaMod_func = function(surface: PSDL_Surface; alpha: pcuint8): cint; cdecl;
var
  {**
   *  Get the additional alpha value used in blit operations.
   *
   *  surface The surface to query.
   *  alpha A pointer filled in with the current alpha value.
   *
   *  0 on success, or -1 if the surface is not valid.
   *
   *  SDL_SetSurfaceAlphaMod()
   *}
  SDL_GetSurfaceAlphaMod : TSDL_GetSurfaceAlphaMod_func = Nil;


type
  TSDL_SetSurfaceBlendMode_func = function(surface: PSDL_Surface; blendMode: TSDL_BlendMode): cint; cdecl;
var
  {**
   *  Set the blend mode used for blit operations.
   *
   *  surface The surface to update.
   *  blendMode ::SDL_BlendMode to use for blit blending.
   *
   *  0 on success, or -1 if the parameters are not valid.
   *
   *  SDL_GetSurfaceBlendMode()
   *}
  SDL_SetSurfaceBlendMode : TSDL_SetSurfaceBlendMode_func = Nil;


type
  TSDL_GetSurfaceBlendMode_func = function(surface: PSDL_Surface; blendMode: PSDL_BlendMode): cint; cdecl;
var
  {**
   *  Get the blend mode used for blit operations.
   *
   *  surface   The surface to query.
   *  blendMode A pointer filled in with the current blend mode.
   *
   *  0 on success, or -1 if the surface is not valid.
   *
   *  SDL_SetSurfaceBlendMode()
   *}
  SDL_GetSurfaceBlendMode : TSDL_GetSurfaceBlendMode_func = Nil;


type
  TSDL_SetClipRect_func = function(surface: PSDL_Surface; const rect: PSDL_Rect): TSDL_Bool; cdecl;
var
  {**
   *  Sets the clipping rectangle for the destination surface in a blit.
   *
   *  If the clip rectangle is NULL, clipping will be disabled.
   *
   *  If the clip rectangle doesn't intersect the surface, the function will
   *  return SDL_FALSE and blits will be completely clipped.  Otherwise the
   *  function returns SDL_TRUE and blits to the surface will be clipped to
   *  the intersection of the surface area and the clipping rectangle.
   *
   *  Note that blits are automatically clipped to the edges of the source
   *  and destination surfaces.
   *}
  SDL_SetClipRect : TSDL_SetClipRect_func = Nil;


type
  TSDL_DuplicateSurface_func = function(surface: PSDL_Surface): PSDL_Surface; cdecl;

type
  TSDL_GetClipRect_proc = procedure(surface: PSDL_Surface; rect: PSDL_Rect); cdecl;
var
  {**
   *  Gets the clipping rectangle for the destination surface in a blit.
   *
   *  rect must be a pointer to a valid rectangle which will be filled
   *  with the correct values.
   *}
  SDL_GetClipRect : TSDL_GetClipRect_proc = Nil;

var
{*
 * Creates a new surface identical to the existing surface
 *}
  SDL_DuplicateSurface : TSDL_DuplicateSurface_func = Nil;


type
  TSDL_ConvertSurface_func = function(src: PSDL_Surface; const fmt: PSDL_PixelFormat; flags: cuint32): PSDL_Surface; cdecl;
var
  {**
   *  Creates a new surface of the specified format, and then copies and maps
   *  the given surface to it so the blit of the converted surface will be as
   *  fast as possible.  If this function fails, it returns NULL.
   *
   *  The flags parameter is passed to SDL_CreateRGBSurface() and has those
   *  semantics.  You can also pass SDL_RLEACCEL in the flags parameter and
   *  SDL will try to RLE accelerate colorkey and alpha blits in the resulting
   *  surface.
   *}
  SDL_ConvertSurface : TSDL_ConvertSurface_func = Nil;

type
  TSDL_ConvertSurfaceFormat_func = function(src: PSDL_Surface; pixel_format: cuint32; flags: cuint32): PSDL_Surface; cdecl;
var
  SDL_ConvertSurfaceFormat : TSDL_ConvertSurfaceFormat_func = Nil;



type
  TSDL_ConvertPixels_func = function(width: cint; height: cint; src_format: cuint32; const src: Pointer; src_pitch: cint; dst_format: cuint32; dst: Pointer; dst_pitch: cint): cint; cdecl;
var
  {**
   *  Copy a block of pixels of one format to another format
   *
   *  0 on success, or -1 if there was an error
   *}
  SDL_ConvertPixels : TSDL_ConvertPixels_func = Nil;



type
  TSDL_FillRect_func = function(dst: PSDL_Surface; const rect: PSDL_Rect; color: cuint32): cint; cdecl;
var
  {**
   *  Performs a fast fill of the given rectangle with color.
   *
   *  If rect is NULL, the whole surface will be filled with color.
   *
   *  The color should be a pixel of the format used by the surface, and 
   *  can be generated by the SDL_MapRGB() function.
   *  
   *  0 on success, or -1 on error.
   *}
  SDL_FillRect : TSDL_FillRect_func = Nil;

type
  TSDL_FillRects_func = function(dst: PSDL_Surface; const rects: PSDL_Rect; count: cint; color: cuint32): cint; cdecl;
var
  SDL_FillRects : TSDL_FillRects_func = Nil;

(* SDL_surface.h uses #define to change all SDL_BlitSurface() calls into SDL_UpperBlit() calls.                         *
 * Since Pascal macro support is very limited, we workaround by outright pointing SDL_BlitSurface() to SDL_UpperBlit(). *)
type
  TSDL_BlitSurface_func = function(src: PSDL_Surface; const srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect): cint; cdecl;
var
  {**
   *  Performs a fast blit from the source surface to the destination surface.
   *
   *  This assumes that the source and destination rectangles are
   *  the same size.  If either \c srcrect or \c dstrect are NULL, the entire
   *  surface ( src or  dst) is copied.  The final blit rectangles are saved
   *  in srcrect and dstrect after all clipping is performed.
   *
   *  If the blit is successful, it returns 0, otherwise it returns -1.
   *
   *  The blit function should not be called on a locked surface.
   *
   *  The blit semantics for surfaces with and without alpha and colorkey
   *  are defined as follows:
   *
      RGBA->RGB:
        SDL_SRCALPHA set:
          alpha-blend (using alpha-channel).
          SDL_SRCCOLORKEY ignored.
        SDL_SRCALPHA not set:
          copy RGB.
          if SDL_SRCCOLORKEY set, only copy the pixels matching the
          RGB values of the source colour key, ignoring alpha in the
          comparison.

      RGB->RGBA:
        SDL_SRCALPHA set:
          alpha-blend (using the source per-surface alpha value);
          set destination alpha to opaque.
        SDL_SRCALPHA not set:
          copy RGB, set destination alpha to source per-surface alpha value.
        both:
          if SDL_SRCCOLORKEY set, only copy the pixels matching the
          source colour key.

      RGBA->RGBA:
        SDL_SRCALPHA set:
          alpha-blend (using the source alpha channel) the RGB values;
          leave destination alpha untouched. [Note: is this correct?]
          SDL_SRCCOLORKEY ignored.
        SDL_SRCALPHA not set:
          copy all of RGBA to the destination.
          if SDL_SRCCOLORKEY set, only copy the pixels matching the
          RGB values of the source colour key, ignoring alpha in the
         comparison.

      RGB->RGB:
        SDL_SRCALPHA set:
          alpha-blend (using the source per-surface alpha value).
        SDL_SRCALPHA not set:
          copy RGB.
        both:
          if SDL_SRCCOLORKEY set, only copy the pixels matching the
          source colour key.r
   *
   *  You should call SDL_BlitSurface() unless you know exactly how SDL
   *  blitting works internally and how to use the other blit functions.
   *}
  SDL_BlitSurface : TSDL_BlitSurface_func = Nil;




type
  TSDL_UpperBlit_func = function(src: PSDL_Surface; const srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect): cint; cdecl;
var
  {**
   *  This is the public blit function, SDL_BlitSurface(), and it performs
   *  rectangle validation and clipping before passing it to SDL_LowerBlit()
   *}
  SDL_UpperBlit : TSDL_UpperBlit_func = Nil;



type
  TSDL_LowerBlit_func = function(src: PSDL_Surface; srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect): cint; cdecl;
var
  {**
   *  This is a semi-private blit function and it performs low-level surface
   *  blitting only.
   *}
  SDL_LowerBlit : TSDL_LowerBlit_func = Nil;



type
  TSDL_SoftStretch_func = function(src: PSDL_Surface; const srcrect: PSDL_Rect; dst: PSDL_Surface; const dstrect: PSDL_Surface): cint; cdecl;
var
  {**
   *  Perform a fast, low quality, stretch blit between two surfaces of the
   *  same pixel format.
   *
   *  This function uses a static buffer, and is not thread-safe.
   *}
  SDL_SoftStretch : TSDL_SoftStretch_func = Nil;


type
  TSDL_BlitSurfaceScaled_func = function(src: PSDL_Surface; const srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect): cint; cdecl;
var
(* SDL_surface.h uses #define to change all SDL_BlitSurfaceScaled() calls into SDL_UpperBlitScaled() calls.                         *
 * Since Pascal macro support is very limited, we workaround by outright pointing SDL_BlitSurfaceScaled() to SDL_UpperBlitScaled(). *)
  SDL_BlitSurfaceScaled : TSDL_BlitSurfaceScaled_func = Nil;



type
  TSDL_UpperBlitScaled_func = function(src: PSDL_Surface; const srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect): cint; cdecl;
var
  {**
   *  This is the public scaled blit function, SDL_BlitScaled(), and it performs
   *  rectangle validation and clipping before passing it to SDL_LowerBlitScaled()
   *}
  SDL_UpperBlitScaled : TSDL_UpperBlitScaled_func = Nil;


type
  TSDL_LowerBlitScaled_func = function(src: PSDL_Surface; srcrect: PSDL_Rect; dst: PSDL_Surface; dstrect: PSDL_Rect): cint; cdecl;
var
  {**
   *  This is a semi-private blit function and it performs low-level surface
   *  scaled blitting only.
   *}
  SDL_LowerBlitScaled : TSDL_LowerBlitScaled_func = Nil;


type
  TSDL_SetYUVConversionMode_proc = procedure(mode: TSDL_YUV_CONVERSION_MODE); cdecl;
var
{**
 *  \brief Set the YUV conversion mode
 *}
  SDL_SetYUVConversionMode : TSDL_SetYUVConversionMode_proc = Nil;


{**
 *  \brief Get the YUV conversion mode
 *}
function SDL_GetYUVConversionMode: TSDL_YUV_CONVERSION_MODE; cdecl;
  external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_GetYUVConversionMode' {$ENDIF} {$ENDIF};

type
  TSDL_GetYUVConversionModeForResolution_func = function(width: cint; height: cint): TSDL_YUV_CONVERSION_MODE; cdecl;
var
{**
 *  \brief Get the YUV conversion mode, returning the correct mode for the resolution when the current conversion mode is SDL_YUV_CONVERSION_AUTOMATIC
 *}
  SDL_GetYUVConversionModeForResolution : TSDL_GetYUVConversionModeForResolution_func = Nil;

