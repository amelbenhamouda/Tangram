Tangram
=======

Projet du jeu Tangram programmé en C++ à l'aide de la librairie MLV.

Installation
============

## Dependence
    * 'MLV' http://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/index.html
    * (optional) 'Doxygen' si on veut de la documentation du code.

## Compilation tester
    * g++ 6.3.0
    * g++ 7.4.0

Utilisation
===========

## Exécutable
    * Créer un dossier "bin" dans le même répertoire que les dossiers "src" et "include" si necéssaire.
    * make dans le dossier Tangram.
    * ./Tangram pour lancer l'exécutable.
    
## Interface du jeu
	* bouton "Solution" pour afficher une aide pour résoudre la figure.
	* bouton "Sauvegarder" pour sauvegarder une nouvelle figure.
	* bouton "<-" et "->" pour changer de figure, les données des figures sont contenues dans le fichier savefig.txt
	* bouton "Quitter" pour quitter le jeu.

## Commandes du jeu
	* clique gauche pour les événement lier aux boutons.
	* clique gauche sur une figure pour la sélectionner.
	* clique gauche en dehors de la figure pour la désélectionner.
	* quand la figure est sélectionner :
		* clique droit pour la rotation.
		* clique gauche + droit pour la rotation lente.
		* clique molette symétrie.
	* ctrl+s pour sauvegarder une figure (en plus du bouton).

Notes
=====

## Authors
    * BEN HAMOUDA Amel (Université Paris-Est Marne-la-Vallee, France)
    * DURAND Aurélien (Université Paris-Est Marne-la-Vallee, France)

