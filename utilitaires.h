#pragma once
#include "type_def.h"

#ifndef UTILITAIRES

#define UTILITAIRES

using namespace std;

personne genererPersonne();
elementListe *creerElementListe(personne personne);
void affichagePersonne(personne personne);
bool egalitePersonne(personne personne1, personne personne2);
bool comparerPersonne(personne personne1, personne personne2);

#endif