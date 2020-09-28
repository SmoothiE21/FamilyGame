#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <conio.h>
const char le = 's';
const char fel = 'w';
const char jobbra = 'd';
const char balra = 'a';

struct Jatekos {//játékos struktúra
    int x;
    int y;
    int pont;
};

struct Szint {
    Jatekos* jatekos;//szint struktúra: tartalmazza a pályát és a játékos információit
    char** palya;
    int hossz;
    int szel;
    int hanyadik;
};

Jatekos* jatekosLetrehozasa();
Szint* beolvasPalyaJatekossal(Jatekos* jatekos, const char* fajlNev, int hanyadik);//beolvassa a pályát a játékos szerint//ez a fgv hivja a beolvaspalyat
char** beolvasPalya(const char* fajlNev, int& hossz, int& szel);//visszakuldi a pályát a hosszát meg a szélét meg a pályát
void kirajzolPalya(Szint* szint);

void mozgas(Szint* szint);//hasznalja a lepesmegtetelt
void lepesMegtetele(Szint* szint, int kovetkezoX, int kovetkezoY);//maga a lépés
void statok(Szint* szint);// játék vége
