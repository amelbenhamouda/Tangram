/**
 * \file rigth_triangle.hpp
 * \brief Header file of rigth_triangle.cpp.
 * \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef RIGTH_TRIANGLE_H
#define RIGTH_TRIANGLE_H
#include <vector>
#include <iostream>
#include "../include/shape.hpp"

namespace geometric_shape{
	 /**
     * \class rigth_triangle
     * \brief object rigth_triangle.
     *
     * square herite from geometric_shape::shape and compute a rigth triangle by the given size of his side.
     * The first point is draw at the position width and heigth given.
     *        .
     * 
     */
        class rigth_triangle : public geometric_shape::shape
        {       
        public:
                rigth_triangle(int size_cote,int height,int width);
                virtual ~rigth_triangle();
                rigth_triangle(const rigth_triangle &tc);
                rigth_triangle & operator=(const rigth_triangle &tc);
                void display( std::ostream & out = std::cout ) const;

        private:        
                double hauteur;
        };
}


#endif // RIGTH_TRIANGLE_H
