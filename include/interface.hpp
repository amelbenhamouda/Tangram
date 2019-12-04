/**
 * \file interface.hpp
 * \brief Header file of interface.cpp.
 * \author BEN HAMOUDA Amel & DURAND Aurélien
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
   
    class Interface {
        public :
            void initialiseShared(int size, int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared);
            void initialiseMotif(int size, int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &motif);
            void clone(std::vector<std::shared_ptr<geometricShape::Shape>> &clone, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared);
            bool importDraw (const int n, const int size, std::vector<std::shared_ptr<geometricShape::Shape>> &motif);
            void saveFigure(int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &fig);
            void drawJeu(int width, int height);
    };

#endif //INTERFACE_H
