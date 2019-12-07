/*!
 *  \file button.hpp
 *  \brief Header file of button.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef BUTTON_H
#define BUTTON_H
	#include <iostream>	
	#include <MLV/MLV_all.h>
	/*! \class Button
     *  \brief classe representant le bouton
     *
     *  La classe gere la création, l'affichage et l'interaction d'un bouton
     */
	class Button {
		private:        
            int x; /*!<  ... */
            int y; /*!<  ... */
            int width; /*!< La longeur de la fenêtre*/
			int height; /*!< La largeur de la fenêtre*/
            const std::string message; /*!<  ... */
            int interligne; /*!<  ... */
            MLV_Color borderColor; /*!<  ... */
            MLV_Color textColor; /*!<  ... */
            MLV_Color backgroundColor; /*!<  ... */

	    public:
	    	/*!
			 *  \brief
			 *
			 */
	    	Button();
	    	
	    	/*!
	    	 *  \brief
	    	 *
			 *  \param x
			 *  \param y
			 *  \param width
			 *  \param height
			 *  \param message
			 */
	    	Button(int x, int y, int width, int height, const std::string message);
            
            /*!
			 * 
			 */
            virtual~Button();
            
            /*!
             *  \brief
             *
			 *  \param interligne 
			 *  \param borderColor 
			 *  \param textColor 
			 *  \param backgroundColor
			 */
	    	void drawButton(int interligne, MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor);
	    	
	    	/*!
	    	 *  \brief
	    	 *
			 *  \param pX 
			 *  \param pY
			 */
	    	bool inButton(int pX, int pY);
	};

#endif // BUTTON_H