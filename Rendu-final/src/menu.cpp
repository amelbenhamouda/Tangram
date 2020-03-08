#include "../include/menu.hpp"
#include "../include/button.hpp"

Menu::Menu(const int width, const int height) : width(width), height(height), buttons(0) {}

Menu::~Menu() {}

void Menu::drawMenu() {
    int widthButton = round(width / 6);
    int heightButton = round(height / 35);
    int interligne = 15;
    
    MLV_Image *image = MLV_load_image("images/titre.jpg");
    int image_width, image_height;
    MLV_get_image_size(image, &image_width, &image_height);
    MLV_resize_image_with_proportions(image, image_width * 2, image_height * 2);
    MLV_get_image_size(image, &image_width, &image_height);
    int x_image = (width / 2) - (image_width / 2);
    int y_image = (height / 2) - (image_height / 2);
    MLV_draw_image(image, x_image, y_image - 100);

    // x, y La coordonnée en X, Y de la position du coin Nord-Ouest de la boîte.
    int x = (width / 2) - (widthButton / 2);
    int y = (height / 2) - (heightButton / 2);
    buttons.push_back(Button<int>(x, y, widthButton, heightButton, "Jouer"));
    buttons.push_back(Button<int>(x, y + heightButton + interligne, widthButton, heightButton, "Quitter"));
    for (auto button : buttons) {
        button.drawButton(interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE);
    }
    MLV_free_image(image);
}

int Menu::inMenu(const int pX, const int pY) {
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
