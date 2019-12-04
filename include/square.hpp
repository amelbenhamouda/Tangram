/**
 * \file square.hpp
 * \brief Header file of square.cpp.
 * \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef SQUARE_H
#define SQUARE_H
#include <vector>
#include <iostream>
#include "../include/shape.hpp"

namespace geometricShape{
    /**
     * \class Square
     * \brief object Square.
     *
     * Square herite from geometricShape::Shape and compute a Square by the given size of his side.
     * The first point is draw at the position width and heigth given. 
     * 
     */
    class Square : public geometricShape::Shape {       
        public:
            Square(int size_cote, int width, int height);
            virtual ~Square();
            Square(const Square &tc);
            Square & operator=(const Square &tc);
            void display(std::ostream & out = std::cout) const;
    };
}

#endif // SQUARE_H
