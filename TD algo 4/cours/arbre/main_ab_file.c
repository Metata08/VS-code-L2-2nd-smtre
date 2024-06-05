#include"file_pile_AB.h"
#include"arbre_bin.h"
#define n 15
int main()
{
    Arbrebin a=NULL;
    File_element f = init_file();

     for (int i = 0; i < n;i++)
    {
        // scanf("%d",&d);
         a = saisie_AB_equilibre(a, i+1);

        // a = inserer_noeud_(a, i+1);
    }
    printf("\n =======================\n");
    affichage_prefixe(a);
    printf("\n =======================\n");

    printf("nivau 1e element pair %d \n", niv_ele_pair(a));

    return 0;
}