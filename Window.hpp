#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include <string>

using namespace genv;
using namespace std;

class Window {
protected:
    vector<Widget*> widgets;
public:
    virtual void event(string es)=0;
    void event_loop();
};


#endif // WINDOW_HPP_INCLUDED
