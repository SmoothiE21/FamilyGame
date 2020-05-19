
#include "FamilyGame.h"



void statok(Szint* szint) {
    printf("Fel   : W\nLe    : S\nJobbra: D\nBalra : A\n");
 
    printf(" Jenlegi szint: %d", szint->hanyadik);
    printf(" Jenlegi pont: %d", szint->jatekos->pont);
}

Jatekos* jatekosLetrehozasa() {
    Jatekos* jatekos = (Jatekos*)calloc(1, sizeof(Jatekos));
    jatekos->pont = 0;
    jatekos->x = 1;
    jatekos->y = 1;
    return jatekos;
}

void mozgas(Szint* szint) {
    int x = szint->jatekos->x;
    int y = szint->jatekos->y;
    int kovetkezoX = x;
    int kovetkezoY = y;

    char option = getch();

    switch (option)
    {
    case fel: {
        kovetkezoX--;
        break;
        }
    case le: {
        kovetkezoX++;
        break;
    }
    case jobbra: {
        kovetkezoY++;
        break; 
    }
    case balra: {
        kovetkezoY--;
        break;
    }
    default: mozgas(szint); // recursive call while(true) helyett
    }
    lepesMegtetele(szint, kovetkezoX, kovetkezoY);
}

/**
 * 0 - space
 * 1 - csillag
 * 2 - plusz
 * 3 -  fal ( - vagy | )
 * R - Checkpoint
 * P - player
 */
void lepesMegtetele(Szint* szint, int kovetkezoX, int kovetkezoY) {
    char** palya = szint->palya;
    switch (palya[kovetkezoX][kovetkezoY])
    {
    case '0': break;
    case '1': {                 //Vissza rakja az 1-1es pozicioba ha csillagnak megy
        palya[kovetkezoX][kovetkezoY] = '0';  // eltunteti a * jelet
        kovetkezoX = 1;
        kovetkezoY = 1;
        break;
    }
    case '2': {
        szint->jatekos->pont++; 
        palya[kovetkezoX][kovetkezoY] = '0';    // eltunteti a + jelet
        break;
    }
    case '3': {
        szint->jatekos->pont--;         //Ha falnak megy veszit egy pontot es nem mozdul
        kovetkezoX = szint->jatekos->x;     
        kovetkezoY = szint->jatekos->y;
        break;
    }
    case 'R': {
        if (szint->hanyadik == 1) {
            szint->palya = beolvasPalya("terkep2.txt", szint->hossz, szint->szel);     //beolvassa a kettes palyat
            szint->hanyadik = 2;
            kovetkezoX = 1;     // kezdes az 1-1esen a masodik palyan is
            kovetkezoY = 1;
        }
        else {
            system("CLS");
            printf("\n\n\n\n");
            printf("Vege a jateknak! Szep volt! \n\nVegleges pontszam: %d\n\n", szint->jatekos->pont);
            printf("Nyomj egy betut a kilepeshez...");
            getch();
            exit(0);
        }
        break;
    }
    default:
        break;
    }

    szint->jatekos->x = kovetkezoX;
    szint->jatekos->y = kovetkezoY;
}

Szint* beolvasPalya(Jatekos* jatekos, const char* fajlNev, int hanyadik) {
    Szint* palya = (Szint*)calloc(1, sizeof(Szint));
    palya->jatekos = jatekos;
    palya->palya = beolvasPalya(fajlNev, palya->hossz, palya->szel);
    palya->hanyadik = hanyadik;
    return palya;
}


char** beolvasPalya(const char* fajlNev, int &hossz, int &szel)
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

/**
 * 0 - space
 * 1 - csillag
 * 2 - plusz
 * 3 -  fal ( - vagy | )
 * R - Checkpoint
 * P - player
 * @param palya A palya kodolt formaban
 */
void kirajzolPalya(Szint* szint)
{
    char** palya = szint->palya;
    for (int i = 0; i < szint->hossz; ++i) {
        for (int j = 0; j < szint->szel; ++j) {
            if ( (szint->jatekos->x == i) && (j == szint->jatekos->y)) {
                printf("P");
            } else if (palya[i][j] == '3' && (i == 0 || i == szint->hossz - 1)) {
                printf("-");
            }
            else if (palya[i][j] == '3') {
                printf("|");
            }
            else if (palya[i][j] == '0') {
                printf(" ");
            }
            else if (palya[i][j] == '1') {
                printf("*");
            }
            else if (palya[i][j] == '2') {
                printf("+");
            }
            else if (palya[i][j] == 'R') {
                printf("X");
            }
        }
        printf("\n");
    }
}