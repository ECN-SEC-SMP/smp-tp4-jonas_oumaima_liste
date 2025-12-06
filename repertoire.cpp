#include <iostream>
#include "utilitaires.h"


using namespace std;


elementListe * ajouterListe(personne personne, elementListe* liste) {
    elementListe* nouveau = creerElementListe(personne);

    if (liste == nullptr) { // si la liste en entree est vide
        return nouveau; // renvoie de l'element cree
    }

    elementListe* courant = liste; // creation du pointeur pour bouger dans la liste
    elementListe* precedent = nullptr; // creation du pointeur de l'element precedent de la liste

    while (courant != nullptr) { // parcours de la liste
        if (egalitePersonne(personne, courant->pers)) { // si la personne est deja dans la liste
            delete nouveau; // liberation de la memoire 
            return liste; // renvoie de la liste sans la modifier
        }
        if (comparerPersonne(personne, courant->pers)) { // si "personne" passe avant "courant->pers"
            if (precedent == nullptr) { // on verifie si on est en tete de liste (oui si le precedent est null)
                nouveau->suivant = liste; // dans ce cas l'element cree devient la tete de liste
                return nouveau; // renvoie de la nouvelle tete de liste
            } 
            else { // si on ce trouve apres la tete de liste
                // insertion du nouvel element entre l'element precedent et l'element courant
                precedent->suivant = nouveau; 
                nouveau->suivant = courant;
                return liste; // renvoie de la tete de liste 
            }
        }
        // avancement dans la liste
        precedent = courant; 
        courant = courant->suivant;
    } // si l'element de la liste ne trouve pas de place avant le dernier element
    precedent->suivant = nouveau; // ajout du nouvel element a la fin de la liste 
    return liste; // renvoie de la tete de liste
}

elementTableau ajouterTab(personne personne, elementTableau tab){
    for(int i = 0; i < tab.taille; i++){
        if(egalitePersonne(personne, tab.pers[i])){
            return tab; 
        }
        
        if(comparerPersonne(personne, tab.pers[i])){
            for(int j = tab.taille; j > i; j--){
                tab.pers[j] = tab.pers[j-1];
            }
            tab.pers[i] = personne;
            tab.taille++;
            return tab;
        }
    }
    
    tab.pers[tab.taille] = personne;
    tab.taille++;
    return tab;
}

void affichageListe(elementListe *liste){
    elementListe *courant = liste; // creation du pointeur pour avancer dans la liste

    if (liste == nullptr){ // si la liste a afficher est vide
        cout << "Liste vide" << endl; 
    }
    while(courant != nullptr){ // tant que l'element de la liste n'est pas vide
        // affichage de la liste
        affichagePersonne(courant->pers);
        courant = courant->suivant; // parcours de la liste
    }
}

void affichageTab(elementTableau tab){
    for(int i=0; i < tab.taille; i++){
        affichagePersonne(tab.pers[i]);
    }
}


int rechercheListe(personne personne, elementListe *liste){
    int i = 0; // initialisation de la position de l'element dans la liste 
    elementListe *courant = liste;  // creation du pointeur pour avancer dans la liste

    while(courant!=nullptr){
        if (egalitePersonne(courant->pers, personne)){ // si on trouve l'element rechercher
            return i; // renvoie l'indice de l'element 
        }
        else{
            i++; // incrementation de l'indice de l'element
            courant = courant->suivant; // parcours de la liste
        }  
    }
    return -1; // si l'element n'est pas dans la liste
}

int rechercheTab(personne personne, elementTableau tab){
    for (int i = 0; i < tab.taille; i++){
        if (egalitePersonne(personne, tab.pers[i])){
            return i;
        }
    }
    return -1;
}


elementListe *supprimerListe(personne personne, elementListe *liste){
    elementListe *courant = liste; // creation du pointeur pour avancer dans la liste
    elementListe *precedent = nullptr; // creation du pointeur de l'element precedent de la liste

    while(courant!=nullptr){
        if(egalitePersonne(personne, courant->pers)){ // si on trouve la personne
            if(precedent == nullptr){  // si cette personne ce trouve a la tete de liste
                liste = courant->suivant; // la tete de liste devient la le second element de la liste
                delete courant; // liberation de la memoire
                return liste; // renvoie de la nouvelle tete de liste
            }
            else{ // si cette personne ce trouve apres la tete de liste
        // on relie l'element avant celui qu'on veut supprimer a celui apres celui qu'on veut supprimer
                precedent->suivant = courant->suivant; 
                delete courant; // liberation de la memoire
                return liste; // renvoie de la tete de liste
            }
        }
        // deplacement dans la liste
        precedent = courant; 
        courant = courant->suivant;
    }
    // renvoie de la liste si l'element a supprimer n'existe pas 
    return liste;
}

elementTableau supprimerTab(personne personne, elementTableau tab){
    int pos = rechercheTab(personne, tab);

    if(pos == -1){
        return tab;
    }

    for(int i = pos; i < tab.taille; i++){
                tab.pers[i] = tab.pers[i+1];
    }
    tab.taille--;
    return tab;
}
