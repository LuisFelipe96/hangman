#include "h.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct word {
    size_t length;
    char * text;
};

struct wordlist {
    size_t count;
    struct word * list[90000];
    size_t maxlen;
} * words;



void load(char * path) {
    char temp[300];
    size_t index = 0;

    words = malloc(sizeof(struct wordlist));
    words->maxlen = 1;

    FILE * pFileWords;
    pFileWords = fopen(path, "r");
    if (pFileWords == NULL) {
        printf("\nnehuma lista de palavras foi encontrada%s\n", path);
        exit(1);
    }
    while (fscanf(pFileWords, "%s", temp) != EOF) {
        size_t length = strlen(temp);
        if (words->maxlen < length) {
            words->maxlen = length;
        }
        words->list[index] = malloc(sizeof(struct word));
        words->list[index]->text = (char *)malloc(length*sizeof(char)+1);
        strcpy(words->list[index]->text, temp);
        words->list[index]->length = length;
        index++;
    }
    words->count = index;
}
int forca(int *chances)
{
	switch(*chances)
		{
			case 0:
				printf("\n|---------------|\n|\n|               O\n|              /o\\\n|              / \\\n|\n|\n|\n");
				break;
			case 1:
				printf("\n|---------------|\n|\n|               O\n|              /o\\\n|              / \n|\n|\n|\n");
				break;
			case 2:
				printf("\n|---------------|\n|\n|               O\n|              /o\\\n|\n|\n|\n|\n");
				break;
			case 3:
				printf("\n|---------------|\n|               O\n|              /o\n|\n|\n|\n|\n|\n");
				break;
			case 4:
				printf("\n|---------------|\n\n|               O\n|               o\n|\n|\n|\n|\n|\n|\n");
				break;					
 			case 5:
				printf("\n|---------------|\n|               O\n|\n|\n|\n|\n|\n|\n");
				break;
			case 6:
				printf("\n|---------------|\n|\n|\n|\n|\n|\n|\n|\n");
				break;
		}
}


void inicializaPlayer(struct player *jogadores,int qp){
	int i;
	int j;
	for(i=0;i<qp;i++){
		jogadores->pontos[i]=0;
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			jogadores->forca[i][j]='.';
		}
	}
}

int play(int minlen,int qp) {
    printf("\n");
    int resp,i;
    struct word *palavra;
    char temp[300];
    srand(time(NULL));
    struct player jogadores;
    inicializaPlayer(&jogadores,qp);
    int cj=0;
    int mod=0;
    int maior=0;
    int p=1;
    do {
        struct word * word;
        printf("deseja usar uma palavra do dicionario ou digitar uma? 1- dicionario 0 - digitar\n");
        scanf("%d", &resp);
        if(resp) {
            do {
                word = words->list[rand()%words->count];
            } while (word->length < minlen);
        } else {

            scanf("%s",temp);
            size_t length = strlen(temp);
            palavra = malloc(sizeof(struct word));
            palavra->text = (char *)malloc(length*sizeof(char)+1);
            strcpy(palavra->text, temp);
            palavra->length = length;
            word = palavra;
	    printf("\33[H\33[2J"); 
        }
        int guess;
        int chances = 6;
        char wrong[30] = "";
        char found[word->length+1];
        memset(found, '\0', word->length+1);
        memset(found, '.', word->length);
		forca(&chances);
	while (getchar() != '\n') {
            /* do nothing */
        };
	if (qp>1){
		mod=cj%qp;
		printf("vez do jogador: %i\n",mod+1);
	}
        printf("acertos %s | chances %i | erros '%s'  ", found, chances, wrong);
        do {
            guess = getchar();
            if (guess == '\n') {
		if (qp>1){
			mod=cj%qp;
			printf("vez do jogador: %i\n",mod+1);	
		}
		printf("pontos %i\n", jogadores.pontos[mod]);
                printf("acertos %s | chances %i | erros '%s'  ", found, chances, wrong);
                continue;
            }
            else if (guess == EOF) {
                printf("\n");
                return 0;
            }
            else if (guess < 97 || guess > 122) {
                continue;
            }
            else {
                int i;
                for (i = 0; i < strlen(found); i++) {
                    if (word->text[i] == guess) {
                        found[i] = guess;
			jogadores.pontos[mod]++;
                    }
                }
            }
            if (strchr(found, guess) == NULL && strchr(wrong, guess) == NULL) {
                strncat(wrong, (char *)&guess, 30);
                chances--;
		if (qp>0){
			cj++;
		}
            }
		forca(&chances);
	
        } while (strchr(found, '.') != NULL && chances > 0);
        printf("acertos %s | chances %i | erros '%s'\n", word->text, chances, wrong);
        if (chances > 0) {
            printf("VITÓRIA!\n\n");
        } else {
            printf("PERDESTE!\n\n");
        }
	maior=jogador.pontos[0];
	p=1;
	for(i=0;i<qp;i++){
	    	if(jogadores.pontos[i] > maior){	
			maior=jogadores.pontos[i];
			p=i+1;
		}
    	}
	printf("Ganhador: %i Pontos: %i \n", p,maior);
        printf("deseja jogar? 1- sim 0 - não\n");
        scanf("%d", &resp);
        while (getchar() != '\n') {
            /* do nothing */
        };
	inicializaPlayer(&jogadores,qp);
    }
    while(resp);

    return 0;
}
