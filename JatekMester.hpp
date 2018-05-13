#ifndef MYWINDOW_HPP_INCLUDED
#define MYWINDOW_HPP_INCLUDED

#include "Window.hpp"

#include <string>

using namespace genv;

class JatekMester : public Window
{
protected:
    string kijon;
    bool vege_a_kornek;
    string nyertes;
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

