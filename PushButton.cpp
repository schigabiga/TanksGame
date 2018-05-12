#include "PushButton.hpp"
#include "graphics.hpp"
#include <iostream>
#include <time.h>
#include <math.h>
using namespace genv;
using namespace std;


PushButton::PushButton(int x, int y, int sx, int sy, string szoveg): Widget(x,y,sx,sy)
{
	_focused=false;
	_lenyomott=false;
	_lenyomott_old=false;
	_szoveg=szoveg;
}
void PushButton::draw()
{
    if(!_lenyomott)
   {
        gout<<move_to(_x+2,_y+2)<<color(112,124,22)<<box(_size_x,_size_y);
        gout<<move_to(_x,_y)<<color(22,22,22)<<box(_size_x,_size_y);
        gout<<move_to(_x+_size_x/2-gout.twidth(_szoveg)/2,_y+_size_y/2+(gout.cascent()+gout.cdescent())/2)<<color(21,243,255)<<text(_szoveg);



   }
   else
   {

        gout<<move_to(_x+2,_y+2)<<color(0,0,0)<<box(_size_x,_size_y);
        gout<<move_to(_x,_y)<<color(22,22,22)<<box(_size_x,_size_y);
        gout<<move_to(_x+_size_x/2-gout.twidth(_szoveg)/2,_y+_size_y/2+(gout.cascent()+gout.cdescent())/2)<<color(21,243,255)<<text(_szoveg);

   }
}
/*void PushButton::csdraw(double xi,double yi, double sz, double ks, event ev){



        srand(time(0));

        const double rad= 180/3.141592654;
        const double grav=9.81;

        double kseb=ks;

        int ax=xi;
        int ay=yi;


        double timerr=0;

        double c=0.45;

        double xx=ax;
        double yy=ay;

        double v_l=-10;


        double w=kseb*sin(sz);
        double u=kseb*cos(sz);

        double px=0;
        double py=0;

        bool t=false;

        gin.timer(1);

        while(gin>>ev && t==false){

        if (v_l<0)
        {
            u-=v_l*cos(sz)/1000;
            w-=v_l*sin(sz)/1000;
        }
            px=xx;
            py=yy;

            double r=sqrt(u*u+w*w);

            double f_x=1.073*0.0011157*c*pow(u/10+v_l*cos(sz),2);
            double f_y=1.073*0.0011157*c*pow(w/10+v_l*sin(sz),2);

            timerr+=0.02;

            xx=ax+u*timerr-f_x*timerr*timerr;
            yy=ay-w*timerr+(grav/2)*timerr*timerr+f_y*timerr*timerr;

            if(yy<_y+20){
                gout<<move_to(px,py)<<color(153, 204, 255)<<box(10,10);

                gout<<move_to(xx,yy)<<color(77, 77, 51)<<box(10,10);

                gout<<refresh;

            }
            else
            {
                t=true;
                //wind=rand()%40+30;
                gin.timer(0);
            }
        }
}*/

void PushButton::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
		{
            _lenyomott=true;
            _lenyomott_old=true;
		    _focused=true;

		}
	if (ev.type == ev_mouse &&  ev.button==-btn_left)
		{
		    action();

            //csdraw(ix,iy,f,ks,ev);

		    _focused=false;
		    _lenyomott=false;
		}


}
void PushButton::setfocused()
{
	_focused=!_focused;
}
bool PushButton::kijelolt()
{
    return _lenyomott_old;
}
bool PushButton::_focusable()
{
    return true;
}
void PushButton::katt()
{
    _lenyomott_old=false;
}


void PushButton::fok(double fo){
    f=fo;
}
void PushButton::seb(double se){
    ks=se;
}

void PushButton::ex(double x){
    ix=x;
}
void PushButton::ey(double y){
    iy=y;
}


