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

namespace geometric_shape{
     /**
     * \class parallelogram
     * \brief object parallelogram.
     *
     * parallelogram herite from geometric_shape::shape and compute a parallelogram by the given size of his side.
     * The first point is draw at the position width and heigth given. 
     * 
     */
        class parallelogram : public geometric_shape::shape
        {       
        public:
                parallelogram(int size_cote,int height,int width);
                virtual ~parallelogram();
                parallelogram(const parallelogram &tc);
                parallelogram & operator=(const parallelogram &tc);
                void display( std::ostream & out = std::cout ) const override;
                void reverse() override;

        };
}


#endif // PARALLELOGRAM_H
