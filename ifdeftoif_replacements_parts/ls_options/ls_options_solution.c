// initialize with maximum size
static char ls_options[] __attribute__((aligned(1))) = "Cadil1gnsxQAk" "cetu" "SXrv" "Fp" "R" "KZ" "LH" "h" "T:w:";

static void init_ls_options() {
	int currentLength = 13;
#if (definedEx(CONFIG_FTPD) || definedEx(CONFIG_FEATURE_LS_TIMESTAMPS))
ls_options[currentLength] = 'c';
ls_options[currentLength+1] = 'e';
ls_options[currentLength+2] = 't';
ls_options[currentLength+3] = 'u';
currentLength+=4;
#endif
 /* 4, 17 */
	
#if definedEx(CONFIG_FEATURE_LS_SORTFILES)
ls_options[currentLength] = 'S';
ls_options[currentLength+1] = 'X';
ls_options[currentLength+2] = 'r';
ls_options[currentLength+3] = 'v';
currentLength+=4;
#endif
  /* 4, 21 */
	
#if definedEx(CONFIG_FEATURE_LS_FILETYPES)
ls_options[currentLength] = 'F';
ls_options[currentLength+1] = 'p';
currentLength+=2;
#endif
    /* 2, 23 */
	
#if definedEx(CONFIG_FEATURE_LS_RECURSIVE)
ls_options[currentLength] = 'R';
currentLength+=1;
#endif
     /* 1, 24 */
	
#if (definedEx(CONFIG_FEATURE_FIND_CONTEXT) || definedEx(CONFIG_SELINUX))
ls_options[currentLength] = 'K';
ls_options[currentLength+1] = 'Z';
currentLength+=2;
#endif
                 /* 2, 26 */
	
#if definedEx(CONFIG_FEATURE_LS_FOLLOWLINKS)
ls_options[currentLength] = 'L';
ls_options[currentLength+1] = 'H';
currentLength+=2;
#endif
  /* 2, 28 */
	
#if definedEx(CONFIG_FEATURE_HUMAN_READABLE)
ls_options[currentLength] = 'h';
currentLength+=1;
#endif
   /* 1, 29 */
	
#if definedEx(CONFIG_FEATURE_AUTOWIDTH)
ls_options[currentLength] = 'T';
ls_options[currentLength+1] = ':';
ls_options[currentLength+2] = 'W';
ls_options[currentLength+3] = ':';
currentLength+=4;
#endif
ls_options[currentLength] = '\0';
}
