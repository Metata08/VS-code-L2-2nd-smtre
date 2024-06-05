#ifndef ARBRE_BIN_H_INCLUDED
#define ARBRE_BIN_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int donne;

typedef struct noeud
{
    donne age;
    struct noeud *sag;
    struct noeud *sad; 
} Noeud;

typedef Noeud *Arbrebin;

int arbre_vide(Arbrebin a);

Arbrebin creer_noeud_bin(donne,Arbrebin,Arbrebin);

Arbrebin inserer_noeud(Arbrebin, donne);

Arbrebin inserer_noeud_ABR(Arbrebin, donne);

Arbrebin saisie_ABR(Arbrebin);

void affichage(Arbrebin );

Arbrebin saisie_AB_equilibre(Arbrebin ,donne);

void affichage_postfixe(Arbrebin);

void affichage_infixe(Arbrebin);

void affichage_prefixe(Arbrebin);

int recherche_AB(Arbrebin,donne);

void recherche_AB_bis(Arbrebin a, donne d, int *trouver);

int recherche_ABR(Arbrebin,donne);

int max_AB(Arbrebin);

int min_AB(Arbrebin);

int max_ABR(Arbrebin);

int min_ABR(Arbrebin);

int nbre_feuilles(Arbrebin);

int nbre_noeuds_interne(Arbrebin);

int profondeur(Arbrebin);

Arbrebin Liberer(Arbrebin);

int niveau(Arbrebin, donne);

void ParcoursLargeur(Arbrebin);

int simi(Arbrebin A1, Arbrebin A2);

int equilibrer(Arbrebin a);

int ele_sup10(Arbrebin a);

#endif //ARBRE_BIN_H_INCLUDED