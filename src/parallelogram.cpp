#include "../include/parallelogram.hpp"
#include <cmath>
#include <MLV/MLV_all.h>

geometric_shape::parallelogram::~parallelogram()
{
   
}

geometric_shape::parallelogram & geometric_shape::parallelogram::operator=(const parallelogram & tc)
{
    if (this == &tc)
        return *this;
    geometric_shape::parallelogram copy(tc);
    return *this;
}
geometric_shape::parallelogram::parallelogram(const parallelogram & tc):shape(tc)
{
        //std::cout << "constructeur de copie" << std::endl;

}


geometric_shape::parallelogram::parallelogram(int size_cote,int height,int width):shape(size_cote,height,width)
                                                                                
{
        int _size_cote=size_cote;
        std::vector<double> _px;
        std::vector<double> _py;
        std::vector<double> center;
        _px.push_back(width);
        _px.push_back(width+_size_cote);
        _px.push_back(width);
        _px.push_back(width-_size_cote);
        _py.push_back(height);
        _py.push_back(height);
        _py.push_back(height+_size_cote);
        _py.push_back(height+_size_cote);
        center.push_back((double)width);
        center.push_back((double)height+(double)_size_cote/2);
        set_shape(_px,_py,center,_size_cote);
        /*_px.push_back(center[0]);
        _py.push_back(center[1]);*/

};


void geometric_shape::parallelogram::display ( std::ostream & os) const
{
  os << "[parallelogram]";
  geometric_shape::shape::display();
}

std::ostream &operator<<(std::ostream &os, const geometric_shape::parallelogram &_tr)
{

    _tr.display(os);
    return os ;
}


void geometric_shape::parallelogram::reverse()
{
    //std::cout << "reverse virtual"<< std::endl;
    double px0 ;
    double py0 ;
    double px2 ;
    double py2 ;

    std::vector <double> px=get_px();
    std::vector <double> py=get_py();
    if (isrevert== true)
    {
        px0 = px[2];
        py0 = py[2];
        px2 = px[0];
        py2 = py[0];
    }
    else
    {
        px0 = px[0];
        py0 = py[0];
        px2 = px[2];
        py2 = py[2];                   

    }
    std::vector <double> newpx;
    std::vector <double> newpy;
    double npx1=2*px0-px[1];
    double npy1=2*py0-py[1];
    double npx3=2*px2-px[3];
    double npy3=2*py2-py[3];
    newpx.push_back(px[2]);
    newpx.push_back(npx1);
    newpx.push_back(px[0]);
    newpx.push_back(npx3);
    newpy.push_back(py[2]);
    newpy.push_back(npy1);
    newpy.push_back(py[0]);
    newpy.push_back(npy3);
    std::vector <double> newcenter = get_center();
    int newsizecote= get_size_cote();
    set_shape(newpx,newpy,newcenter,newsizecote);
    isrevert = !isrevert;
    //std::cout << isrevert << " -- ";
    MLV_wait_milliseconds(500);
}
    
