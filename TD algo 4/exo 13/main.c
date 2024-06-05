#include"liste_exo_13.h"

int main()
{
    int n;
    liste l;
    l = creer_liste();
    l = remplir_liste(l, &n);
    affiche_liste(l);
    puts("\n ZIP ==>");
    l = zip(l);
    affiche_liste(l);
    puts(" \n UNZIP ==>");
    l = unzip(l);
    affiche_liste(l);
    l= detruir_liste(l);

    return 0;
}