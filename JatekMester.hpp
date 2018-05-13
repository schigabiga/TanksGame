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
    bool vege_a_kornek;
    string nyertes;
    TextBox *s1;
    int elsoj;
    int masoj;
    bool vege_a_jateknak;
public:
    JatekMester();
    //
    void lepes();
	string getkijon();
	void vege();
	void nyertesjatekos(string n);
	//
    virtual void event(string es);
};

#endif // MYWINDOW_HPP_INCLUDED

