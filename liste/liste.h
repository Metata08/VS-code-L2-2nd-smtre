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

typedef struct
{
    int n;
    liste (*f)(liste l, donne d);
}TAB;


void erreur();
int estvide(liste);
liste creer_liste();
liste inserer_tete(liste,donne);
liste inserer_milieu_croissant(liste, donne);
liste inserer_queue(liste, donne);
liste creer_maillon(donne);
liste remplir_liste(liste,int);
void affiche_maillon(liste);
void affiche_liste (liste);
liste detruir_maillon(liste);
liste detruir_liste(liste);
liste supp_tete(liste);
liste supp_queue(liste);
liste supp_position(liste,int);
 int taille_liste(liste l);
 liste inserer_position_actu(liste l,donne d,int pos);


#endif // LISTE_H_INCLUDED
