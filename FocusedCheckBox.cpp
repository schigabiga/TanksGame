#include "FocusedCheckBox.hpp"
#include "graphics.hpp"
using namespace genv;
#include <string>
#include <string.h>
#include <iostream>
#include <cstdlib>
using namespace std;

FocusedCheckBox::FocusedCheckBox(int x, int y, int sx, int sy): ExampleCheckBox(x,y,sx,sy)
{
    _focused=false;
    _texter="";
    _tel="";
    _hossz=0;
    _tolodas=0;
    _vege=false;

    _kurzor=0;
    _merre=0;


}
void FocusedCheckBox::draw()
{
	if (_focused){
        gout << move_to(_x, _y) << color(255,0,0) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);



        if(_hossz<_size_x){
            gout<<color(44,145,255)<<move_to(_x+_size_x/2-_tolodas,_y+_size_y/2+5)<<text(_texter);
        }
        else{
            gout<<color(44,145,255)<<move_to(_x+_size_x/2-_tolodas,_y+_size_y/2+5)<<text(_texter);
        }
        gout<<color(255,255,255)<<move_to(_x+_size_x/2-_tolodas+_kurzor,_y+_size_y/2+5)<<line_to(_x+_size_x/2-_tolodas+_kurzor,_y+_size_y/2+5-9);


	}
	else {
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
        gout<<color(44,145,255)<<move_to(_x+_size_x/2-_tolodas,_y+_size_y/2+5)<<text(_texter);

	}
}

void FocusedCheckBox::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }
    if (ev.type == ev_mouse && ev.button==btn_left) {
     if ( is_selected(ev.pos_x, ev.pos_y) ) {
       _checked = !_checked;
       _focused=true;
     } else {
     	_focused=false;
     }
    }

    if(_focused==true){
        if(ev.keycode==key_left && ev.keycode>0){
            _merre=1;
        }
        else if(ev.keycode==key_right && ev.keycode>0){
            _merre=2;
        }
        else if(ev.keycode>0 && ev.keycode!=key_f1){
            _merre=0;
            if(ev.keycode==key_backspace && ev.keycode>0)
                _kar=toupper(_kar);
            else
                _kar=ev.keycode;
        }

        if(ev.keycode>0 && ev.keycode!=key_enter){
            if(_vege==false){
                if(_hossz>_size_x){
                    if(_merre==1){
                        _bet--;
                    }
                    else if(_merre==2){
                        _bet++;
                    }
                    else{
                        if(ev.keycode!=key_backspace){
                            _tel+=_kar;
                            _hossz+=gout.cascent();
                        }

                        if(ev.keycode==key_backspace){
                            string p;
                            _sz--;
                            for(int i=_sz;i<_tel.size()-1;i++){
                                p+=_tel[i];
                            }
                            _texter=p;
                            _tel.pop_back();
                        }
                        else{
                            string p;
                            _sz++;
                            for(int i=_sz;i<_tel.size();i++){
                                p+=_tel[i];
                            }
                            _texter=p;
                        }
                    }
                    _kurzor=_bet*8;
                }

                else{

                    if(_merre==1){
                        _bet--;
                    }
                    else if(_merre==2){
                        _bet++;
                    }
                    else{
                        if(ev.keycode!=key_backspace){
                            _tel+=_kar;
                            _hossz+=gout.cascent();
                        }
                        _bet++;

                        _texter=_tel;
                        _tolodas+=gout.cascent()-9;

                    }

                    if(ev.keycode==key_backspace){
                        _bet--;
                        string av="";
                        for(unsigned i=0;i<_texter.length();i++){
                            if(i!=(_bet-1)){
                                av+=_texter[i];
                            }
                        }
                        cout<<_tel<<endl;
                        _texter=av;
                        _tel=_texter;
                        _hossz-=gout.cascent();
                        string m="";
                        m+=ev.keycode;
                        _tolodas-=gout.twidth(m);
                        _bet--;

                    }
                    _kurzor=_bet*8;
                }
            }
        }
    }
}
bool FocusedCheckBox::is_focused()
{
    return _focused;
}

string FocusedCheckBox::_text(){
    return _tel;
}

void FocusedCheckBox::texting(string t){
    _tel=t;
    _texter=t;
}
