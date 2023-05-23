#define _CRT_SECURE_NO_WARNINGS

#include  "generer-carte.h"


// Fonction pour m�langer les cartes
// @param : Tableau des 52 cartes cr��es dans l'ordre

void melange(sCarte tableau_cartes[], sCarte tableau_cartes_rand[]) {

  int max = 52, nb_random;
  
  sCarte carte_temp;

  //Initialisation du nb random
  srand(time(NULL));

  for (int i = 0; i < 52; i++)
  {
    //nb random g�n�rer entre 0 et 51 et d�cr�ment� au fur et � mesure
    nb_random = rand() % max;

    //On place la carte tirer au hasard dans le tableau de cartes non tri�es
    tableau_cartes_rand[i] = tableau_cartes[nb_random];

    //On place la derni�re carte du tableau dans une carte temporaire
    carte_temp = tableau_cartes[max-1];

    //Puis on place la carte tir�e au hasard � la fin du tableau pour ne pas la tirer deux fois
    tableau_cartes[max-1] = tableau_cartes[nb_random];

    //On �change de place entre la derni�re carte et la carte tir�e
    tableau_cartes[nb_random] = carte_temp;

    //D�cr�mentation du nombre max pour que le nombre random soit
    max --;
  }
  
}


// Fonction pour g�n�rer les 52 cartes cartes

void generer(sCarte tableau_cartes_rand[]) {

    sCarte carte;
    sCarte tableau_cartes[52];
    char tab_couleur[4] = { 'C','T','P','K' }; // C = carreau, T = trefle, K = coeur, P = pique
    int compt_tab = 0;

    //Boucle sur les couleurs
    for (int i = 0; i < 4; i++)
    {
        //Boucle sur les num�ros (de l'as : 1 au roi : 13)
        for (int y = 1; y < 14; y++)
        {
            carte.couleur = tab_couleur[i];
            carte.numero = y;
            carte.visible = 0;
            carte.numArbre[0] = 0;
            carte.numArbre[1] = 0;
            tableau_cartes[compt_tab] = carte;
            compt_tab++;
        }
    }

    melange(tableau_cartes, tableau_cartes_rand);
}