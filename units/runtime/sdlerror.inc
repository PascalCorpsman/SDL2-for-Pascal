// based on "sdl_error.h" (2.0.14)

{**
 *  \file SDL_error.h
 *
 *  Simple error message routines for SDL.
 *}

{* Public functions *}

type
  TSDL_SetError_func = function(const fmt: PAnsiChar; args: array of const): cint; cdecl;
var
{**
 *  \brief Set the error message for the current thread
 *
 *  \return -1, there is no error handling for this function
 *}
  SDL_SetError : TSDL_SetError_func = Nil;


{**
 *  \brief Get the last error message that was set
 *
 * SDL API functions may set error messages and then succeed, so you should
 * only use the error value if a function fails.
 *
 * This returns a pointer to a static buffer for convenience and should not
 * be called by multiple threads simultaneously.
 *
 *  \return a pointer to the last error message that was set
 *}
function SDL_GetError: PAnsiChar; cdecl;
  external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_GetError' {$ENDIF} {$ENDIF};

type
  TSDL_GetErrorMsg_func = function(const errstr: PAnsiChar; maxlen: cint): PAnsiChar; cdecl;
var
{**
 *  \brief Get the last error message that was set for the current thread
 *
 * SDL API functions may set error messages and then succeed, so you should
 * only use the error value if a function fails.
 *
 *  \param errstr A buffer to fill with the last error message that was set
 *                for the current thread
 *  \param maxlen The size of the buffer pointed to by the errstr parameter
 *
 *  \return errstr
 *}
  SDL_GetErrorMsg : TSDL_GetErrorMsg_func = Nil;


{**
 *  \brief Clear the error message for the current thread
 *}
procedure SDL_ClearError cdecl; external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_ClearError' {$ENDIF} {$ENDIF};

{*Internal error functions*}
{**
 *  Internal error functions
 *
 *  Private error reporting function - used internally.
 *}
    {
#define SDL_OutOfMemory()   SDL_Error(SDL_ENOMEM)
#define SDL_Unsupported()   SDL_Error(SDL_UNSUPPORTED)
#define SDL_InvalidParamError(param)    SDL_SetError("Parameter '%s' is invalid", (param))
   }


type
  PPSDL_ErrorCode = ^PSDL_ErrorCode;
  PSDL_ErrorCode = ^TSDL_ErrorCode;
  TSDL_ErrorCode = (SDL_ENOMEM,
                    SDL_EFREAD,
                    SDL_EFWRITE,
                    SDL_EFSEEK,
                    SDL_UNSUPPORTED,
                    SDL_LASTERROR);

type
  TSDL_Error_func = function(code: TSDL_ErrorCode): cint; cdecl;
var
{* SDL_Error() unconditionally returns -1. *}
  SDL_Error : TSDL_Error_func = Nil;

