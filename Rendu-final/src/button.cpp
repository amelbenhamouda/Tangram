#include "../include/button.hpp"
Button::Button():x(0), y(0), width(0), height(0), message(0), interligne(0), borderColor(MLV_COLOR_BLACK), textColor(MLV_COLOR_BLACK), backgroundColor(MLV_COLOR_BLACK) {}

Button::Button(int x, int y, int width, int height, const std::string message) : x(x), y(y), width(width), height(height), message(message), interligne(0), borderColor(MLV_COLOR_BLACK), textColor(MLV_COLOR_BLACK), backgroundColor(MLV_COLOR_BLACK) {}

Button::~Button(){}

void Button::drawButton(int interligne, MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor) {
    // x, y	La coordonnée en X, Y de la position du coin Nord-Ouest de la boîte.
    const char * cstr = message.c_str();
    MLV_draw_text_box(x, y, width, height, cstr, interligne, borderColor, textColor, backgroundColor, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
   // MLV_actualise_window();
}

bool Button::inButton(int pX, int pY) {
	if (pX >= x and pX <= (x + width) and pY >= y and pY <= (y + height)) {
		return 1;
	}
	return 0;
}
