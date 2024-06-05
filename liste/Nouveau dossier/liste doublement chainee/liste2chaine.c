#include"liste2chaine.h"

void erreur()
{
    puts("Erreur !!! \n");
    EXIT_SUCCESS;
}

int estvide(liste l)
{
    return (l==NULL);
}

liste creer_liste()
{
    return NULL;
}

liste ajout_tete(liste l,typeElement donne)
{
    liste m=creer_maillon(donne);
    if(estvide(l))
        l= m;
    else
    {
        l->preced=m;
        m->suiv = l;
        l=m;
    }
    return l;
}
liste creer_maillon(typeElement donne)
{
    liste m=(liste)malloc(sizeof(maillon));
    if(estvide(m))
        erreur();
    m->donne=donne;
    m->preced=NULL;
    m->suiv = NULL;
    return m;
}
liste remplir_liste(liste l,int n )
{
    typeElement donne;
    for (int i = 0; i < n;i++)
    {
        printf("Entre Donne :");
        scanf("%d",&donne);
        l = ajout_tete(l,donne);
    }
    return l;
}
void affiche_maillon(liste m)
{
    printf(" %d ", m->donne);

}
void affiche_liste (liste l)
{
    liste q = l;
    if(estvide(l))
        puts("LISTE VIDE !!!");
    else
    {
        printf("liste = ");
        while (!estvide(q))
        {
            affiche_maillon(q);
            q = q->suiv;
        }
    }


}
liste detruir_liste(liste l)
 {
    while(!estvide(l))
    {
        l=detruir_maillon(l);
    }

    return l;
 }

liste detruir_maillon(liste l)
{
    liste q;
    q=l;
    free(l->preced);
    l=l->suiv;
    free(q);
    return l;
}
