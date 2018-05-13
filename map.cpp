#include "map.hpp"
#include "graphics.hpp"
#include <ctime>
using namespace genv;
using namespace std;

Map::Map(int x, int y, int sx, int sy): Widget(x,y,sx,sy)
{
    _checked=false;
}

void Map::draw()
{
    gout<<move_to(0,0)<<color(153, 204, 255)<<box(_size_x,500);

    gout << move_to(_x, _y) << color(102, 255, 102) << box(_size_x, _size_y-100);
    gout << move_to(_x, _y+20) << color(153, 51, 0) << box(_size_x, _size_y-20);

    gout<<move_to(0,90)<<color(255,255,255)<<box(_size_x,5);

}

void Map::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;
    }
}
bool Map::is_checked()
{
    return _checked;
}

double Map::szelgeneral(){
    srand(time(0));
    double wind=rand()%40+20;
    return wind;
}

double Map::szelirany(){
    srand(time(0));
    double ir=rand()%2+1;
    return ir;
}

