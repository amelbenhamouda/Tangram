/**
 * \file rigth_triangle.hpp
 * \brief Header file of rigth_triangle.cpp.
 * \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef RIGTHTRIANGLE_H
#define RIGTHTRIANGLE_H
#include <vector>
#include <iostream>
#include "../include/shape.hpp"

namespace geometricShape{
	/**
     * \class RigthTriangle
     * \brief object RigthTriangle.
     *
     * square herite from geometricShape::Shape and compute a rigth triangle by the given size of his side.
     * The first point is draw at the position width and heigth given.
     *        .
     * 
     */
    class RigthTriangle : public geometricShape::Shape {       
        public:
            RigthTriangle(int sizeCote, int width, int height);
            virtual ~RigthTriangle();
            RigthTriangle(const RigthTriangle &tc);
            RigthTriangle & operator=(const RigthTriangle &tc);
            void display(std::ostream & out = std::cout) const;
        private:        
            double hauteur;
    };
}

#endif // RIGTHTRIANGLE_H
