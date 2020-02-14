#include "../include/square.hpp"
#include "../include/point.hpp"
#include <cmath>
#include <MLV/MLV_all.h>

geometricShape::Square::~Square(){}

geometricShape::Square & geometricShape::Square::operator=(const Square & tc) {
    if (this == &tc) {
        return *this;
    }
    geometricShape::Square copy(tc);
    *this = copy;
    return *this;
}

geometricShape::Square::Square(const Square & tc) : Shape(tc) {}

geometricShape::Square::Square(double sizeCote, int width, int height) : Shape(sizeCote, width, height) {
    double _size_cote = sizeCote;
    std::vector<double> _px;
    std::vector<double> _py;
    std::vector<double> center;
    double dw = (double)width;
    double dh = (double)height;
    Point<double> point_square({dw, dw + _size_cote, dw + _size_cote, dw}, {dh, dh, dh + _size_cote, dh + _size_cote});
    _px = point_square.get_Px();
    _py = point_square.get_Py();
    center.push_back((double)width + (double)_size_cote / 2);
    center.push_back((double)height + (double)_size_cote / 2);
    setShape(_px, _py, center, _size_cote);
}

void geometricShape::Square::display(std::ostream & os)const {
    os << "[Square]";
    geometricShape::Shape::display();
}
