/*!
 *  \file menu.hpp
 *  \brief Le fichier d'entête de menu.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef MENU_H
#define MENU_H
	#include <iostream>	
	#include <MLV/MLV_all.h>
 	#include <vector>
	#include <cmath>
	
	/*! \class Button
     *  \brief Déclaration de l'objet Button.
     *
     *  \tparam T Type associé à un bouton (int, double,...).
     */
	template<class T> 
   	class Button;

   	/*! \class Menu
     *  \brief Classe représentant le menu du jeu.
     *
     *  La classe gére le choix de l'utilisateur.
     */
	class Menu {
		private:
			int width; /*!< La longeur de la fenêtre. */
			int height; /*!< La largeur de la fenêtre. */
			std::vector<Button<int>> buttons; /*!< La liste des boutons du menu. */

	    public:
	    	/*!
	    	 *  \brief Constructeur de Menu.
	    	 *
			 *  \param width : La longeur de la fenêtre.
		     *  \param height : La largeur de la fenêtre.
			 */
	    	Menu(int width, int height);

	    	/*!
	    	 *  \brief Destructeur de Menu.
			 * 
			 *  Destructeur de la classe Menu déclaré en virtuel.
             *  Le destructeur n'a pas d'implémentation car les attributs sont statics.
			 */
            virtual~Menu();

            /*!
             *  \brief Affiche le menu principale lors du lancement du jeu.
			 * 
			 *  Affiche les boutons et logo du jeu.
			 */
	    	void drawMenu();

	    	/*!
	    	 *  \brief Savoir si on a cliqué sur le bouton
	    	 *
	    	 *  Renvoie un entier en fonction du bouton cliqué.
	    	 *
			 *  \param pX : La coordonnée x du clic de la souris.
             *  \param pY : La coordonnée y du clic de la souris.
			 */
	    	int inMenu(int pX, int pY);
	};

#endif // MENU_H