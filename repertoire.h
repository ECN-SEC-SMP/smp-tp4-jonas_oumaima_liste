#pragma once
#include "type_def.h"
#ifndef REPERTOIRE
#define REPERTOIRE



/*Fonction permettant d'ajouter une personne au bon endroit

Paramètres d'entrées :
- Une personne
- Une liste

Elle retourne la tête de la liste dont la personne a été ajoutée
*/
elementListe *ajouter(personne personne, elementListe *liste);

/*Fonction permettant d'afficher une liste

Paramètre d'entrée :
- Une liste

Elle retourne rien mais affiche a l'écran la liste
*/
void affichage(elementListe *liste);
/*Fonction permettant de rechercher une personne dans une liste et de déterminer sa position

Paramètres d'entrées :
- Une personne
- Une liste

Elle retourne la position de la personne dans la liste
*/
int recherche(personne personne, elementListe *liste);
/*Fonction permettant de supprimer une personne au bon endroit

Paramètres d'entrées :
- Une personne
- Une liste

Elle retourne la tête de la liste dont la personne a été supprimée
*/
elementListe *supprimer(personne personne, elementListe *liste);


#endif