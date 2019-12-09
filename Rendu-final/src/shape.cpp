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
    int thresh = round(sizeCote * 0.2);
    unsigned int nbequal = 0;
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

// bool operator==(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel) {
//     bool ret = false;
//     if (vectShapes.size() == vectModel.size()) {
//         auto model_it = vectModel.begin();
//         for (auto shap_it = vectShapes.begin(); shap_it < vectShapes.end(); shap_it++) {
//                 bool loc = (*shap_it == *model_it);
//                 ret = loc;
//                 if (ret == false) {
//                     return false;
//                 }
//                 model_it++;
//             }
//         }
//     return ret;
// }

bool operator==(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel){
    return areEqual(vectShapes, vectModel); 
}

bool geometricShape::areEqual(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, const std::vector<std::shared_ptr<geometricShape::Shape>> &vectModel){
    unsigned int count = 0;
    bool ret = false;
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
            ret =false;
        }
    }
    return ret; 
}
                
geometricShape::Shape::Shape(const Shape & tc) : sizeCote(tc.sizeCote), px(tc.px), py(tc.py), center(tc.center) {}

geometricShape::Shape::Shape(int sizeCote, int width, int height) : sizeCote(sizeCote), px(0), py(0), center(0) {}

void geometricShape::Shape::setShape(std::vector<double> &pXnew, std::vector<double> &pYnew, std::vector<double> &cnew, int &scnew) {
    sizeCote = scnew;
    px = pXnew;
    py = pYnew;
    center = cnew;
}

int geometricShape::Shape::getSizeCote() const {
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
    MLV_draw_filled_polygon(pxDraw.data(), pyDraw.data(),px.size(), colorShape);
    MLV_draw_polygon(pxDraw.data(), pyDraw.data(), px.size(), colorBorder);
}

// void geometricShape::drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, MLV_Color colorShape, MLV_Color colorBorder) {
//     for (auto it : vectShapes) {
//         std::vector<int> pxDraw;
//         std::vector<int> pyDraw;
//         for (unsigned int i = 0; i < it->_px.size(); i++) {
//           pxDraw.push_back(floor(it->px[i] + 0.5));
//           pyDraw.push_back(floor(it->py[i] + 0.5));
//         }
//         MLV_draw_filled_polygon(pxDraw.data(), pyDraw.data(), it->px.size(), colorShape);
//         MLV_draw_polygon(pxDraw.data(), pyDraw.data(), it->px.size(), colorBorder);
//     }
// }

void geometricShape::drawAllShapes(const std::vector<std::shared_ptr<geometricShape::Shape>> &vectShapes, MLV_Color colorShape, MLV_Color colorBorder) {
    for(auto it : vectShapes){
        it->draw(colorShape, colorBorder);
    }
}

