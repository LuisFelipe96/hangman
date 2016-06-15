#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "h.h"

int main(int argc, char * argv[]) {
    char resp;
    struct wordlist * words;
    char * path = "dicionario";
    long minlen = 3;
    int qp=0;
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
		if (strcmp(argv[i], "-p") == 0) {
			if (i+1 < argc) {
                        i++;
                    }
                    else {
                        printf("\n-p requer numero de jogadores\n");
                        return 1;
                    }
		    qp= strtol(argv[i], NULL, 0);	
		    if(qp>3){
		    	printf("\nmaximo de jogadores exedido\n");
			return 1;
                    }	
		}
                i++;
            }	while (i < argc);
        }
    }
    load(path);
    if (qp== 0) {
    	printf("digite o numero de jogadores que voce quer(Máximo 3): ");
	scanf("%i",&qp);
    }	
    /*if (minlen > words->maxlen) {
    	printf("\nsize must not be larger than the longest word, %zu\n", words->maxlen);
    	exit(1);
    } */
    return play(minlen,qp);
}

