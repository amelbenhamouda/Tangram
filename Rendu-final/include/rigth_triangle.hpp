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
             *  \brief Constructeur de la class RigtTriangle 
             *  Le constructeur reçoit en entrer la taille d'un coté et la position du triangle droit dans la fenêtre.
             *  \param int sizeCote : taille d'un coté du triangle rectangle
             *  \param width : emplacement du premier point en largeur
             *  \param height : emplacement du premier point en hauteur
             */
            RigthTriangle(double sizeCote, int width, int height);

            /*!
             *  \brief destructeur de la class RigthTriangle   
             */
            virtual ~RigthTriangle();

            /*!
             *  \brief Constructeur de copie
             *  \param tc : objet de type RigthTriangle à copié
             */
            RigthTriangle(const RigthTriangle &tc);

            /*!
             *  \brief Opérateur de copie
             *  \param tc : objet de type RigthTriangle à copié
             */
            RigthTriangle & operator=(const RigthTriangle &tc);

            /*!
             *  \brief méthode d'affichage pour le fulx de sortie,
             *  Cette méthode permet d'afficher les paramètres de l'objet RigthTriangle dans un flux de sortie ( par défault std::cout).
             *  \param out : flux de sortie, par default std::cout
             */
            void display(std::ostream & out = std::cout) const;

        private:        
            double hauteur; /*!<  ... */
    };
}

#endif // RIGTHTRIANGLE_H
