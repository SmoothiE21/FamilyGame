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
			fscanf(fin, "%c\n", &palya[i][j]);
		}
	}
	return palya;
}
void kirajzolPalya(char** palya)
{
	for (int i = 0; i < hossz; ++i) {
		for (int j = 0; j < szel; ++j) {
			if (palya[i][j] == '3' && (i == 0 || i == hossz - 1)) {
				printf("-");
			}
			else if (palya[i][j] == '3') {
				printf("|");
			}
			if (palya[i][j] == '0') {
				printf(" ");
			}
			if (palya[i][j] == '1') {
				printf("*");
			}
			if (palya[i][j] == 'R') {
				printf("X");
			}
			if (palya[i][j] == 'P') {
				printf("P");
			}
		}
		printf("\n");
	}
	system("pause");
}