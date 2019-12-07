#include "../include/square.hpp"
#include <cmath>
#include <MLV/MLV_all.h>

geometricShape::Square::~Square(){}

geometricShape::Square & geometricShape::Square::operator=(const Square & tc) {}

geometricShape::Square::Square(const Square & tc) {}

geometricShape::Square::Square(int sizeCote, int width, int height) : Shape(sizeCote, width, height) {}

void geometricShape::Square::display(std::ostream & os)const {}
