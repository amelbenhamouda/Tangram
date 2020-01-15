#include "../include/board.hpp"
#include "../include/button.hpp"

Board::Board(int width, int height) : width(width), height(height), buttons() {}

Board::~Board() {}

void Board::drawBoard() {
    MLV_draw_filled_rectangle(40, 30, width - (round(width / 6) * 2) + 150, height - (round(height / 35) * 2), MLV_COLOR_GRAY);
	MLV_actualise_window();
}

void Board::drawButtonForBoard(unsigned int numFig) {
    int y = height / 2;
    int widthButton = round(width / 6);
    int heightButton = round(height / 35);
    int interligne = 15;
    int x = width - 300;
    int size = 25;
    std::cout << "std(numfig) " <<(std::to_string(numFig)).c_str() << std::endl;
    std::cout << "map size: " << buttons.size() << std::endl;
    // x, y La coordonnée en X, Y de la position du coin Nord-Ouest de la boîte.
    buttons.clear();
    buttons.insert(std::make_pair(1,Button<int>(x, y, size, heightButton, "<-")));
    buttons.insert(std::make_pair(2,Button<int>(x + heightButton + interligne, y, size, heightButton, (std::to_string(numFig)).c_str())));
    buttons.insert(std::make_pair(3,Button<int>(x + (interligne + heightButton) * 2, y, size, heightButton, "->")));
    buttons.insert(std::make_pair(4,Button<int>(x, y + heightButton + interligne, widthButton, heightButton, "Contour")));
    buttons.insert(std::make_pair(5,Button<int>(x, y + (heightButton * 2) + (interligne * 2), widthButton, heightButton, "Sauvegarder")));
    buttons.insert(std::make_pair(6,Button<int>(x, y + (heightButton * 3) + (interligne * 3), widthButton, heightButton, "Quitter")));
    std::cout << "map size: " << buttons.size() << std::endl;
    for (auto button : buttons) {
        std::cout << "draw buton"<< std::endl;
        button.second.drawButton(interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE);
    }
    
}

int Board::inBoard(int pX, int pY) {
	int count = 0;
    for (auto button : buttons) {
        bool ibout = button.second.inButton(pX, pY);
        if (ibout == true) {
            break;
        }
        count++;
    }
    return count;
}
