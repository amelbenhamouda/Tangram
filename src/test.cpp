#include <MLV/MLV_all.h>
#include "../include/rigth_triangle.hpp"
#include "../include/square.hpp"
#include "../include/parallelogram.hpp"
#include "../include/shape.hpp"
#include <vector>
#include <algorithm>
#include <cmath>
//
// Fonction affichant les côtes d'une boîte de texte. Les paramètres sont 
// la position du sommet Nord-Ouest ( paramètres x et y ) et la taille de la 
// boîte de texte ( paramètres width et height ).
//
std::vector<geometric_shape::shape*> Initialise(int size,int width, int height){
        MLV_clear_window ( MLV_COLOR_BLACK ) ;  
        int allHeigth = height-200;
        int allWidth =width - 1400;

        /*geometric_shape::square sq(size,allHeigth,allWidth);
        //sq.rotate_center(45);
        geometric_shape::rigth_triangle tr1(size,allHeigth,allWidth+1*(size+15));
        geometric_shape::rigth_triangle tr2(size,allHeigth,allWidth+2*(size+15));
        geometric_shape::rigth_triangle tr3(size*2,allHeigth,allWidth+3*(size+15));
        geometric_shape::rigth_triangle tr4(size*2,allHeigth,allWidth+5*(size+15));
        geometric_shape::rigth_triangle tr5(round(size*sqrt(2)),allHeigth,allWidth+7*(size+15));
        geometric_shape::parallelogram par(size,allHeigth,allWidth+9*(size+15));
        geometric_shape::parallelogram *parp;
        geometric_shape::rigth_triangle *tr1p;
        geometric_shape::rigth_triangle *tr2p;
        geometric_shape::rigth_triangle *tr3p;
        geometric_shape::rigth_triangle *tr4p;
        geometric_shape::rigth_triangle *tr5p;
        geometric_shape::square *sqp ;
        parp = &par;
        tr1p = &tr1;
        tr2p = &tr2;
        tr3p = &tr3;
        tr4p = &tr4;
        tr5p = &tr5;
        sqp  = &sq;
        sqp->draw(MLV_COLOR_WHITE);
        tr1p->draw(MLV_COLOR_WHITE);
        tr2.draw(MLV_COLOR_WHITE);
        tr3.draw(MLV_COLOR_WHITE);
        tr4.draw(MLV_COLOR_WHITE);
        tr5.draw(MLV_COLOR_WHITE);
        parp->reverse();
        parp->draw(MLV_COLOR_WHITE);
        */
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
            /*parp2->draw(MLV_COLOR_WHITE, MLV_COLOR_RED);
            tr1p2->draw(MLV_COLOR_WHITE, MLV_COLOR_RED);
            tr2p2->draw(MLV_COLOR_WHITE, MLV_COLOR_RED);
            tr3p2->draw(MLV_COLOR_WHITE, MLV_COLOR_RED);
            tr4p2->draw(MLV_COLOR_WHITE, MLV_COLOR_RED);
            tr5p2->draw(MLV_COLOR_WHITE, MLV_COLOR_RED);
            sqp2->draw(MLV_COLOR_WHITE, MLV_COLOR_RED);*/
            shapes = std::vector<geometric_shape::shape*>{sqp2,tr1p2,tr2p2,tr3p2,tr4p2,tr5p2,parp2};
            drawAllShapes(shapes,MLV_COLOR_WHITE,MLV_COLOR_RED);        }
        catch (std::bad_alloc & e)
        {
            std::cerr << "bad_alloc caught: " << e.what() << '\n';
            exit(EXIT_FAILURE);
        }



        /*geometric_shape::shape ** tabshape = new geometric_shape::shape*[6];
        tabshape[0]= parp2;
        tabshape[1]= tr1p2;
        tabshape[2]= tr2p2;
        tabshape[3]= tr3p2;
        tabshape[4]= tr4p2;
        tabshape[5]= tr5p2;
        tabshape[6]= sqp2;*/
        
        /*std::vector<geometric_shape::shape> shape{sq,tr1,tr2,tr3,tr4,tr5,par};*/
        MLV_actualise_window();
        return shapes;
}


