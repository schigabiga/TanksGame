#include "vButton.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;


vButton::vButton(int x, int y, int sx, int sy, string szoveg,Window* parent): PushButton(x,y,sx,sy,szoveg)
	{
        _parent=parent;
	}
void vButton::action()
{
    _parent->event(_szoveg);
}

