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

std::list<MLV_Color> figcolor() {
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
std::list<MLV_Color> figWincondition() {
    std::list<MLV_Color> figloc;
    figloc.push_back(MLV_COLOR_GREEN);
    figloc.push_back(MLV_COLOR_GREEN);
    figloc.push_back(MLV_COLOR_GREEN);
    figloc.push_back(MLV_COLOR_GREEN);
    figloc.push_back(MLV_COLOR_GREEN);
    figloc.push_back(MLV_COLOR_GREEN);
    figloc.push_back(MLV_COLOR_GREEN);
    return figloc;
}


void Interface::initialiseShared(const int size,const int width,const int height, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared) {
    shapeShared.clear();
    constexpr int allHeigth = 50;
    constexpr int allWidth = 50;

    try {
        shapeShared.push_back(std::make_shared<geometricShape::Square>(size, allWidth + 70, allHeigth + 100));
        shapeShared.push_back(std::make_shared<geometricShape::Parallelogram>(size, allWidth + 110, allHeigth + 500));
        shapeShared.push_back(std::make_shared<geometricShape::RigthTriangle>(size, allWidth + 70, allHeigth + 300));
        shapeShared.push_back(std::make_shared<geometricShape::RigthTriangle>(size, allWidth + 70, allHeigth + 450));
        shapeShared.push_back(std::make_shared<geometricShape::RigthTriangle>(size * 2, allWidth, allHeigth));
        shapeShared.push_back(std::make_shared<geometricShape::RigthTriangle>(size * 2, allWidth, allHeigth + 200));
        shapeShared.push_back(std::make_shared<geometricShape::RigthTriangle>(round(size * sqrt(2)), allWidth, allHeigth + 400));

        drawAllShapes(shapeShared, figcolor(), MLV_COLOR_RED); 
    }
    catch (std::bad_alloc & e) {
        std::cerr << "bad_alloc caught: " << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    MLV_actualise_window();
    return;
}

void Interface::initialiseMotif(const int size,const int width,const int height, std::vector<std::shared_ptr<geometricShape::Shape>> &motif) {
    motif.clear();
    constexpr int allHeigth = 205;
    constexpr int allWidth = 628;

    try {
        // Initialisation d'une figure de base - un lapin
        motif.push_back(std::make_shared<geometricShape::Square>(size, allWidth, allHeigth));
        motif.push_back(std::make_shared<geometricShape::Parallelogram>(size, allWidth + size * 2, allHeigth - size));
        motif[1]->rotateHW(85, 3);
        motif.push_back(std::make_shared<geometricShape::RigthTriangle>(size, allWidth - round(size / 3.3) - 20, allHeigth));
        motif[2]->rotateHW(-70, 1);
        motif.push_back(std::make_shared<geometricShape::RigthTriangle>(size, allWidth - round(size / 1.45) - 12, allHeigth - round(size / 2.7) - 19));
        motif[3]->rotateHW(110, 0);
        motif.push_back(std::make_shared<geometricShape::RigthTriangle>(size * 2, allWidth + round(size / 0.9) - 50, allHeigth + 2.98 * size + 2));
        motif[4]->rotateHW(90, 0);
        motif.push_back(std::make_shared<geometricShape::RigthTriangle>(size * 2, allWidth + round(size * 3.09) - 47, allHeigth + round(size * 2.62) + 32));
        motif[5]->rotateHW(-90, 0);
        motif.push_back(std::make_shared<geometricShape::RigthTriangle>(round(size * sqrt(2)), allWidth + round(size * 2.4) - 73, allHeigth + round(size * 3.88) + 10));
        motif[6]->rotateHW(-45, 0);
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
void Interface::move(std::vector<std::shared_ptr<geometricShape::Shape>> &move, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared) {
	std::cout << "Before move shapeShared size :" << shapeShared.size() << "  contents: " ;
	for (auto it : shapeShared) {
		std::cout << *it << " ";
	}
	std::cout <<  std::endl; 
	move = std::move(shapeShared);
	std::cout << "After move shapeShared size :" << shapeShared.size() << "  contents: " ;
		for (auto it : shapeShared) {
			std::cout << *it << " ";
	}
	std::cout <<  std::endl;
}


bool Interface::importDraw (const int n, std::vector<std::shared_ptr<geometricShape::Shape>> &motif) {
    std::ifstream importFig("doc/savefig.txt");
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
            return 0;
        }

        if (importFig.eof()) {
            //std::cout << " Eof or figure n° " << n << " does not exist" << std::endl;
            return 0;
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

void Interface::saveFigure(const int width,const int height,const std::vector<std::shared_ptr<geometricShape::Shape>> &fig) {
    MLV_draw_filled_rectangle(round(width / 2) - 20, round(height / 2) - 20, 260, 90, MLV_COLOR_DIM_GREY);
    MLV_draw_rectangle(round(width / 2) - 20, round(height / 2) - 20, 260, 90, MLV_COLOR_BLACK);
    
    int interligne = 40;
    Button<int> button1 (round(width / 2), round(height / 2), 100, 50, "Save");
    Button<int> button2 (round(width / 2) + 120, round(height / 2), 100, 50, "Cancel");
    button1.drawButton(interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE);
    button2.drawButton(interligne, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE);
    MLV_actualise_window();

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

void Interface::winner(const int width,const int height) {
    MLV_Image *image = MLV_load_image("images/winner.png");
    int image_width, image_height;
    MLV_get_image_size(image, &image_width, &image_height);
    MLV_resize_image_with_proportions(image, image_width * 2, image_height * 2);
    MLV_get_image_size(image, &image_width, &image_height);
    int x_image = -((40 - (width - (round(width / 6) * 2) + 150)) / 2 + 100);
	int y_image = -((30 - (height - (round(height / 35) * 2))) / 2 + 100);
    MLV_draw_image(image, x_image, y_image);
    MLV_free_image(image);
    MLV_actualise_window();
}

void Interface::drawJeu(const int width,const int height) {
    Board board(width, height);
    MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
    MLV_actualise_window();
    /* Loading contour. */
    int size = (width + height) / 25; //100;
    MLV_Color motifBorder = MLV_COLOR_BLACK ;
    MLV_Color motifShape = MLV_COLOR_BLACK ;
    
    board.drawBoard();
    board.createButtonForBoard(1);

    std::vector<std::shared_ptr<geometricShape::Shape>> fig;
    initialiseShared(size, width, height, fig);
    /// Utilisation du move sémantic
    std::vector<std::shared_ptr<geometricShape::Shape>> motif_to_copie;
    std::vector<std::shared_ptr<geometricShape::Shape>> motif;
   // initialiseMotif(size, width, height, motif);
    initialiseMotif(size, width, height, motif_to_copie);
    move(motif,motif_to_copie);

    MLV_actualise_window();
    unsigned int nbFig = 1; // figure motif
    bool contour = false; 
    bool wincondi = false;
    std::list<MLV_Color> normal_color = figcolor();
    std::list<MLV_Color> win_color = figWincondition();
    std::list<MLV_Color> colorfig = normal_color;
    // MLV_Event event = MLV_MOUSE_MOTION ;
    while (1) {
    	//MLV_draw_filled_rectangle(round(width / 2) - 20, round(height / 2) - 20, 260, 90, MLV_COLOR_GRAY);
    	//board.drawBoard();
        int xInside, yInside;
        MLV_get_mouse_position(&xInside, &yInside);
        auto fig_i = colorfig.begin();
        std::for_each(fig.begin(), fig.end(), 
            [&](std::shared_ptr<geometricShape::Shape> it){ 
            it-> moveShape(xInside, yInside, fig, motif, motifShape, motifBorder , colorfig,fig_i, board,wincondi);
            drawAllShapes(motif, motifShape, motifBorder);
            drawAllShapes(fig, colorfig, MLV_COLOR_RED);
            fig_i++;
        });
        

        if (areEqual(motif, fig) == 1 && wincondi==false) {//// Probleme doit faire double clic
            wincondi = true;
            //motifShape = MLV_COLOR_GREEN;
            colorfig = win_color;
            drawAllShapes(motif, motifShape, motifBorder);
            drawAllShapes(fig, colorfig, MLV_COLOR_RED);
            winner(width, height); 

            ///std::cout << " LA ";
            
        } else if(wincondi){
        	//std::cout << " ICI ";
        	if (areEqual(motif, fig) == 0) {
        		wincondi = false;
	            colorfig = normal_color;
	            board.drawBoard();
	            drawAllShapes(motif, motifShape, motifBorder);
	        	drawAllShapes(fig, colorfig, MLV_COLOR_RED);
        	} else {
	        	//board.drawBoard();
	       		drawAllShapes(motif, motifShape, motifBorder);
	        	drawAllShapes(fig, colorfig, MLV_COLOR_RED);
            	winner(width, height); 
            	/* if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED){
	            	wincondi = false;
		            colorfig = normal_color;
		            board.drawBoard();
		            drawAllShapes(motif, motifShape, motifBorder);
		        	drawAllShapes(fig, colorfig, MLV_COLOR_RED);
            	}*/

        	}

        } 
         /*drawAllShapes(motif, motifShape, motifBorder);
        }
        drawAllShapes(fig, colorfig, MLV_COLOR_RED);*/

        bool next;

	    if (MLV_get_keyboard_state(MLV_KEYBOARD_LCTRL) == MLV_PRESSED && MLV_get_keyboard_state(MLV_KEYBOARD_s) == MLV_PRESSED) {
	            /* Save a polygon for new figure */
	    	    saveFigure(width, height, fig);
                board.drawBoard();

	    }

        if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
            int bouton = board.inBoard(xInside, yInside);
           // std::cout << bouton << std::endl;


            switch (bouton) {
                case 0:
                    break;
                case 1: 
                    //std::cout << "Fleche gauche" << std::endl;
	                if (nbFig > 0) {
                        nbFig--;
                        board.drawBoard();
	                    //drawAllShapes(fig, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
	                    //drawAllShapes(motif, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
	                    importDraw(nbFig, motif);
                        motifShape = MLV_COLOR_BLACK;
                        motifBorder = MLV_COLOR_BLACK;
                        contour = false; 
	                    drawAllShapes(motif, motifShape, motifBorder);
	                    initialiseShared(size, width, height, fig);
	                    colorfig = normal_color;
	                    drawAllShapes(fig, colorfig,MLV_COLOR_RED);
	                    board.drawButtonForBoard(nbFig);
	                    MLV_actualise_window();
                        if(MLV_get_mouse_button_state(MLV_BUTTON_LEFT) != MLV_RELEASED ){
                            MLV_wait_milliseconds(500);
                        }
	                };
	                break;
	            case 2: 
                    //std::cout << "Num Fig: " << nbFig << std::endl;
                    break;
	            case 3: 
	                //std::cout << "Fleche droite" << std::endl;
	                nbFig++;              
	                // drawAllShapes(fig, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
	                //drawAllShapes(motif, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
	                next = importDraw(nbFig, motif);
	                if (next == false) {
                        nbFig--;

                    } 
                    board.drawBoard();
	                motifShape = MLV_COLOR_BLACK;
                    motifBorder = MLV_COLOR_BLACK;
                    contour = false; 
	                drawAllShapes(motif, motifShape, motifBorder);
	                initialiseShared(size, width, height, fig);
	                colorfig = normal_color;
	                drawAllShapes(fig, colorfig, MLV_COLOR_RED);
	                board.drawButtonForBoard(nbFig);
	                MLV_actualise_window();
                    if(MLV_get_mouse_button_state(MLV_BUTTON_LEFT) != MLV_RELEASED ){
                        MLV_wait_milliseconds(500);
                    }
                    break;
                case 4: // Contour
                    //std::cout << "Contour" << std::endl;
                    if ( contour == true ){
                        motifBorder = MLV_COLOR_ORANGE;
                    }
                    else if( contour == false){
                       motifBorder = MLV_COLOR_BLACK; 
                    }
                    contour = !contour;
                    drawAllShapes(motif, motifShape, motifBorder);
                    drawAllShapes(fig, colorfig, MLV_COLOR_RED);
                    MLV_actualise_window();
                    if(MLV_get_mouse_button_state(MLV_BUTTON_LEFT) != MLV_RELEASED ){
                        MLV_wait_milliseconds(500);
                    }
	                break;
	            case 5: // Sauvegarder
	                //std::cout << "Sauvegarde" << std::endl;
                    saveFigure(width, height, fig);
                    board.drawBoard();
                    break;
                case 6: // Quitter
                    //std::cout << "Quitter" << std::endl;
                    MLV_free_window();
                    exit(EXIT_SUCCESS); 
                    break;
	            default: break;
	        } 

	    }
        MLV_actualise_window();
    }
}
