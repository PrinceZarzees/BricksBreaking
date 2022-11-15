#include<bits/stdc++.h>
# include "iGraphics.h"
#include"Windows.h"
#include<mmsystem.h>
using namespace std;
char str[100];int step=1,j,n=10,m,counter;
double angle=3.1415/2,Y=345,X=350;
typedef struct
{double ball_x=350,ball_y=5,dx=2*cos(ang),dy=2*sin(ang), ang=angle,temp1=0;  }bal;
typedef struct
{double block1=0,blockx1=50+rand()%600,blocky1=400+rand()%200,blockp1=10,dx=rand()%10+1; int color=0;}bloc;
bloc block[100];
bal ball[6];
void iCover()
{counter=0;m=6;
   angle=3.1415/2;
	    for(int i=0;i<n;i++)
	{block[i].block1=0; block[i].blockx1=50+rand()%600; block[i].blocky1=400+rand()%200; block[i].blockp1=10; block[i].dx=rand()%10+1; block[i].color=0;

	}
	for(int j=0;j<m;j++)
    {ball[j].ball_x=350;ball[j].ball_y=5; ball[j].ang=angle; ball[j].dx=2*cos(ball[j].ang); ball[j].dy=2*sin(ball[j].ang);   ball[j].temp1=0;

    }

}
void iDraw()
{if (step==12) //28-38 change
{iClear();
iSetColor(230,123,7);iFilledRectangle(200,X,180,20);
iSetColor(5,100,0);iText(250,350,"EASY",GLUT_BITMAP_HELVETICA_18);
iSetColor(5,100,0);iText(250,300,"MEDIUM",GLUT_BITMAP_HELVETICA_18);
iText(250,250,"HARD",GLUT_BITMAP_HELVETICA_18);




}// 38-41
    if (step==1) {iClear();
iSetColor(230,123,7);iFilledRectangle(200,Y,180,20);iSetColor(5,100,0);iText(250,350,"NEW GAME",GLUT_BITMAP_HELVETICA_18);
iText(250,300,"LEVEL",GLUT_BITMAP_HELVETICA_18);}

    if (step==2) {iClear(); iSetColor(rand()%256,rand()%256,rand()%256);
iText(250,350,"ARE YOU READY?",GLUT_BITMAP_TIMES_ROMAN_24);
iText(250,300,"Press Enter to Start",GLUT_BITMAP_TIMES_ROMAN_24);iCover();}
if(step==3)
{
    int current =0;

	iClear();

stringstream ss;
ss<<counter;
ss>>str;
iText(620,680,"Your Score:");
iText(650,650,str);
for(int i=0;i<n;i++)
{if (block[i].blockp1>0)
{ if (block[i].color==0)
	    {iSetColor(rand()%256,rand()%256,rand()%256); block[i].color=1;}
iFilledRectangle(block[i].blockx1,block[i].blocky1,30,30);

iSetColor(0, 0, 0);
		stringstream ss;
	ss<<block[i].blockp1;
	ss>>str;
		iText(block[i].blockx1+10,block[i].blocky1+10, str);
		block[i].block1=1;}
else
    block[i].block1=0;
for(int j=0;j<m;j++)
{iSetColor(255,0,0);
iFilledCircle(ball[j].ball_x,ball[j].ball_y,10);}
for(int j=0;j<m;j++)
    if (ball[j].temp1!=0)  current=1;
if (current==0)
{
    iSetColor(0,255,255);
iLine(350,5,350+1000*cos(angle),1000*sin(angle));}


}

for(j=0;j<n;j++)
    if (block[j].block1!=0) break;
if (j==n) {step=4;}
}
 if(step==4)
{iClear();
stringstream ss;
ss<<counter;
ss>>str;
iText(250,350,"YOUR SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
iText(300,300,str,GLUT_BITMAP_TIMES_ROMAN_24);
}
}
void blockchange()
{for(int j=0;j<n;j++)
{
    block[j].blockx1 =(int(block[j].blockx1 + block[j].dx))%1000;
  //  block[j].blockx1+=block[j].dx; if (block[j].blockx1>650 || block[j].blockx1<30) block[j].dx=-block[j].dx;}
    }}

void ballChange(){

  for(int j=0;j<m;j++)
  {if (ball[j].temp1==1)
      {ball[j].ball_x +=ball[j].dx;
	ball[j].ball_y +=ball[j].dy;

	if(ball[j].ball_x > 700 || ball[j].ball_x < 0)  {ball[j].dx=-ball[j].dx;}
	if(ball[j].ball_y > 700) {ball[j].dy=-ball[j].dy;}
	if (ball[j].ball_y<0) {ball[j].temp1=0; ball[j].ball_x=350; ball[j].ball_y=10; ball[j].ang=3.1415/2;}
for(int i=0;i<n;i++) //in for loop full
{if ((abs(ball[j].ball_x-block[i].blockx1)<=abs(ball[j].dx) || abs(ball[j].ball_x-block[i].blockx1-30)<=abs(ball[j].dx))
     && (abs(ball[j].ball_y-block[i].blocky1)<=abs(ball[j].dy)|| abs(ball[j].ball_y-block[i].blocky1-30)<=abs(ball[j].dy))
&& block[i].block1==1)
{if (abs(ball[j].ball_x-block[i].blockx1)<=abs(ball[j].dx)) ball[j].ball_x=block[i].blockx1-abs(ball[j].dx)-0.1;
else ball[j].ball_x=block[i].blockx1+abs(ball[j].dx)+30+0.1;

if (abs(ball[j].ball_y-block[i].blocky1)<=abs(ball[j].dy)) ball[j].ball_y=block[i].blocky1-abs(ball[j].dy)-0.1;
else ball[j].ball_y=block[i].blocky1+abs(ball[j].dy)+30+0.1;
    ball[j].dx=-ball[j].dx;ball[j].dy=-ball[j].dy;
 block[i].blockp1--;
}
else
{if(ball[j].ball_x>=block[i].blockx1-5 && ball[j].ball_x<=block[i].blockx1+30+5 && ball[j].ball_y>=block[i].blocky1-5 && ball[j].ball_y<=block[i].blocky1+30+5 && block[i].block1==1)
    {if (ball[j].ball_x>=block[i].blockx1-5 && ball[j].ball_x<=block[i].blockx1+30+5 && ( abs(ball[j].ball_y-block[i].blocky1+5)<=abs(ball[j].dy) || abs(ball[j].ball_y-block[i].blocky1-30-5)<=abs(ball[j].dy)))
         { if (abs(ball[j].ball_y-block[i].blocky1+5)<=abs(ball[j].dy)) ball[j].ball_y=block[i].blocky1-5-abs(ball[j].dy)-0.1;
    else ball[j].ball_y=block[i].blocky1+30+5+abs(ball[j].dy)+0.1;
             ball[j].dy=-ball[j].dy; block[i].blockp1--; }
    if (ball[j].ball_y>=block[i].blocky1-5 && ball[j].ball_y<=block[i].blocky1+30+5 && ( abs(ball[j].ball_x-block[i].blockx1+5)<=abs(ball[j].dx) || abs(ball[j].ball_x-block[i].blockx1-30-5)<=abs(ball[j].dx)))
{if (abs(ball[j].ball_x-block[i].blockx1+5)<=abs(ball[j].dx)) ball[j].ball_x=block[i].blockx1-5-abs(ball[j].dx)-0.1;
    else ball[j].ball_x=block[i].blockx1+30+5+ball[j].dx+0.1;
    ball[j].dx=-ball[j].dx; block[i].blockp1--;}

    }}



      }}}
}


/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{ if(key=='\r' && step==3)
{


    counter++;
for(int j=0;j<m;j++)
{
 ball[j].temp1=1;}
 ball[0].dx=(7)*cos(angle);
    ball[0].dy=(7)*sin(angle);
ball[1].dx=(10)*cos(angle);
    ball[1].dy=(10)*sin(angle);
ball[2].dx=(15)*cos(angle);
    ball[2].dy=(15)*sin(angle);
ball[3].dx=(20)*cos(angle);
    ball[3].dy=(20)*sin(angle);
ball[4].dx=(25)*cos(angle);
    ball[4].dy=(25)*sin(angle);
ball[5].dx=(30)*cos(angle);
    ball[5].dy=(30)*sin(angle);
}
else if (key=='\r' && step==1 && Y==345) step=2;
else if (key=='\r' && step==1 && Y==295) step=12;
else if(step==12) {
if (X==350 && key=='\r') {n=5; step=1; Y=345;}
if (X==300 && key=='\r') {n=10; step=1; Y=345;}
if (X==250 && key=='\r') {n=15; step=1; Y=345;}
}
else if (key=='\r' && step==2) step=3;
else if (key=='\r' && step==4) step=1;
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{if (key==GLUT_KEY_LEFT)
{
    angle+=0.01;

}
if (key==GLUT_KEY_RIGHT)
{
    angle-=0.01;

}
if(step==1 && key==GLUT_KEY_DOWN) Y=295;
if (step==12 && key==GLUT_KEY_DOWN) {if (X>250) X-=50; else X=350;}
if (step==12 && key==GLUT_KEY_UP) {if (X<350) X+=50; else X=250;}


	if(key == GLUT_KEY_END)
	{
exit(0);
	}

	//place your codes for other keys here
}

int main()
{bloc block[n];
iSetTimer(10,ballChange);


iSetTimer(50,blockchange);

	iInitialize(700, 700, "BricksBreaking");
	return 0;
}


