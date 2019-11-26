/**
 * \file shape.hpp
 * \brief Header file of shape.cpp.
 * \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include <iostream>
#include <MLV/MLV_all.h>

namespace geometric_shape{
	 /**
     * \class shape
     * \brief object shape.
     *
     * shape is a geometric_shape that compute a rigth triangle by the given size of his side.
     * That class is composed by std::vector who contain the position of the vertex.
     * 
     */
        class shape
        {       
        public:
                shape(int size_cote,int height,int width);
                virtual~shape();
                shape(const shape &tc);
                shape & operator=(const shape &tc);
                bool operator== (const shape &) const;
                //friend bool operator == (const std::vector<geometric_shape::shape*> vectshapes,const std::vector<geometric_shape::shape*> vectshapes2) ;
                virtual void move_shape(int &x_inside,int &y_inside, std::vector<geometric_shape::shape*> fig);

                void draw(MLV_Color color_shape,  MLV_Color color_border= MLV_COLOR_BLACK) const;
    /*           
     * 
     * Overload draw(MLV_Color color,  MLV_Color color_border= MLV_COLOR_BLACK) for vector of shape
     * 
     */
                friend void drawAllShapes(const std::vector<geometric_shape::shape*> vectshapes,MLV_Color color,  MLV_Color color_border= MLV_COLOR_BLACK);

                virtual void display( std::ostream & out = std::cout ) const;
                bool isInside(const int &x,const int &y) const;
                virtual void reverse();
                
        protected:
                void set_shape(std::vector<double> &pxnew, std::vector<double> &pynew,std::vector<double> &cnew,int &scnew);
                int get_size_cote() const;
                std::vector<double> get_px() const;
                std::vector<double> get_py() const;
                std::vector<double> get_center() const;
                void rotate_center(int angle,int x=0,int y=0,int x0=0, int y0=0);
                void rotate_hw(int angle);
                void translate(int x,int y);
                bool isrevert = false;
                /*shape & operator[](shape &) const {return this;}*/
                
        private:        
                int _size_cote;
                std::vector<double> _px;
                std::vector<double> _py;
                std::vector<double> center;
        };
        void drawAllShapes(const std::vector<geometric_shape::shape*> vectshapes,MLV_Color color_shape,  MLV_Color color_border);
}

std::ostream &operator<<(std::ostream &os, const geometric_shape::shape &_tr);

#endif // SHAPE_H
