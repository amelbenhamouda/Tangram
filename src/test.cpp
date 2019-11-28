#include <MLV/MLV_all.h>
#include "../include/rigth_triangle.hpp"
#include "../include/square.hpp"
#include "../include/parallelogram.hpp"
#include "../include/shape.hpp"

#include <memory> // shared_ptr
#include <vector>
#include <algorithm>
#include <cmath>
//
// Fonction affichant les côtes d'une boîte de texte. Les paramètres sont 
// la position du sommet Nord-Ouest ( paramètres x et y ) et la taille de la 
// boîte de texte ( paramètres width et height ).
//
/*std::vector<geometric_shape::shape*> Initialise(int size,int width, int height){
        MLV_clear_window ( MLV_COLOR_BLACK ) ;  
        int allHeigth = height-200;
        int allWidth =width - 1400;

        std::vector<geometric_shape::shape*>  shapes;
        try
        {
            geometric_shape::parallelogram *parp2= new geometric_shape::parallelogram(size,allHeigth,allWidth+9*(size+15));
            geometric_shape::rigth_triangle *tr1p2= new geometric_shape::rigth_triangle(size,allHeigth,allWidth+1*(size+15));
            geometric_shape::rigth_triangle *tr2p2= new geometric_shape::rigth_triangle(size,allHeigth,allWidth+2*(size+15));
            geometric_shape::rigth_triangle *tr3p2= new geometric_shape::rigth_triangle(size*2,allHeigth,allWidth+3*(size+15));
            geometric_shape::rigth_triangle *tr4p2= new geometric_shape::rigth_triangle(size*2,allHeigth,allWidth+5*(size+15));
            geometric_shape::rigth_triangle *tr5p2= new geometric_shape::rigth_triangle(round(size*sqrt(2)),allHeigth,allWidth+7*(size+15));
            geometric_shape::square *sqp2 = new geometric_shape::square(size,allHeigth,allWidth);
            shapes = std::vector<geometric_shape::shape*>{sqp2,tr1p2,tr2p2,tr3p2,tr4p2,tr5p2,parp2};
            drawAllShapes(shapes,MLV_COLOR_WHITE,MLV_COLOR_RED);   

     }
        catch (std::bad_alloc & e)
        {
            std::cerr << "bad_alloc caught: " << e.what() << '\n';
            exit(EXIT_FAILURE);
        }

        MLV_actualise_window();
        return shapes;
}*/

