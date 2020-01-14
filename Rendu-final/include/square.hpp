/*!
 *  \file square.hpp
 *  \brief Header file of square.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef SQUARE_H
#define SQUARE_H
#include <vector>
#include <iostream>
#include "../include/shape.hpp"

namespace geometricShape{

    /*! \class Square
     *  \brief classe representant le carré
     *
     *  Square hérite de geometricShape::Shape et calcul un carré en fonction de la taille de son côté.
     *  Le premier point est dessiné à la largeur et à la hauteur de position données.
     *        .
     */
    class Square : public geometricShape::Shape {       
        public:
            /*!
             *  \brief
             *
             *  \param int sizeCote
             *  \param height
             *  \param width
             */
            Square(double sizeCote, int width, int height);

            /*!
             *  \brief
             * 
             */
            virtual ~Square();

            /*!
             *  \brief
             *
             *  \param tc
             */
            Square(const Square &tc);

            /*!
             *  \brief
             *
             *  \param tc
             */
            Square & operator=(const Square &tc);

            /*!
             *  \brief
             *
             *  \param out
             */
            void display(std::ostream & out = std::cout) const;
    };
}

#endif // SQUARE_H
