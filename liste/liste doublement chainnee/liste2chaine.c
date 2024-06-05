#include"liste2chaine.h"

void erreur()
{
    puts("Erreur !!! \n");
    exit -1;
}

int estvide(liste l)
{
    return (l==NULL);
}

liste creer_liste()
{
    return NULL;
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

liste ajout_queue(liste l,typeElement donne)
{
    liste m = creer_maillon(donne);
    liste courant;
    if(estvide(l))
        l = m;
    else
    {
        courant=l;
        while (!estvide(courant->suiv))
        {
            courant = courant->suiv;
        }
        m->preced = courant;
        courant->suiv = m;   
    }
    return l;
}

liste remplir_liste_tete(liste l, int n)
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

liste remplir_liste_queue(liste l, int n)
{
    typeElement donne;
    for (int i = 0; i < n;i++)
    {
        printf("Entre Donne :");
        scanf("%d",&donne);
        l = ajout_queue(l,donne);
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
     liste m;
     if(estvide(l))
        puts("LISTE VIDE !!!");
     while (!estvide(l))
     {
         m = l;
         l = l->suiv;
         m = detruir_maillon(m);
    }
    free(l);
    return l;
 }

liste detruir_maillon(liste l)
{
    free(l);
    return l;
}