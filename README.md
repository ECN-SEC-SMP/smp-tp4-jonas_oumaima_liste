
# Compte Rendu TP4 - Gestion de listes chaînées

**Auteurs :** Jonas & Oumaima
**Date :** 7 décembre 2025

**Objectif :** Implémenter et manipuler des listes chaînées en C (insertion, suppression, recherche, affichage, génération aléatoire, etc.)

---

## Table des matières

1. [Introduction](#introduction)
2. [Architecture du projet](#architecture)
3. [Fonctionnalités implémentées](#fonctionnalités)
4. [Jeux d'essai et résultats](#jeux-dessai)
5. [Conclusion](#conclusion)

---


## 1. Introduction

L’objectif de ce TP est de créer et de manipuler concrètement deux structures de données fondamentales : le tableau trié et la liste chaînée triée. Le but est de comparer les temps d’exécution des opérations de base (ajout, recherche, suppression, affichage) sur ces deux structures.

Le thème du TP est l’organisation d’informations relatives à des personnes à travers la gestion d’un répertoire. Chaque élément du répertoire correspond à une personne, contenant son nom, prénom et numéro de téléphone. Le répertoire est représenté à la fois par :
- un **tableau trié**
- une **liste chaînée triée**

L’ordre des éléments est défini d’abord par le nom, puis le prénom, puis le numéro de téléphone.

Les opérations implémentées sont :
- **Création d’une structure (liste ou tableau)**
- **Insertion (ajout) d’un élément**
- **Suppression d’un élément**
- **Recherche d’un élément**
- **Affichage de la structure**
- **Génération aléatoire de données**
- **Chargement depuis un fichier**

L’ensemble du TP permet ainsi de comparer concrètement l’efficacité et la simplicité d’utilisation de ces deux structures pour la gestion d’un répertoire de personnes.

  

---


## 2. Architecture du projet

### Structure des fichiers

```
smp-tp4-jonas_oumaima_liste/
├── TP4.cpp                # Programme principal
├── type_def.h             # Définitions des structures (liste chaînée)
├── repertoire/            # Fonctions de gestion du répertoire (ajout, suppression, recherche)
│   ├── repertoire.cpp
│   └── repertoire.h
├── utilitaire_generation/ # Génération aléatoire de listes
│   ├── utilitaire_generation.cpp
│   └── utilitaire_generation.h
├── utilitaires/           # Fonctions utilitaires diverses
│   ├── utilitaires.cpp
│   └── utilitaires.h
├── Noms_TP4.txt           # Fichier de noms pour génération
├── Prenoms_TP4.txt        # Fichier de prénoms pour génération
├── Makefile               # Compilation du projet
└── README.md              # Ce rapport
```


### Structures de données

#### Structure d'une personne
```cpp
struct personne {
        string nom;
        string prenom;
        string tel; // 10 chiffres dans une chaîne de caractères
};
```

#### Structure d'une liste chaînée simple
```cpp
struct elementListe {
        personne pers;
        elementListe *suivant;
};
```

#### Structure d'un tableau de personnes
```cpp
const int taillemax = 1000;
struct elementTableau {
        personne pers[taillemax];
        int taille;
};
```

---

## Spécifications des fonctions utilitaires

### Génération et création
- `personne genererPersonne();`  
Génère une personne aléatoire (nom, prénom, téléphone).
- `elementListe* creerElementListe(personne p);`  
Crée un élément de liste à partir d'une personne.

### Affichage
- `void affichagePersonne(personne p);`  
Affiche les informations d'une personne.
- `void affichageListe(elementListe* liste);`  
Affiche tous les éléments d'une liste chaînée.
- `void affichageTab(elementTableau tab);`  
Affiche tous les éléments d'un tableau.

### Comparaison et égalité
- `bool egalitePersonne(personne p1, personne p2);`  
Retourne vrai si deux personnes sont identiques (nom, prénom, tel).
- `bool comparerPersonne(personne p1, personne p2);`  
Retourne vrai si p1 < p2 selon l'ordre nom, prénom, tel.

### Recherche
- `int rechercheListe(personne p, elementListe* liste);`  
Retourne la position de la personne dans la liste, -1 si absente.
- `int rechercheTab(personne p, elementTableau tab);`  
Retourne la position de la personne dans le tableau, -1 si absente.

### Ajout
- `elementListe* ajouterListe(personne p, elementListe* liste);`  
Ajoute une personne à la bonne position dans la liste triée (pas de doublon).
- `elementTableau ajouterTab(personne p, elementTableau tab);`  
Ajoute une personne à la bonne position dans le tableau trié (pas de doublon).

### Suppression
- `elementListe* supprimerListe(personne p, elementListe* liste);`  
Supprime une personne de la liste si elle existe.
- `elementTableau supprimerTab(personne p, elementTableau tab);`  
Supprime une personne du tableau si elle existe.

---

## Algorithmes principaux (résumé)

### Ajout dans la liste triée
1. Créer un nouvel élément pour la personne.
2. Si la liste est vide, le nouvel élément devient la tête.
3. Parcourir la liste :
     - Si la personne existe déjà, ne rien faire.
     - Si la personne doit être insérée avant l’élément courant, l’insérer à cette position.
     - Sinon, avancer.
4. Si la fin est atteinte, insérer à la fin.

### Ajout dans le tableau trié
1. Parcourir le tableau :
     - Si la personne existe déjà, ne rien faire.
     - Si la personne doit être insérée avant l’élément courant, décaler les éléments suivants et insérer.
2. Si la fin est atteinte, insérer à la fin.

### Affichage
Parcours simple de la structure (liste ou tableau), affichage de chaque personne.

### Recherche
Parcours séquentiel de la structure, retour de la position si trouvée, -1 sinon.

### Suppression dans la liste
1. Parcourir la liste pour trouver la personne.
2. Si trouvée, relier l’élément précédent au suivant et libérer la mémoire.
3. Si absente, ne rien faire.

### Suppression dans le tableau
1. Chercher la position de la personne.
2. Si trouvée, décaler les éléments suivants vers la gauche.
3. Si absente, ne rien faire.

---

## Commentaires sur les cas normaux et limites

- **Ajout** :
    - Cas normal : insertion à la bonne position, pas de doublon.
    - Cas limite : ajout en tête, en queue, dans une structure vide, ou structure pleine (tableau).
- **Affichage** :
    - Cas normal : affichage de tous les éléments.
    - Cas limite : affichage d’une structure vide (message spécifique).
- **Recherche** :
    - Cas normal : la personne est trouvée à une position quelconque.
    - Cas limite : la personne n’existe pas (retour -1), recherche en tête ou en queue.
- **Suppression** :
    - Cas normal : suppression d’un élément existant.
    - Cas limite : suppression en tête, en queue, d’un élément unique, ou d’un élément absent (pas de modification).

---

---


## 3. Fonctionnalités implémentées

### 3.1 Création et affichage d'une liste ou d'un tableau

**But :** Initialiser une liste ou un tableau vide et afficher son contenu.

**Code clé :**
```cpp
void affichageListe(elementListe *liste);
void affichageTab(elementTableau tab);
```

### 3.2 Ajout d'un élément (liste ou tableau)

**But :** Ajouter une personne à la bonne position dans la structure triée (pas de doublon).

**Code clé :**
```cpp
elementListe *ajouterListe(personne personne, elementListe *liste);
elementTableau ajouterTab(personne personne, elementTableau tab);
```

### 3.3 Suppression d'un élément (liste ou tableau)

**But :** Supprimer une personne de la structure si elle existe.

**Code clé :**
```cpp
elementListe *supprimerListe(personne personne, elementListe *liste);
elementTableau supprimerTab(personne personne, elementTableau tab);
```

### 3.4 Recherche d'un élément (liste ou tableau)

**But :** Rechercher une personne dans la structure.

**Code clé :**
```cpp
int rechercheListe(personne personne, elementListe *liste);
int rechercheTab(personne personne, elementTableau tab);
```

### 3.5 Génération et utilitaires

**But :** Générer une personne aléatoire, créer un élément de liste, comparer ou afficher des personnes.

**Code clé :**
```cpp
personne genererPersonne();
elementListe *creerElementListe(personne personne);
void affichagePersonne(personne personne);
bool egalitePersonne(personne personne1, personne personne2);
bool comparerPersonne(personne personne1, personne personne2);
```

---



## 4. Jeux d'essai et résultats

### 🧪 Test 1 : Affichage d'une liste générée

**Objectif :** Vérifier la génération et l'affichage d'une liste de personnes à partir des fichiers fournis.

#### Données d'entrée
- Fichiers : `Noms_TP4.txt`, `Prenoms_TP4.txt`
- Génération automatique de plusieurs personnes

#### Résultat obtenu (extrait)
```
[(1000, cssy, 0546966938); (Adam, martín, 0742075153); (Adam, vttora, 0171692234); ...]
```
La liste générée contient de nombreux éléments, chacun avec un nom, prénom et numéro.

#### ✅ Validation
- Génération et affichage corrects, données variées

---

### 🧪 Test 2 : Affichage d'une personne aléatoire

**Objectif :** Vérifier la génération et l'affichage d'une personne aléatoire.

#### Résultat obtenu
```
Affichage d'une personne aléatoire

(Bergeron, vck, 0779251461);
```
#### ✅ Validation
- Affichage conforme

---

### 🧪 Test 3 : Comparaison et égalité entre personnes

**Objectif :** Vérifier la comparaison et l'égalité entre deux personnes.

#### Résultat obtenu
```
Egalité entre deux personne :

Daneau
David

Ce ne sont pas les mêmes personnes

Comparaison entre deux personnes :

Daneau est avant David
```
#### ✅ Validation
- Les fonctions de comparaison et d'égalité fonctionnent

---

### 🧪 Test 4 : Mesures de performance (liste vs tableau)

**Objectif :** Comparer les temps de création, d'affichage, de recherche et de suppression entre une liste chaînée et un tableau.

#### Résultat obtenu
```
Temps de création pour d'une liste / tableau de 1000 personne :

Temps création liste : 0.482118 s
Temps création tableau : 0.428345 s

Temps d'affichage :

Temps d'affichage de la liste : 0.00033s
Temps d'affichage du tableau : 0.000327s

Recherche d'une personne :

Temps recherche 100 personnes (liste) : 0.046236 s
Temps recherche 100 personnes (tableau) : 0.042603 s

Suppression d'une de 100 personnes :

Temps suppression 100 personnes (liste) : 0.042302 s
Temps suppression 100 personnes (tableau) : 0.045763 s
```
#### ✅ Validation
- Les performances sont mesurées et comparées, les deux structures sont efficaces pour ces opérations

---


## 5. Conclusion

### Objectifs atteints ✅

- ✅ Implémentation complète des opérations sur listes chaînées (création, insertion, suppression, recherche, affichage)
- ✅ Génération et chargement de listes depuis fichiers de noms/prénoms
- ✅ Comparaison fonctionnelle et temporelle entre listes chaînées et tableaux
- ✅ Tests exhaustifs sur différents cas, avec mesures de performance
- ✅ Résultats conformes aux attentes et sans dépendance à des images

---
## Annexes

### Compilation
```bash
make
```
### Exécution
```bash
./tp4_liste
```
### Nettoyage
```bash
make clean
```

---

**Fin du rapport**