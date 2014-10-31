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
};

static int OPTBIT_color = 0;
static int OPT_color = 0;

// this would not work if some code between the enum declaration and the call of my init function would use the value of OPTBIT_color or OPT_color.
// fortunately the only usage of OPT_color in ls.pi is in the main method.
// we can inject a call to init_OPT_enumVars at the beginning of the main method.
void init_OPT_enumVars() {
	OPTBIT_color = 13;
	
#if (definedEx(CONFIG_FTPD) || definedEx(CONFIG_FEATURE_LS_TIMESTAMPS))
 OPTBIT_color += 4;
#endif
#if definedEx(CONFIG_FEATURE_LS_SORTFILES)
OPTBIT_color += 4;
#endif
#if definedEx(CONFIG_FEATURE_LS_FILETYPES)
OPTBIT_color += 2;
#endif
#if definedEx(CONFIG_FEATURE_LS_FOLLOWLINKS)
OPTBIT_color += 1;
#endif
#if definedEx(CONFIG_FEATURE_LS_RECURSIVE)
OPTBIT_color += 1;
#endif
#if definedEx(CONFIG_FEATURE_HUMAN_READABLE)
OPTBIT_color += 1;
#endif
#if (definedEx(CONFIG_FEATURE_FIND_CONTEXT) || definedEx(CONFIG_SELINUX))
OPTBIT_color += 2;
#endif
#if definedEx(CONFIG_FEATURE_AUTOWIDTH)
OPTBIT_color += 2;
#endif
	OPT_color = 1 << OPTBIT_color;
}
