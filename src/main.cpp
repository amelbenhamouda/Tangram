#include <MLV/MLV_all.h>
#include "../include/rigth_triangle.hpp"
#include "../include/square.hpp"
#include "../include/parallelogram.hpp"
#include "../include/shape.hpp"

#include "../include/board.hpp"
#include "../include/menu.hpp"

#include <memory> // shared_ptr
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

//valgrind --leak-check=full ./Tangram

void Initialise_shared(int size,int width, int height,std::vector<std::shared_ptr<geometric_shape::shape> > &shape_shared){
        shape_shared.clear();
        //MLV_clear_window ( MLV_COLOR_BLACK ) ;  
        int allHeigth = height-225;
        int allWidth = 50;

        try{
            shape_shared.push_back(std::make_shared<geometric_shape::square>(size,allHeigth,allWidth) );
            shape_shared.push_back(std::make_shared<geometric_shape::parallelogram>(size,allHeigth,allWidth+9*(size+15)) );
            shape_shared.push_back(std::make_shared<geometric_shape::rigth_triangle>(size,allHeigth,allWidth+1*(size+15)) );
            shape_shared.push_back(std::make_shared<geometric_shape::rigth_triangle>(size,allHeigth,allWidth+2*(size+15)) );
            shape_shared.push_back(std::make_shared<geometric_shape::rigth_triangle>(size*2,allHeigth,allWidth+3*(size+15)) );
            shape_shared.push_back(std::make_shared<geometric_shape::rigth_triangle>(size*2,allHeigth,allWidth+5*(size+15)) );
            shape_shared.push_back(std::make_shared<geometric_shape::rigth_triangle>(round(size*sqrt(2)),allHeigth,allWidth+7*(size+15)) );
            drawAllShapes(shape_shared,MLV_COLOR_WHITE,MLV_COLOR_RED); 

        }
        catch (std::bad_alloc & e){
            std::cerr << "bad_alloc caught: " << e.what() << '\n';
            exit(EXIT_FAILURE);
        }

        MLV_actualise_window();
        return;
}

void Initialise_motif(int size,int width, int height,std::vector<std::shared_ptr<geometric_shape::shape> > &motif){
        motif.clear();
        int allHeigth = 250;
        int allWidth = 300;
        try{
        	// Initialisation d'une figure de base - un lapin
            motif.push_back(std::make_shared<geometric_shape::square>(size,allHeigth,allWidth) );
            motif.push_back(std::make_shared<geometric_shape::parallelogram>(size,allHeigth-size,allWidth+size*2) );
            motif[1]->rotate_hw(80,3);
            motif.push_back(std::make_shared<geometric_shape::rigth_triangle>(size,allHeigth,allWidth-round(size/3.3)) );
            motif[2]->rotate_hw(-60,1);
            motif.push_back(std::make_shared<geometric_shape::rigth_triangle>(size,allHeigth-round(size/2.7),allWidth-round(size/1.45)) );
            motif[3]->rotate_hw(120,0);
            motif.push_back(std::make_shared<geometric_shape::rigth_triangle>(size*2,allHeigth+2.98*size,allWidth+round(size/0.9 )));
            motif[4]->rotate_hw(100,0);
            motif.push_back(std::make_shared<geometric_shape::rigth_triangle>(size*2,allHeigth+round(size*2.62),allWidth+round(size*3.09)) );
            motif[5]->rotate_hw(-80,0);
            motif.push_back(std::make_shared<geometric_shape::rigth_triangle>(round(size*sqrt(2))
                                                ,allHeigth+round(size*3.88),allWidth+round(size*2.4) ));
            motif[6]->rotate_hw(-35,0);
            drawAllShapes(motif,MLV_COLOR_BLACK,MLV_COLOR_ORANGE); 

        }
        catch (std::bad_alloc & e){
            std::cerr << "bad_alloc caught: " << e.what() << '\n';
            exit(EXIT_FAILURE);
        }

        MLV_actualise_window();
        return;
}

void clone(std::vector<std::shared_ptr<geometric_shape::shape> > &clone, std::vector<std::shared_ptr<geometric_shape::shape> > &shape_shared){
    for(auto it : shape_shared){
        auto  fig = it;
        clone.push_back(it);
    }
}

