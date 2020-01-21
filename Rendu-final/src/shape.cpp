#include "../include/shape.hpp"
#include <cmath>
#include <assert.h> 
#include <fstream>
#include <iostream>
#include <string>

geometricShape::Shape::~Shape() {}

geometricShape::Shape & geometricShape::Shape::operator=(const Shape & tc) {
    if (this == &tc){
        return *this;
    }

    geometricShape::Shape copy(tc);
    std::swap(sizeCote, copy.sizeCote);
    std::swap(px, copy.px);
    std::swap(py, copy.py);
    std::swap(center, copy.center);
    return *this;
}

bool geometricShape::Shape::operator==(const Shape & s) const {
    bool ret = false;
    double thresh = round(sizeCote * 0.2);
    unsigned int nbequal = 0;
    if (px.size() != s.px.size())
        return false;
    
    for (unsigned int i = 0; i < px.size(); i++) {
        for (unsigned int j = 0; j < s.px.size(); j++) {
            if ((px[i] <= s.px[j] + thresh) && (px[i] >= s.px[j] - thresh) && (py[i] <= s.py[j] + thresh) && (py[i] >= s.py[j] - thresh)) {
                nbequal++;
            }
        }
    }
    if ((nbequal == px.size()) && (sizeCote == s.sizeCote)) {
        ret = true;
    }
    return ret;
}

bool  geometricShape::Shape::magnetisme(const Shape &s2) {
    if(*this==s2){
        *this=s2 ;
        //std::cout << ret << std::endl;
        return true;
    }
    return false;
}



bool operator==(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel){
    return areEqual(vectShapes, vectModel); 
}

bool geometricShape::areEqual(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel){
    unsigned int count = 0;
    bool ret = false;
    drawAllShapes(vectShapes, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
    drawAllShapes(vectModel, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
    if (vectShapes.size() == vectModel.size()) {
        for (auto shap_it : vectShapes) {
            for (auto model_it : vectModel) {
                bool loc = (*shap_it == *model_it);
                ret = loc;
                if (loc == true) {
                    count++;
                }
            }
        }
        if (count == vectShapes.size()) {
            ret = true;
        }
        else {
            ret = false;
        }
    }
    return ret; 
}
                
geometricShape::Shape::Shape(const Shape & tc) : sizeCote(tc.sizeCote), px(tc.px), py(tc.py), center(tc.center) {}

geometricShape::Shape::Shape(double sizeCote, int width, int height) : sizeCote(sizeCote), px(0), py(0), center(0) {}

void geometricShape::Shape::setShape(std::vector<double> &pXnew, std::vector<double> &pYnew, std::vector<double> &cnew, double &scnew) {
    sizeCote = scnew;
    px = pXnew;
    py = pYnew;
    center = cnew;
}

double geometricShape::Shape::getSizeCote() const {
    return sizeCote;
}

std::vector<double> geometricShape::Shape::getPx() const {
    return px;
}

std::vector<double> geometricShape::Shape::getPy() const {
    return py;
}

std::vector<double> geometricShape::Shape::getCenter() const {
    return center;
}

void geometricShape::Shape::draw(MLV_Color colorShape, MLV_Color colorBorder) const {
    std::vector<int> pxDraw;
    std::vector<int> pyDraw;
    for (unsigned int i = 0; i < px.size(); i++) {
      pxDraw.push_back(floor(px[i] + 0.5));
      pyDraw.push_back(floor(py[i] + 0.5));
    }
    MLV_draw_filled_polygon(pxDraw.data(), pyDraw.data(), px.size(), colorShape);
    MLV_draw_polygon(pxDraw.data(), pyDraw.data(), px.size(), colorBorder);
}

void geometricShape::drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, MLV_Color colorShape, MLV_Color colorBorder) {
    for(auto it : vectShapes){
        it->draw(colorShape, colorBorder);
    }
}

void geometricShape::drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, std::list<MLV_Color> colorShapes, MLV_Color colorBorder) {
    auto itcolor = colorShapes.begin();
    for (auto it : vectShapes) {
        it->draw(*itcolor, colorBorder);
        itcolor++;
    }
}

void geometricShape::Shape::rotateHW(int angle, unsigned int n) {       
    assert(n <= px.size() && n >= 0);
    double pivoX = px[n];
    double pivoY = py[n];
    double angleRad = (double) angle * 3.141592653589793238462643383279 / 180;
    for (unsigned int it = 0; it < px.size(); it++) {
        if (it != n) {
            double xM = px[it] - pivoX;
            double yM = py[it] - pivoY;
            px[it] = xM * cos(angleRad) + yM * sin(angleRad) + pivoX; 
            py[it] = -xM * sin(angleRad) + yM * cos(angleRad) + pivoY;
        }
    }
    double xM = center[0] - pivoX;
    double yM = center[1] - pivoY;
    center[0] = xM * cos(angleRad) + yM * sin(angleRad) + pivoX;
    center[1] = -xM * sin(angleRad) + yM * cos(angleRad) + pivoY;
} 

