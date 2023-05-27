#include <stdio.h>
#include <stdlib.h>
#include "LISTE_DOUBLE.h"
int main()
{
    printf("Hello world!\n");
    DList maliste = nouvel_list();
    affiche_liste(maliste);
    printf("la taille de la liste doublement chaine donne: %d\n",longueur_list(maliste));
    affiche_liste(maliste);
    return 0;
}

