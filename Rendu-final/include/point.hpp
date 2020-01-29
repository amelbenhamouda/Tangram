/*!
 *  \file point.hpp
 *  \brief Header file of point.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef POINT_H
#define POINT_H
#include <vector>
#include <iostream>


namespace geometricShape {

    /*! \class Point
     *  \brief classe Pour créer des points 2D le carré
     *  \tparam T Type associé à un bouton (int, double,...)
     *  Square hérite de geometricShape::Shape et calcul un carré en fonction de la taille de son côté.
     *  Le premier point est dessiné à la largeur et à la hauteur de position données.
     *        .
     */

    template<class T> 
    class Point {       
        public:
            /*!
             *  \brief constructeur de Point
             *
             *  \param int sizeCote
             *  \param height
             *  \param width
             */
            Point(T x, T y);

            /*!
             *  \brief Destructeur de Point
             */
            virtual ~Point();

            /*!
             *  \brief constructeur avec list d'initialisation de point
             *
             *  \param list_x : liste de coordonnée en x
             *  \param list_y : liste de coordonnée en y 
             */
            Point(std::initializer_list<T> list_x, std::initializer_list<T> list_y);

            /*!
             *  \brief Geter du vecteur _px
             * 
             */
            std::vector<T> get_Px() {
                return _px;
            }

            /*!
             *  \brief \brief Geter du vecteur _py
             * 
             */
            std::vector<T> get_Py() {
                return _py;
            }
            
        private:
            std::vector<T> _px;
            std::vector<T> _py;
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
