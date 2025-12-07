#include <iostream>
#include "../utilitaires/utilitaires.h"


using namespace std;


elementListe * ajouterListe(personne personne, elementListe* liste) {
    elementListe* nouveau = creerElementListe(personne); // creation du nouvel element qui pour valeur "personne"

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
    for(int i = 0; i < tab.taille; i++){ // parcours du tableau
        if(egalitePersonne(personne, tab.pers[i])){ // si la personne est déjà dans le tableau
            return tab; // renvoie le tableau sans ajout
        }
        
        // si "personne" est avant "tab.pers[i]" 
        if(comparerPersonne(personne, tab.pers[i])){
            // parcours du tableau de la fin vers la position du nouvel element
            for(int j = tab.taille; j > i; j--){ 
                tab.pers[j] = tab.pers[j-1];// decalage de chaque personne vers la droite
            }
            tab.pers[i] = personne;  // ajout du nouvel element
            tab.taille++; // incrementation de la taille du tableau
            return tab; // renvoie du tableau modifié
        }
    }
    // le cas ou le nouvel element est a la fin du tableau
    tab.pers[tab.taille] = personne; //ajout du nouvel element a la fin
    tab.taille++; // incrementation de la taille du tableau
    return tab; // renvoie du tableau modifié
}

void affichageListe(elementListe *liste){
    elementListe *courant = liste; // creation du pointeur pour avancer dans la liste

    if (liste == nullptr){ // si la liste a afficher est vide
        cout << "Liste vide" << endl; 
    }
    cout << "[";
    while(courant != nullptr){ // tant que l'element de la liste n'est pas vide
        // affichage de la liste
        affichagePersonne(courant->pers);
        courant = courant->suivant; // parcours de la liste
    }
    cout << "]";
}

void affichageTab(elementTableau tab){
    cout << "[";
    for(int i=0; i < tab.taille; i++){ // parcours du tableau
        affichagePersonne(tab.pers[i]); // affichage de chaque personne
    }
    cout << "]";
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
    for (int i = 0; i < tab.taille; i++){ // parcours du tableau du début a la fin
        if (egalitePersonne(personne, tab.pers[i])){ // si on retrouve la personne dans le tableau
            return i; // renvoie la position de la personne dans le tableau
        }
    }
    return -1; // renovie de -1 si la personne n'est pas dans le tableau
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
    int pos = rechercheTab(personne, tab); // position de l'element recherché 

    if(pos == -1){ // si l'element n'est pas dans le tableau
        return tab; // renvoie du tableau sans modification
    }

    // décalage vers la gauche du tableau
    for(int i = pos; i < tab.taille-1; i++){ 
                tab.pers[i] = tab.pers[i+1];
    }
    tab.taille--; // reduction de la taille du tableau
    return tab; // renvoie du tableau apres décalage
}
