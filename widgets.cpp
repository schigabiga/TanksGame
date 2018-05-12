#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>

Widget::Widget(int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy)
{

}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

string Widget::getextrainfo(){
    vector<int> szov={_x,_y,_size_x,_size_y};
    vector<string> sz;
    for(int i=0;i<4;i++){
        string szove;
        stringstream ss;
        ss<<szov[i];
        ss>>szove;
        sz.push_back(szove);
    }
    return "A widget \n\t pozicioja: \n\t\t x: "+sz[0]+" \n\t\t y: "+sz[1]+"\n\t meretei: \n\t\t szelesseg: "+sz[2]+" \n\t\t magassag:  "+sz[3];
}








