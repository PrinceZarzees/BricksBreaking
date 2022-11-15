
#include "iGraphics.h"
#include<bits/stdc++.h>
using namespace std;

int tc=20;
int height  = 400;
int x[20],y[20];
int begin=1;
double ball_x[10];;
double ball_y[10];
double arrowlength =1200;
double polyx[3], polyy[3];
///int ball_x=50, ball_y=50;
int curr_x=250, curr_y=0;
double arrow_x1=250,arrow_x2,arrow_y1=0,arrow_y2;
double theta[10];
int count = 10;
int flag[10];
int acc[10];
//cha str[] = {'1', '0'};
double radius = 10;
double dx,dy;
int counter[20];
char str[2];

  bool pause = false;


void ToString(int num);
int isactive();
void Bricks();
void iDraw()
{
	iClear();


	//iShowBMP(0,0,"bck.bmp");\

	iSetColor(255,0,0);
	for(int i=0;i<tc;i++)
    {
      if(counter[i] >0)

      { //  cout<<counter[i]<<endl;
          iFilledRectangle(x[i],y[i],60,60);
          iSetColor(0,0,0);
          ToString(counter[i]);
          iText(x[i]+15,y[i]+15, str,  GLUT_BITMAP_TIMES_ROMAN_24);

      }   iSetColor(255,0,0);

    }
    if(begin==1){
            for(int iii=0;iii<10;iii++)
            {
                  acc[iii] = iii+5;

            }
    iSetColor(0,0,255);
    ball_x [0] = 350;
    ball_y [0] = 50;
    iFilledCircle(ball_x[0], ball_y[0], radius  , 50);
      iFilledPolygon(polyx,polyy,3);
      dx = acc[5] * cos(theta[0]);
      dy = acc[5]* sin(theta[0]);
              iLine(arrowlength*cos(theta[0]),arrowlength*sin(theta[0]), ball_x[0], ball_y[0]);
        for(int i=1;i<10;i++)
        {
            ball_x[i] = ball_x[0]  ;
            ball_y[i] = ball_y[0] ;
            theta[i] = theta[0];
        }

    }

  if(begin == 0){
            for(int i=0;i<=9;i++)
            {
              iSetColor(0,0,255);
         //cout<<ball_x[i]<<" " <<ball_y[i]<<endl;
             iFilledCircle(ball_x[i],ball_y[i],radius,50);

             iSetColor(0,0,0);

  }
  }
  if(isactive() && begin==0) {
        begin=1;
         height -= 100;
         Bricks();

  }
  ///  if(!flag)

   /// {
     ///   iFilledPolygon(polyx,polyy,3);
   ///     iLine(ball_x-25*cos(theta),ball_y-25*sin(theta), ball_x, ball_y);
   /// }
   // while(!flag)
    // iSetColor(255,255,255);

      ///  if(!flag)iLine(ball_x, ball_y,arrowlength*cos(theta), arrowlength*sin(theta));




}
int isactive()
{
  int z=0;
    for(int i =0;i<10;i++)
    {
        if(ball_y[i]==0 ) z++;;
    }
    return z==10;
}

void iMouseMove(int mx, int my)
{

}


void ToString(int num)
{


    // declaring output string stream
   ostringstream str1;

    // Sending a number as a stream into output
    // string
    str1 << num;
//
    // the str() coverts number into string
   string geek =str1.str();
    for(int i=0;i<2;i++) str[i]=geek[i];
   // return geek;
}

