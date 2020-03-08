#include "../include/interface.hpp"
#include "../include/menu.hpp"
#include "../include/button.hpp"
#include <memory> 
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    constexpr int width = 1350, height = 700;
    Menu menu(width, height);
    Interface interface;
    int x, y ; //Point
    // Créé et affiche la fenêtre
    MLV_create_window( "Tangram", "", width, height);

    /* Displays buttons. */
    menu.drawMenu();
    MLV_actualise_window();
    MLV_wait_mouse(&x, &y);
    bool action = true;
    while (action) {
        if (menu.inMenu(x, y) == 0) { // Jouer
            // Afficher board
            interface.drawJeu(width, height);
            MLV_actualise_window();
            action = false;
        }
        else if (menu.inMenu(x, y) == 1) { //Quitter
            action = false;
            MLV_free_window();
            exit(EXIT_SUCCESS); 
        }
        else {
            MLV_wait_mouse(&x, &y);
        }
    }
    return 0;
}

