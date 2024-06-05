#ifndef ENTREPRISE_H_INCLUDED
#define ENTREPRISE_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
 {
 	char nom[50];
 	char prenom[70];
 	char metier[30] ;
 	char sexe[1];
 	int salaire ;
 	int nbre_annees ;

 }membres_personnels;

 int Menu();
 void fin();
 membres_personnels* creer_tableau(int n);
 void affiche_pesonnel(membres_personnels e);
 void affiche(membres_personnels *tab,int n);
 void membre_sup30(membres_personnels *tab,int n);
 void affiche_fem_secretaire(membres_personnels *tab,int n);
int masse_sallaire(membres_personnels *tab,int n);
void affiche_ingenieur(membres_personnels *tab,int n);
void select_femme(membres_personnels *tab,int n);
#endif // ENTREPRISE_H_INCLUDED
