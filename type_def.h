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

#endif