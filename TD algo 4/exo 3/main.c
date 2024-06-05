#include"liste.h"

int main(void)
{
    liste l;
    l = creer_liste();
    l = remplir_liste(l);
    affiche_liste(l);
    detruir_liste(l);
    return 0;
    
}
