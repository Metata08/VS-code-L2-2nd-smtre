#ifndef PILE_FILE_H_INCLUDED
#define PILE_FILE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char ch15 [16] ;
typedef struct personne
{
    ch15 nom;
    struct personne* suiv;
} Personne;
typedef Personne * pPersonne;

typedef struct 
{
    pPersonne sommet;
    int taille;
} pilePersonne;

typedef struct
{
    pPersonne tete;
    pPersonne queue;
    int taille;
} filePersonne;


filePersonne init_file();
int file_vide(filePersonne f );
pPersonne tete_file(filePersonne f);
filePersonne enfiler(filePersonne f, ch15 nom);
filePersonne defiler(filePersonne f);
pilePersonne init_pile();
int pile_vide(pilePersonne p);
pPersonne sommet_pile(pilePersonne p);
pilePersonne empiler(pilePersonne p, ch15 d);
void  afficher_Personne(pPersonne);    

pilePersonne desempiler(pilePersonne);
pPersonne detruir_Personne(pPersonne l);
filePersonne tpf(pilePersonne p);
pilePersonne tfp(filePersonne f);
filePersonne tff(filePersonne f);
pilePersonne tpp(pilePersonne p);
int recherche_ele_pile(pilePersonne, ch15);
pilePersonne supp_ele_pos(pilePersonne p, int pos);

#endif //PILE_FILE_H_INCLUDED