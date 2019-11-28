#include "../include/rigth_triangle.hpp"
#include <cmath>
#include <MLV/MLV_all.h>

geometric_shape::rigth_triangle::~rigth_triangle()
{
   
}

geometric_shape::rigth_triangle & geometric_shape::rigth_triangle::operator=(const rigth_triangle & tc)
{
    if (this == &tc)
        return *this;

    geometric_shape::rigth_triangle copy(tc);

    std::swap(hauteur, copy.hauteur);
    return *this;
}
geometric_shape::rigth_triangle::rigth_triangle(const rigth_triangle & tc):shape(tc),hauteur(tc.hauteur)
{
        //std::cout << "constructeur de copie" << std::endl;

}


geometric_shape::rigth_triangle::rigth_triangle(int size_cote,int height,int width):shape(size_cote,height,width),hauteur(0)
{
        int _size_cote=size_cote;
        std::vector<double> _px;
        std::vector<double> _py;
        std::vector<double> center;
        _px.push_back(width);
        _px.push_back(width+_size_cote);
        _px.push_back(width);
        _py.push_back(height);
        _py.push_back(height);
        _py.push_back(height+_size_cote);
        center.push_back((double)width + (double)_size_cote/3);
        center.push_back((double)height + (double)_size_cote/3);
        hauteur = sqrt(pow(_size_cote,2)*2)/2;
        set_shape(_px,_py,center,_size_cote);
        //std::cout << hauteur << std::endl;
        /*_px.push_back(center[0]);
        _py.push_back(center[1]);*/

};



void geometric_shape::rigth_triangle::display ( std::ostream & os) const
{
  os << "[rigth_triangle]";
  geometric_shape::shape::display();
}

