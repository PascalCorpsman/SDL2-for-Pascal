
//since the array of const in delphi is not C compatible:
{$IFDEF FPC}

{**
 *  \brief The maximum size of a log message
 *
 *  Messages longer than the maximum size will be truncated
 *}
const
  SDL_MAX_LOG_MESSAGE = 4096;

{**
 *  \brief The predefined log categories
 *
 *  By default the application category is enabled at the INFO level,
 *  the assert category is enabled at the WARN level, test is enabled
 *  at the VERBOSE level and all other categories are enabled at the
 *  CRITICAL level.
 *}
type
  PPSDL_LogCategory = ^PSDL_LogCategory;
  PSDL_LogCategory = ^TSDL_LogCategory;
  TSDL_LogCategory = type cint;

const
  SDL_LOG_CATEGORY_APPLICATION           = TSDL_LogCategory(0);
  SDL_LOG_CATEGORY_ERROR                 = TSDL_LogCategory(1);
  SDL_LOG_CATEGORY_ASSERT                = TSDL_LogCategory(2);
  SDL_LOG_CATEGORY_SYSTEM                = TSDL_LogCategory(3);
  SDL_LOG_CATEGORY_AUDIO                 = TSDL_LogCategory(4);
  SDL_LOG_CATEGORY_VIDEO                 = TSDL_LogCategory(5);
  SDL_LOG_CATEGORY_RENDER                = TSDL_LogCategory(6);
  SDL_LOG_CATEGORY_INPUT                 = TSDL_LogCategory(7);
  SDL_LOG_CATEGORY_TEST                  = TSDL_LogCategory(8);

  {* Reserved for future SDL library use *}
  SDL_LOG_CATEGORY_RESERVED1             = TSDL_LogCategory(9);
  SDL_LOG_CATEGORY_RESERVED2             = TSDL_LogCategory(10);
  SDL_LOG_CATEGORY_RESERVED3             = TSDL_LogCategory(11);
  SDL_LOG_CATEGORY_RESERVED4             = TSDL_LogCategory(12);
  SDL_LOG_CATEGORY_RESERVED5             = TSDL_LogCategory(13);
  SDL_LOG_CATEGORY_RESERVED6             = TSDL_LogCategory(14);
  SDL_LOG_CATEGORY_RESERVED7             = TSDL_LogCategory(15);
  SDL_LOG_CATEGORY_RESERVED8             = TSDL_LogCategory(16);
  SDL_LOG_CATEGORY_RESERVED9             = TSDL_LogCategory(17);
  SDL_LOG_CATEGORY_RESERVED10            = TSDL_LogCategory(18);

  {* Beyond this point is reserved for application use *}
  SDL_LOG_CATEGORY_CUSTOM                = TSDL_LogCategory(19);

{**
 *  \brief The predefined log priorities
 *}
type
  PPSDL_LogPriority = ^PSDL_LogPriority;
  PSDL_LogPriority = ^TSDL_LogPriority;
  TSDL_LogPriority = type cint32;
const
  SDL_LOG_PRIORITY_VERBOSE = TSDL_LogPriority(1);
  SDL_LOG_PRIORITY_DEBUG = TSDL_LogPriority(2);
  SDL_LOG_PRIORITY_INFO = TSDL_LogPriority(3);
  SDL_LOG_PRIORITY_WARN = TSDL_LogPriority(4);
  SDL_LOG_PRIORITY_ERROR = TSDL_LogPriority(5);
  SDL_LOG_PRIORITY_CRITICAL = TSDL_LogPriority(6);
  SDL_NUM_LOG_PRIORITIES = TSDL_LogPriority(7);

{**
 *  \brief Set the priority of all log categories
 *}
type
  TSDL_LogSetAllPriority_proc = procedure(priority: TSDL_LogPriority); cdecl;
var
  SDL_LogSetAllPriority : TSDL_LogSetAllPriority_proc = Nil;


{**
 *  \brief Set the priority of a particular log category
 *}
type
  TSDL_LogSetPriority_proc = procedure(category: TSDL_LogCategory; priority: TSDL_LogPriority); cdecl;
var
  SDL_LogSetPriority : TSDL_LogSetPriority_proc = Nil;


{**
 *  \brief Get the priority of a particular log category
 *}
type
  TSDL_LogGetPriority_func = function(category: TSDL_LogCategory): TSDL_LogPriority; cdecl;
