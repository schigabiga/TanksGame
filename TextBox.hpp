#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "examplecheckbox.hpp"
#include "widgets.hpp"
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class TextBox : public Widget
{
    protected:
        string _tel;

	public:
		TextBox(int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual void texting(double t);
};


#endif;
