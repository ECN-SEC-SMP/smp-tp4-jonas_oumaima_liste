#include <string>
#ifndef TYPE_DEF
#define TYPE_DEF
using namespace std;

struct personne{
    string nom; 
    string prenom;
    string tel; // 10 chiffres dans un chaine de caractère sans espace
};

struct elementListe{
    personne pers;
    elementListe *suivant;
};

#endif