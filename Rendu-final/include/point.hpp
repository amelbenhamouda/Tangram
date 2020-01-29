/*!
 *  \file point.hpp
 *  \brief Le fichier d'entête de point.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef POINT_H
#define POINT_H
#include <vector>
#include <iostream>

namespace geometricShape {

    /*! \class Point
     *  \brief Classe pour créer des points 2D.
     *
     *  \tparam T Type associé à un bouton (int, double,...).
     */
    template<class T> 
    class Point {       
        public:
            /*!
             *  \brief Constructeur de Point.
             *
             *  \param x : La coordonnée x d'un point.
             *  \param y : La coordonnée y d'un point.
             */
            Point(T x, T y);

            /*!
             *  \brief Destructeur de Point.
             *
             *  Destructeur de la classe Point déclarée en virtuel.
             *  Le destructeur n'a pas d'implémentation car les attributs sont statics.
             */
            virtual ~Point();

            /*!
             *  \brief Constructeur avec une liste d'initialisation de point.
             *
             *  \param list_x : Liste de coordonnée en x.
             *  \param list_y : Liste de coordonnée en y.
             */
            Point(std::initializer_list<T> list_x, std::initializer_list<T> list_y);

            /*!
             *  \brief Geter du vecteur _px.
             *
             *   Renvoie le vecteur _px.
             */
            std::vector<T> get_Px() {
                return _px;
            }

            /*!
             *  \brief \brief Geter du vecteur _py.
             *
             *   Renvoie le vecteur _py.
             */
            std::vector<T> get_Py() {
                return _py;
            }
            
        private:
            std::vector<T> _px; /*!< Vecteur des coordonnées x. */
            std::vector<T> _py; /*!< Vecteur des coordonnées y. */
    };

    template <class T>
    Point<T>::Point(T x, T y) {
        _px.push_back(x);
        _py.push_back(y);
    };

    template <class T>
    Point<T>::~Point(){};

    template <class T>
    Point<T>::Point(std::initializer_list<T> list_x, std::initializer_list<T> list_y) : _px(list_x), _py(list_y){};
}

#endif // POINT_H
