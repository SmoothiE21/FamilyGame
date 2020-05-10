#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include "FamilyGame.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int hossz;
int szel;



char** beolvasPalya(const char* fajlNev)
{

	FILE* fin = fopen(fajlNev, "rt");
	char* c = (char*)calloc(1, sizeof(char));

	if (!fin) {
		printf("Sikertelen");
		exit(1);
	}
	fscanf(fin, "%i%i\n", &hossz, &szel);
	char** palya = (char**)(calloc(hossz, sizeof(char*)));
	//ellenorzes
	for (int i = 0; i < hossz; ++i) {
		palya[i] = (char*)(calloc(szel, sizeof(char)));
	}
	for (int i = 0; i < hossz; ++i) {
		for (int j = 0; j < szel; ++j) {
			fscanf(fin, "%c\n", &c);
			if (c[0] == '3' && (i == 0 || i == hossz - 1)) {
				palya[i][j] = "-";
			}
			else if( c[0] == '3') {
				palya[i][j] = "|";
			}
			else

				if (c[0] == '0') {
					palya[i][j] = " ";;
				}
				else

					if (c[0] == '1') {
						palya[i][j] = "*";
					}
					else
						if (c[0] == 'R') {
							palya[i][j]= "X";
						}

		}
	}
	return palya;
}
void kirajzolPalya(char** palya,player jatekos)
{
	for (int i = 0; i < hossz; ++i) {
		for (int j = 0; j < szel; ++j) {
			
			
			
				printf("%c", palya[i][j]);
		}
		printf("\n");
	}


	

	system("pause");
}

void mozgat(char** palya, player jatekos, int le, int jobbra)
{
	int* pozicio = jatekos.pozicio;


	if (palya[pozicio[X_poz] + jobbra][pozicio[Y_poz] + le] == '1' ||//kikerulni a csillagokat
		palya[pozicio[X_poz] + jobbra][pozicio[Y_poz] + le] == '3') // nem kimenni a falbol
	{
		return;

	}

	palya[pozicio[X_poz]][pozicio[Y_poz]] = '0';
	pozicio[Y_poz] += le;
	pozicio[X_poz] += jobbra;
	palya[pozicio[X_poz]][pozicio[Y_poz]] = jatekos.nev;

}