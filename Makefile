build: h.o hangman.c
	gcc hangman.c h.o -o hangman
h.o: h.c h.h
	gcc -c h.c -o h.o
