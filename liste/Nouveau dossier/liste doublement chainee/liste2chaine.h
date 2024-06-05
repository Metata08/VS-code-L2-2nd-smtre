#ifndef LISTE2CHAINE_H_INCLUDED
#define LISTE2CHAINE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int typeElement ;
typedef struct cel
{
    typeElement donne;
    struct cel *suiv;
    struct cel *preced;
}maillon;

typedef maillon *liste;
void erreur();
int estvide(liste);
liste creer_liste();
liste ajout_tete(liste,typeElement );
liste creer_maillon(typeElement);
liste remplir_liste(liste,int );
void affiche_maillon(liste);
void affiche_liste (liste);
liste detruir_maillon(liste);
liste detruir_liste(liste);

#endif // LISTE2CHAINE_H_INCLUDED