void geometricShape::Shape::rotateHW(int angle, unsigned int n) {       
        assert(n <= px.size() && n >= 0);
        double pivoX = px[n];
        double pivoY = py[n];
        double angleRad = (double) angle * 3.141592653589793238462643383279 / 180;
        for (unsigned int it = 0; it < px.size(); it++){
            if (it != n) {
                double xM = px[it] - pivoX;
                double yM = py[it] - pivoY;
                px[it] = xM * cos(angleRad) + yM * sin(angleRad) + pivoX;   /* [cos(0) -sin(0); sin(0) cos(0)]*/
                py[it] = -xM * sin(angleRad) + yM * cos(angleRad) + pivoY;
            }
        }
        double xM = center[0] - pivoX;
        double yM = center[1] - pivoY;
        center[0] = xM * cos(angleRad) + yM * sin(angleRad) + pivoX;
        center[1] = xM * sin(angleRad) + yM * cos(angleRad) + pivoY;
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
        pyloc[it]= -xM * sin(angleRad) + yM * cos(angleRad) + center[1];
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

void geometricShape::Shape::reverse() {
    rotateCenter(180);
}

bool geometricShape::Shape::isInside(const int &x, const int &y) const {
    for (unsigned int i = 0; i < px.size(); i++) {
        int Ax = px[i];
        int Ay = py[i];
        int Bx, By;
        if (i == px.size() - 1) {  // if i== last point of vector px then B == first point
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

bool geometricShape::isInsideBoard(const int &x, const int &y, const int &with, const int &heigth, const int &sizeW, const int &sizeH) {
    std::vector<double> Boardx; // 40, 30, sizex 1150, sizey 950
    std::vector<double> Boardy;
    Boardx.push_back(45);
    Boardy.push_back(35);
    Boardx.push_back(45 + 1140);
    Boardy.push_back(35);
    Boardx.push_back(45 + 1140);
    Boardy.push_back(35 + 940);
    Boardx.push_back(45);
    Boardy.push_back(35 + 940);

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

void geometricShape::Shape::moveShape(int &xInside, int &yInside, std::vector<std::shared_ptr<geometricShape::Shape>> &fig, std::vector<std::shared_ptr<geometricShape::Shape>> &motif, MLV_Color motifShape, MLV_Color motifBorder) {
    if (isInside(xInside, yInside) == 1) { 
        bool done = false;
        while (done != true) {
            int xEnd, yEnd, xRot0, yRot0;
            MLV_get_mouse_position(&xRot0, &yRot0);
            MLV_wait_milliseconds(0.01);
            if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
                while (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
                    int x2, y2;
                    MLV_get_mouse_position(&x2, &y2);
                    draw(MLV_COLOR_GRAY, MLV_COLOR_GRAY);
                    drawAllShapes(motif, motifShape, motifBorder);
                    translate(x2 - xInside, y2 - yInside);
                    MLV_wait_milliseconds(0.01);
                    if (MLV_get_mouse_button_state(MLV_BUTTON_RIGHT) == MLV_PRESSED) {
                        rotateCenter(1);
                        MLV_wait_milliseconds(80); 
                    }
                    if (MLV_get_mouse_button_state(MLV_BUTTON_MIDDLE) == MLV_PRESSED) {
                        reverse();
                    }
                    drawAllShapes(motif, motifShape, motifBorder);
                    drawAllShapes(fig, MLV_COLOR_WHITE, MLV_COLOR_RED);
                    MLV_actualise_window();
                    xInside = x2; 
                    yInside = y2;
                }
            }
            while (MLV_get_mouse_button_state(MLV_BUTTON_RIGHT) == MLV_PRESSED) {
                    draw(MLV_COLOR_GRAY, MLV_COLOR_GRAY);
                    int xRot, yRot;
                    MLV_wait_milliseconds(10);
                    MLV_get_mouse_position(&xRot, &yRot);
                    if ((xRot != xRot0) && (yRot != yRot0)) {
                        rotateCenter(1, xRot, yRot, xRot0, yRot0);
                        drawAllShapes(motif, motifShape, motifBorder);
                        drawAllShapes(fig, MLV_COLOR_WHITE, MLV_COLOR_RED);
                        MLV_actualise_window();
                        MLV_wait_milliseconds(10);
                        xRot0 = xRot;
                        yRot0 = yRot;
                    }
                }
            if (MLV_get_mouse_button_state(MLV_BUTTON_MIDDLE) == MLV_PRESSED) {
                draw(MLV_COLOR_GRAY, MLV_COLOR_GRAY);
                MLV_wait_milliseconds(1);
                reverse();
                drawAllShapes(motif, motifShape, motifBorder);
                drawAllShapes(fig, MLV_COLOR_WHITE, MLV_COLOR_RED);
                MLV_actualise_window();
            }
            MLV_wait_milliseconds(1);
            MLV_get_mouse_position(&xEnd, &yEnd);
            if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED && (isInside(xEnd, yEnd) == 0)) {
                done = true;
            }
        }
    }
}

void geometricShape::Shape::display(std::ostream & os) const {
    os << " Shape with coordinate : ";
    for (unsigned int i = 0; i < px.size(); i++) {
        os << "[" << px[i] << "; " << py[i] << "] ";
    }
    os << std::endl;
}

void geometricShape::saveDraw (const std::vector<std::shared_ptr<geometricShape::Shape>> &fig) {
    std::ofstream saveFig("savefig.txt",std::ios::app);
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
