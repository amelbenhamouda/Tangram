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

//valgrind --leak-check=full ./Tangram

int main( int argc, char *argv[] ){
    int width = 1500, height = 1000;
    //int width = 1200, height = 600;
    Menu menu(width, height);
    Interface interface;
    int x, y ; //Point
    // Créé et affiche la fenêtre
    MLV_create_window( "Tangram", "", width, height);

    /* Displays buttons. */
    menu.drawMenu();
    MLV_wait_mouse(&x, &y);
    bool action = true;
    while (action){
        if (menu.inMenu(x, y) == 0) { // Jouer
            std::cout << "Jouer" << std::endl;
            // Afficher board
            interface.drawJeu(width, height);
            action = false;
        }
        else if (menu.inMenu(x, y) == 1) {
            std::cout << "Quitter" << std::endl;
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

