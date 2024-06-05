#include"liste_exo_13.h"

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

 liste inserer_milieu_croissant(liste l,donne d)
{
    liste suivant, courant, m = creer_maillon(d);
    if(estvide(l))
        l=m;
    else
    {
        courant = l;
        suivant = courant->suiv;
        if(l->done >d)
            l = inserer_tete(l, d);
        else
        {
             while(!estvide(suivant) && courant->done<d)
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
        }
       
        return l;
    }   

}

 liste remplir_liste(liste l,int *taille)
 {
     donne d;
     char choix;
     *taille = 0;
     do
     {
        printf("entrer donne : ");
        scanf("%d", &d);
        l = inserer_queue(l, d);
        *taille = *taille + 1;
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

liste supp_position_bis(liste l)
{
    liste c = l,pre,suiv;
     pre= c;
     c = c->suiv;
     suiv = c->suiv;
     pre->suiv = suiv;
     c = detruir_maillon(c);
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
    l = NULL;
    return l; 
}

int test_liste_egale(liste l1,liste l2)
{
    liste p1=l1,p2=l2;
    int resultat=1;

    while (!estvide(p1) && !estvide(p2))
    {
        if(p1->done!=p2->done)
         {
                resultat = 0;
            break;
         }
         p1=p1->suiv;
         p2 = p2->suiv;
    }

    return resultat;
}

int test_liste_similaire(liste l1,int taille1,liste l2,int taille2)
{
    liste p1=l1,p2;
    int resultat=1;
    if(taille1!=taille2)
       {
        resultat = 0;
       } 
    else
    {
        while (!estvide(p1) )
         {
            p2=l2;
            while(!estvide(p2) && p1->done!=p2->done)
                p2 = p2->suiv;
            
            if(estvide(p2))
            {
                resultat = 0;
                break;
            }
            else
            p1=p1->suiv;
        }
    } 
    
         while (!estvide(p1) )
         {
            p2=l2;
            while(!estvide(p2) && p1->done!=p2->done)
                p2 = p2->suiv;
            
            if(estvide(p2))
            {
                resultat = 0;
                break;
            }
            else
            p1=p1->suiv;
        }
    return resultat;
}

int test_liste_comparable(liste l1,int taille1,liste l2,int taille2)
{
    liste p1,p2;
    int test=0;
if( taille1>taille2)
{
         p1 = l1;
         while (!estvide(p1))
         {
            p2 = l2;
            while (!estvide(p2))
            {
                if (p2->done == p1->done)
                {
                    test = 1;
                }
                p2 = p2->suiv;
            }

            p1 = p1->suiv;
    }
}
else
{
    p2 = l2;
    while (!estvide(p2))
    {
        p1=l1;
        while(!estvide(p1))
        {
            if(p1->done==p2->done)
            {
                test=1;
            }
            p1 = p1->suiv;
        }

        p2 = p2->suiv;
    }

}
    return test;
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

 liste inserer_position_actu(liste l,donne d)
 {
    liste  m = creer_maillon(d);
    liste  preced=l,cour;


            cour = preced->suiv;
            preced->suiv=m;
            m->suiv = cour;

     return l;
 }

 liste zip(liste l)
 {
     liste c, pre,s,m;
     int n;
     if(estvide(l))
     {
         puts("liste vide ");
         return l;
     }
     else 
     {
         
         if(!estvide(l))
         {
          n=1;
            if(!estvide(l->suiv))
         {
            while(!estvide(l->suiv) && l->done == (l->suiv)->done)
         {
            l = supp_tete(l);
            n++;
         }
         }
         l = inserer_tete(l,n);
         }
         c = l->suiv;
         s=c->suiv;
        while(!estvide(s))
        {
            n = 1;
            while(!estvide(s->suiv) && s->done==(s->suiv)->done)
         {
            c->suiv = s->suiv;
            s = detruir_maillon(s);
            s = c->suiv;
            n++;
         }
         m = creer_maillon(n);
         c->suiv = m;
         m->suiv = s;
         c = s;
         s = s->suiv;
         }
         return l;
     } 
}

liste unzip(liste l)
{
     liste c = l->suiv,temp, s=c->suiv, m;
     int n;
     donne k;
     if(estvide(l))
     {
         puts("liste vide ");
         return l;
     }
     else 
     {
        if(!estvide(l))
        {
         n = l->done;
         k = l->suiv->done;
         if(n==1)
         {
            l = supp_tete(l);
         }
         else
         {
            l = supp_tete(l);
            for (int i = 1; i < n; i++)
            l = inserer_tete(l, k);
         }
         while(!estvide(s))
         {
            n = s->done;
            k = s->suiv->done;
            c->suiv = s->suiv;
            s=detruir_maillon(s);
            s = c->suiv;
            // k = s->done;
            for (int i = 1; i < n;i++)
            {
                m = creer_maillon(s->done);
                c->suiv = m;
                m->suiv = s;
                c = m;
            }
            c = c->suiv;
            s = s->suiv;
         }
        }
        return l;
     }

}

liste occ1(liste l,donne d,int *n)
{
     liste c, s;
     while(!estvide(l) && l->done==d)
         {
            l = supp_tete(l);
            *n = *n + 1;
         }

    if(!estvide(l))
    {
         c = l;
         s = l->suiv;
         while(!estvide(s))
         {
            if(s->done==d && s->suiv->done==d)
            {
                *n = *n + 1;
                c->suiv = s->suiv;
                s = detruir_maillon(s);
                s = c->suiv;
            }
            else
            {
                c=s;
                s = s->suiv;
            }
         }
    }
    return l;
}

liste occ2(liste l, donne d, int k,int *n)
{
    liste c,p;
    if(estvide(l))
         return l;
    else
    {
         int i = 0;
         c = l;
         p = NULL;
         while(!estvide(c) && i<k)
         {
            if(c->done==d)
              {
                i++;
                *n = *n + 1;
              }  
            p = c;
            c = c->suiv;
         }
        if(!estvide(p))
            p->suiv = occ1(c, d,n);
        else
            c = occ1(c, d, n);
        return l;
    }

}

liste occ3(liste l,donne d,int *n)
{
    return occ2(l, d, 1,n);
}