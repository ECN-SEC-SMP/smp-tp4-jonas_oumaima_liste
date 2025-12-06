#include "type_def.h"
#include "utilitaire_generation.h"
#include <iostream>
using namespace std;


personne genererPersonne(){
    personne personne; // création de la personne
    personne.nom = genererNomPrenom("Noms_TP4.txt", 1000); // assignation du nom de la personne
    personne.prenom = genererNomPrenom("Prenoms_TP4.txt", 11612); // assignation du prenom de la personne
    personne.tel = genererTel(); // assignation du numéro de téléphone de la personne
    return personne; // retourne la personne
}

elementListe *creerElementListe(personne personne){
    elementListe* nouv; // création du nouveau pointeur de type elementListe
    nouv = new elementListe; // affectation mémoire du pointeur
    nouv->pers = personne; // assignation de la personne en parametre au pointeur
    nouv->suivant = nullptr; // assignation d'aucun pointeur pour l'élément suivant de cet élément
    return nouv; // retourne le nouvel élément
}

void affichagePersonne(personne personne){
    cout << "[" + personne.nom + ", " << personne.prenom + ", "<< personne.tel << "]" << endl;
}

bool egalitePersonne(personne personne1, personne personne2){
    if (personne1.nom == personne2.nom){ // on compare d'abord les noms
        if(personne1.prenom == personne2.prenom){ // ensuite les prenoms
            if(personne1.tel == personne2.tel){ // enfin les numeros de telephone
                return true; // si tous les tests passe on renvoie vrai
            }
        }
    } 
    else{
        return false; // si au moins un test echoue on renvoie faux
    }
    return 0; // retour 0 pour eviter un warning (jamais appelé)
}

bool comparerPersonne(personne personne1, personne personne2){
    if(personne1.nom == personne2.nom){ // on compare d'abord les noms
        if(personne1.prenom == personne2.prenom){ // on compare ensuite les prenom si la comparaison precedente n'a pas suffit
            if(personne1.tel == personne2.tel){ // on compare les numeros si les deux tests precedent ne sont pas concluant

            }
            else{
                if(personne1.tel < personne2.tel){
                    return true; // le tel de la personne 1 passe avant le tel de la personne 2 
                }
                else{
                    return false; // le tel de la personne 2 passe avant le tel de la personne 1
                }
            }
        }
        else{
            if(personne1.prenom < personne2.prenom){
                return true; // le prenom de la personne 1 passe avant le prenom de la personne 2 
            }
            else{
                return false; // le prenom de la personne 2 passe avant le prenom de la personne 1 
            }
        }
    }
    else{ 
        if(personne1.nom < personne2.nom){
            return true; // le nom de la personne 1 passe avant le nom de la personne 2 
        }
        else{
            return false; // le nom de la personne 2 passe avant le nom de la personne 1 
        }
    }
    return 0;
}