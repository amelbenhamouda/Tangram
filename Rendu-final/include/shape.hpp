/*!
 *  \file shape.hpp
 *  \brief Header file of shape.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include <list>
#include <iostream>
#include <MLV/MLV_all.h>
#include <memory> // shared_ptr

/*!
 *  \namespace geometricShape
 *  \brief  geometricShape.
 *  Le namespace geometricShape permet de regouper les différentes figures et fonction extern des class utiliser pour le tangram.
 *  Les classs du namespace sont shape, rigth_triangle, paralleogram, square. 
 */
namespace geometricShape {
    /*!
     *  \class Shape
     *  \brief Shape.
     *  La class Shape est la class mère des figures du tangram elle permet aprés héritage de construire l'ensemble des figures(rigth_triangle, paralleogram, square)
     *  et regroupe l'ensemble des méthodes permettant de manipuler les formes quand celle-ci n'ont pas besoin d'être virtuel.
     * 
     */
    class Shape {       
        public:
            /*!
             *  \brief Constructeur
             *
             *  Constructeur explicit de la classe Shape
             *
             *  \param sizeCote : taille du coté de la figure
             *  \param width : emplacement en ligne du premier point de construction
             *  \param height : emplacement en collone du premier point de construction
             */
            explicit Shape(double sizeCote, int width, int height);

            /*!
             *  \brief Destructeur
             *
             *  Destructeur de la classe Shape déclaré en virtuel car on cette class est hérité par rigth_triangle, paralleogram et square.
             *  Le destructeur n'a pas d'implémentation car les attribut sont statics.
             */
            virtual~Shape();

            /*!
             *  \brief Constructeur de copie
             *
             *  Constructeur de copie de la classe Shape 
             *  \param cshape : figure à copier.
             */
            Shape(const Shape &cshape);

            /*!
             *  \brief Operateur de copie
             *
             *  Assigment par copie de la classe Shape 
             *  \param cshape : figure à copier.
             */
            Shape & operator=(const Shape &cshape);

            /*!
             *  \brief Surcharge de l'opérateur de comparaison pour une figure
             *  \param cshape : figure à comparer.
             *  \return Un booléen indiquant l'égalité plus ou moins un seuil par sommets (20% de size_cote)
             */
            bool operator==(const Shape &cshape) const;

            /*!
             *  \brief Surcharge de l'opérateur de comparaison pour un ensemble figure
             *  \deprecated Pas Opérative pour l'instant utiliser areEqual.
             *  Fait appel à la surcharge de l' operator== pour une figure afin de comparé un ensemble de figure.
             *  \return Un booléen indiquant l'égalité plus ou moins un seuil par sommets (20% de size_cote)
             *  \param vectShapes : figures de l'utilisateur à comparer aux modèles.
             *  \param vectModel : figures modèles à comparer à la figure utilisateur.
             */
            friend bool operator==(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel);
      
            /*!
             *  \brief Methode de comparaison pour un ensemble figure
             *  \return Un booléen indiquant l'égalité plus ou moins un seuil (20% de size_cote)
             *  \param vectShapes : figures de l'utilisateur à comparer aux modèles.
             *  \param vectModel : figures modèles à comparer à la figure utilisateur.
             */
            friend bool areEqual(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel);
           
            /*!
             *  \brief Methode permettant de géré les events utilisateur et les rotation/translation des figures.
             *  \param xInside : position en x de la souris.
             *  \param yInside :  position en y de la souris.
             *  \param fig : ensembles des figures de l'utilisateur à bouger/redesinner.
             *  \param motif : ensembles des figures de du modèle à redesinner.
             *  \param colorfig : vecteur couleur de la figure.
             */        
            void moveShape(int &xInside, int &yInside, std::vector<std::shared_ptr<geometricShape::Shape>> &fig, std::vector<std::shared_ptr<geometricShape::Shape>> &motif, MLV_Color motifShape, MLV_Color motifBorder, std::list<MLV_Color> &colorfig, std::list<MLV_Color>::iterator  fig_num);
           
            /*!
             *  \brief Methode permettant desinner une figure de la classe Shape.
             *  ....
             *  \param colorShape : 
             *  \param colorBorder : 
             */          
            void draw(MLV_Color colorShape, MLV_Color colorBorder = MLV_COLOR_BLACK) const;

            /*!
             *  \brief Methode de sauvegarder une figure réaliser sur l'interface.
             *  Sauvegarde les positions x et y de pixels d'une figure ainsi que leurs centres et leur taille dans le fichier savefig.txt.
             *  \param fig : ensembles des figures de l'utilisateur à sauvegarder.
             */  
            friend void saveDraw(const std::vector<std::shared_ptr<geometricShape::Shape>> &fig);

            /*!
             *  \brief Methode permettant desinner un ensemble de figures de la classe Shape (tous les objets d'un motif de tangram).
             *  Fait appel à MLV_draw_filled_polygon et MLV_draw_polygon.
             *  \param vectShapes : ensembles des figures de l'utilisateur à desinner.
             *  \param colorShape : couleur de la forme.
             *  \param colorBorder : couleur du contour.
             */  
            friend void drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, MLV_Color colorShape, MLV_Color colorBorder);

