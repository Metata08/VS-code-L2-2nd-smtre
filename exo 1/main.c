#include <stdio.h>
#include <stdlib.h>
#include "entreprise.h"


int main(void)
{
    membres_personnels *t;
    int n ,m;
    puts("BIENVENU DANS MON PROGRAMME *_* ");
    fin();
    do
    {
    m=Menu();
        switch(m)
    {
    case 1:
        printf(" Donner le nombre d'employers de l'entreprise :");
        scanf("%d",&n);
        t=creer_tableau(n);
        affiche(t,n);
        fin();
        m=Menu();
        break;

    case 2:
        affiche_ingenieur(t,n);
        fin();
        m=Menu();
        break;
    case 3:
         membre_sup30(t,n);
         fin();
         m=Menu();
         break;
    case 4:
        printf("MASSE SALAIRE = %d\n", masse_sallaire(t,n));
        fin();
        m=Menu();
        break;
    case 5:
         select_femme(t,n);
         fin();
         m=Menu();
         break;

    case 0:
        free(t);
        break;

    default:
        printf("Choix non valide\n");
        m=Menu();
        break;
    }
    
    }while(m!=0 || m>5); 


    return 0;
}
