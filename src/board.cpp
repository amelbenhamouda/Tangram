#include "../include/board.hpp"
#include "../include/button.hpp"

Board::Board(int width, int height) : width(width), height(height), buttons(0) {}

Board::~Board() {}

void Board::drawBoard() {
    MLV_draw_filled_rectangle(40, 30, width - (round(width / 6) * 2), height - (round(height / 35) * 2), MLV_COLOR_GRAY);
	MLV_actualise_window();
}

void Board::drawButtonForBoard(int numFig) {
    int y = height / 2;
    int widthButton = round(width / 6);
    int heightButton = round(height / 35);
    int interligne = 15;
    int x = width - 300;
    int size = 25;

    // x, y La coordonnée en X, Y de la position du coin Nord-Ouest de la boîte.
    buttons.push_back(Button(x, y, size, heightButton, "<-"));
    buttons.push_back(Button(x + heightButton + interligne, y, size, heightButton, (std::to_string(numFig)).c_str()));
    buttons.push_back(Button(x + (interligne + heightButton) * 2, y, size, heightButton, "->"));
    buttons.push_back(Button(x, y + heightButton + interligne, widthButton, heightButton, "Contour"));
    buttons.push_back(Button(x, y + (heightButton * 2) + (interligne * 2), widthButton, heightButton, "Quitter"));

    for (auto button : buttons) {
        button.drawButton(interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE);
    }
}

int Board::inBoard(int pX, int pY) {
	int count = 0;
    for (auto button : buttons) {
        bool ibout = button.inButton(pX, pY);
        if (ibout == true) {
            break;
        }
        count++;
    }
    return count;
}
