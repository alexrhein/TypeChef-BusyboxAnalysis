#include "stdio.h"
// initialize with maximum size
static char ls_options[] __attribute__((aligned(1))) = "Cadil1gnsxQAk" "cetu" "SXrv" "Fp" "R" "KZ" "LH" "h" "T:w:";

static void init_ls_options() {
	int currentLength = 13;
	ls_options[currentLength] = 'c';
	ls_options[currentLength+1] = 'e';
	ls_options[currentLength+2] = 't';
	ls_options[currentLength+3] = 'u';
	currentLength+=4;
	ls_options[currentLength] = '\0';
}
int main() {
	init_ls_options();
	printf("%s\n", ls_options);}
