#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HAKEMSAYISI 5
#define NAME 20
#define LASTNAME 20
#define COUNTRY 20

typedef struct 
{
    int ID;
    char ad[NAME];
    char soyad[LASTNAME];
    char ulke[COUNTRY];
    int yas;

    float puanlar[HAKEMSAYISI];
    float performans;
    float enYuksekPuan;
    float enDusukPuan;
} yarismaci;

int sadeceHarfMi(const char *str) 
{
    if (strlen(str) == 0) return 0;

    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (!isalpha((unsigned char)str[i]) && !isspace((unsigned char)str[i])) 
        {
            return 0;
        }
    }
    return 1;
}

void yarismaciBilgileriAl(yarismaci *y)
{
    while (1) 
    {
        printf("First Name : ");
        fgets(y->ad, NAME, stdin);
        y->ad[strcspn(y->ad, "\n")] = '\0';

        if (sadeceHarfMi(y->ad)){
            break;
        }
        printf("Invalid input! Only letters are allowed.\n");
    }

    while (1) 
    {
        printf("Last Name  : ");
        fgets(y->soyad, LASTNAME, stdin);
        y->soyad[strcspn(y->soyad, "\n")] = '\0';

        if (sadeceHarfMi(y->soyad)){
            break;
        }
        printf("Invalid input! Only letters are allowed.\n");
    }

    while (1) 
    {
        printf("Country    : ");
        fgets(y->ulke, COUNTRY, stdin);
        y->ulke[strcspn(y->ulke, "\n")] = '\0';

        if (sadeceHarfMi(y->ulke)){
            break;
        }
        printf("Invalid input! Only letters are allowed.\n");
    }

    while (1)
    {
        printf("Age : ");

        if (scanf("%d", &y->yas) == 1 && y->yas > 0){
            break;
        }
        printf("Invalid input!\n");

        while (getchar() != '\n');
    }
}

void hakemPuanlariAl(yarismaci *y)
{
    int i;
    printf("\nEnter Judge Scores\n");

    for (i = 0; i < HAKEMSAYISI; i++)
    {
        while (1) 
        {
            printf("Judge %d: ", i + 1);

            if (scanf("%f", &y->puanlar[i]) == 1 && y->puanlar[i] >= 0.0 && y->puanlar[i] <= 10.0){
                break;
            }

            printf("Invalid score input!\n");

            while (getchar() != '\n');
        }
    }
}

void performansHesapla(yarismaci *y)
{
    float toplamPuan = 0;
    float *puan=y->puanlar;
    y->enDusukPuan = puan[0];
    y->enYuksekPuan = puan[0];

    for (int i = 0; i < HAKEMSAYISI; i++)
    {
        toplamPuan += puan[i];

        if (puan[i] > y->enYuksekPuan) y->enYuksekPuan = puan[i];
        if (puan[i] < y->enDusukPuan)  y->enDusukPuan = puan[i];
    }

    if (HAKEMSAYISI > 2){
        float kirpilmisToplam = toplamPuan - (y->enYuksekPuan + y->enDusukPuan);
        y->performans = kirpilmisToplam / (HAKEMSAYISI - 2);
    } 
    else{
        y->performans = toplamPuan / HAKEMSAYISI;
    }
}

void yarismacilariSirala(yarismaci yarismacilar[], int yarismaciSayisi)
{
    yarismaci temp;

    for (int i = 0; i < yarismaciSayisi - 1; i++)
    {
        for (int j = 0; j < yarismaciSayisi - 1 - i; j++)
        {
            yarismaci *a = &yarismacilar[j];
            yarismaci *b = &yarismacilar[j + 1];

            int degistir = 0;

            // Kırpılmış Performans Ortalama
            if (a->performans < b->performans){
                degistir = 1;
            } 
            // Performanslar eşitse En Yüksek Hakem Puanı
            else if (a->performans == b->performans) 
            {
                if (a->enYuksekPuan < b->enYuksekPuan) {
                    degistir = 1;
                } 
                // En yüksek puanlar da eşitse En Düşük Hakem Puanı
                else if (a->enYuksekPuan == b->enYuksekPuan) {
                    if (a->enDusukPuan < b->enDusukPuan) {
                        degistir = 1;
                    }
                }
            }

            if (degistir) 
            {
                temp = yarismacilar[j];
                yarismacilar[j] = yarismacilar[j + 1];
                yarismacilar[j + 1] = temp;
            }
        }
    }
}

void ilkUcYarismaciyiGoster(yarismaci yarismacilar[], int yarismaciSayisi)
{
    int ilkUc = (yarismaciSayisi < 3) ? yarismaciSayisi : 3;

    printf("\n========== TOP %d ==========\n", ilkUc);

    for (int i = 0; i < ilkUc; i++)
    {
        printf("\nRank %d\n", i + 1);
        printf("Competitor ID : %d\n", yarismacilar[i].ID);
        printf("First Name    : %s\n", yarismacilar[i].ad);
        printf("Last Name     : %s\n", yarismacilar[i].soyad);
        printf("Country       : %s\n", yarismacilar[i].ulke);
        printf("Age           : %d\n", yarismacilar[i].yas);
        printf("Performance   : %.2f\n", yarismacilar[i].performans);
    }
}

void sonuclariGoster(yarismaci *y)
{
    printf("Competitor ID : %d\n", y->ID);
    printf("First Name    : %s\n", y->ad);
    printf("Last Name     : %s\n", y->soyad);
    printf("Country       : %s\n", y->ulke);
    printf("Age           : %d\n", y->yas);

    printf("\nJudge Scores\n");
    for (int i = 0; i < HAKEMSAYISI; i++)
    {
        printf("Judge %d:  %.2f\n", i + 1, y->puanlar[i]);
    }
    printf("\nHighest Score : %.2f\n", y->enYuksekPuan);
    printf("Lowest Score  : %.2f\n", y->enDusukPuan);
    printf("Performance   : %.2f\n", y->performans);
}

void tumYarismacilariGoster(yarismaci yarismacilar[], int yarismaciSayisi)
{
    printf("\n========== ALL COMPETITORS ==========\n");

    for (int i = 0; i < yarismaciSayisi; i++)
    {
        printf("\nRank : %d\n", i + 1);
        sonuclariGoster(&yarismacilar[i]);
    }
}

int main()
{
    yarismaci *yarismacilar;
    int yarismaciSayisi;

    do
    {
        printf("Number of competitors: ");

        if (scanf("%d", &yarismaciSayisi) != 1)
        {
            printf("Invalid input!\n");

            while (getchar() != '\n');

            yarismaciSayisi = 0;
            continue;
        }

        if (yarismaciSayisi <= 0)
        {
            printf("Number of competitors must be greater than 0!\n");
        }

    } while (yarismaciSayisi <= 0);

    yarismacilar = (yarismaci *)malloc(yarismaciSayisi * sizeof(yarismaci));

    if (yarismacilar == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < yarismaciSayisi; i++)
    {
        yarismacilar[i].ID = i + 1;

        printf("\n========== Competitor %d ==========\n", i + 1);

        while (getchar() != '\n');

        yarismaciBilgileriAl(&yarismacilar[i]);
        hakemPuanlariAl(&yarismacilar[i]);
        performansHesapla(&yarismacilar[i]);
    }

    yarismacilariSirala(yarismacilar, yarismaciSayisi);
    ilkUcYarismaciyiGoster(yarismacilar, yarismaciSayisi);
    tumYarismacilariGoster(yarismacilar, yarismaciSayisi);
    free(yarismacilar);
    return 0;
}