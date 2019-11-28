#include "../include/shape.hpp"
#include <cmath>
#include <assert.h> 

geometric_shape::shape::~shape()
{
   
}

geometric_shape::shape & geometric_shape::shape::operator=(const shape & tc)
{
    if (this == &tc)
        return *this;

    geometric_shape::shape copy(tc);
    std::swap(_size_cote, copy._size_cote);
    std::swap(_px, copy._px);
    std::swap(_py, copy._py);
    std::swap(center, copy.center);
    return *this;
}
bool geometric_shape::shape::operator== (const shape & s) const
{

    bool ret = false;
    /*
    if ((_px <= s._px) && (_py <= s._py) && (center <= s.center) && (_size_cote== s._size_cote))
    {
        // les valeurs sont exactements les mêmes
        return true;
    }*/
    int thresh = round(_size_cote*0.2);
    /*bool centequal = false;
    //operator== defined +/- threshold
    
    if ((center[0] <= s.center[0]+thresh) && (center[0] >= s.center[0]-thresh) 
        && (center[1] <= s.center[1]+thresh) && (center[1] >= s.center[1]-thresh) 
        ){
            centequal=true;
    }*/
    unsigned int nbequal =0;
    for (unsigned int i=0 ; i < _px.size();i++){
        for (unsigned int j =0 ; j < s._px.size();j++){
            if((_px[i] <= s._px[j]+thresh) && (_px[i] >= s._px[j]-thresh) 
                 && (_py[i] <= s._py[j]+thresh) && (_py[i] >= s._py[j]-thresh)) {
                    nbequal++;
                 }

        }
    }
    //std::cout << "nbequal: " << nbequal << std::endl;
    if( (nbequal == _px.size()) && (_size_cote== s._size_cote)){
        ret = true;
    }
    return ret;
};
/*
 (const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectshapes,
                          const std::allocator<std::shared_ptr<geometric_shape::shape> >  &,
                          const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectmodel,
                          const std::allocator<std::shared_ptr<geometric_shape::shape> >  &)*/
bool operator == (const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectshapes,const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectmodel){
    bool ret = false;
    if(vectshapes.size() == vectmodel.size()){
        auto model_it = vectmodel.begin();

        for (auto shap_it = vectshapes.begin() ; shap_it < vectshapes.end(); shap_it++){
                bool loc = (*shap_it==*model_it);
                ret=loc;
                if (ret == false){
                    return false;
                }
                model_it++;
            }
        }
    return ret;
}
bool geometric_shape::areEqual(const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectshapes,const std::vector<std::shared_ptr<geometric_shape::shape> >  &vectmodel)
{
    unsigned int count = 0;
    bool ret = false;
    if(vectshapes.size() == vectmodel.size()){
        //std::cout << "le test est la: " << **it << std::endl;
        for (auto shap_it : vectshapes){
            for (auto model_it : vectmodel){
                bool loc = (*shap_it==*model_it);
                ret=loc;
                //std::cout << *shap_it<< " "<<*model_it <<" " << ret << std::endl<< std::endl;
                if (loc == true){
                    count++;
                    std::cout << *shap_it<< " "<<*model_it <<" " << ret << std::endl<< std::endl;
                }
            }

        }
        if ( count == vectshapes.size()){
            ret = true;
        }
        else {
            ret =false;
        }
    }
    return ret; 
}
               




geometric_shape::shape::shape(const shape & tc):_size_cote(tc._size_cote),_px(tc._px),_py(tc._py),center(tc.center)
{
        //std::cout << "constructeur de copie" << std::endl;
}


geometric_shape::shape::shape(int size_cote,int height,int width):_size_cote(size_cote),_px(0),_py(0),center(0)
{

}
void geometric_shape::shape::set_shape(std::vector<double> &pxnew, std::vector<double> &pynew,std::vector<double> &cnew, int &scnew)
{
    _size_cote=scnew;
    _px=pxnew;
    _py=pynew;
    center=cnew;
}
int geometric_shape::shape::get_size_cote() const{return _size_cote;}
std::vector<double> geometric_shape::shape::get_px() const{return _px;}
std::vector<double> geometric_shape::shape::get_py() const{return _py;}
std::vector<double> geometric_shape::shape::get_center() const{return center;}



