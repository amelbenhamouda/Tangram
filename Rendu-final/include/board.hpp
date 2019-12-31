/*!
 *  \file board.hpp
 *  \brief Header file of board.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef BOARD_H
#define BOARD_H
	#include <iostream>	
	#include <MLV/MLV_all.h>
   	#include <vector>
	#include <cmath>
	template<class T> 
   	class Button;
   	/*! \class Board
     *  \brief classe representant le plateau de jeu
     *
     *  La classe gere l'affichage du plateau et des pièces.
     */
	class Board {
		private:
			int width; /*!< La longeur de la fenêtre*/
			int height; /*!< La largeur de la fenêtre*/
			std::vector<Button<int>> buttons; /*!< La liste des boutons du plateau*/

	    public:
	    	/*!
		     *  \brief Constructeur
		     *
		     *  Constructeur de la classe Board
		     *
		     *  \param width : longeur de la fenêtre
		     *  \param height : largeur de la fenêtre
		     */
	    	Board(int width, int height);

	    	/*!
		     *  \brief Destructeur
		     *
		     *  Destructeur de la classe Board
		     */
            virtual~Board();

            /*!
             *  \brief
			 * 
			 */
	    	void drawBoard();

	    	/*!
	    	 *  \brief
	    	 *
			 *  \param numFig
			 */
	    	void drawButtonForBoard(int numFig);

	    	/*!
	    	 *  \brief
	    	 *
			 *  \param pX
 			 *  \param pY
			 */
	    	int inBoard(int pX, int pY);
	};

#endif // BOARD_H