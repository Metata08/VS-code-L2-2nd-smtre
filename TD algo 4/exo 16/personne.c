#include"personne.h"

p2Personne creer_liste_personne()
{
    return NULL;
}

int estVide(p2Personne p)
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
    do
    {
    scanf("%d", &p.ages);
    if(p.ages<=0)
    printf("ERREUR !!! Age impossible \n");
    } while (p.ages<= 0);
    
    return p;
}

void erreur()
{
    puts("ERREUR !!! \a ");
    EXIT_SUCCESS;
}

p2Personne creer_personne(pers x)
{
    p2Personne p = (p2Personne)malloc(sizeof(Personne));
    strcpy(p->matr,x.matr);
    strcpy(p->nom,x.nom);
    strcpy(p->prenom,x.prenom);
    p->age = x.ages;
    p->succ = NULL;
    p->pred=NULL;
    return p;
}

p2Personne insert_tete(p2Personne p,pers x)
{
    p2Personne c=p, per = creer_personne(x);
    
    if(estVide(p))
        p = per;
    else
    {
        c->pred = per;
        per->succ = c;
        p= per;

    }
    return p;
}

p2Personne insert_queue(p2Personne p,pers x)
{
    p2Personne c=p, per = creer_personne(x);
    if(estVide(p))
        p = per;
    else
    {
        while (!estVide(c->succ))
            c = c->succ;
        per->pred = c;
        c->succ = per;
    }
    return p;
}

p2Personne insert_position(p2Personne p,pers x,int pos)
{
    p2Personne pre,cour=p, pers = creer_personne(x);
    
    if(estVide(p))
        p = pers;
    else
    {
        if(taille_liste(p)>=pos)
        {
            if(pos==1)
                p = insert_tete(p, x);
            else
            {
                for (int i = 1; i < pos;i++)
                {
                cour = cour->succ;
                 }
            pre = cour->pred;
            pers->pred = pre;
            pers->succ = cour;
            pre->succ = pers;
            cour->pred = pers;
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

p2Personne remplir_liste_tete(p2Personne p)
{
    char choix='a';
    pers x;
    do
    {
        x = creer_pers(x);
        p = insert_tete(p, x);
        puts("Pour quitter appuyer su 'N' ");
        getchar();
        scanf("%c",&choix);
    } while (choix!='n');

    return p ;
}

p2Personne remplir_liste_position(p2Personne p)
{
    pers x;
    int pos;
    printf(" remplir a une position k ==> \n");
    x = creer_pers(x);
    printf("donner position =");
    scanf("%d", &pos);
    p = insert_position(p,x,pos);

    return p ;
}

p2Personne remplir_liste_queue(p2Personne p)
{
    char choix;
    pers x;
    do
    {
        x = creer_pers(x);
        p = insert_queue(p, x);
        puts("Pour quitter appuyer su 'N' ");
        getchar();
        scanf("%c", &choix);
    } while (choix!='n');

    return p ;
}

void affiche_personne(p2Personne p)
{

    printf("             Matricule =>>   %s \n",p->matr);
    printf("             Prenom    =>>   %s \n",p->prenom);
    printf("             Nom       =>>   %s \n",p->nom);
    printf("             Age       =>>   %d an(s) \n",p->age);
    puts("");
}

void affiche_liste_pers(p2Personne p)
{
    p2Personne c = p;
    int i = 1;
    if(estVide(p))
    {
        puts("liste VIDE !");
        erreur();
    }
    while (!estVide(c))
    {
         printf("PERSONNE => %d  \n",i);
         affiche_personne(c);
         c = c->succ;
         i++;
    }
    
}

p2Personne supp_personne(p2Personne p)
{
    p->pred=NULL;
    p->succ=NULL;
    free(p);
    return p ;
}

p2Personne detruir_liste(p2Personne *p)
{
    p2Personne c = *p, pre;
    if(estVide(*p))
        erreur();
    while (!estVide(c))
    {
        pre = c;
        c = c->succ;
        pre = supp_personne(pre);
    }
    free(*p);
    return *p;
}

int taille_liste(p2Personne p)
{
    int n =0;
    p2Personne c = p;
    while (!estVide(c))
    {
        n++;
        c = c->succ;
    }
    return n;
}

p2Personne supprime_tete(p2Personne p)
{
    p2Personne c = p;
    p = p->succ;
    c=supp_personne(c);
    return p;
}


p2Personne supp_personne_pos(p2Personne p)
{
    p2Personne c = p, preced, suiv;
    int pos;
    printf(" Supprimer a une position k  ==>\n");
    printf("Donner la position k SVP =");
    scanf("%d", &pos);
    if (pos<= taille_liste(p)&&pos>0)
    {
        if(pos==1)
        {
            p = supprime_tete(p);
        }
        else
            {
                for (int i = 1; i < pos; i++)
                    c = c->succ;
                preced = c->pred;
                suiv = c->succ;
                preced->succ = suiv;
                suiv->pred = preced;
                c = supp_personne(c);
            }
        }
        
    else
    {
        puts("Positionn k non admise !!! ");
    }
    return p;
}

p2Personne inverser_liste(p2Personne p)
{
    p2Personne c = p,k;
    puts("liste  INVERSEE  ===>");
    if (estVide(c->succ))
    {
        return p;
    }
    else
    {
        while(!estVide(c))
        {
            k = c->pred;
            c->pred = c->succ;
            c->succ = k;
            c = c->pred; 
            if(!estVide(c))
                    p = c;
        }
        return p;
    }
    
}

p2Personne supp_personne_age(p2Personne p)
{
    p2Personne c, preced, suiv, k;
    int age;
    printf("donner AGE =");
    do
    {
    scanf("%d", &age);
    if(age<=0)
    printf("ERREUR !!! Age impossible \n");
    } while (age<= 0);

    printf(" Supprimer les personnes agees de plus de %d an(s)  ==>\n",age);

            int n = 0;
            while (p->age > age)
            {
              p = supprime_tete(p);
            }
            c = p;
            suiv = p->suiv;
            while(!estVide(c))
            {
                
                if(c->age > age)
                {
                    p = supp_personne_pos_bis(p, n);
                    n = 0;
                    c = p;
                }
                n++;
                c = c->succ;
            }

    return p;
}

p2Personne supp_personne_pos_bis(p2Personne p,int pos)
{
    p2Personne c = p, preced, suiv;
    if (pos<= taille_liste(p) && pos>0)
    {
        if(pos==1)
        {
            p = supprime_tete(p);
        }
        else
            {
                for (int i = 1; i < pos; i++)
                    c = c->succ;
                preced = c->pred;
                suiv = c->succ;
                preced->succ = suiv;
                suiv->pred = preced;
                c = supp_personne(c);
            }
        }
        
    return p;
}
