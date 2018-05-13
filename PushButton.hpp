#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include "widgets.hpp"

class PushButton : public Widget{
protected:

    std::string _szoveg;
    bool _lenyomott;
    bool _lenyomott_old;
    bool _focused;
    bool activ;

public:
    PushButton(int x, int y, int sx, int sy, std::string szoveg);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void action()=0;
    virtual void setfocused();
    void katt();
    bool kijelolt();
    virtual bool _focusable();
    virtual void active();
};

#endif // PUSHBUTTON_HPP_INCLUDED
