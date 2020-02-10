/*!
 *  \file interface.hpp
 *  \brief Le fichier d'entête de interface.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
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
    
    /*! \class Interface
     *  \brief Classe representant l'interface du jeu.
     *
     *  La classe gére l'affichage du jeu.
     */
    class Interface {
        public :
            /*!
             *  \brief Initialisation des figures du tangram.
             *
             *  Reçoit un vecteur de shared_ptr de type Shape qui sera remplie des objets du tangram (Square, Parallelogram et RigthTriangle).
             *
             *  \param size : La taille de référence des figures qui est la taille associé au côté du carré.
             *  \param width : La longeur de la fenêtre.
             *  \param height : La largeur de la fenêtre.
             *  \param shapeShared : Le vecteur de shared_ptr de type Shape à remplir.
             */
            void initialiseShared(const int size,const int width,const int height, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared);

            /*!
             *  \brief Initialisation d'un motif initial.
             *
             *  Reçoit un vecteur de shared_ptr de type Shape qui sera remplie des objets du tangram (Square, Parallelogram et RigthTriangle).
             *
             *  \param size : La taille de référence des figures qui est la taille associé au côté du carré.
             *  \param width : La longeur de la fenêtre.
             *  \param height : La largeur de la fenêtre.
             *  \param motif : Le vecteur de shared_ptr de type Shape à remplir.
             */
            void initialiseMotif(const int size, const int width, const int height, std::vector<std::shared_ptr<geometricShape::Shape>> &motif);

            /*!
             *  \brief Permet la copie d'un shared_ptr.
             *
             *  \param clone : Le vecteur de shared_ptr de type Shape à cloner.
             *  \param shapeShared : Le vecteur de shared_ptr de type Shape à remplir.
             */
            void clone(std::vector<std::shared_ptr<geometricShape::Shape>> &clone, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared);

            /*!
             *  \brief Méthode permettant d'importé des figures.
             *
             *  Permet d'ouvrir le fichier texte savefig.txt qui contient l'ensemble des figures sauvegardées obtenues grâce à la méthode saveFigure.
             *
             *  \param n : Le numéro de la figure à lire.
             *  \param motif : Le motif à remplir en fonction de la lecture du fichier.
             */
            bool importDraw(const int n, std::vector<std::shared_ptr<geometricShape::Shape>> &motif);

            /*!
             *  \brief Méthode permettant de sauvegarder une figure.
             *  
             *  Demande de sauvegarder une figure dessiné par le joueur dans le ficher savefig.txt cette méthode fait appel .
             *
             *  \param width : La longeur de la fenêtre.
             *  \param height : La largeur de la fenêtre.
             *  \param fig : Le vecteur de shared_ptr de type Shape remplie.
             */
            void saveFigure(const int width,const int height,const std::vector<std::shared_ptr<geometricShape::Shape>> &fig);

            /*!
             *  \brief Méthode permettant d'afficher une image (message) quand le joueur gagne.
             *
             *  \param width : La longeur de la fenêtre.
             *  \param height : La largeur de la fenêtre.
             */
            void winner(const int width, const int height);

            /*!
             *  \brief Méthode permettant de dessiner l'interface graphique du jeu.
             *
             *  \param width : La longeur de la fenêtre.
             *  \param height : La largeur de la fenêtre.
             */
            void drawJeu(const int width,const int height);
    };

#endif // INTERFACE_H
