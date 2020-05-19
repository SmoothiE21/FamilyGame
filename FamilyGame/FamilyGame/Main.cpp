#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <conio.h>
#include "FamilyGame.h"

/**
 *  A jatek lenyege:
 *      Plusszokat kell ossze szedni pontokert, ha csillagot szed fel akkor respawnol resetelt pontszammal
 *      -- Falnak menes minusz egy pontot general
 *      -- X az a kovetkezo palya
*/

int main()
{
    printf("\033[1;31m");

    Jatekos* jatekos = jatekosLetrehozasa();
    Szint* szint = beolvasPalya(jatekos, "terkep1.txt", 1);
    while (true) {

        kirajzolPalya(szint);

        statok(szint);
        mozgas(szint);

        system("CLS");
    }
    return(0);
}