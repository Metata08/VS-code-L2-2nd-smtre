#include"liste.h"


void erreur()
{
    puts("Erreur !!! \n");
    exit -1 ;
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

 liste ajout_queue(liste l,donne d)
 {
     liste courant, m = creer_maillon(d);
     if(estvide(l))
         l = m;
    else
    {
        courant = l;
        while(!estvide(courant->suiv))
            courant=courant->suiv;
        courant->suiv = m;
    }
    return l;
 }

 liste ajout_milieu_croissant(liste l,donne d)
{
    liste suivant, courant, m = creer_maillon(d);
    if(estvide(l))
        l=m;
    else
    {
        courant = l;
        suivant = courant->suiv;
        while(!estvide(suivant) && courant->done>d)
        {
            courant = suivant;
            suivant = suivant->suiv;
        }
        if(estvide(suivant))
            suivant=m;
        else
        {
            courant->suiv = m;
            m->suiv = suivant;
        }
        return l;
    }   

}

 liste remplir_liste(liste l,int taille)
 { 
    donne d;
   
    for (int i = 0; i < taille; i++)
    {
        printf("entrer donne : ");
        scanf("%f", &d);
        l = ajout_tete(l, d);
    }
    return l;

 }

 void affiche_maillon(liste m)
 {
    printf(" %.1f ",m->done);
 }

 void affiche_liste(liste l)
 {
    liste q=l;
    printf("liste = ");
    if(estvide(l))
        printf("LISTE VIDE !!!");
    while(!estvide(q))
    {
        affiche_maillon(q);
        q=q->suiv;
    }
    puts("");
 }

liste detruir_maillon(liste l)
 {
    free(l);
    return l;
 }

liste  supprimer_maillon(liste *l,donne d)
 {
     liste c = *l, m;
     liste element;

     while (!estvide(c))
     {
         if (c->done == d)
         {
             m = c;
             c->suiv=m->suiv;
             element=m;
             m = detruir_maillon(m);
         }
    }
    return element ;
 }
 
 liste detruir_liste(liste l)
{
    liste m;
    if(estvide(l))
        printf("LISTE VIDE !!!");
    while(!estvide(l))
    {
        m=l;
        l=l->suiv;
        m=detruir_maillon(m);
    }
    free(l);
    l = NULL;
    return l; 
}

void separe_liste(liste l,liste *l1,liste *l2)
{
    liste c = l;
    while (!estvide(c))
    {
       if(c->done>0)
       {
        *l1=ajout_queue(*l1,c->done);
       }
       else
           *l2 = ajout_queue(*l2,c->done);

        c=c->suiv;
    }
    
}

liste supp_position(liste l, int position)
{
    liste c = l, p, s;
    if(estvide(l))
        erreur();
    for (int i = 1; i < position;i++)
    {
        p = c;
        c = c->suiv;
    }
    s = c->suiv;
    p->suiv = s;
    c = detruir_maillon(c);
    return l;
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

liste separe_liste_bis(liste l,liste *l1)
{
    liste c = l;
    while (!estvide(c))
    {
       if(c->done<0)
       {

           *l1 = ajout_queue(*l1,c->done);
           c = supp_position(c,1);
    }
    return l;
}