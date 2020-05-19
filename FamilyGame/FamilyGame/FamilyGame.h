#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <conio.h>
const char le = 's';//
const char fel = 'w';//
const char jobbra = 'd';//
const char balra = 'a';//

struct Jatekos {//
    int x;//
    int y;//
    int pont;//
};//

struct Szint {//
    Jatekos* jatekos;//
    char** palya;//
    int hossz;//
    int szel;//
    int hanyadik;//
};

char** beolvasPalya(const char* fajlNev, int& hossz, int& szel);//
void kirajzolPalya(Szint* szint);//
Szint* beolvasPalya(Jatekos* jatekos, const char* fajlNev, int hanyadik);
Jatekos* jatekosLetrehozasa();
void mozgas(Szint* szint);//
void lepesMegtetele(Szint* szint, int kovetkezoX, int kovetkezoY);//
void statok(Szint* szint);//
