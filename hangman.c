#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "h.h"

int main(int argc, char * argv[]) {

	struct wordlist * words;
	char * path = "wordlist";
	long minlen = 3;

	if (argc > 1) {
		if (strcmp(argv[1], "-h") == 0) {
			printf("\nhangman command line arguments:\n\
					\n-w path\n\tPath to a whitespace seperated list of words.\
					\n-s size\n\tMinimum word size.\n");
			return 0;
		}
		else {
			int i = 1;
			do {
				if (strcmp(argv[i], "-w") == 0) {
					if (i+1 < argc) { i++; }
					else {
						printf("\n-w requires a wordlist path\n");
						return 1;
					}
					path = argv[i];
				}
				if (strcmp(argv[i], "-s") == 0) {
					if (i+1 < argc) { i++; }
					else {
						printf("\n-s requires a minimum size\n");
						return 1;
					}
					minlen = strtol(argv[i], NULL, 0);
				}
				i++;
			}	while (i < argc);
		}
	}
	load(path);
	/*if (minlen > words->maxlen) {
		printf("\nsize must not be larger than the longest word, %zu\n", words->maxlen);
		exit(1);
	} */
	return play(minlen);
}
