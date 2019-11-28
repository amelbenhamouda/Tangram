#include "../include/menu.hpp"

void Menu::drawButton() {
    int y = 500;
    int width = 250;
    int height = 2 * 15;
    int interligne = 15;
    int x = 750;

    // x, y	La coordonnée en X, Y de la position du coin Nord-Ouest de la boîte.
    MLV_draw_text_box(x, y, width, height, "Jouer", interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(x, y + height + interligne, width, height, "Quitter", interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
}

int Menu::inButton(int pX, int pY) {
	if (pX >= 750 and pX <= 1000 and pY >= 500 and pY <= 530) {  // Bouton Jouer
		return 1;
	}
	else if (pX >= 750 and pX <= 1000 and pY >= 545 and pY <= 575) {  // Bouton Quitter
		return 2;
	}
	return 0;
}






































// int inPictureOrButton(Clic clic) {
//     if ((clic.x >= 142 && clic.x <= 292) && (clic.y >= SIZE_PICTURE + (3 * IMAG_DEP_Y) && clic.y <= SIZE_PICTURE + (5 * IMAG_DEP_Y))) {
//         return 0;
//     }
//     else if ((clic.x >= 302  && clic.x <= 462) && (clic.y >= SIZE_PICTURE + (3 * IMAG_DEP_Y) && clic.y <= SIZE_PICTURE + (5 * IMAG_DEP_Y))) {
//         return 1;
//     }
//     else if ((clic.x >= 472 && clic.x <= 602) && (clic.y >= SIZE_PICTURE + (3 * IMAG_DEP_Y) && clic.y <= SIZE_PICTURE + (5 * IMAG_DEP_Y))) {
//         return 2;
//     }
//     else if ((clic.x >= 612  && clic.x <= 662) && (clic.y >= SIZE_PICTURE + (3 * IMAG_DEP_Y) && clic.y <= SIZE_PICTURE + (5 * IMAG_DEP_Y))) {
//         return 3;
//     }
//     else if ((clic.x >= 782 && clic.x <= 832) && (clic.y >= SIZE_PICTURE + (3 * IMAG_DEP_Y) && clic.y <= SIZE_PICTURE + (5 * IMAG_DEP_Y))) {
//         return 4;
//     }
//     else if ((clic.x >= 842 && clic.x <= 902) && (clic.y >= SIZE_PICTURE + (3 * IMAG_DEP_Y) && clic.y <= SIZE_PICTURE + (5 * IMAG_DEP_Y))) {
//         return 5;
//     }
//     else  if ((clic.x >= IMAG_DEP_X && clic.x <= SIZE_PICTURE + IMAG_DEP_X) && (clic.y >= IMAG_DEP_Y && clic.y <= SIZE_PICTURE + IMAG_DEP_Y)) {
//         return 6;
//     }
//     else if ((clic.x >= SIZE_WINDOW_H - SIZE_PICTURE - IMAG_DEP_X  && clic.x <= SIZE_WINDOW_H - IMAG_DEP_X) && (clic.y >= IMAG_DEP_Y && clic.y <= SIZE_PICTURE + IMAG_DEP_Y)) {
//         return 7;
//     }
//     return -1;
// }
