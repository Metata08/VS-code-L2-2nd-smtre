#include"file_pile.h"
#define n 5
int main(void)
{
    File_element f=init_file(),f1;
    Pile_element p = init_pile(),p1;
    donne d;
    printf(" \n ====================== \n");
    puts("Remplir file");
    for (int i = 0;i<n;i++)
    {
        scanf("%d", &d);
        f = enfiler(f, d);
    }
    f1 = tff(f);
    while(!file_vide(f))
    { 
        affiche_maillon(tete_file(f));
        f = defiler(f);
    }
    printf(" \n ====================== \n");
    while(!file_vide(f1))
    {
        affiche_maillon(tete_file(f1));
        f1 = defiler(f1);
    }
    printf(" \n ====================== \n");
    puts("Remplir pile");
    for (int i = 0;i<n;i++)
    {
        scanf("%d", &d); 
        p = empiler(p, d);
    }
    p1 = tpp(p);
    while(!pile_vide(p))
    {
        affiche_maillon(sommet_pile(p));
        p = desempiler(p);
    }
    printf(" \n ====================== \n");

    while(!pile_vide(p1))
    {
        affiche_maillon(sommet_pile(p1));
        p = desempiler(p1);
    }
    return 0;
}