void geometricShape::Shape::rotateCenter(int angle, int x,int y, int x0, int y0) {   
    double angleRad;
    if ((x != 0) && (y != 0) && x != x0 && y != y0) {
        double Ux = x - center[0];
        double Uy = y - center[1];
        double Vx = x0 - center[0];
        double Vy = y0 - center[1];
        double normU = sqrt(pow(Ux, 2) + pow(Uy, 2));
        double normV = sqrt(pow(Vx, 2) + pow(Vy, 2));
        double distUV = sqrt(pow(x - x0, 2) + pow(y - y0, 2));
        int det = Ux * Vy - Uy * Vx;
        angleRad = 0.5 * (pow(normU, 2) + pow(normV, 2) - pow(distUV, 2));
        angleRad = acos(angleRad / (normU * normV));
        angleRad = copysign(angleRad, det);
    }
    else {
        angleRad = (double) angle * 3.141592653589793238462643383279 / 180;
    }
    std::vector<double> pxloc = px;
    std::vector<double> pyloc = py; 
    bool inside = false;
    for (unsigned int it = 0; it < px.size(); it++) {
        double xM = pxloc[it] - center[0];
        double yM = pyloc[it] - center[1];
        pxloc[it] = xM * cos(angleRad) + yM * sin(angleRad) + center[0];   /* [cos(0) -sin(0); sin(0) cos(0)]*/
        pyloc[it] = -xM * sin(angleRad) + yM * cos(angleRad) + center[1];
        inside = isInsideBoard(pxloc[it], pyloc[it]);
        if (inside == 0) {
            break;
        }
    }
    if (inside == true) {
        px = pxloc;
        py = pyloc;
    }
} 

void geometricShape::Shape::translate(int x, int y) {
    // translation de l'objet en fonction de la position x,y de la souris
    std::vector<double> pxloc = px;
    std::vector<double> pyloc = py; 
    bool inside = false;
    for (unsigned int it = 0; it < pxloc.size(); it++) {
        pxloc[it] += x;   /* [cos(0) -sin(0); sin(0) cos(0)]*/
        pyloc[it] += y;
        inside = isInsideBoard(pxloc[it], pyloc[it]);
        if (inside == false) {
            break;
        }
    }
    if (inside == true) {
        px = pxloc;
        py = pyloc;
        center[0] += x;
        center[1] += y;
    }
}

void geometricShape::Shape::operator()(int x, int y) {
    translate(x, y);
}

void geometricShape::Shape::reverse() {
    rotateCenter(180);
    MLV_wait_milliseconds(500);
}

bool geometricShape::Shape::isInside(const int &x, const int &y) const {
    for (unsigned int i = 0; i < px.size(); i++) {
        int Ax = px[i];
        int Ay = py[i];
        int Bx, By;
        if (i == px.size() - 1) {  // if i == last point of vector px then B == first point
            Bx = px[0];
            By = py[0];
        }
        else {          // else B take the point at i+1
            Bx = px[i + 1];
            By = py[i + 1];
        }
        double Dx, Dy, Tx, Ty;
        Dx = Bx - Ax;
        Dy = By - Ay;
        Tx = x - Ax;
        Ty = y - Ay;
        double d = Dx * Ty - Dy * Tx;
        if (d < 0) {
            return false;  // Point (x,y) is not inside.
        }
    }
    return true;
}

bool geometricShape::isInsideBoard(const int &x, const int &y, const int &width, const int &heigth) {
    std::vector<double> Boardx;
    std::vector<double> Boardy;
    Boardx.push_back(45);
    Boardx.push_back(width - 270);
    Boardx.push_back(width - 270);
    Boardx.push_back(45);

    Boardy.push_back(35);
    Boardy.push_back(35);
    Boardy.push_back(heigth - 12);
    Boardy.push_back(heigth - 12);

    for (unsigned int i = 0; i < Boardx.size(); i++) {
        int Ax = Boardx[i];
        int Ay = Boardy[i];
        int Bx, By;
        if (i == Boardx.size() - 1) { // if i== last point of vector px then B == first point
            Bx = Boardx[0];
            By = Boardy[0];
        }
        else {  // else B take the point at i+1
            Bx = Boardx[i + 1];
            By = Boardy[i + 1];
        }
        double Dx, Dy, Tx, Ty;
        Dx = Bx - Ax;
        Dy = By - Ay;
        Tx = x - Ax;
        Ty = y - Ay;
        double d = Dx * Ty - Dy * Tx;
        if (d < 0) {
            return false;  // Point (x,y) is not inside.
        }
    }
    return true;
}

