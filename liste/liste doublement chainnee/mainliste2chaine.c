#include"liste2chaine.h"

int main(void)
{
liste l,LISTE;
    int nbre_element;
    printf("Nbre d'elements de la liste :");
    scanf("%d",&nbre_element);
    LISTE=creer_liste();
    LISTE=remplir_liste_queue(LISTE,nbre_element);
    affiche_liste(LISTE);
    detruir_liste(LISTE);
    /*l=creer_liste();
    l=remplir_liste_tete(l,nbre_element);
    affiche_liste(l);
    detruir_liste(l);*/
    return 0;
}
