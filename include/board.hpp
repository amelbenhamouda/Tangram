#ifndef BOARD_H
#define BOARD_H
	#include <iostream>	
	#include <MLV/MLV_all.h>
   
	class Board {
	    public :
	    	void drawBoard();
	    	int inBoard(int pX, int pY);
	    	void drawModel(const char * fileImage);
	    	void drawButton(int numFig);
	    	int inButton(int pX, int pY);
	};

#endif