#ifndef BOARD_H
#define BOARD_H
	#include <iostream>	
	#include <MLV/MLV_all.h>
   	#include <vector>
	#include <cmath>
   	class Button;
	class Board {
		private:
			int width;
			int height;
			std::vector<Button> buttons;
	    public:
	    	Board(int width, int height);
            virtual~Board();
	    	void drawBoard();
	    	void drawButtonForBoard(int numFig);
	    	int inBoard(int pX, int pY);
	};

#endif