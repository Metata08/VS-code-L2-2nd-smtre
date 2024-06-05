#include"personne.h"

int main(void)
{
    pPersonne p;
    ch15 mat;
    int pos;

    p = creer_liste_personne();
    p = remplir_liste_queue(p);
    affiche_liste_pers(p);
    puts(" RECHERCHER une PERSONNE par son MATRICULE ");
    printf("MATRICULE = ");
    getchar();
    gets(mat);
    pos = recherche(p, mat);
    if(pos!=0)
        printf("PERSONNE de matricule %s est a la positionn %d \n", mat, pos);
    else
        printf("PERSONNE non trouvee \n");

    printf("la taille de la liste est de %d \n", taille_liste(p));

    return 0;
}