void print_cote( int O, int N, int width, int height, MLV_Color color ){
        int espace = 3;
        int sizeLine = 10;
        int S = N + height -1;
        int E = O + width - 1;
        MLV_draw_line(O, N - espace, O, N - espace - sizeLine , color);
        MLV_draw_line(E, N - espace, E, N - espace - sizeLine , color);
        MLV_draw_line(O, S + espace, O, S + espace + sizeLine , color);
        MLV_draw_line(E, S + espace, E, S + espace + sizeLine , color);
        MLV_draw_line(O - espace, N, O - espace - sizeLine, N, color);
        MLV_draw_line(O - espace, S, O - espace - sizeLine, S, color);
        MLV_draw_line(E + espace, N, E + espace + sizeLine, N, color);
        MLV_draw_line(E + espace, S, E + espace + sizeLine, S, color);
};

//
// Attention ! 
// Pour pouvoir compiler ce programme sous windows et sous macintosh,
// il faut, pour la déclaration du main, respecter strictement la syntaxe
// suivante :
//
int main( int argc, char *argv[] ){
        int width = 1500, height = 700;

        // Créé et affiche la fenêtre
        //
        MLV_create_window(
                "advanced - 1 - texts and boxes", "texts and boxes", width, height );
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
        int size=100;
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
        std::vector<geometric_shape::shape*> fig = Initialise(size,width,height);
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

        while(1)
        {               

                        int x_inside,y_inside;
                        MLV_wait_mouse(&x_inside, &y_inside);
                        /*std::cout << "sq: " << fig[0].isInside(x_inside,y_inside) << std::endl;
                        std::cout << "tr1: "<< fig[1].isInside(x_inside,y_inside) << std::endl;
                        std::cout << "tr2: "<< fig[2].isInside(x_inside,y_inside) << std::endl;
                        std::cout << "tr3: "<< fig[3].isInside(x_inside,y_inside) << std::endl;
                        std::cout << "tr4: "<< fig[4].isInside(x_inside,y_inside) << std::endl;
                        std::cout << "tr5: "<< fig[5].isInside(x_inside,y_inside) << std::endl;
                        std::cout << "par: "<< fig[6].isInside(x_inside,y_inside) << std::endl<< std::endl;*/
                        /*for(int it=0; it<7;it++)
                        {
                            std::cout << it;
                            fig[it]-> move_shape(x_inside,y_inside);
                            fig[it]-> draw(MLV_COLOR_WHITE);
                        }*/
                        /*for(auto it : fig)
                        {
                            //std::vector<geometric_shape::shape*> drawfig = fig;
                            //v.erase(std::remove(v.begin(), v.end(), 5), v.end());
                            it-> move_shape(x_inside,y_inside,fig);
                            drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
                            //it-> draw(MLV_COLOR_WHITE,MLV_COLOR_RED);
                        }*/
                        std::for_each(fig.begin(), fig.end(), [&x_inside,&y_inside,fig](geometric_shape::shape* it)
                        { 
                            it-> move_shape(x_inside,y_inside,fig);
                            drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
                        });
                        //ispermutation;
                        /*fig[0]->move_shape(x_inside,y_inside);
                        fig[1]->move_shape(x_inside,y_inside);
                        fig[2]->move_shape(x_inside,y_inside);
                        fig[3]->move_shape(x_inside,y_inside);
                        fig[4]->move_shape(x_inside,y_inside);
                        fig[5]->move_shape(x_inside,y_inside);
                        fig[6]->move_shape(x_inside,y_inside);
                        fig[0]->draw(MLV_COLOR_WHITE);
                        fig[1]->draw(MLV_COLOR_WHITE);
                        fig[2]->draw(MLV_COLOR_WHITE);
                        fig[3]->draw(MLV_COLOR_WHITE);
                        fig[4]->draw(MLV_COLOR_WHITE);
                        fig[5]->draw(MLV_COLOR_WHITE);
                        fig[6]->draw(MLV_COLOR_WHITE);*/
                        MLV_actualise_window();

        }
        //delete[] fig;
        std::cout << "oui sa ferme" << std::endl;
        for (unsigned int i=0; i<fig.size();i++)
        {
            delete fig[i];
        }
        

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