#include "JatekMester.hpp"
#include "graphics.hpp"
#include "TextBox.hpp"
#include "FocusedCheckBox.hpp"
#include "vButton.hpp"
#include "TankWidget.hpp"
#include "numberchanger.hpp"
#include "map.hpp"

#include <vector>
#include <sstream>

using namespace genv;

TextBox * t1=new TextBox(410,495,50,50,"");
TextBox * t2=new TextBox(50,35,50,50,"0");
TextBox * t3=new TextBox(800,35,50,50,"0");

TextBox * t4=new TextBox(20,2,480,30,"Az ertekek beallitasa utan kattints a tankra a tuzeleshez!");
TextBox * t5=new TextBox(40,445,60,30,"Degree:");
TextBox * t6=new TextBox(160,445,60,30,"Power:");
TextBox * t7=new TextBox(600,445,60,30,"Degree:");
TextBox * t8=new TextBox(740,445,60,30,"Power:");
TextBox * t9=new TextBox(390,455,60,30,"Wind:");

TankWidget * a1;
TankWidget * a2;


numberchanger *n1=new numberchanger(60,480,80,80,1,90,60);
numberchanger *n2=new numberchanger(180,480,80,80,10,200,30);

numberchanger *n3=new numberchanger(620,480,80,80,1,90,60);
numberchanger *n4=new numberchanger(760,480,80,80,10,200,40);

Map *m1=new Map(0,420,900,180);


vButton *b1;
vButton *b2;
TextBox *s1;

JatekMester::JatekMester()
{
    a1=new TankWidget(30,390,70,20,60,60,1,this);
    a2=new TankWidget(800,390,70,20,120,60,2,this);

    s1= new TextBox(325,35,250,50,"Elso tank kövezketik");

	widgets.push_back(m1);

	widgets.push_back(n1);
	widgets.push_back(n2);
	widgets.push_back(n3);
	widgets.push_back(n4);

    b1=new vButton(300,495,50,50,"Set1!",this);
	b2=new vButton(510,495,50,50,"Set2!",this);

	widgets.push_back(b1);
	widgets.push_back(b2);

	widgets.push_back(t1);
	widgets.push_back(t2);
	widgets.push_back(t3);
	widgets.push_back(t4);
	widgets.push_back(t5);
	widgets.push_back(t6);
	widgets.push_back(t7);
	widgets.push_back(t8);
	widgets.push_back(t9);

	widgets.push_back(a1);

	widgets.push_back(a2);

    widgets.push_back(s1);

    double i=m1->szelirany();
    if(i==1){
        a2->szello(m1->szelgeneral());
        t1->texting(m1->szelgeneral());
    }
    else{
        a2->szello(-(m1->szelgeneral()));
        t1->texting(-(m1->szelgeneral()));
    }

    vege_a_jateknak=false;
    kijon="Elso tank";

    elsoj=0;
    masoj=0;

    a1->kisy(345);

    n3->activ();
    n4->activ();
    b2->active();
}

void JatekMester::lepes(){


    if(!vege_a_jateknak){
        double i=m1->szelirany();
        string who="";

        if(kijon=="Elso tank"){

            n1->activ();
            n2->activ();
            n3->activ();
            n4->activ();
            b1->active();
            b2->active();

            a2->kisy(a1->yback());

            //szell
            if(i==1){
                a2->szello(m1->szelgeneral());
                t1->texting(m1->szelgeneral());
            }
            else{
                a2->szello(-(m1->szelgeneral()));
                t1->texting(-(m1->szelgeneral()));
            }
            //
            kijon="Masodik tank";

        }
        else{
            n1->activ();
            n2->activ();
            n3->activ();
            n4->activ();
            b1->active();
            b2->active();

            a1->kisy(a2->yback());

            //szel
            if(i==1){
                a1->szello(m1->szelgeneral());
                t1->texting(m1->szelgeneral());
            }
            else{
                a1->szello(-(m1->szelgeneral()));
                t1->texting(-(m1->szelgeneral()));
            }
            //
            kijon="Elso tank";
        }

        who=kijon;
        who+=" következik";

        s1->settext(who);

        if(vege_a_kornek==true){
            if(nyertes=="Elso tank"){
                elsoj++;
            }
            if(nyertes=="Masodik tank"){
                masoj++;
            }
            stringstream ss;
            string es,ms;
            ss<<elsoj;
            ss>>es;
            ss.clear();
            ss<<masoj;
            ss>>ms;
            t2->settext(es);
            t3->settext(ms);
            vege_a_kornek=false;
        }
    }
    if(elsoj==5 || masoj==5){
        vege_a_jateknak=true;
        if(elsoj==5){
            s1->settext("!!! Az elso tank nyert !!!");
        }
        else{
            s1->settext("!!! A masodik tank nyert");
        }

    }

}
void JatekMester::nyertesjatekos(string n){
    nyertes=n;
}

void JatekMester::vege(){
    vege_a_kornek=true;
}

string JatekMester::getkijon(){
    return kijon;
}

void JatekMester::event(string m)
{
    if(m=="Set1!"){
        a1->Degree(n1->GetNumber());
        a1->Speed(n2->GetNumber());
        a1->Start();
    }

    if(m=="Set2!"){
        a2->Degree(180-n3->GetNumber());
        a2->Speed(n4->GetNumber());
        a2->Start();
    }
}


