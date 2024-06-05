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

 liste inserer_queue(liste l,donne d)
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

 int taille_liste(liste l)
 {
    int n;
    liste c = l;
    if(estvide(l))
        n = 0;
    else if(estvide(l->suiv))
        n=1;
    else
    {
        n = 1;
        while(!estvide(c))
        {
            n++;
            c = c->suiv;
        }
    }
    return n;
  }

 liste inserer_position_actu(liste l,donne d,int pos)
 {
    liste suivant, m = creer_maillon(d);
    liste  preced=l,cour;
    if(pos==1)
        l = inserer_tete(l, d);
    else
     {
        if (pos < taille_liste(l))
        {
            for (int i = 2; i < pos; i++)
                preced = preced->suiv;

            cour = preced->suiv;
            preced->suiv=m;
            m->suiv = cour;
        }
        else
        {
            l = inserer_queue(l, d);
        }
            
     }
     return l;
 }

 liste inserer_milieu_croissant(liste l,donne d)
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
        scanf("%d", &d);
        l = inserer_tete(l, d);
    }
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
liste supp_queue(liste l)
{
    liste c = l, k;
    if(estvide(l))
        erreur();
    while(!estvide(c->suiv))
    {
        k = c;
        c=c->suiv;
    }

    k->suiv = NULL;
    c = detruir_maillon(c);
   
    return l;
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


liste detruir_maillon(liste l)
 {
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
    l = NULL;
    return l; 
}


