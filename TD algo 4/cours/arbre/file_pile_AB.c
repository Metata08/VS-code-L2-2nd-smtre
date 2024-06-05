
#include"file_pile_AB.h"

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

liste creer_maillon(Arbrebin d)
 {
    liste m=(liste)malloc(sizeof(maillon));
    if(estvide(m))
        erreur();
    m->done= d;
    m->suiv=NULL;
    return m;
 }

 liste ajout_tete(liste l,Arbrebin d)
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

 liste ajout_queue(liste l,Arbrebin d)
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

 liste remplir_liste(liste l)
 {
     Arbrebin d;
     char choix;
     do
     {
        printf("entrer Arbrebin : ");
        scanf("%d", &d);
        l = ajout_tete(l, d);
        puts("Pour continuer appuyez sur 'O' sinon 'N'");
        getchar();
        scanf("%c",&choix);
     } while (choix!='n');

     return l;

 }

 liste supprimer_tete(liste l)
 {
    liste c=l;
    if(!estvide(l))
    {
        l = l->suiv;
        c = detruir_maillon(c);
    }
    return l;
 }

 liste supprimer_queue(liste l)
 {
     liste c = l;
     while(!estvide(c->suiv))
     {
         c = c->suiv;
     }
     c = detruir_maillon(c);
     return l;
 }


 void affiche_maillon(liste m)
 {
    printf(" %d ",m->done->age);
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


File_element init_file()
{
    File_element f;
    f.taille = 0;
    f.queue=f.tete=NULL;
    return f;
}


int file_vide(File_element f )
{
    return (f.taille == 0);
}

liste tete_file(File_element f)
{
    return f.tete ;
}

File_element enfiler(File_element f, Arbrebin d)
{
    if(file_vide(f))
        f.queue = f.tete = ajout_tete(f.tete, d);
    else
       {
             f.queue = ajout_queue(f.queue, d);
             f.queue = f.queue->suiv;
       }
    f.taille++;
    return f;
}

File_element defiler(File_element f)
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

Pile_element init_pile()
{
    Pile_element p;
    p.sommet = NULL;
    p.taille = 0;
    return p;
}

int pile_vide(Pile_element p)
{
    return(p.taille==0);

}

liste sommet_pile(Pile_element p)
{
    return p.sommet;
}

Pile_element empiler(Pile_element p, Arbrebin d)
{
    p.sommet = ajout_tete(p.sommet, d);
    p.taille++;
    return p;
}

Pile_element desempiler(Pile_element p)
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

File_element tpf(Pile_element p)
{
    File_element f = init_file();
    while (!pile_vide(p))
    {
        f = enfiler(f, p.sommet->done);
        p=desempiler(p);
    }
    return f;
}
Pile_element tfp(File_element f)
{
    Pile_element p = init_pile();
    while (!file_vide(f))
    {
        p = empiler(p, f.tete->done);
        f = defiler(f);
    }
    return p;
}

File_element tff(File_element f)
{
    File_element f1=init_file();
    while (!file_vide(f))
    {
        f1 = enfiler(f1, f.tete->done);
        f = defiler(f);
    }
    return f1;
}

Pile_element tpp(Pile_element p)
{
    Pile_element p1 = init_pile();
    while (!pile_vide(p))
    {
        p1 = empiler(p1, p.sommet->done);
        p = desempiler(p);

    }
    return p1;
}

int niv_ele_pair(Arbrebin a)
{
    File_element f = init_file();
    Arbrebin T;
    int nb_ele = 0, niv=0,ele_pair=0;
    if (!arbre_vide(a))
    {
        f = enfiler(f, a);
        while (!file_vide(f))
        {

            nb_ele++;
            if(tete_file(f)->done->age%2==0)
            {
                ele_pair++;
                if(ele_pair==3)
                break;
            }
            T =tete_file(f)->done;
            f = defiler(f);
            if (!arbre_vide(T->sag))
                f = enfiler(f, T->sag);
            if (!arbre_vide(T->sad))
                f = enfiler(f, T->sad);
            
        }
        if(ele_pair==3)
        {
            while(nb_ele/2!=0)
            {
                niv++;
                nb_ele = nb_ele / 2;
            }
        }
        else
            niv = -255;
    }
    return niv ;
}
