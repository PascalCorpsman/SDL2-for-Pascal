// based on "sdl_platform.h" (2.0.14)

{**
 *  \file SDL_platform.h
 *
 *  Try to get a standard set of platform defines.
 *}

type
  TSDL_GetPlatform_func = function(): PAnsiChar; cdecl;
var
{**
 *  Gets the name of the platform.
 *}
  SDL_GetPlatform: TSDL_GetPlatform_func = Nil;
