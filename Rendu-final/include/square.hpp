/*!
 *  \file square.hpp
 *  \brief Le fichier d'entête de square.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef SQUARE_H
#define SQUARE_H
#include <vector>
#include <iostream>
#include "../include/shape.hpp"

namespace geometricShape {

    /*! \class Square
     *  \brief Classe représentant un carré.
     *
     *  Square hérite de geometricShape::Shape et calcul un carré en fonction de la taille de son côté.
     *  Le premier point est dessiné à la largeur et à la hauteur des positions données (width/heigth).
     *        .
     */
    class Square : public geometricShape::Shape {       
        public:
            /*!
             *  \brief Constructeur de la classe Square qui reçoit en entrer la taille d'un coté et la position du carré dans la fenêtre.
             *
             *  \param sizeCote : Taille d'un coté du carré.
             *  \param height : Emplacement du premier point en hauteur.
             *  \param width : Emplacement du premier point en largeur.
             */
            Square(double sizeCote, int width, int height);

            /*!
             *  \brief Destructeur de la class Square.
             *
             *  Destructeur de la classe Shape déclaré en virtuel.
             *  Le destructeur n'a pas d'implémentation car les attribut sont statics.  
             */
            virtual ~Square();

            /*!
             *  \brief Constructeur de copie.
             *
             *  \param tc : Objet de type Square à copié.
             */
            Square(const Square &tc);

            /*!
             *  \brief Opérateur de copie.
             *
             *  \param tc : Objet de type Square à copié.
             */
            Square & operator=(const Square &tc);

            /*!
             *  \brief Méthode d'affichage pour le fulx de sortie.
             *
             *  Cette méthode permet d'afficher les paramètres de l'objet Square dans un flux de sortie ( par défault std::cout).
             *  \param out : Flux de sortie, par default std::cout.
             */
            void display(std::ostream & out = std::cout) const;
    };
}

#endif // SQUARE_H
