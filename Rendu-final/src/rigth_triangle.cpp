#include "../include/rigth_triangle.hpp"
#include <cmath>
#include <MLV/MLV_all.h>

geometricShape::RigthTriangle::~RigthTriangle() {}

geometricShape::RigthTriangle & geometricShape::RigthTriangle::operator=(const RigthTriangle & tc) {
    if (this == &tc) {
        return *this;
    }
    geometricShape::RigthTriangle copy(tc);
    std::swap(hauteur, copy.hauteur);
    return *this;
}

geometricShape::RigthTriangle::RigthTriangle(const RigthTriangle & tc) : Shape(tc), hauteur(tc.hauteur) {}

geometricShape::RigthTriangle::RigthTriangle(int sizeCote, int width, int height) : Shape(sizeCote, width, height), hauteur(0) {
    int _size_cote = sizeCote;
    std::vector<double> _px;
    std::vector<double> _py;
    std::vector<double> center;
    _px.push_back(width);
    _px.push_back(width + _size_cote);
    _px.push_back(width);
    _py.push_back(height);
    _py.push_back(height);
    _py.push_back(height + _size_cote);
    center.push_back((double)width + (double)_size_cote / 3);
    center.push_back((double)height + (double)_size_cote / 3);
    hauteur = sqrt(pow(_size_cote, 2) * 2) / 2;
    setShape(_px, _py, center, _size_cote);
}

void geometricShape::RigthTriangle::display(std::ostream & os) const {
    os << "[RigthTriangle]";
    geometricShape::Shape::display();
}
