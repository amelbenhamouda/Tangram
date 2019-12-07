#include "../include/shape.hpp"
#include <cmath>
#include <assert.h> 
#include <fstream>
#include <iostream>
#include <string>

geometricShape::Shape::~Shape() {}

geometricShape::Shape & geometricShape::Shape::operator=(const Shape & tc) {}

bool geometricShape::Shape::operator==(const Shape & s) const {}

bool operator==(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel){}

bool geometricShape::areEqual(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel){}
                
geometricShape::Shape::Shape(const Shape & tc) {}

geometricShape::Shape::Shape(int sizeCote, int width, int height) {}

void geometricShape::Shape::setShape(std::vector<double> &pXnew, std::vector<double> &pYnew, std::vector<double> &cnew, int &scnew) {}

int geometricShape::Shape::getSizeCote() const {}

std::vector<double> geometricShape::Shape::getPx() const {}

std::vector<double> geometricShape::Shape::getPy() const {}

std::vector<double> geometricShape::Shape::getCenter() const {}

void geometricShape::Shape::draw(MLV_Color colorShape, MLV_Color colorBorder) const {}

void geometricShape::drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, MLV_Color colorShape, MLV_Color colorBorder) {}

void geometricShape::Shape::rotateHW(int angle, unsigned int n) {} 

void geometricShape::Shape::rotateCenter(int angle, int x,int y, int x0, int y0) {} 

void geometricShape::Shape::translate(int x, int y) {}

void geometricShape::Shape::reverse() {}

bool geometricShape::Shape::isInside(const int &x, const int &y) const {}

bool geometricShape::isInsideBoard(const int &x, const int &y, const int &with, const int &heigth, const int &sizeW, const int &sizeH) {}

void geometricShape::Shape::moveShape(int &xInside, int &yInside, std::vector<std::shared_ptr<geometricShape::Shape>> &fig, std::vector<std::shared_ptr<geometricShape::Shape>> &motif) {}

void geometricShape::Shape::display(std::ostream & os) const {}

void geometricShape::saveDraw (const std::vector<std::shared_ptr<geometricShape::Shape>> &fig) {}

std::ostream &operator<<(std::ostream &os, const geometricShape::Shape &tr) {}
