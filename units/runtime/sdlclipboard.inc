
{*
 * \file SDL_clipboard.h
 *
 * Include file for SDL clipboard handling
  }

{* Function prototypes *}

{*
 * Put UTF-8 text into the clipboard.
 *
 * \param text the text to store in the clipboard
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetClipboardText
 * \sa SDL_HasClipboardText
  }
type
  TSDL_SetClipboardText_func = function(text: PAnsiChar): cint; cdecl;
var
  SDL_SetClipboardText : TSDL_SetClipboardText_func = Nil;


{*
 * Get UTF-8 text from the clipboard, which must be freed with SDL_free().
 *
 * This functions returns empty string if there was not enough memory left for
 * a copy of the clipboard's content.
 *
 * \returns the clipboard text on success or an empty string on failure; call
 *          SDL_GetError() for more information. Caller must call SDL_free()
 *          on the returned pointer when done with it (even if there was an
 *          error).
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_HasClipboardText
 * \sa SDL_SetClipboardText
  }
type
  TSDL_GetClipboardText_func = function(): PAnsiChar; cdecl;
var
  SDL_GetClipboardText : TSDL_GetClipboardText_func = Nil;


{*
 * Query whether the clipboard exists and contains a non-empty text string.
 *
 * \returns SDL_TRUE if the clipboard has text, or SDL_FALSE if it does not.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetClipboardText
 * \sa SDL_SetClipboardText
  }
type
  TSDL_HasClipboardText_func = function(): TSDL_bool; cdecl;
var
  SDL_HasClipboardText : TSDL_HasClipboardText_func = Nil;


{*
 * Put UTF-8 text into the primary selection.
 *
 * \param text the text to store in the primary selection
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.26.1.
 *
 * \sa SDL_GetPrimarySelectionText
 * \sa SDL_HasPrimarySelectionText
  }
type
  TSDL_SetPrimarySelectionText_func = function(text: PAnsiChar): cint; cdecl;
var
  SDL_SetPrimarySelectionText : TSDL_SetPrimarySelectionText_func = Nil;


{*
 * Get UTF-8 text from the primary selection, which must be freed with
 * SDL_free().
 *
 * This functions returns empty string if there was not enough memory left for
 * a copy of the primary selection's content.
 *
 * \returns the primary selection text on success or an empty string on
 *          failure; call SDL_GetError() for more information. Caller must
 *          call SDL_free() on the returned pointer when done with it (even if
 *          there was an error).
 *
 * \since This function is available since SDL 2.26.1.
 *
 * \sa SDL_HasPrimarySelectionText
 * \sa SDL_SetPrimarySelectionText
  }
type
  TSDL_GetPrimarySelectionText_func = function(): PAnsiChar; cdecl;
var
  SDL_GetPrimarySelectionText : TSDL_GetPrimarySelectionText_func = Nil;


{*
 * Query whether the primary selection exists and contains a non-empty text
 * string.
 *
 * \returns SDL_TRUE if the primary selection has text, or SDL_FALSE if it
 *          does not.
 *
 * \since This function is available since SDL 2.26.1.
 *
 * \sa SDL_GetPrimarySelectionText
 * \sa SDL_SetPrimarySelectionText
  }
type
  TSDL_HasPrimarySelectionText_func = function(): TSDL_bool; cdecl;
var
  SDL_HasPrimarySelectionText : TSDL_HasPrimarySelectionText_func = Nil;

