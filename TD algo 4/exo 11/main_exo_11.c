#include"liste.h"

int main()
{
    liste l;
    l = creer_liste();
    l = remplir_liste(l);
    affiche_liste(l);
    puts("");
    // l = supp_aternative(l); //POUR UTILISER CETTE INSTRUCTION ENLEVER LES SLASHS
    l = supp_ele_impair(l);
    affiche_liste(l);
    detruir_liste(l);
    return 0;
}