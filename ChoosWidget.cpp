#include "ChoosWidget.hpp"
#include "graphics.hpp"
using namespace genv;

ChoosWidget::ChoosWidget(int x, int y, int sx, int sy,vector<string> vektor): Widget(x,y,sx,sy)
{
    _checked=false;
    _focus=false;
    _mezok=vektor;
    _gor=false;
    _szel=_size_x-(_size_x/2/2);
    _magas=vektor.size()*20+10;

    _db2=(600-(y+sy))/20;

    if(_db2>_mezok.size()){
        _db=_mezok.size();
    }
    else
        _db=_db2-1;

    for(unsigned int i=0;i<_db;i++){
        _jel.push_back(_mezok[i]);
    }



    _mennyi=0;

    _wx=x;
    _adott=_mezok[0];

    _hany=0;

    active=true;
}

void ChoosWidget::draw()
{

    if(!_focus){
        //gout<<move_to(_x-70,_y+_size_y/2+5)<<color(255,255,255)<<text("colors:");

        gout<<move_to(_x,_y)<<color(102, 102, 102)<<box(_size_x,_size_y); //nagyobb

        gout<<move_to(_x+2,_y+2)<<color(255,255,255)<<box(_size_x-4,_size_y-4); //kisebb

        gout<<move_to(_x+5,_y+_size_y/2+5)<<color(0,0,0)<<text(_adott);

        gout<<move_to(_x+_size_x/2+_size_x/2/2,_y+2)<<color(166, 166, 166)<<box(_size_x-(_size_x/2+_size_x/2/2)-2,_size_y-4);

        gout<<move_to(_x+_size_x/2+_size_x/2/2+_size_x/2/2/2/2,_y+_size_y/2-_size_y/2/2)<<color(0,0,0)<<line_to(_x+_size_x/2+_size_x/2/2+_size_x/2/2/2,_y+_size_y/2+_size_y/2/2)<<line_to(_x+_size_x/2+_size_x/2/2+_size_x/2/2/2/2+_size_x/2/2/2,_y+_size_y/2-_size_y/2/2);

    }
    else{
       // gout<<move_to(_x-70,_y+_size_y/2+5)<<color(255,255,255)<<text("colors:");

        gout<<move_to(_x,_y)<<color(175, 175, 131)<<box(_size_x,_size_y); //nagyobb

        gout<<move_to(_x+2,_y+2)<<color(255,255,255)<<box(_size_x-4,_size_y-4); //kisebb

        gout<<move_to(_x+5,_y+_size_y/2+5)<<color(0,0,0)<<text(_adott);

        gout<<move_to(_x+_size_x/2+_size_x/2/2,_y+2)<<color(166, 166, 166)<<box(_size_x-(_size_x/2+_size_x/2/2)-2,_size_y-4);

        gout<<move_to(_x+_size_x/2+_size_x/2/2+_size_x/2/2/2/2,_y+_size_y/2-_size_y/2/2)<<color(0,0,0)<<line_to(_x+_size_x/2+_size_x/2/2+_size_x/2/2/2,_y+_size_y/2+_size_y/2/2)<<line_to(_x+_size_x/2+_size_x/2/2+_size_x/2/2/2/2+_size_x/2/2/2,_y+_size_y/2-_size_y/2/2);
    }

    if(_gor==true && _focus){
        gout<<move_to(_x,_y+_size_y-2)<<color(175, 175, 131)<<box(_szel,_jel.size()*20+10);

        gout<<move_to(_x+2,_y+_size_y+2)<<color(255,255,255)<<box(_szel-4,_jel.size()*20+10-8);

        int kx=_x+2;
        int ky=_y+2;
        int ksx=_size_x-4;
        int ksy=_size_y-4;

        int m=gout.cascent()+gout.cdescent();

        int f=m+3;
        for(unsigned int i=0;i<_jel.size();i++){

            gout<<move_to(_x+5,_y+_size_y+f)<<color(0,0,0)<<text(_jel[i]);
            f+=(m+3);

        }

        double h=_magas/_jel.size();
        int ff=m+3;
        for(unsigned int i=0;i<_jel.size();i++){
            if(_bool[i]==true){
                gout<<move_to(kx,ky+_size_y+20*i)<<color(102, 102, 255)<<box(_szel-4,23)<<move_to(_x+5,_y+_size_y+ff)<<color(255,255,255)<<text(_jel[i]);
            }
            ff+=(m+3);
        }

    }
    else{
        gout<<move_to(_x,_y+_size_y)<<color(153, 51, 0)<<box(_szel,_jel.size()*20+8);
        _mennyi=0;
        for(unsigned int i=0;i<_jel.size();i++){
            _jel[i]=_mezok[i];
        }
    }




}

void ChoosWidget::handle(event ev)
{
   if(active==true){


    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }

    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked=!_checked;
    }

    if (ev.type == ev_mouse && chos(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _gor=true;
    }

    if(ev.type == ev_mouse && _gor==true){
        _bool=on(ev.pos_x, ev.pos_y,_mezok);
    }

    if(ev.type == ev_mouse && _gor==true && ev.button==btn_left){
        for(unsigned int i=0;i<_jel.size();i++){
            if(_bool[i]==true){
                _adott=_jel[i];
                _hany=i+_mennyi;
            }
        }
    }

    //gorgés
    if(ev.type == ev_mouse && _gor==true && ev.button==btn_wheeldown){
        if(_mennyi<_mezok.size()-_db){
            for(unsigned int i=0;i<_jel.size();i++){
                    _mennyi++;
                    _jel[i]=_mezok[_mennyi];
            }
            _mennyi-=_db-1;
        }
    }
    if(ev.type == ev_mouse && _gor==true && ev.button==btn_wheelup){
         if(_mennyi>=0){
            for(unsigned int i=0;i<_jel.size();i++){
                _jel[i]=_mezok[_mennyi];
                _mennyi++;
            }
            _mennyi-=(_db+1);
            if(_mennyi==-1){
                _mennyi=0;
            }
        }
    }
    //gorgésvége

    if (ev.type == ev_mouse && ev.button==btn_left) {
     if ( is_selected(ev.pos_x, ev.pos_y) ) {
       _checked = !_checked;
       _focus=true;
     } else {
        if(_gor==true){
            _focus=true;
        }
        else{
            _focus=false;
        }
        _gor=false;
     }
    }
   }
}
void ChoosWidget::activ(){
    active=!active;
}

string ChoosWidget::adottback(){
    return _adott;
}

bool ChoosWidget::chos(int mouse_x, int mouse_y)
{
    return mouse_x>_x+_size_x/2+_size_x/2/2 && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

vector<bool> ChoosWidget::on(int mouse_x, int mouse_y,vector<string> v)
{
    double h=_magas/v.size();
    vector<bool> eredmenyek;
    for(unsigned int i=0;i<v.size();i++){

        eredmenyek.push_back( mouse_x>_x && mouse_x<_x+_szel && mouse_y>_y+_size_y+i*h && mouse_y<_y+_size_y+(i+1)*h);

    }
    return eredmenyek;

}

int ChoosWidget::valueback(){
    return _wx;
}

void ChoosWidget::add(string h){
    _mezok.push_back(h);
    _jel.clear();
    for(unsigned int i=0;i<_db;i++){
        _jel.push_back(_mezok[i]);
    }
}

int ChoosWidget::hanyback(){
    return _hany;
}
