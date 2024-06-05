#include "arbre_bin.h"

int arbre_vide(Arbrebin a)
{
    return (a == NULL);
}

Arbrebin creer_noeud_bin(donne d, Arbrebin gauche, Arbrebin droite)
{
    Arbrebin a;
    a = (Arbrebin)malloc(sizeof(Noeud));
    a->sag = gauche;
    a->sad = droite;
    a->age = d;
    return a;
}

Arbrebin inserer_noeud(Arbrebin a, donne d)
{
    if (a == NULL)
    {
        a = creer_noeud_bin(d, NULL, NULL);
        return a;
    }
    else if (a->sag == NULL)
    {
        a->sag = creer_noeud_bin(d, NULL, NULL);
    }
    else if (a->sad == NULL)
    {
        a->sad = creer_noeud_bin(d, NULL, NULL);
    }
    else
        a->sag = inserer_noeud(a->sag, d);

    return a;
}

Arbrebin inserer_noeud_ABR(Arbrebin a, donne d)
{
    if (a == NULL)
        a = creer_noeud_bin(d, NULL, NULL);
    else
    {
        if (d <= a->age)
            a->sag = inserer_noeud_ABR(a->sag, d);
        else
        {
            a->sad = inserer_noeud_ABR(a->sad, d);
        }
    }
    return a;
}

int feuille(Arbrebin a)
{
    if (arbre_vide(a))
        return 0;
    return (arbre_vide(a->sag) && arbre_vide(a->sad));
}

Arbrebin saisie_AB_equilibre(Arbrebin a, donne d)
{
    if (a == NULL)
    {
        a = creer_noeud_bin(d, NULL, NULL);
        return a;
    }
    else if (a->sag == NULL)
    {
        a->sag = creer_noeud_bin(d, NULL, NULL);
    }
    else if (a->sad == NULL)
    {
        a->sad = creer_noeud_bin(d, NULL, NULL);
    }
    else
    {
        if (!feuille(a))
        {
            if(nbre_feuilles(a->sag)!=2)
            a->sag = saisie_AB_equilibre(a->sag, d);
            else
            a->sad = saisie_AB_equilibre(a->sad, d);
        }
    }

    return a;
}

Arbrebin saisie_ABR(Arbrebin a)
{
    char car;
    int elmt;
    printf("Donner les elmts de l'arbre \n");
    printf("Nbre d'elements de l' arbre :");
    scanf("%d", &elmt);
    for (int i = 0; i < elmt; i++)
    {
        a = inserer_noeud_ABR(a, i + 1);
    }
    // do
    // {
    //         scanf("%d",&elmt);
    //         a = inserer_noeud_ABR(a,elmt);
    //         printf("Voulez-vous continuer (O/n) :");
    //         getchar();
    //         car=getchar();

    // } while (car!='n');

    return a;
}

void affichage(Arbrebin a)
{
    printf("%d ", a->age);
}

void affichage_postfixe(Arbrebin a)
{
    if (a != NULL)
    {
        affichage_postfixe(a->sag);
        affichage_postfixe(a->sad);
        affichage(a);
    }
}

void affichage_infixe(Arbrebin a)
{
    if (a != NULL)
    {
        affichage_infixe(a->sag);
        affichage(a);
        affichage_infixe(a->sad);
    }
}

void affichage_prefixe(Arbrebin a)
{
    if (a != NULL)
    {
        affichage(a);
        affichage_prefixe(a->sag);
        affichage_prefixe(a->sad);
    }
}

int recherche_AB(Arbrebin a, donne d)
{
    if(a==NULL)
    return 0;
    else 
    return( (a->age==d) || recherche_AB(a->sag, d) || recherche_AB(a->sad, d));
}

void recherche_AB_bis(Arbrebin a, donne d, int *trouver)
{
    if (a != NULL)
    {
        if (a->age == d)
            *trouver = 1;
        else
        {
            recherche_AB_bis(a->sag, d, trouver);
            recherche_AB_bis(a->sad, d, trouver);
        }
    }
}

