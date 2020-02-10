/*!
 *  \file shape.hpp
 *  \brief Le fichier d'entête de shape.cpp.
 *  \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include <list>
#include <iostream>
#include <MLV/MLV_all.h>
#include <memory> // shared_ptr

/*! \class Board
 *  \brief Déclaration de l'objet Board.
 *
 */
class Board;

/*!
 *  \namespace geometricShape
 *  \brief  Espace de nommage geometricShape regroupant les différentes classes de figures utilisées.
 *
 *  Le namespace geometricShape permet de regouper les différentes figures et fonctions extern des class utiliser pour le tangram.
 *  Les class du namespace sont shape, rigth_triangle, paralleogram, square. 
 */
namespace geometricShape {
    /*!
     *  \class Shape
     *  \brief Classe Shape.
     *
     *  La classe Shape est la class mère des figures du tangram elle permet aprés héritage de construire l'ensemble des figures(rigth_triangle, paralleogram, square)
     *  et regroupe l'ensemble des méthodes permettant de manipuler les formes quand celle-ci n'ont pas besoin d'être virtuel.
     * 
     */
    class Shape {       
        public:
            /*!
             *  \brief Constructeur de la class Shape.
             *
             *  Constructeur explicit de la classe Shape.
             *
             *  \param sizeCote : Taille du coté de la figure.
             *  \param width : Emplacement en ligne du premier point de construction.
             *  \param height : Emplacement en collone du premier point de construction.
             */
            explicit Shape(double sizeCote, int width, int height);

            /*!
             *  \brief Destructeur de la class Shape.
             *
             *  Destructeur de la classe Shape déclaré en virtuel car on cette class est hérité par rigth_triangle, paralleogram et square.
             *  Le destructeur n'a pas d'implémentation car les attribut sont statics.
             */
            virtual~Shape();

            /*!
             *  \brief Constructeur de copie.
             *
             *  Constructeur de copie de la classe Shape.
             *  \param cshape : Figure à copier.
             */
            Shape(const Shape &cshape);

            /*!
             *  \brief Opérateur de copie.
             *
             *  Assigment par copie de la classe Shape.
             *  \param cshape : Figure à copier.
             */
            Shape & operator=(const Shape &cshape);

            /*!
             *  \brief Surcharge de l'opérateur de comparaison pour une figure.
             *  \param cshape : Figure à comparer.
             *  \return Un booléen indiquant l'égalité plus ou moins un seuil par sommets (20% de size_cote).
             */
            bool operator==(const Shape &cshape) const;

            /*!
             *  \brief Surcharge de l'opérateur de comparaison pour un ensemble figure
             *
             *  \deprecated Pas Opérative pour l'instant utiliser areEqual.
             *
             *  Fait appel à la surcharge de l' operator== pour une figure afin de comparé un ensemble de figure.
             *  \return Un booléen indiquant l'égalité plus ou moins un seuil par sommets (20% de size_cote)
             *  \param vectShapes : Figures de l'utilisateur à comparer aux modèles.
             *  \param vectModel : Figures modèles à comparer à la figure utilisateur.
             */
            friend bool operator==(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel);
      
            /*!
             *  \brief Méthode de comparaison pour un ensemble figure.
             *
             *  \return Un booléen indiquant l'égalité plus ou moins un seuil (20% de size_cote)
             *  \param vectShapes : Figures de l'utilisateur à comparer aux modèles.
             *  \param vectModel : Figures modèles à comparer à la figure utilisateur.
             */
            friend bool areEqual(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel);
           
