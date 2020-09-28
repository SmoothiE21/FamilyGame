
#include "FamilyGame.h"



void statok(Szint* szint) {
    printf("\033[1;34m");
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
    
    int kovetkezoX = szint->jatekos->x;
    int kovetkezoY = szint->jatekos->y;

    char option = getch();

    switch (option)
    {
    case fel: {
        kovetkezoX--;//sor -1
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
    default: {
        mozgas(szint); // recursive call while(true) helyett
        return;//nem tesz lepest ebben a hivasban
    }
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
    switch (palya[kovetkezoX][kovetkezoY])//ide akarunk menni
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
            kovetkezoX = 1;    
            kovetkezoY = 1;
        }
        else {
            system("CLS");
            printf("\n\n\n\n");
            printf("Vege a jateknak \n\nVegleges pontszam: %d", szint->jatekos->pont);
            printf(" osszegyujtott korona\n");
            if (szint->jatekos->pont < 0)
            {
                printf("Hat ez nagyon gyenge volt...\n\n");
            }
            else if ((szint->jatekos->pont > 0) && (szint->jatekos->pont < 20))
            {
                printf("Kozepes eredmeny!\n\n");
            }
            else if(szint->jatekos->pont >= 20)
            printf("\nKivalo eredmeny!\n\n");

            printf("Nyomj egy gombot a kilepeshez...\n");
            getch();
            exit(0);
        }
        break;
    }
    default:
        break;
    }

    szint->jatekos->x = kovetkezoX;//lepesmegtetel in  real
    szint->jatekos->y = kovetkezoY;
}

Szint* beolvasPalyaJatekossal(Jatekos* jatekos, const char* fajlNev, int hanyadik) {
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
                printf("\033[0;33m");
                printf("P");
                printf("\033[0;32m");
               
            } else if (palya[i][j] == '3' && (i == 0 || i == szint->hossz - 1)) {
                printf("-");
                printf("\033[0;32m");
            }
            else if (palya[i][j] == '3') {
                printf("|");
            }
            else if (palya[i][j] == '0') {
                printf(" ");
            }
            else if (palya[i][j] == '1') {
                printf("\033[1;35m");
                printf("*");
                printf("\033[0;32m");
            }
            else if (palya[i][j] == '2') {
                printf("\033[1;36m");
                printf("+");
                printf("\033[0;32m");
            }
            else if (palya[i][j] == 'R') {
                printf("\033[1;31m");
                printf("X");
                printf("\033[0;32m");
            }
        }
        printf("\n");
    }
}