void BricksMove()
{

    for(int i=0;i<tc;i++)
    {
        int a = int(x[i]);
        x[i] = (a + 1) %700;
    }
}
  double search(double bl_x, double bl_y, double thta,int ac)
{
    int rect = 60;
      dx = ac* cos(thta);
      dy = ac* sin(thta);
    for(int i=0;i<tc;i++)
            {
                if(counter[i]>0){
                if(bl_x > x[i]-radius  && bl_x < x[i]+rect+radius)
                {
                    if( (y[i]-radius-bl_y) <5  && y[i]-radius-bl_y >0 )
                        {
                            thta = -thta;
                            counter[i]--;
                           // return thta;
                          //  std::cout<<bl_y<<"  "<<bl_x<<std::endl;
                        }
                    else if((bl_y-radius-y[i]-rect)<5 && (bl_y-radius-y[i]-rect )>0)

                         {

                         thta = -thta;
                          counter[i]--;
                        //  return thta;
                         }

                }
                     if( bl_x + dx > x[i] - radius  && bl_x+dx <x[i] + rect + radius )
                    {
                        if( (y[i]-radius-bl_y) <5  && y[i]-radius-bl_y >0 )
                        {
                            thta = -thta;
                            counter[i]--;
                                //    return thta;
                          //  std::cout<<bl_y<<"  "<<bl_x<<std::endl;
                        }
                    else if((bl_y-radius-y[i]-rect )<5 && (bl_y-radius-y[i]-rect )>0)

                         {

                          thta = -thta;

                          counter[i]--;
                              //   return thta;
                         }



                    }
                   else  if(bl_y > y[i]-radius  && bl_y< y[i]+rect+radius)
                {
                    if( (x[i]-radius-bl_x) <5  && x[i]-radius-bl_x >0 )
                        {
                            thta = acos(-1)-thta;
                            counter[i]--;
                                  //  return thta;
                          //  std::cout<<bl_y<<"  "<<bl_x<<std::endl;
                        }
                    else if((bl_x-radius-x[i]-rect )<5 && (bl_x-radius-x[i]-rect )>0)

                         {

                         thta = acos(-1)-thta;
                          counter[i]--;
                                //  return thta;
                         }

                }
                    else if( bl_y + dy > y[i] - radius  && bl_y+dy <y[i] + rect + radius )
                    {
                        if( (x[i]-radius-bl_x) <5  && x[i]-radius-bl_x >0 )
                        {
                           thta =acos(-1) -thta;
                            counter[i]--;
                                  //  return thta;
                          //  std::cout<<bl_y<<"  "<<bl_x<<std::endl;
                        }
                    else if((bl_x-radius-x[i]-rect )<5 && (bl_x-radius-x[i]-rect )>0)

                         {

                         thta =acos(-1) -thta;
                          counter[i]--;
                                //  return thta;
                         }



                    }

        /*    if((x[i]-bl_x-radius*sin(45) < 5) && (x[i]-bl_x-radius*sin(45) >0))
                {
                    if ((y[i]-bl_y-radius*sin(45)<5) && (y[i]-bl_y-radius*sin(45)>0 ))
                        { thta = acos(-1) + thta ;  counter[i]--; }
                    else if((bl_y - y[i] - rect - radius*sin(45) < 5)&&(bl_y - y[i] - rect - radius*sin(45) >0))
                   {
                       counter[i]--;

                    thta  = acos(-1)+ thta;
                   }
                }
              else   if((bl_x-x[i]-rect- radius*sin(45) < 5) && (bl_x-x[i]-rect- radius*sin(45) > 0))
                {
                    if((y[i]-bl_y-radius*sin(45)<5) && (y[i]-bl_y-radius*sin(45)>0 ))
                        {thta = acos(-1) + thta; counter[i]--;}
                    else if((bl_y - y[i] - rect - radius*sin(45) < 5) && (bl_y - y[i] - rect - radius*sin(45) > 0))
                    {thta  = acos(-1)+ thta;  counter[i]--; }
                }

*/







             }

}
return thta;
}
int FindPosition(int a[], int i,int mod)
{

    int k;
    if(mod==650)
    {

       k=0;
    }
    else
    {

        k=height;;
    }
    int num1=k + rand()%mod;
    int j=0;

    while(j<i)
    {
        if(num1 > a[j]+60 || num1< a[j]) j++;
        else
        {
            num1 = k + rand() %mod;
            j=0;
        }
    }
    return num1;


}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		pause = (!pause);

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{


	}
}


void iKeyboard(unsigned char key)
{

}


void iSpecialKeyboard(unsigned char key)
{
   if(key==GLUT_KEY_LEFT)
   {

      if(begin) theta[0] -= (3*acos(-1)) /180;

   }
   if(key== GLUT_KEY_RIGHT)
   {

       if(begin) theta[0]= theta[0] + (3*acos(-1))/ 180 ;
   }

   if(key == GLUT_KEY_UP)
   {

        begin = 0;
    // pause=false;

    }
   if(key == GLUT_KEY_DOWN)
   {
         begin =1;
      // pause = true;
   }

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
}
void Bricks()
{   int cntt =1;
    for(int i=0;i<tc; i++)
    {
        x[i]= FindPosition(x,i,650 );
        y[i] = FindPosition(y,i, 450);



    }





}
void   BallMove()
{
  //   int rect= 50;
 // cout<<begin<<endl;
 if(begin==0){

     for(int i=0;i<10;i++)
     {






        if(ball_y[i]<=25)
        {

            ball_y[i] =0;
            flag[i]=0;
            theta[i] = 0;
        }
        else
        {
            int accel = (int)acc[i];
             if(ball_x[i] <= radius || ball_x[i] >=700-radius-10 )
               theta[i] = acos(-1) - theta[i];

            if(ball_y[i] >= 900-radius)
                theta[i] = -theta[i];

           theta[i] =   search(ball_x[i] , ball_y[i], theta[i],accel);
          // cout<< theta[i]<<endl;

           ball_x[i]+=accel * cos(theta[i]);
           ball_y[i]+= accel *sin(theta[i]);




        }
   //  return theta[i];

    }










}
}

/*void arrowmove()
{

    if(!flag)
    {
        arrow_x2


    }
}*/

///void DrawArrow()
int main()
{
    Bricks();

    for(int i=0;i<tc;i++)
    {

        counter[i] = rand()%50;;

    }






  //  if(pause == false )
    //{
      // if(begin ==0)
        //iSetTimer(0.1, BricksMove);
      //iSetTimer(0.1, BallMove);

    //}*/

    iInitialize(700, 900, "BRICKS BREAKING");



}
