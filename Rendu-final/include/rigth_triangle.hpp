/*!
 *  \file rigth_triangle.hpp
 *  \brief Header file of rigth_triangle.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef RIGTHTRIANGLE_H
#define RIGTHTRIANGLE_H
#include <vector>
#include <iostream>
#include "../include/shape.hpp"
//#include "../include/point.hpp"

namespace geometricShape{
	/*! \class RigthTriangle
     *  \brief classe representant le trianble
     *
     *  RigthTriangle hérite de geometricShape::Shape et calcul un triangle en fonction de la taille de son côté.
     *  Le premier point est dessiné à la largeur et à la hauteur de position données.
     *        .
     */
    class RigthTriangle : public geometricShape::Shape {       
        public:
            /*!
             *  \brief
             *
             *  \param sizeCote
             *  \param height
             *  \param width
             */
            RigthTriangle(double sizeCote, int width, int height);

            /*!
             *  \brief
             * 
             */
            virtual ~RigthTriangle();

            /*!
             *  \brief
             *
             *  \param tc
             */
            RigthTriangle(const RigthTriangle &tc);

            /*!
             *  \brief
             *
             *  \param tc
             */
            RigthTriangle & operator=(const RigthTriangle &tc);

            /*!
             *  \brief
             *
             *  \param out
             */
            void display(std::ostream & out = std::cout) const;

        private:        
            double hauteur; /*!<  ... */
    };
}

#endif // RIGTHTRIANGLE_H
