/* TODO: simple toggles may be stored as OPT_xxx bits instead */
static unsigned opt_flags[] = {
	LIST_SHORT | STYLE_COLUMNS, /* C */
	DISP_HIDDEN | DISP_DOT,     /* a */
	DISP_NOLIST,                /* d */
	LIST_INO,                   /* i */
	LIST_LONG | STYLE_LONG,     /* l - remember LS_DISP_HR in mask! */
	LIST_SHORT | STYLE_SINGLE,  /* 1 */
	0,                          /* g (don't show owner) - handled via OPT_g */
	LIST_ID_NUMERIC,            /* n */
	LIST_BLOCKS,                /* s */
	DISP_ROWS,                  /* x */
	0,                          /* Q (quote filename) - handled via OPT_Q */
	DISP_HIDDEN,                /* A */
	0, //[12]
	#if (definedEx(CONFIG_FTPD) || definedEx(CONFIG_FEATURE_LS_TIMESTAMPS))
	// from here to after [16] the entries are optional _and_ partly variable
	// so, i need two instances of the array (one with and one without the optional entries.
	// if the entries are present, then i also need to initalize them in the init function
	0, //[13]
	LIST_FULLTIME,              /* e */
	0,//[15]
	0,//[16]
	#endif
#if definedEx(CONFIG_FEATURE_LS_SORTFILES)
	SORT_SIZE,                  /* S */
	SORT_EXT,                   /* X */
	SORT_REVERSE,               /* r */
	SORT_VERSION,               /* v */
#endif
#if definedEx(CONFIG_FEATURE_LS_FILETYPES)
	LIST_FILETYPE | LIST_EXEC,  /* F */
	LIST_FILETYPE,              /* p */
#endif
#if definedEx(CONFIG_FEATURE_LS_FOLLOWLINKS)
	FOLLOW_LINKS,               /* L */
#endif
#if definedEx(CONFIG_FEATURE_LS_RECURSIVE)
	DISP_RECURSIVE,             /* R */
#endif
#if definedEx(CONFIG_FEATURE_HUMAN_READABLE)
	LS_DISP_HR,                 /* h */
#endif
#if (definedEx(CONFIG_FEATURE_FIND_CONTEXT) || definedEx(CONFIG_SELINUX))
	LIST_MODEBITS|LIST_NLINKS|LIST_CONTEXT|LIST_SIZE|LIST_DATE_TIME, /* K */
#endif
#if (definedEx(CONFIG_FEATURE_FIND_CONTEXT) || definedEx(CONFIG_SELINUX))
	LIST_MODEBITS|LIST_ID_NAME|LIST_CONTEXT, /* Z */
#endif
	(1U<<31)
	/* options after Z are not processed through opt_flags:
	 * T, w - ignored
	 */
};

void init_opt_flags() {
opt_flags[12]=
#if (definedEx(CONFIG_FEATURE_FIND_CONTEXT) || definedEx(CONFIG_SELINUX))
1
#endif
#if (!definedEx(CONFIG_FEATURE_FIND_CONTEXT) && !definedEx(CONFIG_SELINUX))
0
#endif
 * LIST_CONTEXT;
 
// optional entry initialization from here on
#if (definedEx(CONFIG_FTPD) || definedEx(CONFIG_FEATURE_LS_TIMESTAMPS))

opt_flags[13]=
	TIME_CHANGE | (
#if definedEx(CONFIG_FEATURE_LS_SORTFILES)
1
#endif
#if !definedEx(CONFIG_FEATURE_LS_SORTFILES)
0
#endif
 * SORT_CTIME);

opt_flags[15]=
#if definedEx(CONFIG_FEATURE_LS_SORTFILES)
1
#endif
#if !definedEx(CONFIG_FEATURE_LS_SORTFILES)
0
#endif
 * SORT_MTIME;

opt_flags[16]=
	TIME_ACCESS | (
#if definedEx(CONFIG_FEATURE_LS_SORTFILES)
1
#endif
#if !definedEx(CONFIG_FEATURE_LS_SORTFILES)
0
#endif
 * SORT_ATIME);

#endif

}
