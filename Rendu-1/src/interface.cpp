#include "../include/interface.hpp"
#include "../include/rigth_triangle.hpp"
#include "../include/square.hpp"
#include "../include/parallelogram.hpp"
#include "../include/shape.hpp"
#include "../include/board.hpp"
#include "../include/menu.hpp"
#include "../include/button.hpp"

#include <memory> 
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>


void Interface::initialiseShared(int size, int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared) {}

void Interface::initialiseMotif(int size, int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &motif) {}

void Interface::clone(std::vector<std::shared_ptr<geometricShape::Shape>> &clone, std::vector<std::shared_ptr<geometricShape::Shape>> &shapeShared) {}

bool Interface::importDraw (const int n, const int size, std::vector<std::shared_ptr<geometricShape::Shape>> &motif) {}

void Interface::saveFigure(int width, int height, std::vector<std::shared_ptr<geometricShape::Shape>> &fig) {}

void Interface::drawJeu(int width, int height) {}
