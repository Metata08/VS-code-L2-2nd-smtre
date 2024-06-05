#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"
typedef int donne;

typedef struct noeud
{
    donne age;
    struct noeud *frere;
    struct noeud *enfant;
} Noeud;

typedef Noeud *ArbreNaire;
ArbreNaire creer_noeud(donne);
#endif //ARBRE_H_INCLUDED
