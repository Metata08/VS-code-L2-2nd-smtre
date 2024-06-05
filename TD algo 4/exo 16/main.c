#include"personne.h"

int main(void)
{
    p2Personne p;
    p= creer_liste_personne();
    p= remplir_liste_queue(p);
    affiche_liste_pers(p);
    p= remplir_liste_position(p);
    affiche_liste_pers(p);
    p = supp_personne_pos(p);
    affiche_liste_pers(p);
    p=inverser_liste(p);
    affiche_liste_pers(p);
    p=supp_personne_age(p);
    affiche_liste_pers(p);
    detruir_liste(&p);
    
    return 0;
}