/*!
 *  \file menu.hpp
 *  \brief Header file of menu.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef MENU_H
#define MENU_H
	#include <iostream>	
	#include <MLV/MLV_all.h>
 	#include <vector>
	#include <cmath>
   	class Button;

   	/*! \class Menu
     *  \brief classe representant le menu du jeu
     *
     *  La classe gere le choix de l'utilisateur
     */
	class Menu {
		private:
			int width; /*!< La longeur de la fenêtre*/
			int height; /*!< La largeur de la fenêtre*/
			std::vector<Button> buttons; /*!< La liste des boutons du menu*/

	    public:
	    	/*!
	    	 *  \brief
	    	 *
			 *  \param width
			 *  \param height
			 */
	    	Menu(int width, int height);

	    	/*!
	    	 *  \brief
			 * 
			 */
            virtual~Menu();

            /*!
             *  \brief
			 * 
			 */
	    	void drawMenu();

	    	/*!
	    	 *  \brief
	    	 *
			 *  \param pX
			 *  \param pY
			 */
	    	int inMenu(int pX, int pY);
	};

#endif // MENU_H