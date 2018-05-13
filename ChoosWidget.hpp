#ifndef CHOOSWIDGET_H
#define CHOOSWIDGET_H

#include "ChoosWidget.hpp"
#include <vector>
#include "widgets.hpp"

class ChoosWidget : public Widget
{
	protected:
        bool _checked;
        bool _focus;
        bool _gor;
        int _szel;
        int _magas;
        vector<string> _mezok;
        vector<bool> _bool;
        string _adott;
        vector<string> _jel;
        int _mennyi;
        int _db;
        double _db2;
        int _wx;
        string _h;
        int _hany;
        bool active;

	public:
	    ChoosWidget(int x,int y,int m,int n,vector<string> vektor);
        virtual bool chos(int mouse_x, int mouse_y);
        virtual vector<bool> on(int mouse_x, int mouse_y,vector<string> v);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual int valueback();
        virtual void add(string h);
        virtual int hanyback();
        virtual string adottback();
        virtual void activ();

};

#endif;

