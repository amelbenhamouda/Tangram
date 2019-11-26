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

namespace geometric_shape{
     /**
     * \class square
     * \brief object square.
     *
     * square herite from geometric_shape::shape and compute a square by the given size of his side.
     * The first point is draw at the position width and heigth given. 
     * 
     */
        class square : public geometric_shape::shape
        {       
        public:
                square(int size_cote,int height,int width);
                virtual ~square();
                square(const square &tc);
                square & operator=(const square &tc);
                void display( std::ostream & out = std::cout ) const;

        };
}

std::ostream &operator<<(std::ostream &os, const geometric_shape::square &_tr);

#endif // SQUARE_H
