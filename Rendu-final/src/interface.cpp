#include "../include/interface.hpp"
#include "../include/rigth_triangle.hpp"
#include "../include/square.hpp"
#include "../include/parallelogram.hpp"
#include "../include/shape.hpp"
#include "../include/board.hpp"
#include "../include/menu.hpp"
#include "../include/button.hpp"

#include <memory> 
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

std::list<MLV_Color> figcolor(){
    std::list<MLV_Color> figloc;
    figloc.push_back(MLV_COLOR_GREEN);
    figloc.push_back(MLV_COLOR_PINK);
    figloc.push_back(MLV_COLOR_ORANGE);
    figloc.push_back(MLV_COLOR_BLUE);
    figloc.push_back(MLV_COLOR_CYAN);
    figloc.push_back(MLV_COLOR_MAGENTA);
    figloc.push_back(MLV_COLOR_YELLOW);
    return figloc;
}

void Interface::initialiseShared(int size, int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared) {
    shapeShared.clear();
    int allHeigth = height - 225;
    int allWidth = 50;

    try {
        shapeShared.push_back(std::make_shared<geometricShape::Square>(size, allWidth, allHeigth));
        shapeShared.push_back(std::make_shared<geometricShape::Parallelogram>(size, allWidth + 9 * (size + 15), allHeigth));
        shapeShared.push_back(std::make_shared<geometricShape::RigthTriangle>(size, allWidth + 1 * (size + 15), allHeigth));
        shapeShared.push_back(std::make_shared<geometricShape::RigthTriangle>(size, allWidth + 2 * (size + 15), allHeigth));
        shapeShared.push_back(std::make_shared<geometricShape::RigthTriangle>(size * 2, allWidth + 3 * (size + 15), allHeigth));
        shapeShared.push_back(std::make_shared<geometricShape::RigthTriangle>(size * 2, allWidth + 5 * (size + 15), allHeigth));
        shapeShared.push_back(std::make_shared<geometricShape::RigthTriangle>(round(size * sqrt(2)), allWidth + 7 * (size + 15), allHeigth));
        drawAllShapes(shapeShared, figcolor(), MLV_COLOR_RED); 
    }
    catch (std::bad_alloc & e) {
        std::cerr << "bad_alloc caught: " << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    MLV_actualise_window();
    return;
}

void Interface::initialiseMotif(int size, int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &motif) {
    motif.clear();
    int allHeigth = 250;
    int allWidth = 300;

    try {
        // Initialisation d'une figure de base - un lapin
        motif.push_back(std::make_shared<geometricShape::Square>(size, allWidth, allHeigth));
        motif.push_back(std::make_shared<geometricShape::Parallelogram>(size, allWidth + size * 2, allHeigth - size));
        motif[1]->rotateHW(80, 3);
        motif.push_back(std::make_shared<geometricShape::RigthTriangle>(size, allWidth - round(size / 3.3), allHeigth));
        motif[2]->rotateHW(-60, 1);
        motif.push_back(std::make_shared<geometricShape::RigthTriangle>(size, allWidth - round(size / 1.45), allHeigth - round(size / 2.7)));
        motif[3]->rotateHW(120, 0);
        motif.push_back(std::make_shared<geometricShape::RigthTriangle>(size * 2, allWidth + round(size / 0.9), allHeigth + 2.98 * size));
        motif[4]->rotateHW(100, 0);
        motif.push_back(std::make_shared<geometricShape::RigthTriangle>(size * 2, allWidth + round(size * 3.09), allHeigth + round(size * 2.62)));
        motif[5]->rotateHW(-80, 0);
        motif.push_back(std::make_shared<geometricShape::RigthTriangle>(round(size * sqrt(2)), allWidth + round(size * 2.4), allHeigth + round(size * 3.88)));
        motif[6]->rotateHW(-35, 0);
        drawAllShapes(motif, MLV_COLOR_BLACK, MLV_COLOR_ORANGE); 
    }
    catch (std::bad_alloc & e) {
        std::cerr << "bad_alloc caught: " << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    MLV_actualise_window();
    return;
}

void Interface::clone(std::vector<std::shared_ptr<geometricShape::Shape>> &clone, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared) {
    for (auto it : shapeShared) {
        auto  fig = it;
        clone.push_back(it);
    }
}

bool Interface::importDraw (const int n, const int size, std::vector<std::shared_ptr<geometricShape::Shape>> &motif) {
    std::ifstream importFig("savefig.txt");
    if (!importFig) {
        std::cout << "ERROR: Cannot open savefig.txt." << std::endl;
        return true;
    }

    int count = 1;
    while (true) {
        std::vector<double> pxloc;
        std::vector<double> pyloc;
        std::vector<double> centloc;
        double sizeloc;
        int x;
        double valx;
        double valy;
        importFig >> x;
        int countFig = 0;
        if (x > 0 && x <= 2) {
            countFig = 4;
        }
        else if (x >= 3 && x <= 7) {
            countFig = 3;
        }   
        else { 
            std::cout << "  Read error "<< std::endl; 
            break;
            return 0;
        }

        if (importFig.eof()) {
            std::cout << " Eof or figure n° " << n << " does not exist" << std::endl;
            return 0;
            break;
        }
        for (int i = 0; i < countFig; i++) {
            importFig >> valx;
            importFig >> valy;
            if (count == n) {
                pxloc.push_back(valx);
                pyloc.push_back(valy);
            }
        }
        importFig >> valx;
        importFig >> valy;
        if (count == n) {
            centloc.push_back(valx);
            centloc.push_back(valy);
        }
        importFig >> valx;
        if (count == n) {
            sizeloc = valx;
        }
        if (count == n) {
            switch(x) {
                case 1:
                    motif[0]->setShape(pxloc, pyloc, centloc, sizeloc);
                    break;
                case 2:
                    motif[1]->setShape(pxloc, pyloc, centloc, sizeloc);
                    break;
                case 3:
                    motif[2]->setShape(pxloc, pyloc, centloc, sizeloc);
                    break;
                case 4:
                    motif[3]->setShape(pxloc, pyloc, centloc, sizeloc);
                    break;
                case 5:
                    motif[4]->setShape(pxloc, pyloc, centloc, sizeloc);
                    break;
                case 6:
                    motif[5]->setShape(pxloc, pyloc, centloc, sizeloc);
                    break;
                case 7:
                    motif[6]->setShape(pxloc, pyloc, centloc, sizeloc);
                    break;
            }
        }
        if (x == 7 && count == n) {
            break;
        }
        if (x == 7) {
            count++; // si on fini un paquet de 7
        }
    }
    importFig.close();
    return true;
}

void Interface::saveFigure(int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &fig) {
    MLV_draw_filled_rectangle(round(width / 2) - 20, round(height / 2) - 20, 260, 90, MLV_COLOR_DIM_GREY);
    MLV_draw_rectangle(round(width / 2) - 20, round(height / 2) - 20, 260, 90, MLV_COLOR_BLACK);
    MLV_actualise_window();

    int interligne = 40;

    Button<int> button1 (round(width / 2), round(height / 2), 50, 100, "Save");
    Button<int> button2 (round(width / 2) + 120, round(height / 2), 50, 100, "Cancel");
    button1.drawButton(interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE);
    button2.drawButton(interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE);
    
    int xInside, yInside;
    MLV_wait_mouse(&xInside, &yInside);
    bool save = true;
    while (save) {
        if (button1.inButton(xInside, yInside)){
            std::cout << "Motif saved" << std::endl;
            saveDraw(fig);
            save = false;
        }
        else if (button2.inButton(xInside, yInside)){
            std::cout << "Cancel" << std::endl;
            save = false;
        }
        else {
            MLV_wait_mouse(&xInside, &yInside);
        }
    }
}

void save(int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &fig){
    int interligne = 40;
    MLV_draw_filled_rectangle(round(width / 2) - 20, round(height / 2) - 20, 260, 90, MLV_COLOR_DIM_GREY);
    MLV_draw_rectangle(round(width / 2) - 20, round(height / 2) - 20, 260, 90, MLV_COLOR_BLACK);
    MLV_actualise_window();
    MLV_draw_text_box(round(width / 2), round(height / 2), 100, 50,"Save", interligne , MLV_COLOR_GREY,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
    MLV_draw_text_box(round(width / 2) + 120, round(height / 2), 100, 50, "Cancel", interligne , MLV_COLOR_GREY,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    int xInside, yInside;
    MLV_wait_mouse(&xInside, &yInside);
    bool save = true;
    while (save) {
        if (xInside >= round(width / 2) and xInside <= round(width / 2) + 100 and yInside >= round(height / 2) and yInside <= round(height / 2) + 50) {  // Bouton Save
            std::cout << "Motif saved" << std::endl;
            saveDraw(fig);
            save = false;
        }
        else if (xInside >= round(width / 2) + 120 and xInside <= round(width / 2) + 220 and yInside >= round(height / 2) and yInside <= round(height / 2) + 50) {  // Bouton Cancel
            std::cout << "Cancel" << std::endl;
            save = false;
        }
        else {
            MLV_wait_mouse(&xInside, &yInside);
        }
    }
}

void Interface::drawJeu(int width, int height) {
    Board board(width, height);
    int numFig = 1;
    MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
    MLV_actualise_window();
    /* Loading contour. */
    int size = 100;
    MLV_Color motifBorder = MLV_COLOR_BLACK ;
    MLV_Color motifShape = MLV_COLOR_BLACK ;
    
    board.drawBoard();
    board.drawButtonForBoard(numFig);
    numFig++;
    std::vector<std::shared_ptr<geometricShape::Shape>> fig;
    initialiseShared(size, width, height, fig);

    std::vector<std::shared_ptr<geometricShape::Shape>> motif;
    initialiseMotif(size, width, height, motif);
    MLV_actualise_window();
    unsigned int nbFig = 1; // figure motif
    bool contour = false; 
    std::list<MLV_Color> colorfig = figcolor();
    while (1) {               
        int xInside, yInside;
        MLV_get_mouse_position(&xInside, &yInside);
        auto fig_i = colorfig.begin();
        std::for_each(fig.begin(), fig.end(), 
            [&xInside, &yInside, &fig, &motif, &motifBorder, &motifShape , &colorfig ,&fig_i](std::shared_ptr<geometricShape::Shape> it){ 
            it-> moveShape(xInside, yInside, fig, motif, motifShape, motifBorder , colorfig,fig_i);
            drawAllShapes(fig, colorfig, MLV_COLOR_RED);
            drawAllShapes(motif, motifShape, motifBorder);
            fig_i++;
        });
            
        if (areEqual(motif, fig) == 1) {
            std::cout << "equal" << std::endl;
            motifShape = MLV_COLOR_GREEN;
            drawAllShapes(fig, colorfig, MLV_COLOR_RED);
            drawAllShapes(motif, motifShape, motifBorder);
            MLV_actualise_window();
            int x2, y2;
            MLV_wait_mouse(&x2, &y2);
        }
        else {
            motifShape = MLV_COLOR_BLACK;
        }

        if (MLV_get_keyboard_state(MLV_KEYBOARD_LCTRL) == MLV_PRESSED && MLV_get_keyboard_state(MLV_KEYBOARD_s) == MLV_PRESSED) {
            /* Save a polygon for new figure */
            std::cout << "save" << std::endl;
            save(width, height, fig);
        }
        MLV_draw_filled_rectangle(round(width / 2) - 20, round(height / 2) - 20, 260, 90, MLV_COLOR_GRAY);
        drawAllShapes(motif, motifShape, motifBorder);
        drawAllShapes(fig, colorfig, MLV_COLOR_RED);
        bool next;
        if ((MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED)) {
            int bouton = board.inBoard(xInside, yInside);
            switch (bouton) {
                case 0: 
                    std::cout << "Fleche gauche" << std::endl;
	                if (nbFig > 0) {
                        nbFig--;
	                    drawAllShapes(fig, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
	                    drawAllShapes(motif, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
	                    importDraw(nbFig, size, motif);
	                    motifShape = MLV_COLOR_BLACK;
	                    drawAllShapes(motif, motifShape, motifBorder);
	                    initialiseShared(size, width, height, fig);
	                    drawAllShapes(fig, colorfig,MLV_COLOR_RED);
	                    board.drawButtonForBoard(nbFig);
	                    MLV_actualise_window();
	                };
	                break;
	            case 1: 
                    std::cout << "Num Fig" << std::endl;
                    break;
	            case 2: 
	                std::cout << "Fleche droite" << std::endl;
	                nbFig++;              
	                drawAllShapes(fig, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
	                drawAllShapes(motif, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
	                next = importDraw(nbFig, size, motif);
	                if (next == false) {
                        nbFig--;
                    } 
	                motifShape = MLV_COLOR_BLACK;
	                drawAllShapes(motif, motifShape, motifBorder);
	                initialiseShared(size, width, height, fig);
	                drawAllShapes(fig, colorfig, MLV_COLOR_RED);
	                board.drawButtonForBoard(nbFig);
	                MLV_actualise_window();
                    break;
                case 3: // Contour
                    std::cout << "Contour" << std::endl;

                    if ( contour == true ){
                        motifBorder = MLV_COLOR_ORANGE;
                    }
                    else if( contour == false){
                       motifBorder = MLV_COLOR_BLACK; 
                    }
                    contour = !contour;
                    drawAllShapes(motif, motifShape, motifBorder);
                    MLV_actualise_window();
	                break;
	            case 4: // Quitter
	                std::cout << "Sauvegarde" << std::endl;
                    save(width, height, fig);
                    break;
                case 5: // Quitter
                    std::cout << "Quitter" << std::endl;
                    MLV_free_window();
                    exit(EXIT_SUCCESS); 
                    break;
	            default: break;
	        }
	       // MLV_wait_milliseconds(500);
	    }
        MLV_actualise_window();
    }
}
