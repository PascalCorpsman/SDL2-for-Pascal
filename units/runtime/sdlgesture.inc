//from "sdl_gesture.h"

type
  PPSDL_GestureID = ^PSDL_GestureID;
  PSDL_GestureID = ^TSDL_GestureID;
  TSDL_GestureID = type cint64;

  {* Function prototypes *}

  {/**
 * Begin recording a gesture on a specified touch device or all touch devices.
 *
 * If the parameter `touchId` is -1 (i.e., all devices), this function will
 * always return 1, regardless of whether there actually are any devices.
 *
 * \param touchId the touch device id, or -1 for all touch devices
 * \returns 1 on success or 0 if the specified device could not be found.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetTouchDevice
 *}
type
  TSDL_RecordGesture_func = function(touchId: TSDL_TouchID): cint; cdecl;
var
  SDL_RecordGesture : TSDL_RecordGesture_func = Nil;


type
  TSDL_SaveAllDollarTemplates_func = function(dst: PSDL_RWops): cint; cdecl;
  {**
 * Save all currently loaded Dollar Gesture templates.
 *
 * \param dst a SDL_RWops to save to
 * \returns the number of saved templates on success or 0 on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_LoadDollarTemplates
 * \sa SDL_SaveDollarTemplate
 *}
var
  SDL_SaveAllDollarTemplates : TSDL_SaveAllDollarTemplates_func = Nil;


type
  TSDL_SaveDollarTemplate_func = function(gestureId: TSDL_GestureID; dst: PSDL_RWops): cint; cdecl;
  {**
 * Save a currently loaded Dollar Gesture template.
 *
 * \param gestureId a gesture id
 * \param dst a SDL_RWops to save to
 * \returns 1 on success or 0 on failure; call SDL_GetError() for more
 *          information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_LoadDollarTemplates
 * \sa SDL_SaveAllDollarTemplates
 *}
var
  SDL_SaveDollarTemplate : TSDL_SaveDollarTemplate_func = Nil;



type
  TSDL_LoadDollarTemplates_func = function(touchId: TSDL_TouchID; src: PSDL_RWops): cint; cdecl;
  {**
 * Load Dollar Gesture templates from a file.
 *
 * \param touchId a touch id
 * \param src a SDL_RWops to load from
 * \returns the number of loaded templates on success or a negative error code
 *          (or 0) on failure; call SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_SaveAllDollarTemplates
 * \sa SDL_SaveDollarTemplate
 *}
var
  SDL_LoadDollarTemplates : TSDL_LoadDollarTemplates_func = Nil;