bool importdraw (const int n,const int size,std::vector<std::shared_ptr<geometric_shape::shape> > &motif){
    std::ifstream importfig("savefig.txt");
    if(importfig){

        int count = 1;
        while (true) {

            std::vector<double> pxloc;
            std::vector<double> pyloc;
            std::vector<double> centloc;
            int sizeloc;
            //std::cout << "count: " << count << std::endl;
            int x;
            double valx;
            double valy;
            importfig >> x;
            //std::cerr << x ;
            int countfig=0;
            if (x>0 && x <= 2){
                countfig =4;
            }
            else if(x>=3 && x <=7){
                countfig=3;
            }   
            else { 
            	std::cout << "  Read error "<< std::endl; 
            	break;
            	return 0;
            }

            if(importfig.eof()) {
                std::cout << " Eof or figure n° " << n << " does not exist" << std::endl;
                return 0;
                break;
            }
            for (int i=0; i <countfig;i++){
                importfig>> valx;
                importfig>> valy;
                if(count == n){
                    pxloc.push_back(valx);
                    pyloc.push_back(valy);
                }
            }
            importfig>> valx;
            importfig>> valy;
            if(count == n){
                centloc.push_back(valx);
                centloc.push_back(valy);
            }
            importfig>> valx;
            if(count == n){
                sizeloc= valx;

            }

            /*if(count==n){
                for(unsigned int i =0; i< pxloc.size(); i++){
                    //std::cout << " error " << std::endl;
                    std::cout << pxloc[i] << "/" << pyloc[i] << " ";

                }
                std::cout << centloc[0] << "/" << centloc[1] << " "<< sizeloc << " ";
                std::cout << std::endl;
            }
            */

            if(count == n) {
                switch(x){
                    case 1:
                        motif[0]->set_shape(pxloc,pyloc,centloc,sizeloc);
                        break;
                    case 2:
                        motif[1]->set_shape(pxloc,pyloc,centloc,sizeloc);
                        break;
                    case 3:
                        motif[2]->set_shape(pxloc,pyloc,centloc,sizeloc);
                        break;
                    case 4:
                        motif[3]->set_shape(pxloc,pyloc,centloc,sizeloc);
                        break;
                    case 5:
                        motif[4]->set_shape(pxloc,pyloc,centloc,sizeloc);
                        break;
                    case 6:
                        motif[5]->set_shape(pxloc,pyloc,centloc,sizeloc);
                        break;
                    case 7:
                        motif[6]->set_shape(pxloc,pyloc,centloc,sizeloc);
                        break;

                }
            };
            if (x==7 && count == n) break;
            if (x==7) count++; // si on fini un paquet de 7

        }
        importfig.close();
    }
    else{
        std::cout << "ERROR: Cannot open savefig.txt." << std::endl;
    }
    return true;

}

