//ofline project 1
# include "iGraphics.h"



int cnt=0;
double polyx[3],polyy[3];
int color1[3],color[3];
int i=255,j=0,k=0;
int ii=0,jj=0,k1=255;
int x1=50,yy=50,x2=70,y2=70;
double x=x2+100,y=y2+100,dx=5,dy=0,theta=0,sign=1,mx=80,my=200,msign=1,mdx=5,mdy;
/*
x1 , yy  are the left and butto, point point of exterior rectengle
and x2 and y2 are of interior one*/
//x and y represents the x ,y corodiantes of  circle


void colorchange();

void iDraw()
{

    iClear();
    iSetColor(i,j,k);
    iFilledRectangle(x1 ,yy,500,500);
    iSetColor(0,0,0);
    iFilledRectangle(x2,y2,460,460);


    iSetColor(ii,jj,k1);
    iFilledCircle(x,y,50,100);

    iSetColor(150,150,150);
    iFilledPolygon(polyx,polyy,3);
    iSetColor(0,0,0);
    iLine(x-50*cos(theta),y-50*sin(theta), x, y);
    }



void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {


    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {

    }
}


void iKeyboard(unsigned char key)
{
     if(key=='s')
    {
        if(yy>=10)
        {
          int temp = y-y2;
             yy=yy-2;
             y2=yy+20;

             y= y2 + temp;;
        }

        if(y>=y2+410)
        {
            y-=12; theta=-theta;
            colorchange();
        }
    }
    if(key=='w')
    {
         if(yy<=390)

             {
                int temp = y-y2;
             yy=yy+2;
             y2=yy+20;

             y = y2 + (temp);
             }
             if(y<=y2+50)
        {
            y+=12; theta=-theta;
            colorchange();}

    }
    if(key=='a')
    {
        if(x1>=10)
            {x1-=2;
            int temp = x-x2;
            x2=x1+20;
            x= x2 + temp;}

          if(x>=x2+410)
        {x-=12; theta= acos(-1)-theta;
        colorchange(); }
    }
    if(key=='d')
    {
         if(x1<=590)

         {int temp = x-x2;

             x1+=2;
         x2=x1+20;
          x=  x2 + temp;}
         if(x<=x2+50)
        {x+=12; theta=acos(-1)-theta;
        colorchange();  }
    }


    if(key == 'q')
    {
        exit(0);
    }

}

void iSpecialKeyboard(unsigned char key)
{
     if(key==GLUT_KEY_RIGHT)
    {
        theta=theta - ( 5*acos(-1)/180);

    }
    if(key==GLUT_KEY_LEFT)
    {

        theta =theta + ( 5*acos(-1)/180);
    }


    if(key == GLUT_KEY_END)
    {
        exit(0);
    }

}
void colorchange()
{
  int tmp1=ii,tmp2=jj,tmp3=k1;
  ii=i;
  jj=j;
  k1=k;
  i=tmp1;
  j=tmp2;
  k=tmp3;


}



void circlemove()
{
   if(x <= (x2+55)|| x >= (x2+410)) {  theta = acos(-1)-theta;  colorchange();;}
    if(y <= (y2+55)|| y >= (y2+410)){theta= -theta; colorchange(); ;}
    x = x + dx*cos(theta);
    y= y+ dx*sin(theta);




   polyx[0]=x+50*cos(theta);
   polyx[1]= x  - 50*sin(theta);
   polyx[2]=  x + 50*sin(theta);
   polyy[0]=y+50*sin(theta);
   polyy[1]=y+  50 * cos(theta);
   polyy[2]=y  - 50*cos(theta);
}




int main()
{

    iSetTimer(1,circlemove);

    iInitialize(1000, 1000, "BallSelf");
    return 0;
}


