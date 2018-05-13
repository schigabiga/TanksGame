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
	activ=true;
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


void PushButton::handle(event ev)
{
   if(activ==true){

    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
		{
            _lenyomott=true;
            _lenyomott_old=true;
		    _focused=true;

		}
	if (ev.type == ev_mouse &&  ev.button==-btn_left)
		{
		    action();

		    _focused=false;
		    _lenyomott=false;
		}
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

void PushButton::active(){
    activ=!activ;
}


