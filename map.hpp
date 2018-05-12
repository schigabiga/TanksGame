#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class   Map : public Widget {
protected:
    bool _checked;
public:
    Map(int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