void drawJeu(std::vector<const char*> figures, int width, int height){
    Board board;
    int numFig = 1;
    MLV_draw_filled_rectangle(0,0, width, height, MLV_COLOR_BLACK);
    MLV_actualise_window();
    /* Loading contour. */
    int size = 100;
    MLV_Color motifborder = MLV_COLOR_ORANGE ;
    MLV_Color motifshape = MLV_COLOR_BLACK ;
    
    for (auto figure : figures){
        board.drawModel(figure);
        board.drawBoard();
        board.drawButton(numFig);
        numFig++;
        std::vector<std::shared_ptr<geometric_shape::shape> >  fig;
        Initialise_shared(size,width,height,fig);

        std::vector<std::shared_ptr<geometric_shape::shape> >  motif;
        Initialise_motif(size,width,height,motif);
        MLV_actualise_window();
        unsigned int nbfig =1; // figure motif
        while(1) {               
            int x_inside,y_inside;
            //MLV_wait_mouse(&x_inside, &y_inside);
            MLV_get_mouse_position( &x_inside, &y_inside );
            std::for_each(fig.begin(), fig.end(), 
                [&x_inside,&y_inside,&fig,&motif,&motifborder,&motifshape](std::shared_ptr<geometric_shape::shape> it){ 
                it-> move_shape(x_inside,y_inside,fig, motif);
                drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
                drawAllShapes(motif,motifshape,motifborder);
            });
            /*bool oui = (figh == motif);
            if (oui==true) {
            	std::cout << "oui" << std::endl;
            }*/
            if(areEqual(motif,fig)==1){

                std::cout << "equal" << std::endl;
                motifshape= MLV_COLOR_GREEN;
                drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
                drawAllShapes(motif,motifshape,motifborder);
                MLV_actualise_window();
                int x2,y2;
                MLV_wait_mouse(&x2, &y2);
            }
            else {
                motifshape = MLV_COLOR_BLACK;
            }


            if( MLV_get_keyboard_state( MLV_KEYBOARD_LCTRL ) == MLV_PRESSED 
                            && MLV_get_keyboard_state( MLV_KEYBOARD_s ) == MLV_PRESSED ){

                int interligne=40;
                MLV_draw_filled_rectangle(round(width/2)-20,round(height/2)-20,260, 90, MLV_COLOR_DIM_GREY);
                MLV_draw_rectangle(round(width/2)-20,round(height/2)-20,260, 90, MLV_COLOR_BLACK);
                MLV_actualise_window();
                MLV_draw_text_box(round(width/2),round(height/2),100,50,"Save", interligne , 
                            MLV_COLOR_GREY,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
                MLV_draw_text_box(round(width/2)+120,round(height/2),100,50,"Cancel", interligne , 
                            MLV_COLOR_GREY,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
                MLV_actualise_window();
                int x_inside,y_inside;
                MLV_wait_mouse(&x_inside, &y_inside);
                bool save = true;
                while(save){
                    if (x_inside >= round(width/2) and x_inside <= round(width/2)+100 
                        and y_inside >= round(height/2) and y_inside <= round(height/2)+50) {  // Bouton Save
                        std::cout << "Motif saved" << std::endl;
                        savedraw(fig);
                        save=false;

                    }
                    else if(x_inside >= round(width/2)+120 and x_inside <= round(width/2) +220
                            and y_inside >= round(height/2) and y_inside <= round(height/2)+50) {  // Bouton Cancel
                        std::cout << "Cancel" << std::endl;
                        save=false;
                    }
                    else{
                         MLV_wait_mouse(&x_inside, &y_inside);
                    }
                }
                
            }
            MLV_draw_filled_rectangle(round(width/2)-20,round(height/2)-20,260, 90, MLV_COLOR_GRAY);
            drawAllShapes(motif,motifshape,motifborder);
            drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
            bool next;
            if((MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED))
            {
            int bouton = board.inButton(x_inside, y_inside);
	            switch(bouton){
	                case 1: 
	                    std::cout << "Fleche gauche" << std::endl;
	                    if (nbfig>0) {
	                        nbfig--;
	                        drawAllShapes(fig,MLV_COLOR_GRAY,MLV_COLOR_GRAY);
	                        drawAllShapes(motif,MLV_COLOR_GRAY,MLV_COLOR_GRAY);
	                        importdraw(nbfig,size,motif);
	                        motifshape = MLV_COLOR_BLACK;
	                        drawAllShapes(motif,motifshape,motifborder);
	                        Initialise_shared(size,width,height,fig);
	                        drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
	                        board.drawButton(nbfig);
	                        MLV_actualise_window();
	                    };
	                    break;
	                case 2: 
	                    std::cout << "Num Fig" << std::endl;

	                    break;
	                case 3: 
	                    std::cout << "Fleche droite" << std::endl;
	                    nbfig++;
	                    
	                    drawAllShapes(fig,MLV_COLOR_GRAY,MLV_COLOR_GRAY);
	                    drawAllShapes(motif,MLV_COLOR_GRAY,MLV_COLOR_GRAY);
	                    next= importdraw(nbfig,size,motif);
	                    if(next == false) nbfig--;
	                    motifshape = MLV_COLOR_BLACK;
	                    drawAllShapes(motif,motifshape,motifborder);
	                    Initialise_shared(size,width,height,fig);
	                    drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
	                    board.drawButton(nbfig);
	                    MLV_actualise_window();
	                    break;
	                case 4: // Contour
	                    std::cout << "Contour" << std::endl;
	                    break;
	                case 5: // Quitter
	                    std::cout << "Quitter" << std::endl;
	                    MLV_free_window();
	                    exit(EXIT_SUCCESS); 
	                    break;
	                default: break;
	            }
	        MLV_wait_milliseconds(500);
	        }
            MLV_actualise_window();
        }
    }
}

//
// Attention ! 
// Pour pouvoir compiler ce programme sous windows et sous macintosh,
// il faut, pour la déclaration du main, respecter strictement la syntaxe
// suivante :
//
int main( int argc, char *argv[] ){
    Menu menu;
    int width = 1500, height = 1000;
    int x, y ; //Point
    // Créé et affiche la fenêtre
    MLV_create_window( "Tangram", "", width, height);
    

    /* Displays buttons. */
    menu.drawButton();
    MLV_wait_mouse(&x, &y);
    int choix = menu.inButton(x, y);

    if (choix == 1){ // Jouer
        std::cout << "Jouer" << std::endl;
        std::vector<const char*> figures;
        figures.push_back("modele/img.png");
        // Afficher board
        drawJeu(figures, width, height);
    }
    else if (choix == 2) {
        std::cout << "Quitter" << std::endl;
        MLV_free_window();
        exit(EXIT_SUCCESS); 
    }

    return 0;
}
