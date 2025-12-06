#include <iostream>
#include "utilitaires.h"
#include "utilitaire_generation.h"
#include "repertoire.h"
#include "type_def.h"

using namespace std;

int main(){

    cout << endl;
    cout << "Affichage d'une personne aléatoire" << endl;
    cout << endl;

    affichagePersonne(genererPersonne());


    personne personnetest1 = genererPersonne();
    personne personnetest2;
    
    personnetest2.nom = "David";
    personnetest2.prenom = "akny";
    personnetest2.tel = "0307214235";

    cout << endl;
    cout << "Egalité entre deux personne : " << endl;
    cout << endl;
    cout << personnetest1.nom << endl;
    cout << personnetest2.nom << endl;
    cout << endl;

    if(egalitePersonne(personnetest1, personnetest2)){
        cout << "Ce sont les mêmes personnes !"<<endl;
    }
    else{
        cout << "Ce ne sont pas les mêmes personnes"<<endl;
    }

    cout << endl;
    cout << "Comparaison entre deux personnes : " << endl;
    cout << endl;

        if(comparerPersonne(personnetest1, personnetest2)){
        cout << personnetest1.nom << " est avant " << personnetest2.nom <<endl;
    }
    else{
        cout << personnetest1.nom << " est après " << personnetest2.nom <<endl;
    }
    
    cout << endl;
    cout << "Affichage de la liste : " << endl;
    cout << endl;

    elementListe *liste = creerElementListe(personnetest1);

    for (int i = 0; i < 5 ; i++){
        liste = ajouterListe(genererPersonne(),liste);
    }

    liste = ajouterListe(personnetest2,liste);
    
    affichageListe(liste);
    

    cout << endl;
    cout << "Recherche d'une personne : " << endl;
    cout << endl; 

    cout << "David est a la " << recherche(personnetest2,liste) << " position"<<endl;

    cout << endl;
    cout << "Suppression de David" << endl;
    cout << endl;

    liste = supprimer(personnetest2,liste);

    affichageListe(liste);

    cout << endl;
    cout << "Test des tableau : " << endl;
    cout << endl;

    elementTableau tableau;
    tableau.taille = 0;

    for(int i = 0; i < 7 ; i++){
        tableau = ajouterTab(genererPersonne(),tableau);
    }
    
    affichageTab(tableau);

}