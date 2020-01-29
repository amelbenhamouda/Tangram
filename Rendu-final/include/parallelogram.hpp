/*!
 *  \file parallelogram.hpp
 *  \brief Le fichier d'entête de parallelogram.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include <vector>
#include <iostream>
#include "../include/shape.hpp"

namespace geometricShape {
    /*! \class Parallelogram
     *  \brief Classe représentant le parallelogram.
     *
     *  Parallélogramme hérite de geometricShape::Shape et calcul un parallélogramme en fonction de la taille de son côté.
     *  Le premier point est dessiné à la largeur et à la hauteur des positions données (width/heigth).
     * 
     */
    class Parallelogram : public geometricShape::Shape {       
        public:
            /*!
             *  \brief Constructeur de la class Parallelogram.
             *
             *  Le constructeur reçoit en entrer la taille du petit coté du Parallelogram ainsi que sa position dans la fenêtre.
             *  \param sizeCote : Taille d'un coté du Parallelogram.
             *  \param height : Emplacement du premier point en hauteur.
             *  \param width : Emplacement du premier point en largeur.
             */
            Parallelogram(double sizeCote, int width, int height);

            /*!
             *  \brief Destructeur de la classe Parallelogram.
             *
             *  Destructeur de la classe Shape déclaré en virtuel.
             *  Le destructeur n'a pas d'implémentation car les attribut sont statics. 
             */
            virtual ~Parallelogram();

            /*!
             *  \brief Constructeur de copie.
             *
             *  Constructeur de copie de la classe Parallelogram.
             *  \param tc : Parallelogram à copier.
             */
            Parallelogram(const Parallelogram &tc);

            /*!
             *  \brief Opérateur de copie.
             *  \param tc : Objet de type Parallelogram à copié.
             */
            Parallelogram & operator=(const Parallelogram &tc);

            /*!
             *  \brief Méthode d'affichage pour le flux de sortie.
             *
             *  Cette méthode permet d'afficher les paramètres de l'objet Parallelogram dans un flux de sortie (par défault std::cout).
             *  \param out : Flux de sortie, par défaut std::cout.
             */
            void display(std::ostream & out = std::cout) const override;

            /*!
             *  \brief Surcharge de la méthode reverse spécifique aux parallelogram.
             *
             *  La méthode reverse doit être surcharger car contrairement à la classe Square et à la classe RigthTriangle, on doit réalisé le mirroir de celle-ci.
             *  On réalise donc la symétrie du parallèlogram dans cette méthode car un retournement par 180° n'est pas la symétrie du parralèlogramme.
             */
            void reverse() override;
    };
}

#endif // PARALLELOGRAM_H
