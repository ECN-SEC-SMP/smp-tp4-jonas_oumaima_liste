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
elementListe *ajouterListe(personne personne, elementListe *liste);

/*Fonction permettant d'afficher une liste

Paramètre d'entrée :
- Une liste

Elle retourne rien mais affiche a l'écran la liste
*/
void affichageListe(elementListe *liste);

/*Fonction permettant d'afficher un tableau

Paramètre d'entrée :
- Un tableau 


Elle retourne rien mais affiche a l'écran le tableau
*/
void affichageTab(elementTableau tab);
/*Fonction permettant de rechercher une personne dans une liste et de déterminer sa position

Paramètres d'entrées :
- Une personne
- Une liste

Elle retourne la position de la personne dans la liste
*/
int rechercheListe(personne personne, elementListe *liste);
/*Fonction permettant de rechercher une personne dans une liste et de déterminer sa position

Paramètres d'entrées :
- Une personne
- Un tableau

Elle retourne la position de la personne dans la liste
*/
int rechercheTab(personne personne, elementTableau tab);
/*Fonction permettant de supprimer une personne au bon endroit

Paramètres d'entrées :
- Une personne
- Une liste

Elle retourne la tête de la liste sans personne a supprimée
*/
elementListe *supprimerListe(personne personne, elementListe *liste);

/*Fonction permette d'ajouter une personne au bon endroit d'un tableau

Parametres  d'entrées : 

- Une personne
- Un tableau

Elle retourne le tableau avec la personne ajouter
*/
elementTableau ajouterTab(personne personne, elementTableau tab);
/*Fonction permettant de supprimer une personne au bon endroit du tableau

Paramètres d'entrées :
- Une personne
- Un tableau

Elle retourne le tableau sans la personne supprimée
*/
elementTableau supprimerTab(personne personne, elementTableau tab);

#endif