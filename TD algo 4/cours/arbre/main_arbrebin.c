#include"arbre_bin.h"
#define n 10
int main()
{
    Arbrebin a = NULL, b = NULL;
    // donne d;
    for (int i = 0; i < n;i++)
    {
        // scanf("%d",&d);
         a = saisie_AB_equilibre(a, i+1);

        // a = inserer_noeud_(a, i+1);
    }
    // for (int i = 0; i < n;i++)
    // {
    //     // scanf("%d",&d);
    //     //  b = saisie_AB_equilibre(b, i+1);

    //     b = inserer_noeud(b, i+1);
    // }
    //  a = saisie_ABR(a);
    // printf("\n =======================\n");
    // ParcoursLargeur(a);
    printf("\n =======================\n");
    affichage_prefixe(a);
    printf("\n =======================\n");
    //  printf("\n =======================\n");
    // affichage_prefixe(b);
    // printf("\n =======================\n");
    
    // // affichage_infixe(a);
    // printf("\n =======================\n");
    // affichage_postfixe(a);
    // int rec;
//    int  t=0;
    // printf("Recherche un element dans un arbre \n ");
    // scanf("%d", &rec);
    // recherche_AB_bis(a, rec, &t);
    // if(t==1)
    //     printf("ELEMENT TROUVER *_*");
    // else
    //     printf("ELEMENT NON TROUVER  !!!");

    // printf("Recherche un element dans un arbre \n ");
    // scanf("%d", &rec);
    
    // if(recherche_AB(a, rec))
    //     printf("ELEMENT TROUVER *_*");
    // else
    //     printf("ELEMENT NON TROUVER  !!!");

    // int rec;
    // printf("Recherche un element dans un arbre \n ");
    // scanf("%d", &rec);
    // if(recherche_ABR(a,rec)==1)
    //     printf("ELEMENT TROUVER *_* \n");
    // else
    //     printf("ELEMENT NON TROUVER  !!! \n");
    //  printf("max_AB = %d \n", max_AB(a));
    //  printf("min_AB = %d \n", min_AB(a));

    // printf("max_ABR = %d \n", max_ABR(a));
    // printf("min_ABR = %d \n", min_ABR(a));

    // printf(" nbre_feuilles = %d \n", nbre_feuilles(a));
     printf(" nbre_noeuds = %d \n", nbre_noeuds_interne(a));

    //  printf(" profondeur = %d \n", profondeur(a));
    //  Liberer(&a);
    // printf("Donner l'elmt a chercher le niveau :");
    int element;
    scanf("%d", &element);
    printf("l'elmt %d est au niveau %d \n", element,niveau(a,element));

    // if (simi(a,b))
    //      printf("arbre simillaire  \n");

    // if(equilibrer(a)==1)
    //      printf("Arbre equilibre \n");

    // printf("Nbre elements sup 10 de l'arbre est : %d \n", ele_sup10(a));

    return 0;
}