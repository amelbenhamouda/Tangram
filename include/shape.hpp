/**
 * \file shape.hpp
 * \brief Header file of shape.cpp.
 * \author BEN HAMOUDA Amel & DURAND Aurélien
 */

#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include <iostream>
#include <MLV/MLV_all.h>
#include <memory> // shared_ptr

     /**
     * \namespace geometric_shape
     * \brief  geometric_shape.
     * Le namespace geometric_shape permet de regouper les différentes figures et fonction extern des class utiliser pour le tangram.
     * Les classs du namespace sont shape, rigth_triangle, paralleogram, square.
     * 
     */

namespace geometric_shape{
	 /**
     * \class shape
     * \brief shape.
     * La class shape est la class mère des figures du tangram elle permet aprés héritage de construire l'ensemble des figures(rigth_triangle, paralleogram, square)
     * et regroupe l'ensemble des méthodes permettant de manipuler les formes quand celle-ci n'ont pas besoin d'être virtuel.
     * 
     */
        class shape
        {       
        public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe shape
     *
     *  \param size_cote : taille du coté de la figure
     *  \param height : emplacement en collone du premier point de construction
     *  \param width : emplacement en ligne du premier point de construction
     */
                shape(int size_cote,int height,int width);
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe shape déclaré en virtuel car on cette class est hérité par rigth_triangle, paralleogram et square.
     *  Le destructeur n'a pas d'implémentation car les attribut sont statics.
     * 
     *  
     */
                virtual~shape();
    /*!
     *  \brief Constructeur de copie
     *
     *  Constructeur de copie de la classe shape 
     *  \param cshape : figure à copier.
     *  
     */

                shape(const shape &cshape);
    /*!
     *  \brief Operateur de copie
     *
     *  Assigment par copie de la classe shape 
     *  \param cshape : figure à copier.
     *  
     */
                shape & operator=(const shape &cshape);
    /*!
     *  \brief Surcharge de l'opérateur de comparaison pour une figure
     *  \param cshape : figure à comparer.
     *  \return Un booléen indiquant l'égalité plus ou moins un seuil par sommets (20% de size_cote)
     */
                bool operator== (const shape &) const;
     /*!
     *  \brief Surcharge de l'opérateur de comparaison pour un ensemble figure
     *  \deprecated Pas Opérative pour l'instant utiliser areEqual.
     *  Fait appel à la surcharge de l' operator== pour une figure afin de comparé un ensemble de figure.
     *  \return Un booléen indiquant l'égalité plus ou moins un seuil par sommets (20% de size_cote)
     *  \param vectshapes : figures de l'utilisateur à comparer aux modèles.
     *  \param vectmodel : figures modèles à comparer à la figure utilisateur.
     *  
     */
                friend bool operator== (const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectshapes,const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectmodel) ;
      
    /*!
     *  \brief Methode de comparaison pour un ensemble figure
     *  \return Un booléen indiquant l'égalité plus ou moins un seuil (20% de size_cote)
     *  \param vectshapes : figures de l'utilisateur à comparer aux modèles.
     *  \param vectmodel : figures modèles à comparer à la figure utilisateur.
     *  
     */

                friend bool areEqual(const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectshapes,const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectmodel) ;
    /*!
     *  \brief Methode permettant de géré les events utilisateur et les rotation/translation des figures.
     *  \param fig : ensembles des figures de l'utilisateur à bouger/redesinner.
     *  \param motif : ensembles des figures de du modèle à redesinner.
     *  \param x_inside : position en x de la souris.
     *  \param y_inside :  position en y de la souris.
     *  
     */        
               //virtual void move_shape(int &x_inside,int &y_inside, std::vector<geometric_shape::shape*> fig);
                void move_shape(int &x_inside,int &y_inside, std::vector<std::shared_ptr<geometric_shape::shape> >  &fig, std::vector<std::shared_ptr<geometric_shape::shape> >  &motif);
    /*!
     *  \brief Methode permettant desinner une figure de la classe shape.
     *  Fait appel à MLV_draw_filled_polygon et MLV_draw_polygon.
     *  \param fig : ensembles des figures de l'utilisateur à bouger/redesinner.
     *  \param motif : ensembles des figures de du modèle à redesinner.
     *  \param x_inside : position en x de la souris.
     *  \param y_inside :  position en y de la souris.
     *  
     */          

