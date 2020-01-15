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
             *  \brief Constructeur de la class Parallelogram qui reçoit en entrer la taille d'un coté et la Parallelogram du carré dans la fenêtre.
             *  \param int sizeCote : taille d'un coté du Parallelogram
             *  \param height : emplacement du premier point en hauteur
             *  \param width : emplacement du premier point en largeur
             */
            Parallelogram(double sizeCote, int width, int height);

            /*!
             *  \brief destructeur de la class Parallelogram
             */
            virtual ~Parallelogram();

            /*!
             *  \brief   
             *  \param tc
             */
            Parallelogram(const Parallelogram &tc);

            /*!
             *  \brief Constructeur de copie
             *  \param tc : objet de type Parallelogram à copié
             */
            Parallelogram & operator=(const Parallelogram &tc);

            /*!
             *  \brief méthode d'affichage pour le fulx de sortie,
             *  Cette méthode permet d'afficher les paramètres de l'objet Parallelogram dans un flux de sortie ( par défault std::cout).
             *  \param out : flux de sortie, par default std::cout
             */
            void display(std::ostream & out = std::cout) const override;

            /*!
             *  \brief Surcharge de la méthode reverse specifique aux parallelogram
             *  La méthode reverse doit être surcharger car contrairement à la class Square et à la class RigthTriangle, on doit réalisé le mirroir de celle-ci.
             *  On réalise donc la symétrie du parallèlogram dans cette méthode car un retournement par 180° n'est pas la symétrie du parralèlogramme.
             */
            void reverse() override;
    };
}

#endif // PARALLELOGRAM_H
