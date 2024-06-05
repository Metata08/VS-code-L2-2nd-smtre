#include"liste2chaine.h"

int main(void)
{
    liste l;
    int nbre_element;
    printf("Nbre d'elements de la liste :");
    scanf("%d",&nbre_element);
    l=creer_liste();
    l=remplir_liste(l,nbre_element);
    affiche_liste(l);
    detruir_liste(l);
    affiche_liste(l);
    return 0;
}
