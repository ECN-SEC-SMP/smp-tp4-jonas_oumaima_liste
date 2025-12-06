#include <ctime>
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

    // Mesure création répertoire liste
    clock_t start = clock();
    elementListe* liste = nullptr;
    for(int i = 0; i < 1000; i++) {
        liste = ajouterListe(genererPersonne(), liste);
    }
    clock_t end = clock();
    std::cout << "Temps création liste : " << double(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    // Mesure création répertoire tableau
    start = clock();
    elementTableau tableau;
    tableau.taille = 0;
    for(int i = 0; i < 1000; i++) {
        tableau = ajouterTab(genererPersonne(), tableau);
    }
    end = clock();
    std::cout << "Temps création tableau : " << double(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    cout << endl;
    cout << "Recherche d'une personne : " << endl;
    cout << endl; 

    cout << "David est a la " << rechercheListe(personnetest2,liste) << " position"<<endl;

    cout << endl;
    cout << "Suppression de David" << endl;
    cout << endl;

    liste = supprimerListe(personnetest2,liste);

    affichageListe(liste);

    cout << endl;
    cout << "Test des tableau : " << endl;
    cout << endl;


    cout << endl;
    cout << "Recherche dans le tableau : " << endl;
    cout << endl;

    cout << "David est a la " << rechercheTab(personnetest2, tableau) << " position"<<endl;

    cout << endl;
    cout << "Suppression de David" << endl;
    cout << endl;
    
    tableau = supprimerTab(personnetest2,tableau);

    affichageTab(tableau);

    // Mesure affichage liste
    start = clock();
    affichageListe(liste);
    end = clock();
    std::cout << "Temps affichage liste : " << double(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    // Mesure affichage tableau
    start = clock();
    affichageTab(tableau);
    end = clock();
    std::cout << "Temps affichage tableau : " << double(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    // Mesure recherche de 100 personnes
    start = clock();
    for(int i = 0; i < 100; i++) {
        personne p = genererPersonne();
        rechercheListe(p, liste);
    }
    end = clock();
    std::cout << "Temps recherche 100 personnes (liste) : " << double(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    start = clock();
    for(int i = 0; i < 100; i++) {
        personne p = genererPersonne();
        rechercheTab(p, tableau);
    }
    end = clock();
    std::cout << "Temps recherche 100 personnes (tableau) : " << double(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    // Mesure suppression de 100 personnes
    start = clock();
    for(int i = 0; i < 100; i++) {
        personne p = genererPersonne();
        liste = supprimerListe(p, liste);
    }
    end = clock();
    std::cout << "Temps suppression 100 personnes (liste) : " << double(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    start = clock();
    for(int i = 0; i < 100; i++) {
        personne p = genererPersonne();
        tableau = supprimerTab(p, tableau);
    }
    end = clock();
    std::cout << "Temps suppression 100 personnes (tableau) : " << double(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

}