var
  SDL_LogGetPriority : TSDL_LogGetPriority_func = Nil;


{**
 *  \brief Reset all priorities to default.
 *
 *  \note This is called in SDL_Quit().
 *}
type
  TSDL_LogResetPriorities_proc = procedure(); cdecl;
var
  SDL_LogResetPriorities : TSDL_LogResetPriorities_proc = Nil;


{**
 *  \brief Log a message with SDL_LOG_CATEGORY_APPLICATION and SDL_LOG_PRIORITY_INFO
 *}
type
  TSDL_Log_proc = procedure(const fmt: PAnsiChar; pars: array of const); cdecl;
var
  SDL_Log : TSDL_Log_proc = Nil;


{**
 *  \brief Log a message with SDL_LOG_PRIORITY_VERBOSE
 *}
type
  TSDL_LogVerbose_proc = procedure(category: TSDL_LogCategory; const fmt: PAnsiChar; pars: array of const); cdecl;
var
  SDL_LogVerbose : TSDL_LogVerbose_proc = Nil;


{**
 *  \brief Log a message with SDL_LOG_PRIORITY_DEBUG
 *}
type
  TSDL_LogDebug_proc = procedure(category: TSDL_LogCategory; const fmt: PAnsiChar; pars: array of const); cdecl;
var
  SDL_LogDebug : TSDL_LogDebug_proc = Nil;


{**
 *  \brief Log a message with SDL_LOG_PRIORITY_INFO
 *}
type
  TSDL_LogInfo_proc = procedure(category: TSDL_LogCategory; const fmt: PAnsiChar; pars: array of const); cdecl;
var
  SDL_LogInfo : TSDL_LogInfo_proc = Nil;


{**
 *  \brief Log a message with SDL_LOG_PRIORITY_WARN
 *}
type
  TSDL_LogWarn_proc = procedure(category: TSDL_LogCategory; const fmt: PAnsiChar; pars: array of const); cdecl;
var
  SDL_LogWarn : TSDL_LogWarn_proc = Nil;


{**
 *  \brief Log a message with SDL_LOG_PRIORITY_ERROR
 *}
type
  TSDL_LogError_proc = procedure(category: TSDL_LogCategory; const fmt: PAnsiChar; pars: array of const); cdecl;
var
  SDL_LogError : TSDL_LogError_proc = Nil;


{**
 *  \brief Log a message with SDL_LOG_PRIORITY_CRITICAL
 *}
type
  TSDL_LogCritical_proc = procedure(category: TSDL_LogCategory; const fmt: PAnsiChar; pars: array of const); cdecl;
var
  SDL_LogCritical : TSDL_LogCritical_proc = Nil;


{**
 *  \brief Log a message with the specified category and priority.
 *}
type
  TSDL_LogMessage_proc = procedure(category: TSDL_LogCategory; priority: TSDL_LogPriority; const fmt: PAnsiChar; pars: array of const); cdecl;
var
  SDL_LogMessage : TSDL_LogMessage_proc = Nil;


{**
 *  \brief Log a message with the specified category and priority.
 *}
type
  TSDL_LogMessageV_proc = procedure(category: TSDL_LogCategory; priority: TSDL_LogPriority; const fmt: PAnsiChar; ap: array of const); cdecl;
var
  SDL_LogMessageV : TSDL_LogMessageV_proc = Nil;


{**
 *  \brief The prototype for the log output function
 *}
type
  PPSDL_LogOutputFunction = ^PSDL_LogOutputFunction;
  PSDL_LogOutputFunction = ^TSDL_LogOutputFunction;
  TSDL_LogOutputFunction = procedure(
    userdata: Pointer;
    category: TSDL_LogCategory;
    priority: TSDL_LogPriority;
    const msg: PAnsiChar); cdecl;

{**
 *  \brief Get the current log output function.
 *}
procedure SDL_LogGetOutputFunction(callback: PSDL_LogOutputFunction; userdata: PPointer); cdecl;
  external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_LogGetOutputFunction' {$ENDIF} {$ENDIF};

{**
 *  \brief This function allows you to replace the default log output
 *         function with one of your own.
 *}
procedure SDL_LogSetOutputFunction(callback: TSDL_LogOutputFunction; userdata: Pointer); cdecl;
  external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_LogSetOutputFunction' {$ENDIF} {$ENDIF};

{$ENDIF}
