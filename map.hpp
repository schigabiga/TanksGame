#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include "widgets.hpp"

class   Map : public Widget {
protected:
    bool _checked;
public:
    Map(int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked();
    virtual double szelgeneral();
    virtual double szelirany();

};

#endif // EXAMPLECHECKBOX_HPP_INCLUDED
