#include <string>
#ifndef TYPE_DEF
#define TYPE_DEF
using namespace std;

/*Définition d'une structure d'une personne*/
struct personne{
    string nom; 
    string prenom;
    string tel; // 10 chiffres dans un chaine de caractère sans espace
};
/*Définition d'une structure d'une liste a chaine simple*/
struct elementListe{
    personne pers;
    elementListe *suivant;
};

/*Définition d'un tableau*/

const int taillemax = 1000;

struct elementTableau{
    personne pers[taillemax];
    int taille;
};
#endif