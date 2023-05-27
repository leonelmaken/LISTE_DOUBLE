#include <stdio.h>
#include <stdlib.h>
#include "LISTE_DOUBLE.h"
DList nouvel_list(void)
{
    return NULL;
}
/*----------------------------------------------*/
Bool liste_vide(DList li)
{
    if(li == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*----------------------------------------------*/
int longueur_list(DList li)
{
    if(liste_vide(li))
    {
        return 0;
    }
    else
    {
        return li->longueur;
    }
}
/*----------------------------------------------*/
int premier_element(DList li)
{
    if(liste_vide(li))
    {
        exit(1);
    }
    else
    {
        return li->premier->valeur;
    }
}
int dernier_element(DList li)
{
    if(liste_vide(li))
        exit(1);
    return li->dernier->valeur;
}
DList ajouter_derriere(DList li,int x)
{
    DListNote *element;
    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr,"Erreur : probleme allocation.\n");
        exit(EXIT_FAILURE);
    }
    element->valeur = x;
    element->suivant=NULL;
    element->precedant=NULL;
    if(liste_vide(li))
    {
        li = malloc(sizeof(*li));
        if(li == NULL)
        {
            fprintf(stderr,"Erreur: allocation.\n");
            exit(EXIT_FAILURE);
        }
            li->longueur = 0;
            li->premier = element;
            li->dernier = element;
    }
    else//si la liste n'est pas vide
    {
        li->dernier->suivant = element;
        element->precedant = li->dernier;
        li->dernier = element;
    }
    li->longueur++;
    return li;
}
DList ajouter_devant(DList li,int x)
{
        DListNote *element;
    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr,"Erreur : probleme allocation.\n");
        exit(EXIT_FAILURE);
    }
    element->valeur = x;
    element->suivant=NULL;
    element->precedant=NULL;
    if(liste_vide(li))
    {
        li = malloc(sizeof(*li));
        if(li == NULL)//si la liste est vide
        {
            fprintf(stderr,"Erreur: allocation.\n");
            exit(EXIT_FAILURE);
        }
            li->longueur = 0;
            li->premier = element;
            li->dernier = element;
    }
    else//si la liste n'est pas vide
    {
        li->premier->precedant = element;
        element->suivant = li->premier;
        li->premier = element;
    }
    li->longueur++;
    return li;
}
DList retirer_derrier(DList li)
{
    if(liste_vide(li))
    {
        printf("liste vide.\n");
        return nouvel_list();
    }
    if(li->premier == li->dernier)//s'il y'a un seul element dans la liste
    {
        free(li);
        li = NULL;
        return nouvel_list();
    }
    DListNote *temp = li->dernier;
    li->dernier = li->dernier->precedant;
    li->dernier->suivant = NULL;

    temp->suivant = NULL;
    temp->precedant = NULL;
    free(temp);
    temp = NULL;
    li->longueur--;
    return li;
}
DList retirer_devant(DList li)
{
    if(liste_vide(li))
    {
        printf("liste vide.\n");
        return nouvel_list();
    }
    if(li->premier == li->dernier)//s'il y'a un seul element dans la liste
    {
        free(li);
        li = NULL;
        return nouvel_list();
    }
    DListNote *temp = li->dernier;
    li->premier = li->dernier->suivant;
    li->premier->precedant = NULL;
    temp->suivant = NULL;
    temp->precedant = NULL;
    free(temp);
    temp = NULL;
    li->longueur--;
    return li;
}
void affiche_liste(DList li)
{
    if(liste_vide(li))
    {
        printf("liste vide.\n");
        return;
    }
    DListNote *temp = li->premier;
    while(temp-> suivant !=NULL)
    {
        printf("[%d]",temp->valeur);
        temp = temp->suivant;
    }
    printf("\n");
}
