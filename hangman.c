#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "h.h"

int main(int argc, char * argv[]) {
    char resp;
    struct wordlist * words;
    char * path = "dicionario";
    long minlen = 3;
    if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0) {
            printf("\nhangman comando linha de argumentos:\n\
					\n-w caminho\n\tCaminho para um espaço em branco lista de palavras separadas .\
					\n-s tamanho\n\ttamanho minimo para a pavra.\n\
					\n-p jogadores\n\tnumero de jogadores 1,2,3");
            return 0;
        }
        else {
            int i = 1;
            do {
                if (strcmp(argv[i], "-w") == 0) {
                    if (i+1 < argc) {
                        i++;
                    }
                    else {
                        printf("\n-w requer uma localidade para o dicionario\n");
                        return 1;
                    }
                    path = argv[i];
                }
                if (strcmp(argv[i], "-s") == 0) {
                    if (i+1 < argc) {
                        i++;
                    }
                    else {
                        printf("\n-s requer um tamanho minimo\n");
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

