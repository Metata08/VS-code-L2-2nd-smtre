#include"liste.h"

int main(void)
{
    liste phrase1=creer_liste(), phrase2=creer_liste();
    int taille1,taille2;
    printf(" Donner le nbre de mots de la phrase n°1  \n");
    scanf("%d",&taille1);
    printf(" Donner le nbre de mots de la phrase n°2  \n");
    scanf("%d",&taille2);
    puts("PHRASE N°1");
    phrase1 = remplir_liste(phrase1, taille1);
    puts("PHRASE N°2");
    phrase2 = remplir_liste(phrase2, taille2);

    affiche_liste(phrase1);
    puts("");
    affiche_liste(phrase2);
    if (annagramme(phrase1, phrase2))
        puts("  ANNAGRAMME   *_*  ");
    else
        puts("  NON ANNAGRAMME /!\\ ");

    detruir_liste(phrase1);
    detruir_liste(phrase2);

return 0;

}