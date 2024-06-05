#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char ch15 [16] ;
typedef struct 
{
    ch15 matr, nom, prenom;
    int ages ;
}pers;

typedef struct personne {
ch15 matr, nom, prenom;
int age ;
struct personne *suiv;
} Personne;
typedef Personne *pPersonne;
void erreur();
pPersonne creer_personne(pers x);
pPersonne creer_liste_personne();
pPersonne inserer_tete(pPersonne ,pers );
pPersonne inserer_queue(pPersonne ,pers );
pPersonne inserer_position(pPersonne ,pers ,int);
pPersonne inserer_position_name(pPersonne, pers );
pPersonne remplir_liste_tete(pPersonne p);
pPersonne remplir_liste_position(pPersonne );
pPersonne remplir_liste_queue(pPersonne);
void affiche_personne(pPersonne );
void affiche_liste_pers(pPersonne );
pPersonne supp_personne(pPersonne );
pPersonne detruir_liste(pPersonne*);
int taille_liste(pPersonne);
pers creer_pers(pers);
int recherche(pPersonne, ch15);
pPersonne remplir_liste_position_name(pPersonne,int);
pPersonne fusion_liste_personne(pPersonne, pPersonne);
pPersonne supprime_tete(pPersonne);
pPersonne supp_personne_age(pPersonne, int);
pPersonne supp_personne_age_bis(pPersonne,int );

#endif // PERSONNE_H_INCLUDED