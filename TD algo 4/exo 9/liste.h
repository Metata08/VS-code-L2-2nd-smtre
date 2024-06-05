#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char  *donne;
typedef struct cel
{
    donne done ;
    struct cel *suiv;
}maillon;
typedef maillon *liste;

void erreur();
liste creer_liste();
int estvide(liste);
liste ajout_tete(liste,donne);
liste ajout_milieu_croissant(liste, donne);
liste ajout_queue(liste, donne);
liste creer_maillon(donne);
liste remplir_liste(liste,int);
void affiche_maillon(liste);
void affiche_liste (liste);
liste detruir_maillon(liste);
liste detruir_liste(liste);
liste supp_tete(liste);
liste supp_queue(liste);
liste supp_position(liste,int);
int annagramme(liste,liste);
int nbr_mots(char *texte);

#endif // LISTE_H_INCLUDED
