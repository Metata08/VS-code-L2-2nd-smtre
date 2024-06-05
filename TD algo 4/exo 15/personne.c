#include"personne.h"

pPersonne creer_liste_personne()
{
    return NULL;
}

int estVide(pPersonne p)
{
    return (p == NULL);
}

pers creer_pers(pers p)
{

    printf("Donner MATRICULE = ");
    scanf("%s",p.matr);
    printf("Donner NOM =  ");
    scanf("%s",p.nom);
    printf("Donner PRENOM =  ");
    scanf("%s",p.prenom);
    printf("Donner  AGE = ");
    scanf("%d",&p.ages);
    
    return p;
}

void erreur()
{
    puts("ERREUR !!! \a ");
    EXIT_SUCCESS;
}

pPersonne creer_personne(pers x)
{
    pPersonne p = (pPersonne)malloc(sizeof(Personne));
    strcpy(p->matr,x.matr);
    strcpy(p->nom,x.nom);
    strcpy(p->prenom,x.prenom);
    p->age = x.ages;
    p->suiv = NULL;
    return p;
}

pPersonne inserer_tete(pPersonne p,pers x)
{
    pPersonne c=p, per = creer_personne(x);
    
    if(estVide(p))
        p = per;
    else
    {
        per->suiv =c;
        p= per;

    }
    return p;
}

pPersonne inserer_queue(pPersonne p,pers x)
{
    pPersonne c=p, per = creer_personne(x);
    if(estVide(p))
        p = per;
    else
    {
        while (!estVide(c->suiv))
            c = c->suiv;
        c->suiv = per;
    }
    return p;
}

pPersonne inserer_position(pPersonne p,pers x,int pos)
{
    pPersonne pre,cour=p, pers = creer_personne(x);
    
    if(estVide(p))
        p = pers;
    else
    {
        if(taille_liste(p)>=pos)
        {
            if(pos==1)
                p = inserer_tete(p, x);
            else
            {
                for (int i = 2; i < pos;i++)
                {
                cour = cour->suiv;
                 }
            pre = cour;
            pers->suiv = cour->suiv;
            pre->suiv = pers;
        }
        
        }
        else
        {
            puts("Positionn k plus grand que la taille de la liste ");
            erreur();
        }
            
        }
    return p;
}

pPersonne remplir_liste_tete(pPersonne p)
{
    char choix='a';
    pers x;
    do
    {
        x = creer_pers(x);
        p = inserer_tete(p, x);
        puts("Pour quitter appuyer su 'N' ");
        getchar();
        scanf("%c",&choix);
    } while (choix!='n');

    return p ;
}

pPersonne remplir_liste_position(pPersonne p)
{
    pers x;
    int pos;
    printf(" remplir a une position k ==> \n");
    x = creer_pers(x);
    printf("donner position =");
    scanf("%d", &pos);
    p = inserer_position(p,x,pos);

    return p ;
}

pPersonne remplir_liste_queue(pPersonne p)
{
    char choix;
    pers x;
    do
    {
        x = creer_pers(x);
        p = inserer_queue(p, x);
        puts("Pour quitter appuyer su 'N' ");
        getchar();
        scanf("%c", &choix);
    } while (choix!='n');

    return p ;
}

void affiche_personne(pPersonne p)
{
    printf("PERSONNE =>  \n");

    printf("             Matricule =>>   %s \n",p->matr);
    printf("             Prenom    =>>   %s \n",p->prenom);
    printf("             Nom       =>>   %s \n",p->nom);
    printf("             Age       =>>   %d ans \n",p->age);
    puts("");
}

void affiche_liste_pers(pPersonne p)
{
    pPersonne c = p;
    if(estVide(p))
    {
        puts("liste VIDE !");
        erreur();
    }
    while (!estVide(c))
    {
        affiche_personne(c);
        c=c->suiv;
    }
    
}

pPersonne supp_personne(pPersonne p)
{
    p->suiv=NULL;
    free(p);
    return p ;
}

pPersonne detruir_liste(pPersonne *p)
{
    pPersonne c = *p, pre;
    if(estVide(*p))
        erreur();
    while (!estVide(c))
    {
        pre = c;
        c = c->suiv;
        pre = supp_personne(pre);
    }
    free(*p);
    return *p;
}

int taille_liste(pPersonne p)
{
    int n =0;
    pPersonne c = p;
    while (!estVide(c))
    {
        n++;
        c = c->suiv;
    }
    return n;
}

int recherche(pPersonne p ,ch15 matricule)
{
    int pos = 1;
    pPersonne c = p;
    while(!estVide(c) && strcmpi(c->matr,matricule)!=0)
        {
            c = c->suiv;
            pos++;
        }
        if(estVide(c))
            return 0;
        else
        return pos;
}

pPersonne inserer_position_name(pPersonne p,pers x)
{
    pPersonne cour=p, pers = creer_personne(x);

    if(estVide(p))
        p = pers;
    else
    {
        if( strcmpi(cour->nom,pers->nom)>0)
            p=inserer_tete(p,x);
        else
        {
            while(!estVide(cour->suiv) && strcmpi(cour->suiv->nom,pers->nom)<0)
            {
                // pre = cour;
                cour = cour->suiv;
            }
            if(!estVide(cour->suiv))
            {
                pPersonne k = cour->suiv;
                cour->suiv = pers;
                pers->suiv = k;

            }
            else
                p = inserer_queue(p, x);
        }
    }
    return p;
}

pPersonne remplir_liste_position_name(pPersonne p,int n)
{
    pers x;
    for (int i = 0; i < n;i++)
    {
        x = creer_pers(x);
        p = inserer_position_name(p,x);
    }

    return p ;
}


pPersonne fusion_liste_personne(pPersonne p1,pPersonne p2)
{
    pPersonne p=p1;
     pers x;
     while(!estVide(p2))
    {
         x.ages = p2->age;
        strcpy(x.matr,p2->matr);
        strcpy(x.nom,p2->nom);
        strcpy(x.prenom,p2->prenom);

        p = inserer_position_name(p,x);
        p2 = p2->suiv;
    }

    return p;
}

pPersonne supprime_tete(pPersonne p)
{
    pPersonne c = p;
    p = p->suiv;
    c=supp_personne(c);
    return p;
}


pPersonne supp_personne_age(pPersonne p,int age)
{
    pPersonne c, s;
    while(!estVide(p) && (p->age==age))
        p = supprime_tete(p);
    if(!estVide(p))
    {
        c = p;
        s = p->suiv;
        while(!estVide(s))
        {
            if(s->age==age)
            {
                c->suiv = s->suiv;
                s = supp_personne(s);
                s = c->suiv;
            }
            else
            {
                c = s;
                s = s->suiv;
            }
        }
    }
    return p;
}
