#include"liste.h"

int main(void)
{
    int n=3;
    liste l,l1,l2;
    l=creer_liste();
    l=remplir_liste(l,n);
    affiche_liste(l);
    l1 = creer_liste();
   // l2 = creer_liste();
    l=separe_liste_bis(l, &l1);
    affiche_liste(l);
    affiche_liste(l1);
    //detruir_liste(l);
    //detruir_liste(l1);
    //detruir_liste(l2);
    return 0;
}
