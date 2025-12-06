#pragma once
#include "type_def.h"
#ifndef UTILITAIRES
#define UTILITAIRES
using namespace std;

/*Fonction permettant de générer aléatoirement une personne
- Aucun paramètre d'entrée
- Elle retourne une personne
*/
personne genererPersonne();
/*Fonction permettant de créer un élément d'une liste dont la valeur est un type personne

Paramètre d'entrée : 
- Une personne

Elle retourne le nouvel élément 
*/
elementListe *creerElementListe(personne personne);
/*Fonction permettant d'afficher les informations d'une personne (nom, prenom, tel)

Paramètre d'entrée :
- Une personne

Elle retourne rien mais affiche a l'écran les infos
*/
void affichagePersonne(personne personne);
/*Fonction déterminant si deux personnes ont les mêmes informations

Paramètres d'entrées :
- Deux personnes

Elle retourne vrai ou faux
*/
bool egalitePersonne(personne personne1, personne personne2);
/*Fonction définissant l'ordre entre deux personnes

Paramètres d'entrées : 
- Deux personnes

Elle retourne vrai si personne1 < personne2
*/
bool comparerPersonne(personne personne1, personne personne2);

#endif