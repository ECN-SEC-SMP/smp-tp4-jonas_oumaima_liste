#pragma once
#include "type_def.h"
#ifndef REPERTOIRE
#define REPERTOIRE

elementListe *ajouter(personne personne, elementListe *liste);
void affichage(elementListe *liste);
int recherche(personne personne, elementListe *liste);
elementListe *supprimer(personne personne, elementListe *liste);
#endif