                void draw(MLV_Color color_shape,  MLV_Color color_border= MLV_COLOR_BLACK) const;
    /*!
     *  \brief Methode de sauvegarder une figure réaliser sur l'interface.
     *  Sauvegarde les positions x et y de pixels d'une figure ainsi que leurs centres et leur taille dans le fichier savefig.txt.
     *  \param fig : ensembles des figures de l'utilisateur à sauvegarder.
     *
     */  
                friend void savedraw (const std::vector<std::shared_ptr<geometric_shape::shape> >  &fig);
    /*!
     *  \brief Methode permettant desinner un ensemble de figures de la classe shape (tous les objets d'un motif de tangram).
     *  Fait appel à MLV_draw_filled_polygon et MLV_draw_polygon.
     *  \param vectshapes : ensembles des figures de l'utilisateur à desinner.
     *  \param color_shape : couleur de la forme.
     *  \param color_border : couleur du contour.
     *  
     */  
                //friend void drawAllShapes(const std::vector<geometric_shape::shape*> vectshapes,MLV_Color color,  MLV_Color color_border= MLV_COLOR_BLACK);
                friend void drawAllShapes(const  std::vector<std::shared_ptr<geometric_shape::shape> >  &vectshapes,MLV_Color color_shape,  MLV_Color color_border);

    /*!
     *  \brief Methode permettant d'afficher sur la console l'objet souhaité.
     *   Méthode virtuel car dépend de la figure appelée.
     *  \param out : flux de sortie sur la console.
     *  
     */  
                virtual void display( std::ostream & out = std::cout ) const;
    /*!
     *  \brief Methode permettant de regardé sur un clique de la souris est compris dans un objet.
     *  \param x : postion x de la souris.
     *  \param y : postion y de la souris.
     */  
                bool isInside(const int &x,const int &y) const;
    /*!
     *  \brief Methode permettant de regardé si un objet va dépasser les bordures de la fenêtre de l'interface.
     *  \param x : postion x de la souris.
     *  \param y : postion y de la souris.
     */  
                friend bool isInsideBoard(const int &x,const int &y,const int &with,const int &heigth,const int &sizew,const int &sizeh) ;
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

                void rotate_hw(int angle,unsigned int n);
    /*!
     *  \brief Seter de la class geometric_shape
     *  \param pxnew : nouvelle ensemble de coordonnée en x.
     *  \param pynew : nouvelle ensemble de coordonnée en x.
     *  \param cnew : nouveau centre.
     *  \param scnew : nnouvelle taille de coté.
     */ 
                void set_shape(std::vector<double> &pxnew, std::vector<double> &pynew,std::vector<double> &cnew,int &scnew);
                
        protected:

    /*!
     *  \brief Geter pour _size_cote de la class geometric_shape
     *    renvoie la taille du coté de construction de la forme
     */ 
                int get_size_cote() const;
    /*!
     *  \brief Geter pour _px la class geometric_shape
     *    renvoie les coordonnées en x de la figure
     */ 
                std::vector<double> get_px() const;
    /*!
     *  \brief Geter pour _py la class geometric_shape
     *    renvoie les coordonnées en y de la figure
     */ 
                std::vector<double> get_py() const;
    /*!
     *  \brief Geter pour center la class geometric_shape
     *    renvoie les coordonnées du centre de la figure.
     */ 
                std::vector<double> get_center() const;
    /*!
     *  \brief Methode permettant de faire la rotation d'un objet par rapport à son centre.
     *  \param angle : angle de la rotation.
     *  \param x : position en x de la souris.
     *  \param y : position en y de la souris.
     *  \param x0 : position de la souris en x à n-1 ( pour obtenir un deux vecteurs).
     *  \param y0 :  position de la souris en yà n-1 ( pour obtenir un deux vecteurs).
     */ 
                void rotate_center(int angle,int x=0,int y=0,int x0=0, int y0=0);
    /*!
     *  \brief Methode permettant de faire la translation d'un objet par rapport à son centre.
     *  \param x : position en x de la souris.
     *  \param y : position en y de la souris.
     */ 
                void translate(int x,int y);

                bool isrevert = false; /*!< Booléen pour savoir si une symétrie à été effectué*/
                /*shape & operator[](shape &) const {return this;}*/
                
        private:        
                int _size_cote; /*!< Taille du coté de la forme*/
                std::vector<double> _px; /*!< Coordonnée en x*/
                std::vector<double> _py; /*!< Coordonnée en y*/
                std::vector<double> center; /*!< Coordonnée du centre*/
        };
        //void drawAllShapes(const std::vector<geometric_shape::shape*> vectshapes,MLV_Color color_shape,  MLV_Color color_border);
        void drawAllShapes(const  std::vector<std::shared_ptr<geometric_shape::shape> >  &vectshapes,MLV_Color color_shape,  MLV_Color color_border);
        bool operator == (const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectshapes,
                          const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectmodel) ;
        bool areEqual(const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectshapes,const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectmodel) ;
        void savedraw (const std::vector<std::shared_ptr<geometric_shape::shape> >  &fig);  
        bool isInsideBoard(const int &x,const int &y,const int &with=0,const int &heigth=0,const int &sizew=0,const int &sizeh=0);   
}
    /*!
     *  \brief Surcharge du flux de sortie.
     *  Fait appel à la méthode virtuel display .
     */ 
std::ostream &operator<<(std::ostream &os, const geometric_shape::shape &_tr);

#endif // SHAPE_H
