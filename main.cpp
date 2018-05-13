#include "graphics.hpp"
#include "widgets.hpp"
#include "numberchanger.hpp"
#include "TextBox.hpp"
#include "JatekMester.hpp"
#include <vector>
#include <fstream>
using namespace std;
using namespace genv;
#include <math.h>

//comment

int main()
{
    int gx=1100;
    int gy=600;
	gout.open(gx,gy);

    JatekMester w;
    w.event_loop();

	return 0;
}
