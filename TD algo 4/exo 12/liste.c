#include"liste.h"
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

 liste remplir_liste(liste l,int *taille)
 {
     donne d;
     char choix;
     *taille = 0;
     do
     {
        printf("entrer donne : ");
        scanf("%d", &d);
        l = ajout_tete(l, d);
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

int test_liste_egale(liste l1,liste l2)
{
    liste p1=l1,p2=l2;
    int resultat=0;

    if(taille_liste(l1)==taille_liste(l2))
    {
        resultat = 1;
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
    }
    

    return resultat;
}

int test_liste_similaire(liste l1,liste l2)
{
    liste p1=l1,p2;
    int resultat=1;
    if(taille_liste(l1)!=taille_liste(l2))
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