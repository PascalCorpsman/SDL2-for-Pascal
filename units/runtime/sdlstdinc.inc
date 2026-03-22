//types from SDL_stdinc.h

{ SDL-For-Pascal: A lot of the functions are missing. Some functions are useless
                  if working with Pascal (e. g. memory management functions),
                  others could be useful (e. g. math functions).

  TODO: Investigate header file and translate potentially useful functions. }

type
  PPSDL_Bool = ^PSDL_Bool;
  PSDL_Bool = ^TSDL_Bool;
  TSDL_Bool = cbool;

const
  SDL_FALSE = TSDL_Bool(0);
  SDL_TRUE  = TSDL_Bool(1);

  SDL_MAX_SINT8 = High(cint8);
  SDL_MIN_SINT8 = Low(cint8);

  SDL_MAX_UINT8 = High(cuint8);
  SDL_MIN_UINT8 = Low(cuint8);

  SDL_MAX_SINT16 = High(cint16);
  SDL_MIN_SINT16 = Low(cint16);

  SDL_MAX_UINT16 = High(cuint16);
  SDL_MIN_UINT16 = Low(cuint16);

  SDL_MAX_SINT32 = High(cint32);
  SDL_MIN_SINT32 = Low(cint32);

  SDL_MAX_UINT32 = High(cuint32);
  SDL_MIN_UINT32 = Low(cuint32);

  {$IFDEF Has_Int64}
    SDL_MAX_SINT64 = High(cint64);
    SDL_MIN_SINT64 = Low(cint64);

    SDL_MAX_UINT64 = High(cuint64);
    SDL_MIN_UINT64 = Low(cuint64);
  {$ELSE}
    SDL_MAX_SINT64: cuint64 = (hi: SDL_MAX_SINT32; lo: SDL_MAX_UINT32);
    SDL_MIN_SINT64: cuint64 = (hi: SDL_MIN_SINT32; lo: 0);

    SDL_MAX_UINT64: cuint64 = (hi: SDL_MAX_UINT32; lo: SDL_MAX_UINT32);
    SDL_MIN_UINT64: cuint64 = (hi: 0;              lo: 0);
  {$ENDIF}

  SDL_FLT_EPSILON = cfloat(1.1920928955078125e-07);

type
  PPSDL_malloc_func = ^PSDL_malloc_func;
  PSDL_malloc_func = ^TSDL_malloc_func;
  TSDL_malloc_func = function(size: csize_t): Pointer; cdecl;

  PPSDL_calloc_func = ^PSDL_calloc_func;
  PSDL_calloc_func = ^TSDL_calloc_func;
  TSDL_calloc_func = function(nmemb, size: csize_t): Pointer; cdecl;

  PPSDL_realloc_func = ^PSDL_realloc_func;
  PSDL_realloc_func = ^TSDL_realloc_func;
  TSDL_realloc_func = function(mem: Pointer; size: csize_t): Pointer; cdecl;

  PPSDL_free_func = ^PSDL_free_func;
  PSDL_free_func = ^TSDL_free_func;
  TSDL_free_func = procedure(mem: Pointer); cdecl;

{**
 * Get the original set of SDL memory functions
 *
 * \since This function is available since SDL 2.24.0.
 *}
procedure SDL_GetOriginalMemoryFunctions(
  malloc_func: PSDL_malloc_func;
  calloc_func: PSDL_calloc_func;
  realloc_func: PSDL_realloc_func;
  free_func: PSDL_free_func
); cdecl;
  external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_GetOriginalMemoryFunctions' {$ENDIF} {$ENDIF};

(**
 * Get the current set of SDL memory functions
 *
 * \since This function is available since SDL 2.0.7.
 *)
procedure SDL_GetMemoryFunctions(
  malloc_func: PSDL_malloc_func;
  calloc_func: PSDL_calloc_func;
  realloc_func: PSDL_realloc_func;
  free_func: PSDL_free_func
); cdecl;
  external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_GetMemoryFunctions' {$ENDIF} {$ENDIF};

