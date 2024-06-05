#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef int donne;
typedef struct cel
{
    donne done ;
    struct cel *suiv;
}maillon;
typedef maillon *liste;
void erreur();
int estvide(liste);
liste creer_liste();
liste ajout_tete(liste,donne);
liste remplir_liste(liste);
void affiche_maillon(liste);
void affiche_liste (liste);
liste detruir_maillon(liste);
liste detruir_liste(liste);



#endif // LISTE_H_INCLUDED
