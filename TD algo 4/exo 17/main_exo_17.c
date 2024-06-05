#include"pile_file.h"
#define n 5

int main(void)
{

    pilePersonne p = init_pile(),p1;
    int pos, position;
    ch15 nom;
    printf(" \n ====================== \n");
    puts("Remplir pile : \n");
    for (int i = 0;i<n;i++)
    {
        scanf("%s", nom); 
        p = empiler(p, nom);
    }
    // p1 = tpp(p);
     printf("Rchercher un element dans la pile \n");
    printf("Donner le nom de l'element \n");
    scanf("%s",nom);
    p = recherche_ele_pile(p, nom, &position);
    if(position==-1)
        printf("Element NON EXISTANT \n");
    else
        printf("Element EXISTANT et POSITION = %d \n",position);
    // printf("supprimer position :");
    // scanf("%d", &pos);
    // p = supp_ele_pos(p, pos);
    
    // while(!pile_vide(p))
    // {
    //     afficher_Personne(sommet_pile(p));
    //     p = desempiler(p);
    // }
    // printf(" \n ====================== \n");

    // while(!pile_vide(p1))
    // {
    //     affiche_Personne(sommet_pile(p1));
    //     p1= desempiler(p1);
    // }
   
        
    return 0;
}