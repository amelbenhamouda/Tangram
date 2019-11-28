#include "../include/board.hpp"

void Board::drawBoard() {
    MLV_draw_filled_rectangle(40, 30, 1150, 950, MLV_COLOR_GRAY);
	MLV_actualise_window();
}

int Board::inBoard(int pX, int pY){
	if (pX >= 40 and pX <= 740 and pY >= 30 and pY <= 580) { 
		return 1;
	}
	return 0;
}

void Board::drawModel(const char * fileImage) {
	MLV_Image *image = MLV_load_image(fileImage);
	MLV_draw_image(image, 1200, 200);
	MLV_resize_image_with_proportions(image, 500, 500);
	MLV_actualise_window();
}

void Board::drawButton(int numFig) {
    int y = 500;
    int width = 250;
    int height = 2 * 15;
    int interligne = 15;
    int x = 1200;

    // x, y	La coordonnée en X, Y de la position du coin Nord-Ouest de la boîte.
    MLV_draw_text_box(x, y, 25, height, "<-", interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(x + interligne + height, y, 25, height, (std::to_string(numFig)).c_str(), interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(x + (interligne + height) * 2, y, 25, height, "->", interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(x, y + height + interligne, width, height, "Contour", interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(x, y + (height * 2) + (interligne * 2), width, height, "Quitter", interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
   
    MLV_actualise_window();
}

int Board::inButton(int pX, int pY) {
	if (pX >= 1200 and pX <= 1225 and pY >= 500 and pY <= 530) {  // Bouton fleche gauche
		return 1;
	}
	else if (pX >= 1245 and pX <= 1270 and pY >= 500 and pY <= 530) {  // Bouton Numero
		return 2;
	}
	else if (pX >= 1290 and pX <= 1315 and pY >= 500 and pY <= 530) {  // Bouton fleche droite
		return 3;
	}
	else if (pX >= 1200 and pX <= 1450 and pY >= 545 and pY <= 575) {  // Bouton Contour
		return 4;
	}
	else if (pX >= 1200 and pX <= 1450 and pY >= 590 and pY <= 620) {  // Bouton Quitter
		return 5;
	}
	return 0;
}
