#ifndef NUMBERCHANGER_H
#define NUMBERCHANGER_H

#include "numberchanger.hpp"
#include "widgets.hpp"

class numberchanger: public Widget
{
	protected:
        bool _checked;
        bool _focus;
        int _number;
        int _tolas;
        bool _inc;
        bool _dec;
        int _max,_min;
        bool active;

	public:
	    numberchanger(int x,int y,int m,int n,int ma,int mi,int k);
	    virtual bool is_inc(int mouse_x, int mouse_y);
	    virtual bool is_dec(int mouse_x, int mouse_y);
        virtual void draw();
        virtual double GetNumber();
        virtual void handle(genv::event ev);
        virtual void activ();

};

#endif;
