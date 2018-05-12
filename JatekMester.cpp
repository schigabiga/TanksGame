#include "JatekMester.hpp"
#include "graphics.hpp"
#include "TextBox.hpp"
#include "FocusedCheckBox.hpp"
#include "vButton.hpp"
#include "TankWidget.hpp"
#include "numberchanger.hpp"
#include "map.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace genv;
using namespace std;

//FocusedCheckBox * f1=new FocusedCheckBox(100,50,200,50);

//TextBox * t1=new TextBox(400,495,50,50);

TankWidget * a1=new TankWidget(20,390,70,20,60,60);

TankWidget * a2=new TankWidget(600,390,70,20,60,60);

numberchanger *n1=new numberchanger(40,480,80,80,0,90);
numberchanger *n2=new numberchanger(160,480,80,80,0,1000);

numberchanger *n3=new numberchanger(600,480,80,80,0,90);
numberchanger *n4=new numberchanger(760,480,80,80,0,1000);

Map *m1=new Map(0,420,900,180);


vButton *b1;
vButton *b2;
vButton *b3;

JatekMester::JatekMester()
{
    // tankom legyen focusba és a hozzátartozó widgetek

	//widgets.push_back(f1);

	widgets.push_back(m1);

	widgets.push_back(n1);
	widgets.push_back(n2);
	widgets.push_back(n3);
	widgets.push_back(n4);

    b1=new vButton(300,495,50,50,"Fire!",this);
	//b2=new vButton(500,495,50,50,"Set2!",this);

	//b3=new vButton(10,495,50,50,"Set1!",this);


	widgets.push_back(b1);
//	widgets.push_back(b2);
	//widgets.push_back(b3);

//	widgets.push_back(t1);

	widgets.push_back(a1);
	widgets.push_back(a2);

//	t1->texting(a1->Wind());
}

void JatekMester::event(string m)
{
    if(m=="Fire!"){

        a1->Degree(n1->GetNumber());
        a1->Speed(n2->GetNumber());
        a1->Start();


      /*  b1->ex(a1->x());
        b1->ey(a1->y());

        b1->fok(n1->GetNumber());
        b1->seb(n2->GetNumber());*/
    }
    if(m=="Set1!"){



    }
    if(m=="Set2!"){

        cout<<n1->GetNumber()<<endl;

        a2->Start();
        a2->bul(b2->_focusable());
        a2->Degree(180-n1->GetNumber());
        a2->Speed(n2->GetNumber());

    }

    if(m=="szell"){
       /* string m2="";
        for(int i=f1->_text().size();i>=0;i--){
            m2+=f1->_text()[i];
        }
        t1->texting(m2);*/

//        t1->texting(a1->Wind());
    }
}
