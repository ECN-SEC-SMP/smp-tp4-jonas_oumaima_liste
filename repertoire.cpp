#include <iostream>
#include "utilitaires.h"


using namespace std;


elementListe * ajouter(personne personne, elementListe* liste) {
    elementListe* nouveau = creerElementListe(personne);

    if (liste == nullptr) {
        return nouveau;
    }

    elementListe* courant = liste;
    elementListe* precedent = nullptr;

    while (courant != nullptr) {
        if (egalitePersonne(personne, courant->pers)) {
            delete nouveau;
            return liste;
        }
        if (comparerPersonne(personne, courant->pers)) {
            if (precedent == nullptr) {
                nouveau->suivant = liste;
                return nouveau; 
            } 
            else {
                precedent->suivant = nouveau;
                nouveau->suivant = courant;
                return liste;
            }
        }
        precedent = courant;
        courant = courant->suivant;
    }

    // Insertion en fin de liste
    precedent->suivant = nouveau;
    return liste;
}


void affichage(elementListe *liste){
    if (liste == nullptr){
        cout << "Liste vide" << endl;
    }
    while(liste != nullptr){
        cout << liste->pers.nom + ", " << liste->pers.prenom + ", "<< liste->pers.tel << " ; " << endl;
        liste = liste->suivant;
    }
}