void Initialise_shared(int size,int width, int height,std::vector<std::shared_ptr<geometric_shape::shape> > &shape_shared){ 
        int allHeigth = height-150;
        int allWidth = 100;
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
 
        int allHeigth = 250;
        int allWidth =200;
        try{
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
            drawAllShapes(motif,MLV_COLOR_ORANGE,MLV_COLOR_ORANGE); 

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

//
// Attention ! 
// Pour pouvoir compiler ce programme sous windows et sous macintosh,
// il faut, pour la déclaration du main, respecter strictement la syntaxe
// suivante :
//
int main( int argc, char *argv[] ){
    int width = 1950, height = 900;
    // Créé et affiche la fenêtre
    MLV_create_window(
            "Test Tangram", "Test Tangram", width, height );
    // texte à afficher dans une boîte
    /*const char* text = "Voici une boite de texte, \ncentré par rapport à la fenetre.";
    // Taille de la future boite qui affichera le texte.
    int width_text, height_text; 
    
    //
    // Récupère la taile de la boite de texte qui affichera le texte
    // contenu dans la variable text.
    //

    MLV_get_size_of_text( text, &width_text, &height_text );
    width_text=width_text*2;
    height_text=height_text*2;
    int positionX = (width-width_text)/2, positionY = 100;
    //
    // Affichage du texte
    //
   // MLV_draw_text( positionX, positionY, text, MLV_COLOR_GREEN);
    MLV_draw_adapted_text_box(positionX, positionY, text,40,MLV_COLOR_GREEN,MLV_COLOR_GREEN,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    //
    // Affichage les côtes du texte.
    //
    //print_cote( positionX, positionY, width_text, height_text, MLV_COLOR_GREEN );
    //
    // Second texte à afficher
    //
    const char *text_box = "Voici une boîte de texte.\nCette Boîte de texte est elle aussi centré horizontalement dans la fenetre.";
    int width_box = 0 , height_box = 0, size_interligne = 9;
    //
    // Récupère la taille de la boite de texte qui affichera le texte
    // contenu dans la variable text_box.
    //
    MLV_get_size_of_adapted_text_box(
            text_box,
            size_interligne,
            &width_box, &height_box
    );
    //
    // Calcul la position idéale pour la boîte de texte
    //
    int positionBoxX = (width-width_box)/2, positionBoxY = 300;
    //
    // Affiche la boîte de texte.
    //
    MLV_draw_adapted_text_box(
            positionBoxX, positionBoxY,
            text_box,
            size_interligne,
            MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
            MLV_TEXT_CENTER
    );
    //
    // Affiche les côtes de la boîte de texte.
    //
    print_cote(
            positionBoxX, positionBoxY, width_box, height_box, MLV_COLOR_GREEN
    );
    //
    //  Met à jour l'affichage de la fenêtre
    //
    //Polygone 
    
    int polyHeigth = height - 650;
    int polywidth = width - 500;
    //Triangle
    geometric_shape::rigth_triangle t1(size,polyHeigth,polywidth) ;
    geometric_shape::rigth_triangle t2(t1);
    geometric_shape::rigth_triangle t3=t1;
    //t2.draw();
    geometric_shape::rigth_triangle t4 = t2;
    t4.reverse();
    //t4.draw();
    t4.rotate_center(-180);
    //t4.draw();
    geometric_shape::square c1(size,polyHeigth,polywidth+200);
    geometric_shape::square c3(100,0,0);
    c3.draw(MLV_COLOR_WHITE);
    c1.draw(MLV_COLOR_WHITE);


    geometric_shape::parallelogram par1(size,polyHeigth+200,polywidth+200);
    par1.draw(MLV_COLOR_WHITE);
    geometric_shape::square c4 = c1;
    geometric_shape::parallelogram par4(par1);
    c4.translate(150,0);*/

    //geometric_shape::square c2=c1.rotate(45);
    //c2.draw();
    //MLV_actualise_window();
    /*geometric_shape::rigth_triangle t5 = t4.rotate(35);
    t5.draw();
    t5.display();*/
    int size=50;
    /*int allHeigth = height-200;
    int allWidth =width - 1400;
    geometric_shape::square sq(size,allHeigth,allWidth);
    sq.rotate_center(45);
    geometric_shape::rigth_triangle tr1(size,allHeigth,allWidth+1*(size+25));
    geometric_shape::rigth_triangle tr2(size,allHeigth,allWidth+2*(size+15));
    geometric_shape::rigth_triangle tr3(size*2,allHeigth,allWidth+3*(size+15));
    geometric_shape::rigth_triangle tr4(size*2,allHeigth,allWidth+5*(size+15));
    geometric_shape::rigth_triangle tr5(round(size*sqrt(2)),allHeigth,allWidth+7*(size+15));
    geometric_shape::parallelogram par(size,allHeigth,allWidth+9*(size+15));

    sq.draw(MLV_COLOR_WHITE);
    tr1.draw(MLV_COLOR_WHITE);
    tr2.draw(MLV_COLOR_WHITE);
    tr3.draw(MLV_COLOR_WHITE);
    tr4.draw(MLV_COLOR_WHITE);
    tr5.draw(MLV_COLOR_WHITE);
    par.draw(MLV_COLOR_WHITE);
    MLV_actualise_window();

    std::cout << tr1 << sq << par << std::endl;*/
    //std::vector<geometric_shape::shape*> fig = Initialise(size,width,height);
    std::vector<std::shared_ptr<geometric_shape::shape> >  fig;
    Initialise_shared(size,width,height,fig);
    /*std::vector<std::shared_ptr<geometric_shape::shape> >  fig2;
    clone(fig2,fig);
    std::vector<std::shared_ptr<geometric_shape::shape> >  fig3;
    Initialise_shared(size,width,height,fig3);
    std::cout << "areEqual(fig,fig): "<< areEqual(fig,fig) << std::endl;
    std::cout << "areEqual(fig,fig2): "<< areEqual(fig,fig2) << std::endl;
    std::cout << "areEqual(fig,fig3): "<< areEqual(fig,fig3) << std::endl;*/
   // std::vector<std::shared_ptr<geometric_shape::shape> > fig3= std::make_shared<std::vector<std::shared_ptr<geometric_shape::shape>>>(fig);
    /*for (auto it : fig){
        it->draw(MLV_COLOR_YELLOW,MLV_COLOR_YELLOW);
        //std::cout << *it << std::endl;
    }*/
    //drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
    std::vector<std::shared_ptr<geometric_shape::shape> >  motif;
    Initialise_motif(size,width,height,motif);
    MLV_actualise_window();
    /* ////////////TEST ROTATION//////////////////////
    for (int i = 0;i<20000;i++)
    {
            MLV_wait_milliseconds( 5 );
            t4.draw(MLV_COLOR_BLACK);
            c4.draw(MLV_COLOR_BLACK);
            par4.draw(MLV_COLOR_BLACK);
            MLV_wait_milliseconds( 1 );
            t4.rotate_center(1);
            t4.draw(MLV_COLOR_WHITE);
            c4.rotate_center(1);
            c4.draw(MLV_COLOR_WHITE);
            par4.rotate_center(1);
            par4.draw(MLV_COLOR_WHITE);
            MLV_actualise_window();

    }*/////////////TEST TRANSLATION//////////////////////
    /*int n_translate=1;
    for (int i = 1;i<20000;i++)
    {
            
            MLV_wait_milliseconds( 5);
            t4.draw(MLV_COLOR_BLACK);
            t4.translate(-n_translate,n_translate);
            t4.draw(MLV_COLOR_WHITE);
            c1.draw(MLV_COLOR_BLACK);
            c1.translate(-n_translate,n_translate);
            c1.draw(MLV_COLOR_WHITE);
            par1.draw(MLV_COLOR_BLACK);
            par1.translate(-n_translate,n_translate);
            par1.draw(MLV_COLOR_WHITE);
            MLV_actualise_window();
            if(i%200 == 0) n_translate=-n_translate;
            
    }*/
    /* ///Test opérateur égale
    int allHeigth = height-200;
    int allWidth =width - 1400;
    geometric_shape::rigth_triangle t1(size,allHeigth,allWidth);
    geometric_shape::rigth_triangle t2(size,allHeigth,allWidth);
    std::cout << (t1 == t2) << std::endl;*/
    /*std::vector<geometric_shape::shape*> fig2 = fig;
    for(auto it : fig)
    {
        //std::vector<geometric_shape::shape*> drawfig = fig;
        //v.erase(std::remove(v.begin(), v.end(), 5), v.end());
        std::cout << *it << std::endl;
        it-> reverse();
        //it-> draw(MLV_COLOR_WHITE,MLV_COLOR_RED);
    }*/
   // MLV_Color color= MLV_COLOR_WHITE;
    while(1)
    {               

                    int x_inside,y_inside;
                    MLV_wait_mouse(&x_inside, &y_inside);
                    std::for_each(fig.begin(), fig.end(), [&x_inside,&y_inside,&fig,&motif](std::shared_ptr<geometric_shape::shape> it)
                        
                    { 
                        it-> move_shape(x_inside,y_inside,fig,motif);
                        drawAllShapes(motif,MLV_COLOR_BLACK,MLV_COLOR_ORANGE);
                        drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
                    });
                    //std::cout << areEqual(fig,motif) << std::endl;

                    if(areEqual(motif,fig)==1){
                        drawAllShapes(motif,MLV_COLOR_GREEN,MLV_COLOR_ORANGE);
                        int x2,y2;
                        MLV_wait_mouse(&x2, &y2);
                    }
                    //ispermutation;

                    if( MLV_get_keyboard_state( MLV_KEYBOARD_LCTRL ) == MLV_PRESSED 
                            && MLV_get_keyboard_state( MLV_KEYBOARD_s ) == MLV_PRESSED ){
                                int interligne=40;
                                MLV_draw_text_box(round(width/2),round(height/2),100,50,"Save", interligne , 
                                            MLV_COLOR_GREY,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
                                MLV_draw_text_box(round(width/2)+120,round(height/2),100,50,"Cancel", interligne , 
                                            MLV_COLOR_GREY,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
                                MLV_actualise_window();
                                int x_inside,y_inside;
                                MLV_wait_mouse(&x_inside, &y_inside);
                                if (x_inside >=  round(width/2))
                                savedraw(fig);
                    }
                    MLV_clear_window ( MLV_COLOR_BLACK ) ;
                    drawAllShapes(motif,MLV_COLOR_BLACK,MLV_COLOR_ORANGE);
                    drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
 

                    MLV_actualise_window();

    }
    //delete[] fig;
    std::cout << "oui sa ferme" << std::endl;
    /*for (unsigned int i=0; i<fig.size();i++)
    {
        delete fig[i];
    }*/
    

    // Ferme la fenêtre
    //
    MLV_free_window();
    return 0;
}
/*
 *   This file is part of the MLV Library.
 *
 *   Copyright (C) 2010,2011,2012,2013 Adrien Boussicault, Marc Zipstein
 *
 *
 *    This Library is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This Library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this Library.  If not, see <http://www.gnu.org/licenses/>.
 */