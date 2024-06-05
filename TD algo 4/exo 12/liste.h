#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
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
liste ajout_milieu_croissant(liste, donne);
liste ajout_queue(liste, donne);
liste creer_maillon(donne);
liste remplir_liste(liste,int*);
void affiche_maillon(liste);
void affiche_liste (liste);
liste detruir_maillon(liste);
liste detruir_liste(liste);
liste supp_tete(liste);
liste supp_queue(liste);
liste supp_position(liste,int);
int test_liste_egale(liste,liste);
int test_liste_similaire(liste,int,liste,int);
int test_liste_comparable(liste,int,liste,int);
int taille_liste(liste );
liste inserer_position_actu(liste, donne , int );
liste zip(liste );

#endif // LISTE_H_INCLUDED
