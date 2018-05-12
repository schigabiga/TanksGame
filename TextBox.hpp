#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "examplecheckbox.hpp"
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class TextBox : public ExampleCheckBox
{
    protected:
        string _tel;

	public:
		TextBox(int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
   // virtual bool is_focused();
    virtual void texting(string t);
};


#endif;
