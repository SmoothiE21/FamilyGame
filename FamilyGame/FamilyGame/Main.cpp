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
    

    Jatekos* jatekos = jatekosLetrehozasa();
    Szint* szint = beolvasPalyaJatekossal(jatekos, "terkep1.txt", 1);
    
    while (true) {

        kirajzolPalya(szint);
        statok(szint);    
        mozgas(szint);//mikor a palyer eléri az x-et váltódik a pálya
        system("CLS");
    }
    return(0);
}