void geometric_shape::shape::draw(MLV_Color color_shape, MLV_Color color_border) const
{
    std::vector<int> px_draw;
    std::vector<int> py_draw;
    for(unsigned int i = 0; i<_px.size();i++)
    {
      px_draw.push_back(floor(_px[i]+0.5));
      py_draw.push_back(floor(_py[i]+0.5));
    }
    MLV_draw_filled_polygon(px_draw.data(), py_draw.data(),_px.size(),color_shape);
    MLV_draw_polygon(px_draw.data(), py_draw.data(),_px.size(), color_border);
};

//void geometric_shape::drawAllShapes(const std::vector<shape*> vectshapes,MLV_Color color_shape,  MLV_Color color_border) 
void geometric_shape::drawAllShapes(const std::vector<std::shared_ptr<geometric_shape::shape> > &vectshapes,MLV_Color color_shape,  MLV_Color color_border) 
{

    for(auto it : vectshapes){
        std::vector<int> px_draw;
        std::vector<int> py_draw;
        for(unsigned int i = 0; i<it->_px.size();i++)
        {
          px_draw.push_back(floor(it->_px[i]+0.5));
          py_draw.push_back(floor(it->_py[i]+0.5));
        }
        MLV_draw_filled_polygon(px_draw.data(), py_draw.data(),it->_px.size(),color_shape);
        MLV_draw_polygon(px_draw.data(), py_draw.data(),it->_px.size(), color_border);
    }
}




void geometric_shape::shape::rotate_hw(int angle,unsigned int n) 
{       
        assert(n<=_px.size() && n>=0);
        double pivo_x = _px[n];
        double pivo_y = _py[n];
        double angle_rad = (double)angle*3.141592653589793238462643383279 /180;

        for (unsigned int it = 0; it < _px.size() ; it++)
        {
            if (it!=n){
                double xM = _px[it] - pivo_x;
                double yM = _py[it] - pivo_y;
                _px[it]=xM*cos(angle_rad) + yM*sin(angle_rad) + pivo_x;   /* [cos(0) -sin(0); sin(0) cos(0)]*/
                _py[it]=-xM*sin(angle_rad) + yM*cos(angle_rad) + pivo_y;
            }
        }
        double xM = center[0] - pivo_x;
        double yM = center[1] - pivo_y;
        center[0]=xM*cos(angle_rad) + yM*sin(angle_rad) + pivo_x;
        center[1]=xM*sin(angle_rad) + yM*cos(angle_rad) + pivo_y;
} 

void geometric_shape::shape::rotate_center(int angle,int x,int y,int x0, int y0) 
{   
    double angle_rad;
    if ((x !=0) && (y!=0) && x!=x0 && y!=y0 )
    {
        double Ux = x-center[0];
        double Uy = y-center[1];
        double Vx = x0-center[0];
        double Vy = y0-center[1];
        double normU = sqrt(pow(Ux,2)+pow(Uy,2));
        double normV = sqrt(pow(Vx,2)+pow(Vy,2));
        double distUV = sqrt(pow(x-x0,2)+pow(y-y0,2));
        int det = Ux*Vy-Uy*Vx;
        angle_rad= 0.5 *(pow(normU,2)+pow(normV,2)-pow(distUV,2));
        angle_rad = acos(angle_rad / ( normU*normV ));
        angle_rad = copysign(angle_rad,det);
    }
    else
    {
        angle_rad = (double)angle*3.141592653589793238462643383279 /180;
    }

    for (unsigned int it = 0; it < _px.size() ; it++)
    {
        double xM = _px[it] - center[0];
        double yM = _py[it] - center[1];
        _px[it]= xM*cos(angle_rad) + yM*sin(angle_rad) + center[0] ;   /* [cos(0) -sin(0); sin(0) cos(0)]*/
        _py[it]=-xM*sin(angle_rad) + yM*cos(angle_rad) + center[1] ;
    }


} 

void geometric_shape::shape::translate(int x,int y) 
{

        for (unsigned int it = 0; it < _px.size() ; it++)
        {
            _px[it]+=x;   /* [cos(0) -sin(0); sin(0) cos(0)]*/
            _py[it]+=y;

        }
        center[0]+=x;
        center[1]+=y;
}
void geometric_shape::shape::reverse() 
    {
        rotate_center(180);
    }