int recherche_ABR(Arbrebin a, donne d)
{
    if (a == NULL)
        return 0;
    else if (a->age == d)
        return 1;
    else
    {
        if (a->age > d)
            return recherche_ABR(a->sag, d);
        else
        {
            return recherche_ABR(a->sad, d);
        }
    }
}

int max_3(int a, int b, int c)
{
    int d = (a > b) ? a : b;
    return (c > d) ? c : d;
}

int min_3(int a, int b, int c)
{
    int d = (a < b) ? a : b;
    return (c < d) ? c : d;
}

int max_AB(Arbrebin a)
{
    if (arbre_vide(a))
        return -1;
    else if (arbre_vide(a->sag) && arbre_vide(a->sad))
        return a->age;
    else
        return max_3(a->age, max_AB(a->sag), max_AB(a->sad));
}
int min_AB(Arbrebin a)
{
    if (arbre_vide(a))
        return -1;
    else if (arbre_vide(a->sag) && arbre_vide(a->sad))
        return a->age;
    else
        return min_3(a->age, max_AB(a->sag), max_AB(a->sad));
}

int max_ABR(Arbrebin a)
{
    if (arbre_vide(a))
        return -1;
    if (arbre_vide(a->sad))
        return a->age;
    else
        return max_ABR(a->sad);
}

int min_ABR(Arbrebin a)
{
    if (arbre_vide(a))
        return -1;
    if (arbre_vide(a->sag))
        return a->age;
    else
        return min_ABR(a->sag);
}


int nbre_feuilles(Arbrebin a)
{
    if (arbre_vide(a))
        return 0;
    else if (feuille(a))
        return 1;
    else
        return nbre_feuilles(a->sad) + nbre_feuilles(a->sag);
}

int nbre_noeuds_interne(Arbrebin a)
{
    if (arbre_vide(a))
        return 0;
    else if (feuille(a))
    return 0;
    else
        return (1 + nbre_noeuds_interne(a->sag) + nbre_noeuds_interne(a->sad));
}

int max_2(int a, int b)
{
    return (a > b) ? a : b;
}
int min_2(int a, int b)
{
    return (a < b) ? a : b;
}


int profondeur(Arbrebin a)
{
    if (arbre_vide(a))
        return 0;
    else
        return 1 + max_2(profondeur(a->sad), profondeur(a->sag));
}

Arbrebin Liberer(Arbrebin a)
{
    if (arbre_vide(a))
        return a;
    else
    {
        Liberer(a->sag);
        Liberer(a->sad);
        free(a);
        a = NULL;
        return a;
    }
}

int niveau(Arbrebin a, donne d)
{
    if(arbre_vide(a))
        return 0;
    else
    {
        if(a->age==d)
            return 1;
        else 
        return 1 + min_2(niveau(a->sag, d), niveau(a->sad, d));
    }
}

Arbrebin SAG(Arbrebin a)
{
    return a->sag;
}

Arbrebin SAD(Arbrebin a)
{
    return a->sad;
}

int simi(Arbrebin A1,Arbrebin A2)
{
    if (A1 != NULL && A2 != NULL)
        return (simi(SAG(A1), SAG(A2)) && simi(SAD(A1), SAD(A2)));
    else if (((A1 == NULL) && (A2 != NULL)) || ((A1 != NULL) && (A2 == NULL)))
        return 0;
    else
        return 1;
}

int equilibrer(Arbrebin a)
{
    if(arbre_vide(a))
        return 0;
    else
    {
        int p=1;

        for (int i = 0; i <profondeur(a)-1; i++)
        {
                p = p * 2;
        }
        
        if (p==nbre_feuilles(a))
                return 1;
        else
                return 0;
    }
    
}


int ele_sup10(Arbrebin a)
{
    if(arbre_vide(a))
        return 0;
    else
    {
        if(a->age > 10)
        return 1 + ele_sup10(a->sag) + ele_sup10(a->sad);
        else
        return ele_sup10(a->sag) + ele_sup10(a->sad);
    } 
}