
#include "entreprise.h"


int Menu()
{
    int choix;
    printf(" Veuillez saisir un chiffre pour : \n");
    puts("\t 1- Creer votre liste d'employers ");
    puts("\t 2- Afficher les ingenieur de votre entreprise");
    puts("\t 3- Afficher les membres dont la salaire est > a 300000");
    puts("\t 4- MASSE SALAIRE de l'entreprise");
    puts("\t 5- Affiche: le(s)  femme(s) ingenieur(s) dont le nbre d'experience depasse 5 ANS ");
    puts("\t 0- QUITTER le programme");
    printf("CHOIX :");
    scanf("%d",&choix);
    return choix ;
}

membres_personnels* creer_tableau(int n)
{
   membres_personnels  *tab;
    tab=(membres_personnels*)malloc(n*sizeof(membres_personnels));
    puts(" entrer les employes de l'entreprise ");
    for(int i=0;i<n;i++)
    {
        printf("Donner le prenom et le nom de l'empoyer %d :",i+1);
        scanf("%s%s",tab[i].prenom,tab[i].nom);
        printf("SEXE :");
        scanf("%s",tab[i].sexe);
        while(strcmp(tab[i].sexe,"h")!=0 && strcmp(tab[i].sexe,"f")!=0)
        {
            printf("\a ERREUR \n ENTRER SEXE(H(Homme),F(Femme)) :");
            scanf("%s",tab[i].sexe);
        }

    printf("Donner le metier de l'employer :");
    scanf("%s",tab[i].metier)   ;
    printf("Donner le nombre d'annees que l'employer a fait sur l'entreprise :");
    scanf("%d",&tab[i].nbre_annees);
    while(tab[i].nbre_annees<0 || tab[i].nbre_annees>50 )
    {
        printf(" \a ERREUR \n le nombre d'annees SVP :");
         scanf("%d",&tab[i].nbre_annees);
    }
    printf("Donner la salaire :");
    scanf("%d",&tab[i].salaire);
     while(tab[i].salaire<0 )
    {
        printf(" \a ERREUR CET SALAIRE N'EXISTE PAS \n Entrer un SALAIRE NORMAL SVP :");
         scanf("%d",&tab[i].salaire);
    }

}


    return tab;
}

void affiche_pesonnel(membres_personnels tab)
{
    printf("%25s %.30s \t%s\t %.d \t %.15s\t %.d \n",tab.prenom,tab.nom,tab.sexe,tab.nbre_annees,tab.metier,tab.salaire);
}

void affiche(membres_personnels *tab,int n)
{
    printf("================================================================  \n");
    puts("AFFICHAGE DU TABLEAU D'EMPLOYER \n");
    for(int i=0;i<n;i++)
    {
       affiche_pesonnel(tab[i]) ;
    }
}

void membre_sup30(membres_personnels *tab,int n)
{
    puts(" MEMBRES DONT LE SALAIRE EST > a 300.000 \n");
    int test = 0;
    for (int i = 0; i < n; i++)
    {
       if (tab[i].salaire > 300000)
       {
         affiche_pesonnel(tab[i]);
         test = 1;
       }
  }
  if(test==0)
       printf("LISTE VIDE !!! \n");

}

void affiche_fem_secretaire(membres_personnels *tab,int n)
{
    int test=0;
    printf("================================================================  \n");
    puts(" FEMMES DE METIER SECRETAIRE : \n ");
     for(int i=0;i<n;i++)
  {
      if(strcmp(tab[i].sexe,"f" )==0 && strcmp(tab[i].metier,"secretaire")==0)
         {
                   affiche_pesonnel(tab[i]) ;
                   test=1;
         }

  }
  if(test==0)
    printf(" PAS DE FEMME SECRETAIRE \n");

}

void affiche_ingenieur(membres_personnels *tab,int n)
{
    int test=0;
    printf("================================================================  \n");
    puts(" LES INGENIEURS DE L'ENTREPRISE: ");
     for(int i=0;i<n;i++)
  {
      if(strcmp(tab[i].metier,"ingenieur")==0)
      {
          affiche_pesonnel(tab[i]) ;
          test=1;
      }

  }
  if(test==0)
    printf(" PAS D'INGENIEUR\n");

}


int masse_sallaire(membres_personnels *tab,int n)
{
    int masse=0;

    for(int i=0;i<n;i++)
    {
        masse+=tab[i].salaire ;

    }
    return masse ;

}

void select_femme(membres_personnels *tab,int n)
{
    int a=0;
    puts(" le(s)  femme(s) ingenieur(s) dont le nbre d'experience depasse 5 ANS  ");
    for(int i=0;i<n;i++)
    {
                if(strcmp(tab[i].sexe,"f")==0 && strcmp(tab[i].metier,"ingenieur")==0 && tab[i].nbre_annees>5)
                {
                    printf("\t %s %.20s \n",tab[i].prenom,tab[i].nom);
                    a=1;
                }
    }
    if(0==a)
    puts("Il n'existe pas de FEMME ingenieur dont le nbre d'experience depasse 5 ANS  " );
}

void fin()
{
    puts("================================================================");
    puts("================================================================");
}
