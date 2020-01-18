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

namespace geometricShape {

    /*! \class Square
     *  \brief classe representant le carré*
     *  Square hérite de geometricShape::Shape et calcul un carré en fonction de la taille de son côté.
     *  Le premier point est dessiné à la largeur et à la hauteur des position données (width/heigth).
     *        .
     */
    class Square : public geometricShape::Shape {       
        public:
            /*!
             *  \brief Constructeur de la class Square qui reçoit en entrer la taille d'un coté et la position du carré dans la fenêtre.
             *  \param int sizeCote : taille d'un coté du carré
             *  \param height : emplacement du premier point en hauteur
             *  \param width : emplacement du premier point en largeur
             */
            Square(double sizeCote, int width, int height);

            /*!
             *  \brief destructeur de la class Square  
             */
            virtual ~Square();

            /*!
             *  \brief Constructeur de copie
             *  \param tc : objet de type Square à copié
             */
            Square(const Square &tc);

            /*!
             *  \brief Opérateur de copie
             *  \param tc : objet de type Square à copié
             */
            Square & operator=(const Square &tc);

            /*!
             *  \brief méthode d'affichage pour le fulx de sortie,
             *  Cette méthode permet d'afficher les paramètres de l'objet Square dans un flux de sortie ( par défault std::cout).
             *  \param out : flux de sortie, par default std::cout
             */
            void display(std::ostream & out = std::cout) const;
    };
}

#endif // SQUARE_H
