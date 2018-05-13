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

    gout<<move_to(20,20)<<color(0,0,0)<<text("-> Az értékek beállítása után kattints a tankra a tûzeléshez!");
    gout<<move_to(50,470)<<color(0,0,0)<<text("Degree:");
    gout<<move_to(170,470)<<color(0,0,0)<<text("Power:");
    gout<<move_to(610,470)<<color(0,0,0)<<text("Degree:");
    gout<<move_to(750,470)<<color(0,0,0)<<text("Power:");
    gout<<move_to(400,485)<<color(0,0,0)<<text("Wind:");


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