bool geometric_shape::shape::isInside(const int &x,const int &y) const
{
for(unsigned int i=0;i<_px.size();i++)
  {
     int Ax=_px[i];
     int Ay=_py[i];
     int Bx,By;
     if (i==_px.size()-1)  // if i== last point of vector px then B == first point
         {
         Bx = _px[0];
         By = _py[0];
         }
     else           // else B take the point at i+1
         {
            Bx = _px[i+1];
            By = _py[i+1];
         }
     double Dx,Dy,Tx,Ty;
     Dx = Bx - Ax;
     Dy = By - Ay;
     Tx = x - Ax;
     Ty = y - Ay;
     double d = Dx*Ty - Dy*Tx;
     if (d<0)
        return false;  // Point (x,y) is not inside.
  }
  return true;
}

//void geometric_shape::shape::move_shape(int &x_inside,int &y_inside,std::vector<geometric_shape::shape*> fig )

void geometric_shape::shape::move_shape(int &x_inside,int &y_inside,std::vector<std::shared_ptr<geometric_shape::shape> > &fig )
{
    if(isInside(x_inside,y_inside) == 1)
    { 
       // std::cout << "move normal ";
        bool done = false;
        while(done!=true)   
        {
            int xend;
            int yend;
            int x_rot0;
            int y_rot0;
            MLV_get_mouse_position( &x_rot0, &y_rot0 );

            MLV_wait_milliseconds( 0.01 );
            if(MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED)
            {
                while(MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED)
                {
                    int x2;
                    int y2;
                    MLV_get_mouse_position( &x2, &y2 );
                    draw(MLV_COLOR_BLACK);
                    translate(x2-x_inside,y2-y_inside);
                    MLV_wait_milliseconds( 0.01 );
                    
                    if(MLV_get_mouse_button_state(MLV_BUTTON_RIGHT) == MLV_PRESSED)
                    {
                        rotate_center(1);
                        MLV_wait_milliseconds( 80 );
                        
                    }
                    if(MLV_get_mouse_button_state(MLV_BUTTON_MIDDLE) == MLV_PRESSED)
                    {
                        reverse();
                    }
                    drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
                    //draw(MLV_COLOR_WHITE,MLV_COLOR_RED);
                    MLV_actualise_window();
                    x_inside = x2; 
                    y_inside = y2;

                }
            }
            while(MLV_get_mouse_button_state(MLV_BUTTON_RIGHT) == MLV_PRESSED)
                {
                    draw(MLV_COLOR_BLACK);
                    int x_rot;
                    int y_rot;
                    MLV_wait_milliseconds( 10 );
                    MLV_get_mouse_position( &x_rot, &y_rot );
                    if ((x_rot != x_rot0 ) && (y_rot!=y_rot0))
                    {
                        rotate_center(1,x_rot,y_rot,x_rot0,y_rot0);
                        drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
                        //draw(MLV_COLOR_WHITE,MLV_COLOR_RED);
                        MLV_actualise_window();
                        MLV_wait_milliseconds( 10 );
                        x_rot0 = x_rot;
                        y_rot0 = y_rot;
                    }
                }
            if(MLV_get_mouse_button_state(MLV_BUTTON_MIDDLE) == MLV_PRESSED)
            {
                draw(MLV_COLOR_BLACK);
                MLV_wait_milliseconds( 1 );
                reverse();
                drawAllShapes(fig,MLV_COLOR_WHITE,MLV_COLOR_RED);
                //draw(MLV_COLOR_WHITE,MLV_COLOR_RED);
                MLV_actualise_window();
            }
            MLV_wait_milliseconds( 1 );

            MLV_get_mouse_position(&xend, &yend);
            if ( MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED && (isInside(xend,yend) == 0))
            {
                done =true;
            }
        }
    }
}


void geometric_shape::shape::display ( std::ostream & os) const
{
  os << " shape with coordinate : ";
  for (unsigned int i=0;i<_px.size();i++)
  {
    os << "[" << _px[i] << "; " << _py[i] << "] ";
  }
  os << std::endl;
}

std::ostream &operator<<(std::ostream &os, const geometric_shape::shape &_tr)
{
    _tr.display(os);
    return os ;
}
