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
    personne personnetest2 = genererPersonne();

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

    liste = ajouter(personnetest2, liste);

    affichage(liste);



    

    cout << endl;
    cout << "Comparaison entre deux personnes : " << endl;
    cout << endl; 



}