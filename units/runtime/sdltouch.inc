//from "sdl_touch.h"

type
  PPSDL_TouchID = ^PSDL_TouchID;
  PSDL_TouchID  = ^TSDL_TouchID;
  TSDL_TouchID  = type cint64;

  PPSDL_FingerID = ^PSDL_FingerID;
  PSDL_FingerID = ^TSDL_FingerID;
  TSDL_FingerID = type cint64;

  PPSDL_TouchDeviceType = ^PSDL_TouchDeviceType;
  PSDL_TouchDeviceType = ^TSDL_TouchDeviceType;
  TSDL_TouchDeviceType = type cint;

const
  SDL_TOUCH_DEVICE_INVALID           = TSDL_TouchDeviceType(-1);
  SDL_TOUCH_DEVICE_DIRECT            = TSDL_TouchDeviceType(0);  {* touch screen with window-relative coordinates *}
  SDL_TOUCH_DEVICE_INDIRECT_ABSOLUTE = TSDL_TouchDeviceType(1);  {* trackpad with absolute device coordinates *}
  SDL_TOUCH_DEVICE_INDIRECT_RELATIVE = TSDL_TouchDeviceType(2);  {* trackpad with relative device coordinates *}

type
  PPSDL_Finger = ^PSDL_Finger;
  PSDL_Finger = ^TSDL_Finger;
  TSDL_Finger = record
    id: TSDL_FingerID;
    x: cfloat;
    y: cfloat;
    pressure: cfloat;
  end;

const
  {* Used as the device ID for mouse events simulated with touch input *}
  SDL_TOUCH_MOUSEID = cuint32(-1);
  {* Used as the SDL_TouchID for touch events simulated with mouse input *}
  SDL_MOUSE_TOUCHID = TSDL_TouchID(-1);

  {* Function prototypes *}

type
  TSDL_GetNumTouchDevices_func = function(): cint; cdecl;
var
  {**
   *  Get the number of registered touch devices.
   *}
  SDL_GetNumTouchDevices : TSDL_GetNumTouchDevices_func = Nil;


type
  TSDL_GetTouchDevice_func = function(index: cint): TSDL_TouchID; cdecl;
var
  {**
   *  Get the touch ID with the given index, or 0 if the index is invalid.
   *}
  SDL_GetTouchDevice : TSDL_GetTouchDevice_func = Nil;


type
  TSDL_GetTouchName_func = function(index: cint): PAnsiChar; cdecl;
var
{**
 * Get the touch device name as reported from the driver,
 * or NIL if the index is invalid.
 *
 * \since This function is available since SDL 2.0.22.
 *}
  SDL_GetTouchName : TSDL_GetTouchName_func = Nil;


type
  TSDL_GetTouchDeviceType_func = function(touchID: TSDL_TouchID): TSDL_TouchDeviceType; cdecl;
var
{**
 * Get the type of the given touch device.
 *
 * \since This function is available since SDL 2.0.10.
 *}
  SDL_GetTouchDeviceType : TSDL_GetTouchDeviceType_func = Nil;


type
  TSDL_GetNumTouchFingers_func = function(touchID: TSDL_TouchID): cint; cdecl;
var
  {**
   *  Get the number of active fingers for a given touch device.
   *}
  SDL_GetNumTouchFingers : TSDL_GetNumTouchFingers_func = Nil;


type
  TSDL_GetTouchFinger_func = function(touchID: TSDL_TouchID; index: cint): PSDL_Finger; cdecl;
var
  {**
   *  Get the finger object of the given touch, with the given index.
   *}
  SDL_GetTouchFinger : TSDL_GetTouchFinger_func = Nil;


