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
	template<class T> 
	class Button {
		private:        
            T x; /*!<  ... */
            T y; /*!<  ... */
            T width; /*!< La longeur de la fenêtre*/
			T height; /*!< La largeur de la fenêtre*/
            std::string message; /*!<  ... */
            T interligne; /*!<  ... */
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
	    	Button(T x, T y, T width, T height, const std::string message);
            
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
	    	void drawButton(T interligne, MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor);
	    	
	    	/*!
	    	 *  \brief
	    	 *
			 *  \param pX 
			 *  \param pY
			 */
	    	bool inButton(T pX, T pY);
	};

	template <class T>
	Button<T>::Button() : x(0), y(0), width(0), height(0), message(0), interligne(0), borderColor(MLV_COLOR_BLACK), textColor(MLV_COLOR_BLACK), backgroundColor(MLV_COLOR_BLACK) {}
	template <class T>
	Button<T>::Button(T x, T y, T width, T height, const std::string message) : x(x), y(y), width(width), height(height), message(message), interligne(0), borderColor(MLV_COLOR_BLACK), textColor(MLV_COLOR_BLACK), backgroundColor(MLV_COLOR_BLACK) {}
	template <class T>
	Button<T>::~Button(){}

	template <typename T>
	void Button<T>::drawButton(T interligne, MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor) {
	    // x, y	La coordonnée en X, Y de la position du coin Nord-Ouest de la boîte.
	    const char * cstr = message.c_str();
	    MLV_draw_text_box(x, y, width, height, cstr, interligne, borderColor, textColor, backgroundColor, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	}

	template <typename T>
	bool Button<T>::inButton(T pX, T pY) {
		if (pX >= x and pX <= (x + width) and pY >= y and pY <= (y + height)) {
			return 1;
		}
		return 0;
	}

#endif // BUTTON_H