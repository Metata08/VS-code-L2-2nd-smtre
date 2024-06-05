
#include"liste.h"

void erreur()
{
    puts("Erreur !!! \n");
    EXIT_FAILURE ;
}

int estvide(liste l)
{
    return (l==NULL);
}

liste creer_liste()
{
    return NULL;
}

liste creer_maillon(donne d)
 {
    liste m=(liste)malloc(sizeof(maillon));
    if(estvide(m))
        erreur();
    m->done= d;
    m->suiv=NULL;
    return m;
 }

 liste ajout_tete(liste l,donne d)
 {
    liste m=creer_maillon(d);
    if(estvide(l))
    l=m;
    else
    {
        m->suiv=l;
        l=m;
    }
    return l;

 }
 liste remplir_liste(liste l)
 {
     donne d;
     char choix;
     do
     {
        printf("entrer donne : ");
        scanf("%d", &d);
        l = ajout_tete(l, d);
        puts("Pour continuer appuyez sur 'O' sinon 'N'");
        getchar();
        scanf("%c",&choix);
     } while (choix!='n');

     return l;

 }

 void affiche_maillon(liste m)
 {
    printf(" %d ",m->done);
 }

 void affiche_liste(liste l)
 {
    liste q=l;
    printf("liste = ");
    while(!estvide(q))
    {
        affiche_maillon(q);
        q=q->suiv;
    }

 }

liste detruir_maillon(liste l)
 {
    free(l);
    l=NULL;
    return l;
 }

 liste detruir_liste(liste l)
{
    liste m;
    if(estvide(l))
        puts("LISTE VIDE !!!");
    while(!estvide(l))
    {
        m=l;
        l=l->suiv;
        m=detruir_maillon(m);
    }
    return l;
}
