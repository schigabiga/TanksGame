#ifndef MYWINDOW_HPP_INCLUDED
#define MYWINDOW_HPP_INCLUDED

#include "Window.hpp"
#include "graphics.hpp"
#include "TextBox.hpp"
#include <string>
using namespace std;
using namespace genv;

class JatekMester : public Window
{
protected:
    string kijon;
    bool vege_a_jateknak;
    TextBox *s1;
public:
    JatekMester();
    //
    void lepes_tortent();
	string getkijon();
	//
    virtual void event(string es);
};

#endif // MYWINDOW_HPP_INCLUDED

