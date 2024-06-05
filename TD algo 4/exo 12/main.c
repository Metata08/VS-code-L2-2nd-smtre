#include"liste.h"

int main()
{
    liste l1, l2;
    int taille1, taille2;
    puts("liste n°1");
    l1=creer_liste();
    l1=remplir_liste(l1,&taille1);
    puts("liste n°2");
    l2=creer_liste();
    l2=remplir_liste(l2,&taille2);
    affiche_liste(l1);
    puts("");
    affiche_liste(l2);
    puts("");
    if (test_liste_comparable(l1,taille1,l2,taille2))
    {
        puts("listes comparables ");

    }
    if(test_liste_egale(l1,l2))
    {
        puts("listes egales  ");
    
    }
     if(test_liste_similaire(l1,taille1,l2,taille2))
    {
        puts("listes similaires");
    }

    return 0;
}