#ifndef MYWINDOW_HPP_INCLUDED
#define MYWINDOW_HPP_INCLUDED

#include "Window.hpp"
#include "graphics.hpp"
#include <string>
using namespace std;
using namespace genv;

class JatekMester : public Window
{
public:
    JatekMester();
    virtual void event(string es);
};

#endif // MYWINDOW_HPP_INCLUDED