(**
 * Replace SDL's memory allocation functions with a custom set
 *
 * \since This function is available since SDL 2.0.7.
 *)
function SDL_SetMemoryFunctions(
  malloc_func: TSDL_malloc_func;
  calloc_func: TSDL_calloc_func;
  realloc_func: TSDL_realloc_func;
  free_func: TSDL_free_func
): cint; cdecl;
  external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_SetMemoryFunctions' {$ENDIF} {$ENDIF};

(**
 * Get the number of outstanding (unfreed) allocations
 *
 * \since This function is available since SDL 2.0.7.
 *)
Type
  TSDL_GetNumAllocations_fun = function(): cint; cdecl;
Var
  SDL_GetNumAllocations : TSDL_GetNumAllocations_fun = Nil;


(**
 * Allocate a block of memory. The memory is *not* initialized.
 *)
Type
  TSDL_malloc_fun = function(size: csize_t): Pointer; cdecl;
Var
  SDL_malloc : TSDL_malloc_fun = Nil;


(**
 * Allocate a block of memory that can fit an array of nmemb elements, each of given size.
 * The memory is initialized by setting every byte to 0.
 *)
Type
  TSDL_calloc_fun = function(nmemb, size: csize_t): Pointer; cdecl;
Var
  SDL_calloc : TSDL_calloc_fun = Nil;


(**
 * Resize a block of memory allocated previously with SDL_malloc() or SDL_calloc().
 *
 * The returned pointer may or may not be the same as the original pointer.
 * If the new size is larger than the old size, any new memory will *not* be initialized.
 *)
Type
  TSDL_realloc_fun = function(mem: Pointer; size: csize_t): Pointer; cdecl;
Var
  SDL_realloc : TSDL_realloc_fun = Nil;


(**
 * Free memory returned by functions like SDL_GetBasePath(), SDL_GetPrefPath(), etc.
 *
 * Calling SDL_free() on the same pointer twice is undefined behaviour and may cause
 * your program to crash or behave in unexpected ways.
 *)
Type
  TSDL_free_proc = procedure(mem: Pointer); cdecl;
Var
  SDL_free : TSDL_free_proc = Nil;




{*** --- Character functions --- ***

SDL2-for-Pascal: All comments are added by us and not found in the include file.}


