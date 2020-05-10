
typedef struct player
{
	char nev;
	int* pozicio;

}player;
#define X_poz  0
#define Y_poz  1
char** beolvasPalya(const char* fajlNev);
void kirajzolPalya(char** palya, player jatekos);
void mozgat(char** palya, player jatekos, int le, int jobbra);
