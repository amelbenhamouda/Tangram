/**
 * \file parallelogram.hpp
 * \brief Header file of parallelogram.cpp.
 * \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include <vector>
#include <iostream>
#include "../include/shape.hpp"

namespace geometricShape{
    /**
     * \class Parallelogram
     * \brief object Parallelogram.
     *
     * Parallelogram herite from geometricShape::Shape and compute a Parallelogram by the given size of his side.
     * The first point is draw at the position width and heigth given. 
     * 
     */
    class Parallelogram : public geometricShape::Shape {       
        public:
            Parallelogram(int sizeCote, int width, int height);
            virtual ~Parallelogram();
            Parallelogram(const Parallelogram &tc);
            Parallelogram & operator=(const Parallelogram &tc);
            void display(std::ostream & out = std::cout) const override;
            void reverse() override;
    };
}

#endif // PARALLELOGRAM_H
