#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


struct carte {
    char couleur;   // 'C','T','K','P'
    int numero;  // de 1 � 13
    int visible; // 1 pour visible 0 pour cach�
    int numArbre[2]; // contient le num�ro de l�arbre dans laquelle est la carte
};
typedef struct carte sCarte;

void generer(sCarte tableau_cartes_rand[]);
void melange(sCarte tableau_cartes[], sCarte tableau_cartes_rand[]);