(**
 * Check if the provided ASCII character is an alphabetic character (a letter).
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_isalpha_fun = function(x: cint):cint; cdecl;
Var
  SDL_isalpha : TSDL_isalpha_fun = Nil;


(**
 * Check if the provided ASCII character is an alphanumeric character.
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_isalnum_fun = function(x: cint):cint; cdecl;
Var
  SDL_isalnum : TSDL_isalnum_fun = Nil;


(**
 * Check if the provided ASCII character is a blank character (a space or a tab).
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_isblank_fun = function(x: cint):cint; cdecl;
Var
  SDL_isblank : TSDL_isblank_fun = Nil;


(**
 * Check if the provided ASCII character is a control character.
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_iscntrl_fun = function(x: cint):cint; cdecl;
Var
  SDL_iscntrl : TSDL_iscntrl_fun = Nil;


(**
 * Check if the provided ASCII character is a decimal digit.
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_isdigit_fun = function(x: cint):cint; cdecl;
Var
  SDL_isdigit : TSDL_isdigit_fun = Nil;


(**
 * Check if the provided ASCII character is a hexadecimal digit.
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_isxdigit_fun = function(x: cint):cint; cdecl;
Var
  SDL_isxdigit : TSDL_isxdigit_fun = Nil;


(**
 * Check if the provided ASCII character is any printable character
 * which is not a space or an alphanumeric character.
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_ispunct_fun = function(x: cint):cint; cdecl;
Var
  SDL_ispunct : TSDL_ispunct_fun = Nil;


(**
 * Check if the provided ASCII character is a whitespace character.
 * This set includes the following characters: space,
 * form feed (FF), newline/line feed (LF), carriage return (CR),
 * horizontal tab (HT), vertical tab (VT).
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_isspace_fun = function(x: cint):cint; cdecl;
Var
  SDL_isspace : TSDL_isspace_fun = Nil;


(**
 * Check if the provided ASCII character is an uppercase letter.
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.12.
 *)
Type
  TSDL_isupper_fun = function(x: cint):cint; cdecl;
Var
  SDL_isupper : TSDL_isupper_fun = Nil;


(**
 * Check if the provided ASCII character is a lowercase letter.
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.12.
 *)
Type
  TSDL_islower_fun = function(x: cint):cint; cdecl;
Var
  SDL_islower : TSDL_islower_fun = Nil;


(**
 * Check if the provided ASCII character is a printable character (including space).
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_isprint_fun = function(x: cint):cint; cdecl;
Var
  SDL_isprint : TSDL_isprint_fun = Nil;


(**
 * Check if the provided ASCII character is a printable character (excluding space).
 *
 * \returns 1 if the check passes, 0 otherwise.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_isgraph_fun = function(x: cint):cint; cdecl;
Var
  SDL_isgraph : TSDL_isgraph_fun = Nil;


(**
 * If the given ASCII character is a lowercase letter, converts it to uppercase.
 * Otherwise returns the original value.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_toupper_fun = function(x: cint):cint; cdecl;
Var
  SDL_toupper : TSDL_toupper_fun = Nil;


(**
 * If the given ASCII character is an uppercase letter, converts it to lowercase.
 * Otherwise returns the original value.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_tolower_fun = function(x: cint):cint; cdecl;
Var
  SDL_tolower : TSDL_tolower_fun = Nil;




(*** --- Math functions --- ***)


(**
 * Calculate the arc cosine of x;
 * that is, the value (in radians) whose cosine equals x.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_acos_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_acos : TSDL_acos_fun = Nil;


(**
 * Calculate the arc cosine of x;
 * that is, the value (in radians) whose cosine equals x.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_acosf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_acosf : TSDL_acosf_fun = Nil;


(**
 * Calculate the arc sine of x;
 * that is, the value (in radians) whose sine equals x.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_asin_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_asin : TSDL_asin_fun = Nil;


(**
 * Calculate the arc sine of x;
 * that is, the value (in radians) whose sine equals x.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_asinf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_asinf : TSDL_asinf_fun = Nil;


(**
 * Calculate the arc tangent of x;
 * that is, the value (in radians) whose tangent equals x.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_atan_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_atan : TSDL_atan_fun = Nil;


(**
 * Calculate the arc tangent of x;
 * that is, the value (in radians) whose tangent equals x.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_atanf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_atanf : TSDL_atanf_fun = Nil;


(**
 * Calculate the arc tangent of y/x, using the signs of the two arguments
 * to determine the quadrant of the result.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_atan2_fun = function(y, x: cdouble): cdouble; cdecl;
Var
  SDL_atan2 : TSDL_atan2_fun = Nil;


(**
 * Calculate the arc tangent of y/x, using the signs of the two arguments
 * to determine the quadrant of the result.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_atan2f_fun = function(y, x: cfloat): cfloat; cdecl;
Var
  SDL_atan2f : TSDL_atan2f_fun = Nil;


(**
 * Calculate the smallest integral value that is not less than x.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_ceil_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_ceil : TSDL_ceil_fun = Nil;


(**
 * Calculate the smallest integral value that is not less than x.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_ceilf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_ceilf : TSDL_ceilf_fun = Nil;


(**
 * Return a number whose absolute value matches that of x,
 * but the sign matches that of y.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_copysign_fun = function(x, y: cdouble): cdouble; cdecl;
Var
  SDL_copysign : TSDL_copysign_fun = Nil;


(**
 * Return a number whose absolute value matches that of x,
 * but the sign matches that of y.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_copysignf_fun = function(x, y: cfloat): cfloat; cdecl;
Var
  SDL_copysignf : TSDL_copysignf_fun = Nil;


(**
 * Calculate the cosine of x, where x is given in radians.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_cos_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_cos : TSDL_cos_fun = Nil;


(**
 * Calculate the cosine of x, where x is given in radians.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_cosf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_cosf : TSDL_cosf_fun = Nil;


(**
 * Calculate the value of e (the base of natural logarithms)
 * raised to the power of x.
 *
 * \since This function is available since SDL 2.0.9.
 *)
Type
  TSDL_exp_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_exp : TSDL_exp_fun = Nil;


(**
 * Calculate the value of e (the base of natural logarithms)
 * raised to the power of x.
 *
 * \since This function is available since SDL 2.0.9.
 *)
Type
  TSDL_expf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_expf : TSDL_expf_fun = Nil;


(**
 * Calculate the absolute value of x.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_fabs_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_fabs : TSDL_fabs_fun = Nil;


(**
 * Calculate the absolute value of x.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_fabsf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_fabsf : TSDL_fabsf_fun = Nil;


(**
 * Calculate the largest integral value that is not greater than x.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_floor_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_floor : TSDL_floor_fun = Nil;


(**
 * Calculate the largest integral value that is not greater than x.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_floorf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_floorf : TSDL_floorf_fun = Nil;


(**
 * Calculate the floating-point remainder of dividing x by y.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_fmod_fun = function(x, y: cdouble): cdouble; cdecl;
Var
  SDL_fmod : TSDL_fmod_fun = Nil;


(**
 * Calculate the floating-point remainder of dividing x by y.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_fmodf_fun = function(x, y: cfloat): cfloat; cdecl;
Var
  SDL_fmodf : TSDL_fmodf_fun = Nil;


(**
 * Calculate the natural logarithm of x.
 *
 * \since This function is available since SDL 2.0.4.
 
 SDL2-for-Pascal: ATTENTION: The original C name of this function is SDL_log, 
 but since Pascal names are case-insensitive, it is in conflict with SDL_Log (logging function). 
 Hence we decided to rename it.
 *)
Type
  TSDL_nlog_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_nlog : TSDL_nlog_fun = Nil;


(**
 * Calculate the natural logarithm of x.
 *
 * \since This function is available since SDL 2.0.8.
 
 SDL2-for-Pascal: ATTENTION: The original C name of this function is SDL_logf, 
 but to be consistent with the renamed SDL_log function (see comment of SDL_nlog
 for details), we decided to rename it.
 *)
Type
  TSDL_nlogf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_nlogf : TSDL_nlogf_fun = Nil;


(**
 * Calculate the base 10 logarithm of x.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_log10_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_log10 : TSDL_log10_fun = Nil;


(**
 * Calculate the base 10 logarithm of x.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_log10f_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_log10f : TSDL_log10f_fun = Nil;


(**
 * Round to nearest integer, away from zero.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_lround_fun = function(x: cdouble): clong; cdecl;
Var
  SDL_lround : TSDL_lround_fun = Nil;


(**
 * Round to nearest integer, away from zero.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_lroundf_fun = function(x: cfloat): clong; cdecl;
Var
  SDL_lroundf : TSDL_lroundf_fun = Nil;


(**
 * Calculate the value of x raised to the power of y.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_pow_fun = function(x, y: cdouble): cdouble; cdecl;
Var
  SDL_pow : TSDL_pow_fun = Nil;


(**
 * Calculate the value of x raised to the power of y.
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_powf_fun = function(x, y: cfloat): cfloat; cdecl;
Var
  SDL_powf : TSDL_powf_fun = Nil;


(**
 * Round to nearest integral value, away from zero.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_round_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_round : TSDL_round_fun = Nil;


(**
 * Round to nearest integral value, away from zero.
 *
 * \since This function is available since SDL 2.0.16.
 *)
Type
  TSDL_roundf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_roundf : TSDL_roundf_fun = Nil;


(**
 * Calculate x multiplied by the floating-point radix to the power of n.
 * On most systems, the radix is 2, making this equivalent to x*(2**n).
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_scalbn_fun = function(x: cdouble; n: cint): cdouble; cdecl;
Var
  SDL_scalbn : TSDL_scalbn_fun = Nil;


(**
 * Calculate x multiplied by the floating-point radix to the power of n.
 * On most systems, the radix is 2, making this equivalent to x*(2**n).
 *
 * \since This function is available since SDL 2.0.8.
 *)
Type
  TSDL_scalbnf_fun = function(x: cfloat; n: cint): cfloat; cdecl;
Var
  SDL_scalbnf : TSDL_scalbnf_fun = Nil;


(**
 * Calculate the sine of x, where x is given in radians.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_sin_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_sin : TSDL_sin_fun = Nil;


(**
 * Calculate the sine of x, where x is given in radians.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_sinf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_sinf : TSDL_sinf_fun = Nil;


(**
 * Calculate the non-negative square root of x.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_sqrt_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_sqrt : TSDL_sqrt_fun = Nil;


(**
 * Calculate the non-negative square root of x.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_sqrtf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_sqrtf : TSDL_sqrtf_fun = Nil;


(**
 * Calculate the tangent of x, where x is given in radians.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_tan_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_tan : TSDL_tan_fun = Nil;


(**
 * Calculate the tangent of x, where x is given in radians.
 *
 * \since This function is available since SDL 2.0.4.
 *)
Type
  TSDL_tanf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_tanf : TSDL_tanf_fun = Nil;


(**
 * Round to nearest integral value, towards zero.
 *
 * \since This function is available since SDL 2.0.14.
 *)
Type
  TSDL_trunc_fun = function(x: cdouble): cdouble; cdecl;
Var
  SDL_trunc : TSDL_trunc_fun = Nil;


(**
 * Round to nearest integral value, towards zero.
 *
 * \since This function is available since SDL 2.0.14.
 *)
Type
  TSDL_truncf_fun = function(x: cfloat): cfloat; cdecl;
Var
  SDL_truncf : TSDL_truncf_fun = Nil;




(*** --- iconv functions --- ***)


(**
 * This function converts a string between encodings in one pass, returning a
 * string that must be freed with SDL_free(), or NIL on error.
 *
 * \since This function is available since SDL 2.0.0.
 *)
Type
  TSDL_iconv_string_fun = function(Const tocode, fromcode, inbuf: PAnsiChar; inbytesleft: csize_t): PAnsiChar; cdecl;
Var
  SDL_iconv_string : TSDL_iconv_string_fun = Nil;


// These are macros in the original C headers, we will reimplement them as simple Pascal functions.
function SDL_iconv_utf8_locale(Const str: PAnsiChar): PAnsiChar; cdecl;
function SDL_iconv_utf8_ucs2(Const str: PAnsiChar): pcUint16; cdecl;
function SDL_iconv_utf8_ucs4(Const str: PAnsiChar): pcUint32; cdecl;

(* The SDL implementation of iconv() returns these error codes *)
const
  SDL_ICONV_ERROR  = csize_t(-1);
  SDL_ICONV_E2BIG  = csize_t(-2);
  SDL_ICONV_EILSEQ = csize_t(-3);
  SDL_ICONV_EINVAL = csize_t(-4);

type
  PSDL_iconv = type Pointer;

Type
  TSDL_iconv_open_fun = function(Const tocode, fromcode: PAnsiChar): PSDL_iconv; cdecl;
Var
  SDL_iconv_open : TSDL_iconv_open_fun = Nil;


Type
  TSDL_iconv_close_fun = function(cd: PSDL_iconv): cint; cdecl;
Var
  SDL_iconv_close : TSDL_iconv_close_fun = Nil;


Type
  TSDL_iconv_fun = function(cd: PSDL_iconv; Const inbuf: PPAnsiChar; inbytesleft: pcsize_t; outbuf: PPAnsiChar; outbytesleft: pcsize_t): csize_t; cdecl;
Var
  SDL_iconv : TSDL_iconv_fun = Nil;

