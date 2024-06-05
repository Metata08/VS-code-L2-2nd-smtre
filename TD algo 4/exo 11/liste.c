
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

 liste inserer_tete(liste l,donne d)
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
        l = inserer_tete(l, d);
        puts("Pour continuer appuyez sur 'ENTER <J' sinon 'N'");
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
    if (estvide(l))
    {
        puts("Liste vide !!!");
    }
    
    while(!estvide(q))
    {
        affiche_maillon(q);
        q=q->suiv;
    }

 }

 liste supp_tete(liste l)
{
    liste c = l;
    if(!estvide(l))
    {
        l = l->suiv;
        c=detruir_maillon(c);
    }
    return l;
}

liste detruir_maillon(liste l)
 {
    l->suiv = NULL;
    free(l);
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

liste supp_aternative(liste l)
{
    liste courant ,suivant,t;
    int n;
    l = supp_tete(l);// la suppression a la tete d'abord
    n=1;
    courant = l;
    suivant = l->suiv;
    while (!estvide(courant->suiv))
    {
        n++;
        if((n%2)==0)// j'utilise le modulo d'une division pour savoir si l'elmt doit etre supp ou pas 
        {
            courant->suiv = suivant->suiv;
            t = suivant;
            suivant = courant->suiv;
            t = detruir_maillon(t);
        }
        else
        {
             courant = suivant;
             suivant = suivant->suiv;
        }
       
    }
    return l;
}


liste supp_ele_impair(liste l)
{
    liste courant, suivant, t;
    while (!estvide(l) && l->done%2!=0) // je m'occupe d'abord de la tete liste 
    {
        l = supp_tete(l);
    }
    courant = l;
    suivant = l->suiv;
    while (!estvide(courant->suiv))
    {
        if(courant->suiv->done%2!=0) //je commence a tester a partir du second maillon de la liste car la tete est deja paire 
        {
            courant->suiv = suivant->suiv;
            t = suivant;
            suivant = courant->suiv;
            t = detruir_maillon(t);
        }
        else
        {
             courant = suivant;
             suivant = suivant->suiv;
        }
       
    }
    return l;
}

