#include "numberchanger.hpp"
#include "graphics.hpp"
using namespace genv;
#include <string>
#include <sstream>

numberchanger::numberchanger(int x, int y, int sx, int sy,int mi,int ma,int k): Widget(x,y,sx,sy)
{
    _checked=false;
    _focus=false;
    _number=k;
    _tolas=0;
    _inc=false;
    _dec=false;
    _max=ma;
    _min=mi;

}

void numberchanger::draw()
{

    if(_focus){
        gout<<move_to(_x-2,_y-2)<<color(102,0,102)<<box(_size_x+4,_size_y+4);
        gout<<move_to(_x,_y)<<color(102,0,102)<<box(_size_x,_size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

        gout<<color(153,0,153)<< move_to(_x+_size_x/2+_size_x/2/2,_y)<<line_to(_x+_size_x/2+_size_x/2/2,(_y+_size_y)-2)<<move_to(_x+_size_x/2+_size_x/2/2,_y+_size_y/2)<<line_to(_x+_size_x-2,_y+_size_y/2);

        if(_inc==true){
            int ix=_x+_size_x/2+_size_x/2/2;
            int sx=_size_x-(_size_x/2+_size_x/2/2);
            int iy=_y;
            int sy=_size_y/2;

            gout<<color(96, 31, 96)<<move_to(ix+sx/2-sx/2/2,iy+sy/2+sy/2/2)<<line_to(ix+sx/2,iy+sy/2-sy/2/2)<<line_to(ix+sx/2+sx/2/2,iy+sy/2+sy/2/2);
            _inc=false;
        }
        else{
            int ix=_x+_size_x/2+_size_x/2/2;
            int sx=_size_x-(_size_x/2+_size_x/2/2);
            int iy=_y;
            int sy=_size_y/2;
            gout<<color(153,0,153)<<move_to(ix+sx/2-sx/2/2,iy+sy/2+sy/2/2)<<line_to(ix+sx/2,iy+sy/2-sy/2/2)<<line_to(ix+sx/2+sx/2/2,iy+sy/2+sy/2/2);
        }

        if(_dec==true){
            int ix=_x+_size_x/2+_size_x/2/2;
            int sx=_size_x-(_size_x/2+_size_x/2/2);
            int iy=_y+_size_y/2;
            int sy=_size_y/2;
            gout<<color(96, 31, 96)<<move_to(ix+sx/2-sx/2/2,iy+sy/2-sy/2/2)<<line_to(ix+sx/2,iy+sy/2+sy/2/2)<<line_to(ix+sx/2+sx/2/2,iy+sy/2-sy/2/2);
            _dec=false;
        }
        else{
            int ix=_x+_size_x/2+_size_x/2/2;
            int sx=_size_x-(_size_x/2+_size_x/2/2);
            int iy=_y+_size_y/2;
            int sy=_size_y/2;
            gout<<color(153,0,153)<<move_to(ix+sx/2-sx/2/2,iy+sy/2-sy/2/2)<<line_to(ix+sx/2,iy+sy/2+sy/2/2)<<line_to(ix+sx/2+sx/2/2,iy+sy/2-sy/2/2);

        }

    }
    else{
        gout<<move_to(_x-2,_y-2)<<color(0,0,0)<<box(_size_x+4,_size_y+4);

        gout<<move_to(_x,_y)<<color(153,0,153)<<box(_size_x,_size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
        gout<<color(153,0,153)<< move_to(_x+_size_x/2+_size_x/2/2,_y)<<line_to(_x+_size_x/2+_size_x/2/2,(_y+_size_y)-2)<<move_to(_x+_size_x/2+_size_x/2/2,_y+_size_y/2)<<line_to(_x+_size_x-2,_y+_size_y/2);

        int ix=_x+_size_x/2+_size_x/2/2;
        int sx=_size_x-(_size_x/2+_size_x/2/2);
        int iy=_y;
        int sy=_size_y/2;

        gout<<color(153,0,153)<<move_to(ix+sx/2-sx/2/2,iy+sy/2+sy/2/2)<<line_to(ix+sx/2,iy+sy/2-sy/2/2)<<line_to(ix+sx/2+sx/2/2,iy+sy/2+sy/2/2);

        ix=_x+_size_x/2+_size_x/2/2;
        sx=_size_x-(_size_x/2+_size_x/2/2);
        iy=_y+_size_y/2;
        sy=_size_y/2;

        gout<<color(153,0,153)<<move_to(ix+sx/2-sx/2/2,iy+sy/2-sy/2/2)<<line_to(ix+sx/2,iy+sy/2+sy/2/2)<<line_to(ix+sx/2+sx/2/2,iy+sy/2-sy/2/2);

    }

    stringstream ss;
    string number;
    ss<<_number;
    ss>>number;
    if(_number<0){
        _tolas=-8;
    }
    else if(_number<-10){
        _tolas=16;
    }
    else if(_number>9){
        _tolas=-8;
    }
    int nx= _size_x-_size_x/2/2;
    gout<<move_to((_x+(nx/2)-(gout.twidth(number)/2)),(_y+(_size_y/2)+gout.cascent()/2))<<color(204, 51, 153)<<text(number);


}

void numberchanger::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }
    //növekedes
    if (ev.type == ev_mouse && is_inc(ev.pos_x, ev.pos_y) && ev.button== -btn_left){
        if(_number<_max){
            _number++;
        }
        _inc=true;
    }
    if(ev.keycode==key_up && _focus){
        if(_number<_max){
            _number++;
        }
        _inc=true;
    }
    if(ev.keycode==key_pgup && _focus){
        if(_number+10<=_max){
            _number+=10;
        }
        _inc=true;
    }

    //csokkenes
    if (ev.type == ev_mouse && is_dec(ev.pos_x, ev.pos_y) && ev.button==-btn_left) {
        if(_number>_min){
            _number--;
        }
        _dec=true;
    }
    if(ev.keycode==key_down && _focus){
        if(_number>_min){
            _number--;
        }
        _dec=true;
    }
    if(ev.keycode==key_pgdn && _focus){
        if(_number-10>=_min){
            _number-=10;
        }
        _dec=true;
    }
   //

    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked=!_checked;
    }
    if (ev.type == ev_mouse && ev.button==btn_left) {
     if ( is_selected(ev.pos_x, ev.pos_y) ) {
       _checked = !_checked;
       _focus=true;
     } else {
     	_focus=false;
     }
    }

}

bool numberchanger::is_inc(int mouse_x, int mouse_y)
{
    return mouse_x>_x+_size_x/2+_size_x/2/2 && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y/2;
}

bool numberchanger::is_dec(int mouse_x, int mouse_y)
{
    return mouse_x>_x+_size_x/2+_size_x/2/2 && mouse_x<_x+_size_x && mouse_y>_y+_size_y/2 && mouse_y<_y+_size_y;
}

double numberchanger::GetNumber(){
    return _number;
}

