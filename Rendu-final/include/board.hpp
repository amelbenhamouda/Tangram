/*!
 *  \file board.hpp
 *  \brief Le fichier d'entête de board.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef BOARD_H
#define BOARD_H
	#include <iostream>	
	#include <MLV/MLV_all.h>
   	#include <map>
	#include <cmath>

	/*! \class Button
     *  \brief Déclaration de l'objet Button.
     *
     *  \tparam T Type associé à un bouton (int, double,...).
     */
	template<class T> 
   	class Button;

   	/*! \class Board
     *  \brief Classe représentant le plateau de jeu.
     *
     *  La classe gére l'affichage du plateau et des pièces.
     */
	class Board {
		private:
			int width; /*!< La longeur de la fenêtre. */
			int height; /*!< La largeur de la fenêtre. */
			std::map<int, Button<int>> buttons; /*!< La liste des boutons du plateau. */

	    public:
	    	/*!
		     *  \brief Constructeur de Board.
		     *
		     *  Constructeur de la classe Board.
		     *
		     *  \param width : La longeur de la fenêtre.
		     *  \param height : La largeur de la fenêtre.
		     */
	    	Board(int width, int height);

	    	/*!
		     *  \brief Destructeur de Board.
		     *
		     *  Destructeur de la classe Board.
		     */
            virtual~Board();

            /*!
             *  \brief Affiche un plateau gris.
			 * 
			 *   Fonction qui dessine le plateau de jeu (gris).
			 */
	    	void drawBoard();

	    	/*!
	    	 *  \brief Création des boutons pour le jeu.
	    	 *
			 *  \param numFig : Le numéro de la figure que le joueur essaie de résoudre.
			 */
	    	void createButtonForBoard(unsigned int numFig) ;

	    	/*!
	    	 *  \brief Affiche les boutons pour le jeu.
	    	 *
			 *  \param numFig : Le numéro de la figure que le joueur essaie de résoudre.
			 */
	    	void drawButtonForBoard(unsigned int numFig);

	    	/*!
	    	 *  \brief Savoir si on a cliqué sur le bouton
	    	 *
	    	 *  Renvoie un entier en fonction du bouton cliqué.
	    	 *
			 *  \param pX : La coordonnée x du clic de la souris.
             *  \param pY : La coordonnée y du clic de la souris.
			 */
	    	int inBoard(int pX, int pY);
	};

#endif // BOARD_H