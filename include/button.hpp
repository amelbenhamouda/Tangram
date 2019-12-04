/**
 * \file button.hpp
 * \brief Header file of button.cpp.
 * \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef BUTTON_H
#define BUTTON_H
	#include <iostream>	
	#include <MLV/MLV_all.h>
   
	class Button {
		private:        
            int x;
            int y;
            int width;
            int height;
            const std::string message;
            int interligne;
            MLV_Color borderColor;
            MLV_Color textColor;
            MLV_Color backgroundColor;
	    public:
	    	Button();
	    	Button(int x, int y, int width, int height, const std::string message);
            virtual~Button();
	    	void drawButton(int interligne, MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor);
	    	bool inButton(int pX, int pY);
	};

#endif //BUTTON_H