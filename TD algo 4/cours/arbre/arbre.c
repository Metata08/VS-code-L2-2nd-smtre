#include"arbre.h"

ArbreNaire creer_noeud(donne d)
{
    ArbreNaire a;
    a = (ArbreNaire)malloc(sizeof(Noeud));
    a->frere = NULL;
    a->enfant = NULL;
    
    a->age = d;
    return a;
}


ArbreNaire saisie_arbre()