#include "../include/parallelogram.hpp"
#include "../include/point.hpp"
#include <cmath>
#include <MLV/MLV_all.h>

geometricShape::Parallelogram::~Parallelogram() {}

geometricShape::Parallelogram::Parallelogram(double sizeCote, int width, int height) : Shape(sizeCote, width, height) {
    double _size_cote = sizeCote;
    std::vector<double> _px;
    std::vector<double> _py;
    std::vector<double> center;
    /*_px.push_back(width);
    _px.push_back(width + _size_cote);
    _px.push_back(width);
    _px.push_back(width - _size_cote);
    _py.push_back(height);
    _py.push_back(height);
    _py.push_back(height + _size_cote);
    _py.push_back(height + _size_cote);*/
    double dw = (double)width;
    double dh = (double)height;
    Point<double> point_square({dw,dw+_size_cote,dw,dw-_size_cote},{dh,dh,dh+_size_cote,dh+_size_cote});
    _px=point_square.get_Px();
    _py=point_square.get_Py();
    center.push_back((double)width);
    center.push_back((double)height + (double)_size_cote / 2);
    setShape(_px, _py, center, _size_cote);
}

geometricShape::Parallelogram & geometricShape::Parallelogram::operator=(const Parallelogram & tc) {
    if (this == &tc) {
        return *this;
    }
    geometricShape::Parallelogram copy(tc);
    return *this;
}

geometricShape::Parallelogram::Parallelogram(const Parallelogram & tc) : Shape(tc) {}


void geometricShape::Parallelogram::display(std::ostream & os) const {
    os << "[Parallelogram]";
    geometricShape::Shape::display();
}

void geometricShape::Parallelogram::reverse() {
    double px0, py0, px2, py2 ;
    std::vector <double> px = getPx();
    std::vector <double> py = getPy();
    if (isRevert == true) {
        px0 = px[2];
        py0 = py[2];
        px2 = px[0];
        py2 = py[0];
    }
    else {
        px0 = px[0];
        py0 = py[0];
        px2 = px[2];
        py2 = py[2];                   

    }
    /*std::vector <double> newpx;
    std::vector <double> newpy;*/
    double npx1 = 2 * px0 - px[1];
    double npy1 = 2 * py0 - py[1];
    double npx3 = 2 * px2 - px[3];
    double npy3 = 2 * py2 - py[3];
    std::vector <double> newpx{px[2],npx1,px[0],npx3};
    std::vector <double> newpy{py[2],npy1,py[0],npy3};
    /*newpx.push_back(px[2]);
    newpx.push_back(npx1);
    newpx.push_back(px[0]);
    newpx.push_back(npx3);*/
   /* newpy.push_back(py[2]);
    newpy.push_back(npy1);
    newpy.push_back(py[0]);
    newpy.push_back(npy3);*/
    std::vector <double> newcenter = getCenter();
    double newsizecote = getSizeCote();
    setShape(newpx, newpy, newcenter, newsizecote);
    isRevert = !isRevert;
    MLV_wait_milliseconds(500);
}
