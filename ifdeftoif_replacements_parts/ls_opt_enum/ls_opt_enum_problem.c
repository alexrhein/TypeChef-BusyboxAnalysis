enum {
	//OPT_C = (1 << 0),
	//OPT_a = (1 << 1),
	//OPT_d = (1 << 2),
	//OPT_i = (1 << 3),
	//OPT_l = (1 << 4),
	//OPT_1 = (1 << 5),
	OPT_g = (1 << 6),
	//OPT_n = (1 << 7),
	//OPT_s = (1 << 8),
	//OPT_x = (1 << 9),
	OPT_Q = (1 << 10),
	//OPT_A = (1 << 11),
	//OPT_k = (1 << 12),
	OPTBIT_color = 13
		+ 4 * 
#if (definedEx(CONFIG_FTPD) || definedEx(CONFIG_FEATURE_LS_TIMESTAMPS))
1
#endif
#if (!definedEx(CONFIG_FEATURE_LS_TIMESTAMPS) && !definedEx(CONFIG_FTPD))
0
#endif

		+ 4 * 
#if definedEx(CONFIG_FEATURE_LS_SORTFILES)
1
#endif
#if !definedEx(CONFIG_FEATURE_LS_SORTFILES)
0
#endif

		+ 2 * 
#if definedEx(CONFIG_FEATURE_LS_FILETYPES)
1
#endif
#if !definedEx(CONFIG_FEATURE_LS_FILETYPES)
0
#endif

		+ 1 * 
#if definedEx(CONFIG_FEATURE_LS_FOLLOWLINKS)
1
#endif
#if !definedEx(CONFIG_FEATURE_LS_FOLLOWLINKS)
0
#endif

		+ 1 * 
#if definedEx(CONFIG_FEATURE_LS_RECURSIVE)
1
#endif
#if !definedEx(CONFIG_FEATURE_LS_RECURSIVE)
0
#endif

		+ 1 * 
#if definedEx(CONFIG_FEATURE_HUMAN_READABLE)
1
#endif
#if !definedEx(CONFIG_FEATURE_HUMAN_READABLE)
0
#endif

		+ 2 * 
#if (definedEx(CONFIG_FEATURE_FIND_CONTEXT) || definedEx(CONFIG_SELINUX))
1
#endif
#if (!definedEx(CONFIG_FEATURE_FIND_CONTEXT) && !definedEx(CONFIG_SELINUX))
0
#endif

		+ 2 * 
#if definedEx(CONFIG_FEATURE_AUTOWIDTH)
1
#endif
#if !definedEx(CONFIG_FEATURE_AUTOWIDTH)
0
#endif
,
	OPT_color = 1 << OPTBIT_color,
};