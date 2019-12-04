#ifndef MENU_H
#define MENU_H
	#include <iostream>	
	#include <MLV/MLV_all.h>
 	#include <vector>
	#include <cmath>
   	class Button;
	class Menu {
		private:
			int width;
			int height;
			std::vector<Button> buttons;
	    public:
	    	Menu(int width, int height);
            virtual~Menu();
	    	void drawMenu();
	    	int inMenu(int pX, int pY);
	};

#endif //MENU_H