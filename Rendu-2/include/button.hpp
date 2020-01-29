/*!
 *  \file button.hpp
 *  \brief Le fichier d'entête de button.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef BUTTON_H
#define BUTTON_H
    #include <iostream> 
    #include <MLV/MLV_all.h>

    /*! \class Button
     *  \brief Classe représentant le bouton.
     *
     *  \tparam T Type associé à un bouton (int, float,...).
     *
     *  La classe gére la création, l'affichage et l'interaction d'un bouton.
     */
    template<class T> 
    class Button {
        private:        
            T x; /*!< La coordonnée en x de la position du coin Nord-Ouest de la boîte. */
            T y; /*!< La coordonnée en y de la position du coin Nord-Ouest de la boîte. */
            T width; /*!< La longeur de la fenêtre. */
            T height; /*!< La largeur de la fenêtre. */
            std::string message; /*!< Le message qui sera écrit sur le bouton. */
            T interligne; /*!< La taille de l'interligne. */
            MLV_Color borderColor; /*!< La couleur de la bordure. */
            MLV_Color textColor; /*!< La couleur du texte. */
            MLV_Color backgroundColor; /*!< La couleur du fond de la boîte. */

        public:
            /*!
             *  \brief Constructeur de Button.
             *
             */
            Button();
      
            /*!
             *  \brief Constructeur de Button.
             *
             *  \param x : La coordonnée en x de la position du coin Nord-Ouest de la boîte.
             *  \param y : La coordonnée en y de la position du coin Nord-Ouest de la boîte.
             *  \param width : La longeur de la fenêtre.
             *  \param height : La largeur de la fenêtre.
             *  \param message : Le message qui sera écrit sur le bouton.
             */
            Button(T x, T y, T width, T height, const std::string message);
        
            /*!
             *  \brief Destructeur de Button.
             * 
             *  Destructeur de la classe Button déclaré en virtuel.
             *  Le destructeur n'a pas d'implémentation car les attributs sont statics.
             */
            virtual~Button();
        
            /*!
             *  \brief Dessine un bouton.
             *
             *  Dessine un bouton en fonction de tous ces paramètres.
             *
             *  \param interligne : La taille de l'interligne.
             *  \param borderColor : La couleur de la bordure.
             *  \param textColor : La couleur du texte.
             *  \param backgroundColor : La couleur du fond de la boîte.
             */
            void drawButton(T interligne, MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor);
      
            /*!
             *  \brief Savoir si on a cliqué sur le bouton.
             *
             *  Renvoie un entier en fonction du bouton cliqué.
             *
             *  \param pX : La coordonnée x du clic de la souris.
             *  \param pY : La coordonnée y du clic de la souris.
             */
            bool inButton(T pX, T pY);
    };

    template <class T>
    Button<T>::Button() : x(0), y(0), width(0), height(0), message(0), interligne(0), borderColor(MLV_COLOR_BLACK), textColor(MLV_COLOR_BLACK), backgroundColor(MLV_COLOR_BLACK) {}
    
    template <class T>
    Button<T>::Button(T x, T y, T width, T height, const std::string message) : x(x), y(y), width(width), height(height), message(message), interligne(0), borderColor(MLV_COLOR_BLACK), textColor(MLV_COLOR_BLACK), backgroundColor(MLV_COLOR_BLACK) {}
    
    template <class T>
    Button<T>::~Button(){}

    template <typename T>
    void Button<T>::drawButton(T interligne, MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor) {
        // x, y  La coordonnée en X, Y de la position du coin Nord-Ouest de la boîte.
        const char * cstr = message.c_str();
        MLV_draw_text_box(x, y, width, height, cstr, interligne, borderColor, textColor, backgroundColor, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    }

    template <typename T>
    bool Button<T>::inButton(T pX, T pY) {
        if (pX >= x and pX <= (x + width) and pY >= y and pY <= (y + height)) {
           return 1;
        }
        return 0;
    }

#endif // BUTTON_H