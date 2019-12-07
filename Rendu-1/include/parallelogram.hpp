/*!
 *  \file parallelogram.hpp
 *  \brief Header file of parallelogram.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include <vector>
#include <iostream>
#include "../include/shape.hpp"

namespace geometricShape{
    /*! \class Parallelogram
     *  \brief classe representant le parallelogram
     *
     *  Parallélogramme hérite de geometricShape::Shape et calcul un parallélogramme en fonction de la taille de son côté.
     *  Le premier point est dessiné à la largeur et à la hauteur de position données.
     * 
     */
    class Parallelogram : public geometricShape::Shape {       
        public:
            /*!
             *  \brief 
             *
             *  \param sizeCote 
             *  \param height 
             *  \param width
             */
            Parallelogram(int sizeCote, int width, int height);

            /*!
             *  \brief 
             * 
             */
            virtual ~Parallelogram();

            /*!
             *  \brief 
             *
             *  \param tc
             */
            Parallelogram(const Parallelogram &tc);

            /*!
             *  \brief 
             *
             *  \param tc
             */
            Parallelogram & operator=(const Parallelogram &tc);

            /*!
             *  \brief 
             *
             *  \param out
             */
            void display(std::ostream & out = std::cout) const override;

            /*!
             *  \brief 
             * 
             */
            void reverse() override;
    };
}

#endif // PARALLELOGRAM_H
