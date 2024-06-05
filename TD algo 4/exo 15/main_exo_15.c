#include"personne.h"

int main(void)
{
    pPersonne p, p1, p2, p3;
    int age, taille, taille1, taille2;
    p = creer_liste_personne();
    printf("donner la taille :");
    scanf("%d", &taille);
    p = remplir_liste_position_name(p,taille);
    affiche_liste_pers(p);
    printf("Donner l\'age de suppression :");
    scanf("%d", &age);
    printf("Supprimer les personnes agees de %d \n",age);
    p = supp_personne_age_bis(p,age);
    affiche_liste_pers(p);
    puts("Fusionner deux listes de PERSONNE \n");
    printf(" Remplir liste n°1 \n");
    p1=creer_liste_personne();
     printf("donner la taille :");
    scanf("%d", &taille1);
    p1 = remplir_liste_position_name(p1,taille1);
    affiche_liste_pers(p1);
    printf(" Remplir liste n°2 \n");
    p2=creer_liste_personne();
     printf("donner la taille :");
    scanf("%d", &taille2);
    p2 = remplir_liste_position_name(p2,taille2);
    affiche_liste_pers(p2);
    puts("Apres fusion des listes \n");
    p3=creer_liste_personne();
    p3 = fusion_liste_personne(p1, p2);
    affiche_liste_pers(p3);
    p = detruir_liste(&p);
    p1 = detruir_liste(&p1);
    p2 = detruir_liste(&p2);
    p3 = detruir_liste(&p3);
    return 0;
}