            /*!
             *  \brief Méthode permettant de géré les events utilisateur et les rotation/translation des figures.
             *
             *  La méthode moveShape.
             *
             *  \param xInside : Position en x de la souris.
             *  \param yInside :  Position en y de la souris.
             *  \param fig : Ensembles des figures de l'utilisateur à bouger/redesinner.
             *  \param motif : Ensembles des figures de du modèle à redesinner.
             *  \param motifShape : Couleur de l'intérieur du motif.
             *  \param motifBorder : Couleur du contour du motif.
             *  \param colorfig : Vecteur couleur de la figure.
             *  \param fig_num : Itérateur permetant de connaitre la couleur de la figure sélectionner.
             *  \param board : Objet de la class Board permetant de redessiner le fond de la fenêtre en gris.
             *  \param wincondi : Booléen pour connaitre l'état du jeu.
             */        
            void moveShape(int &xInside, int &yInside, std::vector<std::shared_ptr<geometricShape::Shape>> &fig, std::vector<std::shared_ptr<geometricShape::Shape>> &motif, MLV_Color motifShape, MLV_Color motifBorder, std::list<MLV_Color> &colorfig, std::list<MLV_Color>::iterator  fig_num, Board &board, bool &wincondi);
           
            /*!
             *  \brief Méthode permettant desinner une figure de la classe Shape.
             * 
             *  \param colorShape : Couleur de l'intérieur de la figure.
             *  \param colorBorder : Couleur de la bordure de la figure.
             */          
            void draw(MLV_Color colorShape, MLV_Color colorBorder = MLV_COLOR_BLACK) const;

            /*!
             *  \brief Méthode de sauvegarder une figure réaliser sur l'interface.
             *
             *  Sauvegarde les positions x et y de pixels d'une figure ainsi que leurs centres et leur taille dans le fichier savefig.txt.
             *  \param fig : Ensembles des figures de l'utilisateur à sauvegarder.
             */  
            friend void saveDraw(const std::vector<std::shared_ptr<geometricShape::Shape>> &fig);

            /*!
             *  \brief Méthode permettant desinner un ensemble de figures de la classe Shape (tous les objets d'un motif de tangram).
             *
             *  Fait appel à MLV_draw_filled_polygon et MLV_draw_polygon.
             *  \param vectShapes : Ensembles des figures de l'utilisateur à desinner.
             *  \param colorShape : Couleur de la forme.
             *  \param colorBorder : Couleur du contour.
             */  
            friend void drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, MLV_Color colorShape, MLV_Color colorBorder);

