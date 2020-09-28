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

struct Jatekos {//j�t�kos strukt�ra
    int x;
    int y;
    int pont;
};

struct Szint {
    Jatekos* jatekos;//szint strukt�ra: tartalmazza a p�ly�t �s a j�t�kos inform�ci�it
    char** palya;
    int hossz;
    int szel;
    int hanyadik;
};

Jatekos* jatekosLetrehozasa();
Szint* beolvasPalyaJatekossal(Jatekos* jatekos, const char* fajlNev, int hanyadik);//beolvassa a p�ly�t a j�t�kos szerint//ez a fgv hivja a beolvaspalyat
char** beolvasPalya(const char* fajlNev, int& hossz, int& szel);//visszakuldi a p�ly�t a hossz�t meg a sz�l�t meg a p�ly�t
void kirajzolPalya(Szint* szint);

void mozgas(Szint* szint);//hasznalja a lepesmegtetelt
void lepesMegtetele(Szint* szint, int kovetkezoX, int kovetkezoY);//maga a l�p�s
void statok(Szint* szint);// j�t�k v�ge
