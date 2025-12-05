#include "type_def.h"
#include "utilitaire_generation.h"
#include <iostream>
using namespace std;


personne genererPersonne(){
    personne personne;
    personne.nom = genererNomPrenom("Noms_TP4.txt", 1000);
    personne.prenom = genererNomPrenom("Prenoms_TP4.txt", 11612);
    personne.tel = genererTel();
    return personne;
}

elementListe *creerElementListe(personne personne){
    elementListe* nouv;
    nouv = new elementListe;
    nouv->pers = personne;
    nouv->suivant = nullptr;
    return nouv;
}

void affichagePersonne(personne personne){
    cout << "Nom : " << personne.nom <<endl;
    cout << "Prénom : " << personne.prenom << endl;
    cout << "Téléphone : " << personne.tel << endl;
}

bool egalitePersonne(personne personne1, personne personne2){
    if (personne1.nom == personne2.nom){
        if(personne1.prenom == personne2.prenom){
            if(personne1.tel == personne2.tel){
                return true;
            }
        }
    } 
    else{
        return false;
    }
    return 0;
}

bool comparerPersonne(personne personne1, personne personne2){
    if(personne1.nom == personne2.nom){
        if(personne1.prenom == personne2.prenom){
            if(personne1.tel == personne2.tel){

            }
            else{
                if(personne1.tel < personne2.tel){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        else{
            if(personne1.prenom < personne2.prenom){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        if(personne1.nom < personne2.nom){
            return true;
        }
        else{
            return false;
        }
    }
    return 0;
}