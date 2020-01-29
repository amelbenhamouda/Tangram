/*!
 *  \file rigth_triangle.hpp
 *  \brief Le fichier d'entête de rigth_triangle.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef RIGTHTRIANGLE_H
#define RIGTHTRIANGLE_H
#include <vector>
#include <iostream>
#include "../include/shape.hpp"

namespace geometricShape {
	/*! \class RigthTriangle
     *  \brief Classe répresentant le triangle.
     *
     *  RigthTriangle hérite de geometricShape::Shape et calcul un triangle en fonction de la taille de son côté.
     *  Le premier point est dessiné à la largeur et à la hauteur des positions données (width/heigth).
     *        .
     */
    class RigthTriangle : public geometricShape::Shape {       
        public:
            /*!
             *
             *  \brief Constructeur de la classe RigtTriangle. 
             *
             *  Le constructeur reçoit en entrer la taille d'un coté et la position du triangle droit dans la fenêtre.
             *  \param sizeCote : Taille d'un coté du triangle rectangle.
             *  \param width : Emplacement du premier point en largeur.
             *  \param height : Emplacement du premier point en hauteur.
             */
            RigthTriangle(double sizeCote, int width, int height);

            /*!
             *  \brief Destructeur de la class RigthTriangle.
             *
             *  Destructeur de la class RigthTriangle déclaré en virtuel.
             *  Le destructeur n'a pas d'implémentation car les attribut sont statics.  
             */
            virtual ~RigthTriangle();

            /*!
             *  \brief Constructeur de copie.
             *  \param tc : Objet de type RigthTriangle à copié
             */
            RigthTriangle(const RigthTriangle &tc);

            /*!
             *  \brief Opérateur de copie.
             *  \param tc : Objet de type RigthTriangle à copié
             */
            RigthTriangle & operator=(const RigthTriangle &tc);

            /*!
             *  \brief Méthode d'affichage pour le flux de sortie.
             *
             *  Cette méthode permet d'afficher les paramètres de l'objet RigthTriangle dans un flux de sortie (par défault std::cout).
             *  \param out : Flux de sortie, par default std::cout
             */
            void display(std::ostream & out = std::cout) const;

        private:        
            double hauteur; /*!<  Hauteur du triangle rectangle. */
    };
}

#endif // RIGTHTRIANGLE_H
