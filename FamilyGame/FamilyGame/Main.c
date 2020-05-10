#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h> 
#include <conio.h>
#include "FamilyGame.h"




int main()
{
	printf("hello vilag\n");
	time_t currentTime, startTime;
	startTime = time(NULL);
	int index = 1;
	char** palya;
	palya = beolvasPalya("be.txt");
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya[jatekosX][jatekosY] = 'P';
	//kirajzolPalya(palya);
	while (1) {
		currentTime = time(NULL);
		kirajzolPalya(palya);
		printf("\033[1;31m");

		printf("jobb: j\nle: l\n");
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;
		if (option == 'j') {
			jatekosY++;
		}
		else if (option == 'l') {
			jatekosX++;
		}
		if (palya[jatekosX][jatekosY] == '0') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';
		}
		//Sleep(300);
		system("CLS");
		//	/*if (currentTime - startTime > 10) {
		//		printf("Time limit exceeded!\n Game over\n");
		//		break;*/
		//}

	}



	system("pause");



}