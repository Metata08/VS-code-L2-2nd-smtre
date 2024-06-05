#include"liste.h"

int main(void)
{
    liste l;
    int nbre_element;
    printf("Nbre d'elements de la liste :");
    scanf("%d",&nbre_element);
    l =creer_liste();

    l=remplir_liste(l,nbre_element);
    affiche_liste(l);

    // l=supp_tete(l);
    // affiche_liste(l);

    // l= supp_queue(l);
    // affiche_liste(l);

    // l = supp_position(l , 2);
    // affiche_liste(l);
    l = inserer_position_actu(l, 10, 1);
    affiche_liste(l);
    detruir_liste(l);
    return 0;
}
