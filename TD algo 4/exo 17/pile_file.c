#include"pile_file.h"

void erreur()
{
    puts("Erreur !!! \n");
    EXIT_FAILURE ;
}

int estvide(pPersonne l)
{
    return (l==NULL);
}

pPersonne creer_pPersonne ()
{
    return NULL;
}

pPersonne creer_Personne(ch15 d)
 {
    pPersonne m=(pPersonne )malloc(sizeof(Personne));
    if(estvide(m))
        erreur();
   strcpy(m->nom,d) ;
    m->suiv=NULL;
    return m;
 }

 pPersonne ajout_tete(pPersonne l,ch15 d)
 {
    pPersonne m=creer_Personne(d);
    if(estvide(l))
    l=m;
    else
    {
        m->suiv=l;
        l=m;
    }
    return l;

 }

 pPersonne ajout_queue(pPersonne l,ch15 d)
 {
     pPersonne courant, m = creer_Personne(d);
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

 pPersonne remplir_pPersonne (pPersonne l)
 {
     ch15 d;
     char choix;
     do
     {
        printf("entrer ch15 : ");
        scanf("%d", &d);
        l = ajout_tete(l, d);
        puts("Pour continuer appuyez sur 'O' sinon 'N'");
        getchar();
        scanf("%c",&choix);
     } while (choix!='n');

     return l;

 }

 pPersonne supprimer_tete(pPersonne l)
 {
    pPersonne c=l;
    if(!estvide(l))
    {
        l = l->suiv;
        c = detruir_Personne(c);
    }
    return l;
 }

 pPersonne supprimer_queue(pPersonne l)
 {
     pPersonne c = l;
     if(!estvide(c->suiv))
     {
         c = c->suiv;
     }
     c = detruir_Personne(c);
     return l;
 }


 void afficher_Personne(pPersonne m)
 {
    printf(" %s ",m->nom);
 }

 void affiche_pPersonne (pPersonne l)
 {
    pPersonne q=l;
    printf("pPersonne = ");
    while(!estvide(q))
    {
        afficher_Personne(q);
        q=q->suiv;
    }

 }

pPersonne detruir_Personne(pPersonne l)
 {
    l->suiv = NULL;
    free(l);
    l = NULL;
    return l;
 }

 pPersonne detruir_pPersonne (pPersonne l)
{
    pPersonne m;
    if(estvide(l))
        puts("pPersonne VIDE !!!");
    while(!estvide(l))
    {
        m=l;
        l=l->suiv;
        m=detruir_Personne(m);
    }
    return l;
}

filePersonne init_file()
{
    filePersonne f;
    f.taille = 0;
    f.queue=f.tete=NULL;
    return f;
}


int file_vide(filePersonne f )
{
    return (f.taille == 0);
}

pPersonne tete_file(filePersonne f)
{
    return f.tete ;
}

filePersonne enfiler(filePersonne f, ch15 nom)
{
    if(file_vide(f))
        f.queue = f.tete = ajout_tete(f.tete, nom);
    else
       {
             f.queue = ajout_queue(f.queue, nom);
             f.queue = f.queue->suiv;
       }
    f.taille++;
    return f;
}

filePersonne defiler(filePersonne f)
{
    if(file_vide(f))
        return f;
    else 
    {
        f.tete=supprimer_tete(f.tete);
        if(estvide(f.tete))
            f.queue=NULL;
       
    }
     f.taille--;
     return f;
     
}

pilePersonne init_pile()
{
    pilePersonne p;
    p.sommet = NULL;
    p.taille = 0;
    return p;
}

int pile_vide(pilePersonne p)
{
    return(p.taille==0);

}

pPersonne sommet_pile(pilePersonne p)
{
    return p.sommet;
}

pilePersonne empiler(pilePersonne p, ch15 d)
{
    p.sommet = ajout_tete(p.sommet, d);
    p.taille++;
    return p;
}

void affiche_Personne(pPersonne m)
 {
    printf(" %d ",m->nom);
 }
pilePersonne desempiler(pilePersonne p)
{
    if(pile_vide(p))
        return p;
    else
    {
        p.sommet = supprimer_tete(p.sommet);
        p.taille --;
        return p;

    }
}

filePersonne tpf(pilePersonne p)
{
    filePersonne f = init_file();
    while (!pile_vide(p))
    {
        f = enfiler(f, p.sommet->nom);
        p=desempiler(p);
    }
    return f;
}
pilePersonne tfp(filePersonne f)
{
    pilePersonne p = init_pile();
    while (!file_vide(f))
    {
        p = empiler(p, f.tete->nom);
        f = defiler(f);
    }
    return p;
}

filePersonne tff(filePersonne f)
{
    filePersonne f1=init_file();
    while (!file_vide(f))
    {
        f1 = enfiler(f1, f.tete->nom);
        f = defiler(f);
    }
    return f1;
}

pilePersonne tpp(pilePersonne p)
{
    pilePersonne p1 = init_pile();
    while (!pile_vide(p))
    {
        p1 = empiler(p1, p.sommet->nom);
        p = desempiler(p);

    }
    return p1;
}

pilePersonne recherche_ele_pile(pilePersonne p, ch15 nom,int *n)
{
    pilePersonne temp_pile = init_pile();
    *n = 0;
    if(pile_vide(p))
     {
        puts("la pile est vide ");
     }
     else
     {
        while(!pile_vide(p) && strcmpi(sommet_pile(p)->nom,nom)!=0 )
           {
            *n=*n+1;
            temp_pile = empiler(temp_pile, sommet_pile(p)->nom);
            p = desempiler(p);
           } 

        if(pile_vide(p))
            *n = -1;

        while(!pile_vide(temp_pile))
        {
            p=empiler(p, sommet_pile(temp_pile)->nom);
            temp_pile = desempiler(temp_pile);
        }
        
     }
     return p;
}


pilePersonne supp_ele_pos(pilePersonne p, int pos)
{
     pilePersonne buffer=init_pile();
     if(p.taille>=pos)
     {
        int i =0;
        while (i!=pos)
        {
            buffer=empiler(buffer,p.sommet->nom);
            p = desempiler(p);
            i++;
        }
        buffer = desempiler(buffer);
        while(!pile_vide(buffer))
        {
            p=empiler(p,buffer.sommet->nom);
            buffer = desempiler(buffer);
        }

     }

     return p;
}