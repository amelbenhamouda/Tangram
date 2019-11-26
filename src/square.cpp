#include "../include/square.hpp"
#include <cmath>
#include <MLV/MLV_all.h>

geometric_shape::square::~square()
{
   
}

geometric_shape::square & geometric_shape::square::operator=(const square & tc)
{
    if (this == &tc)
        return *this;
    geometric_shape::square copy(tc);
    return *this;
}
geometric_shape::square::square(const square & tc):shape(tc)
{
        //std::cout << "constructeur de copie" << std::endl;

}


geometric_shape::square::square(int size_cote,int height,int width):shape(size_cote,height,width)
                                                                                
{
        int _size_cote=size_cote;
        std::vector<double> _px;
        std::vector<double> _py;
        std::vector<double> center;
        _px.push_back(width);
        _px.push_back(width+_size_cote);
        _px.push_back(width+_size_cote);
        _px.push_back(width);
        _py.push_back(height);
        _py.push_back(height);
        _py.push_back(height+_size_cote);
        _py.push_back(height+_size_cote);
        center.push_back((double)width+(double)_size_cote/2);
        center.push_back((double)height+(double)_size_cote/2);
        set_shape(_px,_py,center,_size_cote);
        /*_px.push_back(center[0]);
        _py.push_back(center[1]);*/

};


void geometric_shape::square::display ( std::ostream & os) const
{
  os << "[square]";
  geometric_shape::shape::display();
}

std::ostream &operator<<(std::ostream &os, const geometric_shape::square &_tr)
{

    _tr.display(os);
    return os ;
}
