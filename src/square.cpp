#include "../include/square.hpp"
#include <cmath>
#include <MLV/MLV_all.h>

geometricShape::Square::~Square(){}

geometricShape::Square & geometricShape::Square::operator=(const Square & tc) {
    if (this == &tc) {
        return *this;
    }
    geometricShape::Square copy(tc);
    return *this;
}

geometricShape::Square::Square(const Square & tc) : Shape(tc) {}

geometricShape::Square::Square(int sizeCote, int width, int height) : Shape(sizeCote, width, height) {
    int _size_cote = sizeCote;
    std::vector<double> _px;
    std::vector<double> _py;
    std::vector<double> center;
    _px.push_back(width);
    _px.push_back(width + _size_cote);
    _px.push_back(width + _size_cote);
    _px.push_back(width);
    _py.push_back(height);
    _py.push_back(height);
    _py.push_back(height + _size_cote);
    _py.push_back(height + _size_cote);
    center.push_back((double)width + (double)_size_cote / 2);
    center.push_back((double)height + (double)_size_cote / 2);
    setShape(_px, _py, center, _size_cote);
}

void geometricShape::Square::display(std::ostream & os)const {
    os << "[Square]";
    geometricShape::Shape::display();
}
