#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef float donne;
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
liste remplir_liste(liste,int );
void affiche_maillon(liste);
void affiche_liste (liste);
liste detruir_maillon(liste);
liste detruir_liste(liste); 
void separe_liste(liste ,liste* ,liste* );
liste  separe_liste_bis(liste l, liste *l1);
liste  supprimer_maillon(liste *l);


#endif // LISTE_H_INCLUDED