void geometricShape::Shape::moveShape(int &xInside, int &yInside, std::vector<std::shared_ptr<geometricShape::Shape>> &fig, 
                                    std::vector<std::shared_ptr<geometricShape::Shape>> &motif, MLV_Color motifShape, MLV_Color motifBorder, 
                                    std::list<MLV_Color> &colorfig, std::list<MLV_Color>::iterator fig_num) {
    if (isInside(xInside, yInside) == 1) { 
        bool done = false;
        std::list<MLV_Color> colorfig_loc = colorfig;
        Uint8 red, green, blue, alpha;
        MLV_convert_color_to_rgba(*fig_num, &red, &green, &blue, &alpha);
        red = red * 0.5;
        green = green * 0.5;
        blue = blue * 0.5;
        *fig_num = MLV_convert_rgba_to_color(red, green, blue, alpha);

        while (done != true) {
            int x, y;
            MLV_get_mouse_position(&x, &y); 
            MLV_wait_milliseconds(0.01);
            if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED && (isInside(x, y) == true)) {
                while (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
                    int x2, y2;
                    MLV_get_mouse_position(&x2, &y2);
                    draw(MLV_COLOR_GRAY, MLV_COLOR_GRAY);
                    drawAllShapes(motif, motifShape, motifBorder);
                    operator()(x2 - xInside, y2 - yInside);
                    MLV_wait_milliseconds(0.01);
                    if (MLV_get_mouse_button_state(MLV_BUTTON_RIGHT) == MLV_PRESSED) {
                        rotateCenter(1);
                        MLV_wait_milliseconds(80); 
                    }
                    if (MLV_get_mouse_button_state(MLV_BUTTON_MIDDLE) == MLV_PRESSED) {
                        reverse();
                    }
                    drawAllShapes(motif, motifShape, motifBorder);
                    drawAllShapes(fig, colorfig, MLV_COLOR_RED);
                    MLV_actualise_window();
                    xInside = x2; 
                    yInside = y2;
                }
            } 
            else if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED && (isInside(x, y) == 0)) {
                done = true;
            }
            while (MLV_get_mouse_button_state(MLV_BUTTON_RIGHT) == MLV_PRESSED) {
                    draw(MLV_COLOR_GRAY, MLV_COLOR_GRAY);
                    int xRot, yRot;
                    MLV_get_mouse_position(&xRot, &yRot);
                    if ((xRot != x) && (yRot != y)) {
                        rotateCenter(1, xRot, yRot, x, y);
                        drawAllShapes(motif, motifShape, motifBorder);
                        drawAllShapes(fig, colorfig, MLV_COLOR_RED);
                        MLV_actualise_window();
                        MLV_wait_milliseconds(10);
                        x = xRot;
                        y = yRot;
                    }
                }
            if (MLV_get_mouse_button_state(MLV_BUTTON_MIDDLE) == MLV_PRESSED) {
                draw(MLV_COLOR_GRAY, MLV_COLOR_GRAY);
                reverse();
                drawAllShapes(motif, motifShape, motifBorder);
                drawAllShapes(fig, colorfig, MLV_COLOR_RED);
                MLV_actualise_window();
            }
            drawAllShapes(motif, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
            drawAllShapes(fig, MLV_COLOR_GRAY, MLV_COLOR_GRAY);
            for(auto it : motif){
                    magnetisme(*it);
            }
            drawAllShapes(motif, motifShape, motifBorder);
            drawAllShapes(fig, colorfig, MLV_COLOR_RED);
        }
        colorfig = colorfig_loc;
        drawAllShapes(motif, motifShape, motifBorder);
        drawAllShapes(fig, colorfig, MLV_COLOR_RED);
    }
}

void geometricShape::Shape::display(std::ostream & os) const {
    os << " Shape with coordinate : ";
    for (unsigned int i = 0; i < px.size(); i++) {
        os << "[" << px[i] << "; " << py[i] << "] ";
    }
    os << std::endl;
}

void geometricShape::saveDraw(const std::vector<std::shared_ptr<geometricShape::Shape>> &fig) {
    std::ofstream saveFig("doc/savefig.txt",std::ios::app);
    if (saveFig) {   
        int n = 1;
        for (auto it : fig) {
            saveFig << n ;
            n++;
            for (unsigned int itp = 0; itp < it->px.size(); itp++) {
                saveFig << " " << it->px[itp] << " " << it->py[itp] << "  ";
            }
            saveFig << " " << it->center[0] << " " << it->center[1] << " " << it->sizeCote << " ";
            saveFig << std::endl;
        }
        saveFig << std::endl;   
        saveFig.close();
    }
    else {
        std::cout << "ERROR: Cannot open savefig.txt." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const geometricShape::Shape &tr) {
    tr.display(os);
    return os;
}
