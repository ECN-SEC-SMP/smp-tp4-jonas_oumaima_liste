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
    precedent->suivant = nouveau;
    return liste;
}


void affichage(elementListe *liste){
    if (liste == nullptr){
        cout << "Liste vide" << endl;
    }
    while(liste != nullptr){
        cout << "[" + liste->pers.nom + ", " << liste->pers.prenom + ", "<< liste->pers.tel << "]" << endl;
        liste = liste->suivant;
    }
}


int recherche(personne personne, elementListe *liste){
    int i = 1;
    elementListe *courant = liste;

    while(courant!=nullptr){
        if (egalitePersonne(courant->pers, personne)){
            return i;
        }
        else{
            i++;
            courant = courant->suivant;
        }  
    }
    return -1;
}


elementListe *supprimer(personne personne, elementListe *liste){
    elementListe *courant = liste;
    while(courant!=nullptr){
        if(egalitePersonne(personne, courant->pers)){
            courant = nullptr;
            return liste;   
        }
        else{
            courant = courant->suivant;
        }
    }
    return liste;
}
