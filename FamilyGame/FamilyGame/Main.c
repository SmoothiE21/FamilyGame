#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#define MARAD 0
#define FEL -1
#define LE 1
#define JOBBRA 1
#define BALRA -1


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h> 
#include <conio.h>
#include "FamilyGame.h"




int main()
{
	
	player* players = (player*)calloc(4, sizeof(player));
	players[0].pozicio = (int*)calloc(2, sizeof(int));
	players[1].pozicio = (int*)calloc(2, sizeof(int));
	players[2].pozicio = (int*)calloc(2, sizeof(int));
	players[3].pozicio = (int*)calloc(2, sizeof(int));

	players[0].nev = 'A';
	players[1].nev = 'B';
	players[2].nev = 'C';
	players[3].nev = 'D';
	
	players[0].pozicio[X_poz] = 1;
	players[0].pozicio[Y_poz] = 1;

	players[1].pozicio[X_poz] = 1;
	players[1].pozicio[Y_poz] = 1;

	players[2].pozicio[X_poz] = 1;
	players[2].pozicio[Y_poz] = 1;

	players[3].pozicio[X_poz] = 1;
	players[3].pozicio[Y_poz] = 1;

	
	
	char** palya;
	palya = beolvasPalya("be..txt");
	
	
	
	while (1) {
		for (int i = 0; i < 4; i++)
		{
			palya[players[i].pozicio[X_poz]][players[i].pozicio[Y_poz]] = players[i].nev;



			kirajzolPalya(palya, players[i]);
			//printf("\033[1;31m");
			//printf("jobb: j\nle: l\n");
			char option = getch();

			if (option == 'd') {
				mozgat(palya,players[i], JOBBRA, MARAD);//1-t jobbra,semennyit lefele



			}
			else if (option == 's') {
				mozgat(palya, players[i], MARAD, LE);
			}
			else if (option == 'w') {
				mozgat(palya, players[i], MARAD, FEL);//minusz 1 lefele  az 1 felfele
			}
			else if (option == 'a') {
				mozgat(palya, players[i], BALRA, MARAD);
			}


			system("CLS");

		}
	}



	system("pause");



}