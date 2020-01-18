#include "../include/menu.hpp"
#include "../include/button.hpp"

Menu::Menu(int width, int height) : width(width), height(height), buttons(0) {}

Menu::~Menu() {}

void Menu::drawMenu() {
    int y = height / 2;
    int widthButton = round(width / 6);
    int heightButton = round(height / 35);
    int interligne = 15;
    int x = width / 2;

    // x, y La coordonnée en X, Y de la position du coin Nord-Ouest de la boîte.
    buttons.push_back(Button<int>(x, y, widthButton, heightButton, "Jouer"));
    buttons.push_back(Button<int>(x, y + heightButton + interligne, widthButton, heightButton, "Quitter"));
    for (auto button : buttons){
        button.drawButton(interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE);
    }
}

int Menu::inMenu(int pX, int pY) {
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
