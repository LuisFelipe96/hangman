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

int play(int minlen) {
    printf("\n");
    int resp;
    srand(time(NULL));
    do {
        struct word * word;
        do {
            word = words->list[rand()%words->count];
        } while (word->length < minlen);
        int guess;
        int chances = 5;
        char wrong[30] = "";
        char found[word->length+1];
        memset(found, '\0', word->length+1);
        memset(found, '_', word->length);
            printf("acertos %s | chances %i | erros '%s'  ", found, chances, wrong);
           do {
                guess = getchar();
                if (guess == '\n') {
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
                        }
                    }
                    if (strchr(found, guess) == NULL && strchr(wrong, guess) == NULL) {
                        strncat(wrong, (char *)&guess, 30);
                        chances--;
                    } 
                }
            } while (strchr(found, '_') != NULL && chances > 0);
            printf("acertos %s | chances %i | erros '%s'\n", word->text, chances, wrong);
            if (chances > 0) {
                printf("VITÓRIA!\n\n");
            } else {
                printf("PERDESTE!\n\n");
            }
            printf("deseja jogar? 1- sim 0 - não\n");
            scanf("%d", &resp);
        } while( resp);
	
        return 0;
}
