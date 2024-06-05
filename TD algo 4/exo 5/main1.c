#include"liste.h"


int main(void)
{
    liste l;
    l=creer_liste();
    l = remplir_liste(l);
    affiche_liste(l);
    l = tri_liste(l);
    affiche_liste(l);
    return 0;
}