            /*!
             *  \brief Surcharge de la méthode drawAllShapes pour un vecteur de couleur.
             *
             *  Fait appel à MLV_draw_filled_polygon et MLV_draw_polygon.
             *  \param vectShapes : Ensembles des figures de l'utilisateur à desinner.
             *  \param colorShapes : Vecteur de couleurs de la forme.
             *  \param colorBorder : Couleur du contour.
             */  
            friend void drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, std::list<MLV_Color> colorShapes, MLV_Color colorBorder);
           
            /*!
             *  \brief Méthode permettant d'afficher sur la console l'objet souhaité.
             *
             *   Méthode virtuel car dépend de la figure appelée.
             *  \param out : Flux de sortie sur la console (par défault std::cout).
             */  
            virtual void display(std::ostream & out = std::cout) const;

            /*!
             *  \brief Méthode permettant de regardé sur un clique de la souris est compris dans un objet.
             *
             *  \param x : Postion x de la souris.
             *  \param y : Postion y de la souris.
             */  
            bool isInside(const int &x, const int &y) const;

            /*!
             *  \brief Méthode permettant de regardé si un objet va dépasser les bordures de la fenêtre de l'interface.
             *
             *  \param x : Postion x de la souris.
             *  \param y : Postion y de la souris.
             *  \param width : Position du board en x dans la fenêtre.
             *  \param heigth : Position du board en y dans la fenêtre.
             */  
            friend bool isInsideBoard(const int &x, const int &y, const int &width, const int &heigth);
             
            /*!
             *  \brief Méthode permettant de faire la symétrie d'un objet.
             *
             *  Déclaré en virtuel car seul le parallelogram necessite une implementation complete de symetrie dans les autres cas on fait une rotation de 180°.
             */ 
            virtual void reverse();
            
            /*!
             *  \brief Méthode permettant de faire la rotation d'un objet par rapport à l'un de ses sommets.
             *
             *  \param angle : Angle de la rotation.
             *  \param n : Numéro du sommet dans un objet shape qui sera le centre de la rotation.
             */ 
            void rotateHW(int angle, unsigned int n);
            
            /*!
             *  \brief Seter de la class geometricShape.
             *
             *  \param pXnew : Nouvelle ensemble de coordonnée en x.
             *  \param pYnew : Nouvelle ensemble de coordonnée en x.
             *  \param cnew : Nouveau centre.
             *  \param scnew : Nouvelle taille de coté.
             */ 
            void setShape(std::vector<double> &pXnew, std::vector<double> &pYnew, std::vector<double> &cnew, double &scnew);
             

        protected:
            /*!
             *  \brief Geter pour sizeCote de la class geometricShape.
             *
             *  Renvoie la taille du coté de construction de la forme.
             */ 
            double getSizeCote() const;

            /*!
             *  \brief Geter pour px la class geometricShape
             *
             *  Renvoie les coordonnées en x de la figure
             */ 
            std::vector<double> getPx() const;

            /*!
             *  \brief Geter pour py de la class geometricShape.
             *
             *  Renvoie les coordonnées en y de la figure.
             */ 
            std::vector<double> getPy() const;

            /*!
             *  \brief Geter pour center la class geometricShape.
             *
             *  Renvoie les coordonnées du centre de la figure.
             */ 
            std::vector<double> getCenter() const;

            /*!
             *  \brief Méthode permettant de faire la rotation d'un objet par rapport à son centre.
             *
             *  \param angle : Angle de la rotation.
             *  \param x : Position en x de la souris.
             *  \param y : Position en y de la souris.
             *  \param x0 : Position de la souris en x à n-1 ( pour obtenir deux vecteurs).
             *  \param y0 : Position de la souris en y à n-1 ( pour obtenir deux vecteurs).
             */ 
            void rotateCenter(int angle, int x = 0, int y = 0, int x0 = 0, int y0 = 0);

            /*!
             *  \brief Méthode permettant de faire la translation d'un objet.
             *
             *  \param x : Position en x de la souris.
             *  \param y : Position en y de la souris.
             */ 
            void translate(int x, int y);
            /*!
             *  \brief Foncteur de la méthode translate qui réalise donc la translation d'un objet.
             *
             *  \param x : Position en x de la souris.
             *  \param y : Position en y de la souris.
             */ 
            void operator()(int x, int y);


            /*!
             *  \brief Test si deux objets peuvent être magnétisé.
             *
             *  Test si l'objet en praramètre et l'objet courant sont égal. 
             *  Si le test est vrai alors l'objet Shape en paramètre prend la valeur de l'objet courant.
             *  Renvoie un booléen pour savoir si le magnétisme à eu lieu.
             *  \param s2 : Objet à tester et à modifier si les test est vrai.
             */ 
            bool  magnetisme(const Shape &s2) ;

            bool isRevert = false; /*!< Booléen pour savoir si une symétrie à été effectuée.*/
                
        private:        
            double sizeCote; /*!< Taille du coté de la forme.*/
            std::vector<double> px; /*!< Coordonnées en x.*/
            std::vector<double> py; /*!< Coordonnées en y.*/
            std::vector<double> center; /*!< Coordonnées du centre.*/
    };
    void drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, MLV_Color colorShape, MLV_Color colorBorder);
    void drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, std::list<MLV_Color> colorShapes, MLV_Color colorBorder);
  //  bool operator == (const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel) ;
    bool areEqual(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel);
    void saveDraw(const std::vector<std::shared_ptr<geometricShape::Shape>> &fig);  
    bool isInsideBoard(const int &x, const int &y, const int &with = 1350, const int &heigth = 700);   
}
/*!
 *  \brief Surcharge du flux de sortie.
 *
 *  Fait appel à la méthode virtuel display .
 */ 
std::ostream &operator<<(std::ostream &os, const geometricShape::Shape &tr);

#endif // SHAPE_H
