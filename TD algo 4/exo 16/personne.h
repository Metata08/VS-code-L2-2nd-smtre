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
struct personne* succ;
struct personne* pred;
} Personne;
typedef Personne *p2Personne;
void erreur();
p2Personne creer_personne(pers x);
p2Personne creer_liste_personne();
p2Personne remplir_liste(p2Personne );
p2Personne insert_tete(p2Personne ,pers );
p2Personne insert_queue(p2Personne ,pers );
p2Personne insert_position(p2Personne ,pers ,int);
p2Personne remplir_liste_tete(p2Personne p);
p2Personne remplir_liste_position(p2Personne );
p2Personne remplir_liste_queue(p2Personne);
void affiche_personne(p2Personne );
void affiche_liste_pers(p2Personne );
p2Personne supp_personne(p2Personne );
p2Personne detruir_liste(p2Personne*);
int taille_liste(p2Personne);
p2Personne supprime_tete(p2Personne );
p2Personne supp_personne_pos(p2Personne);
pers creer_pers(pers);
p2Personne inverser_liste(p2Personne);
p2Personne supp_personne_age(p2Personne);
p2Personne supp_personne_pos_bis(p2Personne, int );

#endif // PERSONNE_H_INCLUDED