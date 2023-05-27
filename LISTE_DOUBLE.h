#ifndef LISTE_DOUBLE_H_INCLUDED
#define LISTE_DOUBLE_H_INCLUDED
typedef enum
{
    false,
    true
}Bool;
/*definition de la liste doublement chaine*/
typedef struct DListNote
{
    int valeur;
    struct DListNote *precedant;
    struct DListNote *suivant;
} DListNote;
typedef struct DList
{
    int longueur;
    struct DListNote *premier;
    struct DListNote *dernier;
}*DList;
/*prototype*/
DList nouvel_list(void);
Bool liste_vide(DList li);
int premier_element(DList li);//retoune le premier element de la liste
int dernier_element(DList);//retourne le dernier element
int longueur_list(DList li);
DList ajouter_derriere(DList li,int x);
DList ajouter_devant(DList li,int x);
DList retirer_derrier(DList li);
DList retirer_devant(DList li);
void affiche_liste(DList li);

#endif // LISTE_DOUBLE_H_INCLUDED
