
struct player {
    char forca[10][10];
    int pontos[26];
} jogador;

extern void load(char *);

extern int play(int,int);

extern void inicializaPlayer(struct player*, int);
