#include "TextBox.hpp"
#include "graphics.hpp"
using namespace genv;
#include <string>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

TextBox::TextBox(int x, int y, int sx, int sy): Widget(x,y,sx,sy)
{
    _tel="";
}
void TextBox::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
	gout<<color(255,255,255)<<move_to(_x+_size_x/2- (_tel.size()/2*8),_y+_size_y/2+5)<<text(_tel);


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

