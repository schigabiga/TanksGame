#ifndef TANKWIDGET_HPP_INCLUDED
#define TANKWIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

#include "JatekMester.hpp"



class JatekMester;

class TankWidget : public Widget {
protected:
    bool _checked;
    bool start;
    double sz;
    double xi,yi;
    double ks,wind;
    double av,ev;
    bool b;

    bool vege;
    int ki;
    double szell;
    int ir;
    string _ki;
    JatekMester* _parent;


public:
    TankWidget(int x, int y, int sx, int sy,int szog,int sp,int nez, JatekMester* parent);
    virtual void draw() ;
    virtual void Degree( double fok);
    virtual void Speed( double s);
    virtual string Wind();
    virtual void handle(genv::event ev);
    virtual void Start();
    virtual bool is_checked();
    virtual void bul(bool k);
    virtual double x();
    virtual double y();
    virtual void szello(double ertek);
    virtual string getszoveg();

};
#endif
