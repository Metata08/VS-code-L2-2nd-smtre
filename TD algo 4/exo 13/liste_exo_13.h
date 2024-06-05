#ifndef LISTE_EXO_13_H_INCLUDED
#define LISTE_EXO_13_H_INCLUDED

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
liste inserer_tete(liste,donne);
liste inserer_milieu_croissant(liste, donne);
liste inserer_queue(liste, donne);
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
liste inserer_position_actu(liste, donne);
liste zip(liste );
liste unzip(liste );
liste supp_position_bis(liste l);
liste occ1(liste l,donne d,int *n);
liste occ2(liste l, donne d, int k,int *n);
liste occ3(liste l,donne d,int *n);


#endif // LISTE_EXO_13_H_INCLUDED