            /*!
             *  \brief Methode permettant de desinner un ensemble de figures de la classe Shape (tous les objets d'un motif de tangram).
             *  Fait appel à MLV_draw_filled_polygon et MLV_draw_polygon.
             *  \param vectShapes : ensembles des figures de l'utilisateur à desinner.
             *  \param colorShape : vecteur de couleurs de la forme.
             *  \param colorBorder :  couleur du contour.
             */  
            friend void drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, std::list<MLV_Color> colorShapes, MLV_Color colorBorder);
           
            /*!
             *  \brief Methode permettant d'afficher sur la console l'objet souhaité.
             *   Méthode virtuel car dépend de la figure appelée.
             *  \param out : flux de sortie sur la console.
             */  
            virtual void display(std::ostream & out = std::cout) const;

            /*!
             *  \brief Methode permettant de regardé sur un clique de la souris est compris dans un objet.
             *  \param x : postion x de la souris.
             *  \param y : postion y de la souris.
             */  
            bool isInside(const int &x, const int &y) const;

            /*!
             *  \brief Methode permettant de regardé si un objet va dépasser les bordures de la fenêtre de l'interface.
             *  \param x : postion x de la souris.
             *  \param y : postion y de la souris.
             *  \param width : 
             *  \param heigth :  
             */  
            friend bool isInsideBoard(const int &x, const int &y, const int &width, const int &heigth);
             
            /*!
             *  \brief Methode permettant de faire la symétrie d'un objet.
             *  déclaré en virtuel car seul le parallelogram necessite une implementation complete de symetrie dans les autres cas on fait une rotation de 180°.
             */ 
            virtual void reverse();
            
            /*!
             *  \brief Methode permettant de faire la rotation d'un objet par rapport à l'un de ses sommets.
             *  utiliser danss le main pour constuire une figure de base.
             *  \param angle : angle de la rotation.
             *  \param n : n° du sommet qui sera le centre de la rotation.
             */ 
            void rotateHW(int angle, unsigned int n);
            
            /*!
             *  \brief Seter de la class geometricShape
             *  \param pXnew : nouvelle ensemble de coordonnée en x.
             *  \param pYnew : nouvelle ensemble de coordonnée en x.
             *  \param cnew : nouveau centre.
             *  \param scnew : nnouvelle taille de coté.
             */ 
            void setShape(std::vector<double> &pXnew, std::vector<double> &pYnew, std::vector<double> &cnew, double &scnew);
                
        protected:
            /*!
             *  \brief Geter pour sizeCote de la class geometricShape
             *  renvoie la taille du coté de construction de la forme
             */ 
            double getSizeCote() const;

            /*!
             *  \brief Geter pour px la class geometricShape
             *  renvoie les coordonnées en x de la figure
             */ 
            std::vector<double> getPx() const;

            /*!
             *  \brief Geter pour py la class geometricShape
             *  renvoie les coordonnées en y de la figure
             */ 
            std::vector<double> getPy() const;

            /*!
             *  \brief Geter pour center la class geometricShape
             *  renvoie les coordonnées du centre de la figure.
             */ 
            std::vector<double> getCenter() const;

            /*!
             *  \brief Methode permettant de faire la rotation d'un objet par rapport à son centre.
             *  \param angle : angle de la rotation.
             *  \param x : position en x de la souris.
             *  \param y : position en y de la souris.
             *  \param x0 : position de la souris en x à n-1 ( pour obtenir un deux vecteurs).
             *  \param y0 :  position de la souris en yà n-1 ( pour obtenir un deux vecteurs).
             */ 
            void rotateCenter(int angle, int x = 0, int y = 0, int x0 = 0, int y0 = 0);

            /*!
             *  \brief Methode permettant de faire la translation d'un objet.
             *  \param x : position en x de la souris.
             *  \param y : position en y de la souris.
             */ 
            void translate(int x, int y);
            /*!
             *  \brief Foncteur de la méthode translate qui réalise donc la translation d'un objet.
             *  \param x : position en x de la souris.
             *  \param y : position en y de la souris.
             */ 
            void operator()(int x, int y);

            bool isRevert = false; /*!< Booléen pour savoir si une symétrie à été effectué*/
                
        private:        
            double sizeCote; /*!< Taille du coté de la forme*/
            std::vector<double> px; /*!< Coordonnée en x*/
            std::vector<double> py; /*!< Coordonnée en y*/
            std::vector<double> center; /*!< Coordonnée du centre*/
    };
    void drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, MLV_Color colorShape, MLV_Color colorBorder);
    void drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, std::list<MLV_Color> colorShapes, MLV_Color colorBorder);
    bool operator == (const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel) ;
    bool areEqual(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel);
    void saveDraw(const std::vector<std::shared_ptr<geometricShape::Shape>> &fig);  
    bool isInsideBoard(const int &x, const int &y, const int &with = 1350, const int &heigth = 700);   
}
/*!
 *  \brief Surcharge du flux de sortie.
 *  Fait appel à la méthode virtuel display .
 */ 
std::ostream &operator<<(std::ostream &os, const geometricShape::Shape &tr);

#endif // SHAPE_H
