static const char ls_options[] __attribute__((aligned(1))) =
	"Cadil1gnsxQAk" /* 13 opts, total 13 */
	
#if (definedEx(CONFIG_FTPD) || definedEx(CONFIG_FEATURE_LS_TIMESTAMPS))
"cetu"
#endif
#if (!definedEx(CONFIG_FEATURE_LS_TIMESTAMPS) && !definedEx(CONFIG_FTPD))

#endif
 /* 4, 17 */
	
#if definedEx(CONFIG_FEATURE_LS_SORTFILES)
"SXrv"
#endif
#if !definedEx(CONFIG_FEATURE_LS_SORTFILES)

#endif
  /* 4, 21 */
	
#if definedEx(CONFIG_FEATURE_LS_FILETYPES)
"Fp"
#endif
#if !definedEx(CONFIG_FEATURE_LS_FILETYPES)

#endif
    /* 2, 23 */
	
#if definedEx(CONFIG_FEATURE_LS_FOLLOWLINKS)
"L"
#endif
#if !definedEx(CONFIG_FEATURE_LS_FOLLOWLINKS)

#endif
   /* 1, 24 */
	
#if definedEx(CONFIG_FEATURE_LS_RECURSIVE)
"R"
#endif
#if !definedEx(CONFIG_FEATURE_LS_RECURSIVE)

#endif
     /* 1, 25 */
	
#if definedEx(CONFIG_FEATURE_HUMAN_READABLE)
"h"
#endif
#if !definedEx(CONFIG_FEATURE_HUMAN_READABLE)

#endif
   /* 1, 26 */
	
#if (definedEx(CONFIG_FEATURE_FIND_CONTEXT) || definedEx(CONFIG_SELINUX))
"KZ"
#endif
#if (!definedEx(CONFIG_FEATURE_FIND_CONTEXT) && !definedEx(CONFIG_SELINUX))

#endif
 /* 2, 28 */
	
#if definedEx(CONFIG_FEATURE_AUTOWIDTH)
"T:w:"
#endif
#if !definedEx(CONFIG_FEATURE_AUTOWIDTH)

#endif
 /* 2, 30 */
	;