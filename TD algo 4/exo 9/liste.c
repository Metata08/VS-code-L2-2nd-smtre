#include"liste.h"


void erreur()
{
    puts("Erreur !!! \n");
    exit -1 ;
}

liste creer_liste()
{
    return NULL;
}

int estvide(liste l)
{
    return (l==NULL);
}


liste creer_maillon(donne d)
 {
    liste m=(liste)malloc(sizeof(maillon));
    if(estvide(m))
        erreur();
    m->done=(char*)malloc((strlen(d)*sizeof(char)));
    strcpy(m->done,d);
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

 liste remplir_liste(liste l)
 { 
    donne d;
    char texte[100];
        scanf("%s",texte);

        printf("entrer donne : ");

    for (int i = 0; i < nbr_mots(texte); i++)
    {

        d = (char*)malloc(sizeof(char) * (strlen(texte) - 1));
        strcpy(d, texte);
        l = ajout_queue(l,d);
    }
    return l;

 }

 void affiche_maillon(liste m)
 {
    printf("%s ",m->done);
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

int annagramme(liste l1,liste l2)
{
    int resultat=1;
    liste p1 = l1, p2;

    while(!estvide(p1))
    {
        p2 = l2;
        while(!estvide(p2) && strcmpi(p2->done,p1->done)!=0)
            p2 = p2->suiv;
        if(estvide(p2))
           {
            resultat = 0;
            break;
           } 
        p1 = p1->suiv;
    }
    return resultat;
}

int nbr_mots(char *texte)
{
    int i = 0, n = 0;
    while(texte[i]!='\n')
    {
        if(texte[i]=='\0')
            n++;
        i++;
    }
    return n;
}
