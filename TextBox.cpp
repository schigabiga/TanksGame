#include "TextBox.hpp"
#include "graphics.hpp"
using namespace genv;
#include <string>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

TextBox::TextBox(int x, int y, int sx, int sy,string szov): Widget(x,y,sx,sy)
{
    _tel=szov;
}
void TextBox::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

    gout<<move_to(_x+_size_x/2-gout.twidth(_tel)/2,_y+_size_y/2+(gout.cascent()+gout.cdescent())/2)<<color(255, 51, 51)<<text(_tel);

}

void TextBox::handle(event ev)
{
}

void TextBox::texting(double k){
    string w;
    stringstream ss;
    ss<<k;
    ss>>w;
    _tel=w;
}

void TextBox::settext(string t)
{
    _tel=t;
}
string TextBox::gettext()
{
    return _tel;
}

