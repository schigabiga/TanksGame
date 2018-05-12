#ifndef FOCUSEDCHECKBOX_H
#define FOCUSEDCHECKBOX_H

#include "examplecheckbox.hpp"
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class FocusedCheckBox : public ExampleCheckBox
{
	protected:
		bool _focused;
		string _texter;
		string _tel;
		int _hossz;
		int _tolodas;
		bool _vege;
		int _sz;
		int _h;
		vector<char> betuk;
		int _kurzor;
		int _bet;
		int _merre;
		char _kar;

	public:
		FocusedCheckBox(int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_focused();
    virtual string _text();
    virtual void texting(string t);
};

#endif // FOCUSEDCHECKBOX_H
