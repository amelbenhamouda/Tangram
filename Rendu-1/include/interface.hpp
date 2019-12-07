/*!
 *  \file interface.hpp
 *  \brief Header file of interface.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef INTERFACE_H
#define INTERFACE_H
    #include <vector>
    #include <iostream>
    #include <iostream> 
    #include <MLV/MLV_all.h>
    #include <memory> 
    #include <algorithm>
    #include <cmath>
    #include <fstream>
    #include <string>
    #include "../include/shape.hpp"
    
    /*! \class Interface
     *  \brief classe representant l'interface du jeu
     *
     *  La classe gere l'affichage du jeu
     */
    class Interface {
        public :
            /*!
             *  \brief
             *
             *  \param size 
             *  \param width 
             *  \param height 
             *  \param shapeShared
             */
            void initialiseShared(int size, int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared);

            /*!
             *  \brief
             *
             *  \param size 
             *  \param width 
             *  \param height 
             *  \param motif
             */
            void initialiseMotif(int size, int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &motif);

            /*!
             *  \brief
             *
             *  \param clone 
             *  \param shapeShared 
             */
            void clone(std::vector<std::shared_ptr<geometricShape::Shape>> &clone, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared);

            /*!
             *  \brief
             *
             *  \param n 
             *  \param size 
             *  \param motif
             */
            bool importDraw (const int n, const int size, std::vector<std::shared_ptr<geometricShape::Shape>> &motif);

            /*!
             *  \brief
             *
             *  \param width 
             *  \param height 
             *  \param fig
             */
            void saveFigure(int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &fig);

            /*!
             *  \brief
             *
             *  \param width 
             *  \param height 
             */
            void drawJeu(int width, int height);
    };

#endif // INTERFACE_H
