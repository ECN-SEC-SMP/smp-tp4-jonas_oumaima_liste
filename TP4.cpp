#include <ctime>
#include <iostream>
#include "utilitaires/utilitaires.h"
#include "utilitaire_generation/utilitaire_generation.h"
#include "repertoire/repertoire.h"
#include "type_def.h"
    
using namespace std;

int main(){

    personne personnetest1 = genererPersonne();
    personne personnetest2;
    
    personnetest2.nom = "David";
    personnetest2.prenom = "akny";
    personnetest2.tel = "0307214235";

    clock_t start = clock();
    elementListe* liste = nullptr;
    for(int i = 0; i < 999; i++) {
        liste = ajouterListe(genererPersonne(), liste);
    }
    liste = ajouterListe(personnetest2,liste);
    clock_t end = clock();

    double tempscreationliste = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    elementTableau tableau;
    tableau.taille = 0;
    for(int i = 0; i < 999; i++) {
        tableau = ajouterTab(genererPersonne(), tableau);
    }
    tableau = ajouterTab(personnetest2,tableau);
    end = clock();

    double tempscreationtab = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    affichageListe(liste);
    end = clock();

    double tempsaffliste = double(end - start)/ CLOCKS_PER_SEC;

    start = clock();
    affichageTab(tableau);
    end = clock();

    double tempsafftab = double(end - start)/ CLOCKS_PER_SEC;

    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Tests des utilitaires" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << endl;

    cout << endl;
    cout << "Affichage d'une personne aléatoire" << endl;
    cout << endl;

    cout <<endl;
    affichagePersonne(genererPersonne());


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
    cout << "----------------------------------------------------" << endl;
    cout << "Comparaison temporelles entre tableau et liste" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << endl;


    cout << endl;
    cout << "Temps de création pour d'une liste / tableau de 1000 personne : " << endl;
    cout << endl;

    cout << "Temps création liste : " << tempscreationliste << " s" << endl;
    cout << "Temps création tableau : " << tempscreationtab << " s" << endl;


    cout << endl;
    cout << "Temps d'affichage : " << endl;
    cout << endl;

    cout << "Temps d'affichage de la liste : " << tempsaffliste << "s" <<endl;
    cout << "Temps d'affichage du tableau : " << tempsafftab << "s" <<endl;


    cout << endl;
    cout << "Recherche d'une personne : " << endl;
    cout << endl; 

    start = clock();
    for(int i = 0; i < 100; i++) {
        personne p = genererPersonne();
        rechercheListe(p, liste);
    }
    end = clock();
    cout << "Temps recherche 100 personnes (liste) : " << double(end - start) / CLOCKS_PER_SEC << " s" << endl;

    start = clock();
    for(int i = 0; i < 100; i++) {
        personne p = genererPersonne();
        rechercheTab(p, tableau);
    }
    end = clock();
    cout << "Temps recherche 100 personnes (tableau) : " << double(end - start) / CLOCKS_PER_SEC << " s" << endl;

    cout << endl;
    cout << "Suppression d'une de 100 personnes : " << endl;
    cout << endl; 

    start = clock();
    for(int i = 0; i < 100; i++) {
        personne p = genererPersonne();
        liste = supprimerListe(p, liste);
    }
    end = clock();
    cout << "Temps suppression 100 personnes (liste) : " << double(end - start) / CLOCKS_PER_SEC << " s" << endl;

    start = clock();
    for(int i = 0; i < 100; i++) {
        personne p = genererPersonne();
        tableau = supprimerTab(p, tableau);
    }
    end = clock();
    cout << "Temps suppression 100 personnes (tableau) : " << double(end - start) / CLOCKS_PER_SEC << " s" << endl;

}