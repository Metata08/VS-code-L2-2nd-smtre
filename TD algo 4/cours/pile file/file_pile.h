#ifndef FILE_PILE_H_INCLUDED
#define FILE_PILE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int  donne;
typedef struct cel
{
    donne done ;
    struct cel *suiv;
}maillon;

typedef maillon *liste;

typedef struct
{
    int taille ;
    liste tete,queue;
}File_element ;

typedef struct
{
    int taille ;
    liste sommet;
}Pile_element ;

void erreur();
int estvide(liste);
liste creer_liste();
liste ajout_tete(liste,donne);
liste ajout_milieu_croissant(liste, donne);
liste ajout_queue(liste, donne);
liste creer_maillon(donne);
liste remplir_liste(liste );
liste supprimer_tete(liste );
liste supprimer_queue(liste);
void affiche_maillon(liste);    
void affiche_liste (liste);
liste detruir_maillon(liste);
liste detruir_liste(liste); 
void separe_liste(liste ,liste* ,liste* );
liste separe_liste_bis(liste l, liste *l1);
liste  supprimer_maillon(liste *l);

File_element init_file();

int file_vide(File_element);

liste tete_file(File_element);

File_element enfiler(File_element, donne);

File_element defiler(File_element);

Pile_element init_pile();

int pile_vide(Pile_element);

liste sommet_pile(Pile_element);

Pile_element empiler(Pile_element, donne);

Pile_element desempiler(Pile_element);

File_element tpf(Pile_element);

Pile_element tfp(File_element );

File_element tff(File_element);

Pile_element tpp(Pile_element);


#endif // FILE_H_INCLUDED