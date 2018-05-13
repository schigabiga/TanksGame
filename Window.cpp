
#include "graphics.hpp"
#include "Window.hpp"
using namespace genv;
using namespace std;//of
void Window::event_loop()
{
	genv::event ev;
	int focus = -1;

	int af=0;

	while(gin >> ev) {

		if (ev.type == ev_mouse && ev.button==btn_left) {
			for (size_t i=0; i<widgets.size(); i++) {
				if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
					if (focus!=-1) {
						widgets[focus]->handle(ev);
					}
					focus = i;
					/*if(focus==5){
                        cout<<"haha"<<endl;
                        focus=8;
					}*/
				}
			}
		}
		if (focus!=-1) {
			widgets[focus]->handle(ev);
			/*if(af>0){
                widgets[af]->handle(ev);
			}*/
		}
		for (Widget * w : widgets) {
			w->draw();
		}

		gout << refresh;
	}
}
