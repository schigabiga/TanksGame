#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class PushButton : public Widget{
protected:

    std::string _szoveg;
    bool _lenyomott;
    bool _lenyomott_old;
    bool _focused;

    double ix,iy,f,ks;

public:
    PushButton(int x, int y, int sx, int sy, std::string szoveg);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void action()=0;
    virtual void setfocused();
    void katt();
    bool kijelolt();
    virtual bool _focusable();
   // virtual void csdraw(double _x,double _y,double f,double s,genv::event ev );
    virtual void fok(double f);
    virtual void seb(double k);
    virtual void ex(double x);
    virtual void ey(double y);


   // virtual void setText(std::string txt);
};

#endif // PUSHBUTTON_HPP_INCLUDED
