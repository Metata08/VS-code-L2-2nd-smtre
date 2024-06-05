#ifndef ARBRE_BIN_H_INCLUDED
#define ARBRE_BIN_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Noeud_bin
{
    int val;
    struct Noeud_bin *sag;
    struct Noeud_bin *sad; 
} Noeud_bin;

typedef Noeud_bin *Arbrebinaire;
Arbrebinaire creer_Noeud(int,Arbrebinaire,Arbrebinaire);

Arbrebinaire insere_Noeud(Arbrebinaire, int);

// Arbrebinaire inserer_noeud_ABR(Arbrebinaire, int);

Arbrebinaire saisie(Arbrebinaire);

void affichage(Arbrebinaire );

Arbrebinaire saisie_AB_equilibre(Arbrebinaire ,int);

void affichage(Arbrebinaire);

void affichage_postfixe(Arbrebinaire);

void affichage_infixe(Arbrebinaire);

void affichage_prefixe(Arbrebinaire);

// int recherche_AB(Arbrebinaire,int);

// void recherche_AB_bis(Arbrebinaire a, int d, int *trouver);

// int recherche_ABR(Arbrebinaire,int);

int max_AB(Arbrebinaire);

int min_AB(Arbrebinaire);

int max_ABR(Arbrebinaire);

int min_ABR(Arbrebinaire);

int nombre_feuille(Arbrebinaire);

int nbre_noeuds_interne(Arbrebinaire);

int profondeur(Arbrebinaire);

Arbrebinaire detruire(Arbrebinaire);

int niveau(Arbrebinaire, int);

#endif //ARBRE_BIN_H_INCLUDED