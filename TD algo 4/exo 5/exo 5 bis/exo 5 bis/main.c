#include"liste.h"

int main(void)
{
    donne d;
    int taille=0;
    liste l,gauche ,droite;
    l=creer_liste();
    l=remplir_liste(l,&taille);
    affiche_liste(l);
    l=tri(l,taille);
    //  gauche=creer_liste();
    //  droite=creer_liste();
    //  printf(" \n positionner en donnant la valeur a gauche = ");
    //  scanf("%d", &d);
    //  gauche = recherche(l,d);
    //  printf("\n positionner en donnant la valeur a droite = ");
    //  scanf("%d", &d);
    //  droite =recherche(l,d);
    //  puts("\n AFFICHAGE AVANT ECHANGE ");
    // affiche_liste(l);

    //  affiche_liste(gauche);
    //  affiche_liste(droite);



    puts(" \n AFFICHAGE APRES ECHANGE ");
    //  affiche_liste(gauche);
    //  affiche_liste(droite);
     affiche_liste(l);

    //  free(gauche);
    //  free(droite);
     detruir_liste(l);


     return 0;
}
