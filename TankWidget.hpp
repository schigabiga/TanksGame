#ifndef TANKWIDGET_HPP_INCLUDED
#define TANKWIDGET_HPP_INCLUDED

#include "widgets.hpp"

#include "JatekMester.hpp"

class JatekMester;

class TankWidget : public Widget {
protected:
    bool _checked;
    bool start;

    double sz;
    double xi,yi;
    double ix,iy;

    double ks,wind;
    double av,ev;


    bool vege;
    int ki;
    double szell;
    int ir;
    string _ki;
    JatekMester* _parent;

    double yb;
    double _ipy;

public:
    TankWidget(int x, int y, int sx, int sy,int szog,int sp,int nez, JatekMester* parent);
    virtual void draw() ;
    virtual void Degree( double fok);
    virtual void Speed( double s);
    virtual string Wind();
    virtual void handle(genv::event ev);
    virtual void Start();
    virtual bool is_checked();
    virtual double yback();
    virtual void kisy(double y);
    virtual void szello(double ertek);
    virtual string getszoveg();
};
#endif

