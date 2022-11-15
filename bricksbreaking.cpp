
# include "iGraphics.h"
#include"Windows.h"
#include<mmsystem.h>
#include<stdlib.h>
int step = 0;
int startingtimer  = 0 ;
#include"anim.h"

char str[100];
int j,n,m,counter;
char tym[10];
char got_name[10],print_name[20];
int length = 0;
double angle=3.1415/2,Y=345,X=350;;;
int LC =0;///leaders_count
int  loading_timer = 0;
int loading_display = 0;


//double angle=3.1415/2;




int new_game_selected = 0;///step = 1;
int level_selected=0;//..
int level_display = 0;//..
int rules_display =0 ;//..
int rules_selected = 0 ;//
int quit_selected = 0;//
int start_new_game = 0;//
int easy_selected  = 1 ;//for all
int medium_selected = 0;///for all
int hard_selected = 0;//for all
int numofghost =   1;//for ALL
int timer_for_ghost_blinking = 0 ; //FOR ALL;
int inputing_name = 0 ;
int somoy =0 ;//FOR ALLL
int show_leader_boaed = 0;
int game_over = 0;
int LB_display= 0;
int LB_selected = 0;
int LB_easy = 0;
int LB_medium = 0;  ///for_displaying_leader_board
int LB_hard = 0;
int pause_display= 0 ;
int game_quiting = 0 ;
int ball_bonus1 = 0;
int pointer = 0 ;
int asking_save_game  = 0;




struct bonus
{
    int bonus_x;
    int bonus_y;
    int state ;
    int change_y;
    bonus()
    {

        bonus_x = 0;
        bonus_y  =500;
        state = 0;
        change_y = 1;
    }

}bonus_ball;

struct ghost
{

    int ghost_x[10];
    int ghost_y[10];
    int ghost_state[10];
    int isdevil[10];
    //int eye[10];


}ghost1;

struct laser_shooter
{
    int laser_count = 0 ;
    int shooter_x;
    int shooter_y;
    int laser_x[10];
    int laser_y[10];
    int laser_state[10];
}shooterL;


typedef struct
{
    double ball_x=350,ball_y=5,dx=2*cos(ang),dy=2*sin(ang), ang=angle,temp1=0;
}bal;


typedef struct
{
    double block1=0,blockx1=50+rand()%600,blocky1=400+rand()%200,blockp1=10,dx=rand()%10+1; int color=0;
}bloc;
bloc block[100];
bal ball[6];

struct players_info
{
    char player_name[20];
    int consumed_time;
    int number_of_shoot;

};
players_info current_player;
players_info leaders[10];
players_info player_stand[6];

//FILE *num_of_leader = fopen("number.txt" , "w");
int any_ball_active();
void save_game()
{
    FILE *fp;


    fp = fopen("saved_game.txt", "w");
    fprintf(fp, "%d\n%d\n%d\n%d\n" , somoy,counter, n,m);
    for(int i = 0; i < n ; ++i)
    {
                fprintf(fp ,"%lf %lf %lf %lf %lf\n",block[i].block1,block[i].blockx1,
                block[i].blocky1 , block[i].blockp1,block[i].dx);
    }
    for(int  i = 0 ; i < m;++i)
    {
        fprintf(fp, "%lf %lf %lf %lf %lf\n", ball[i].ball_x ,ball[i].ball_y,ball[i].dx,ball[i].dy,ball[i].temp1);


    }

    fprintf(fp ,"%d %d %d\n",shooterL.laser_count,shooterL.shooter_x,shooterL.shooter_y );
    for(int   i = 0 ; i < 10;++i)
    {
        fprintf(fp,"%d %d %d\n",shooterL.laser_x[i], shooterL.laser_y[i],shooterL.laser_state[i] );
    }
        fprintf(fp, "%d\n",numofghost);
    for(int  i =0; i< 10;++i)
    {

        fprintf(fp,"%d %d %d %d\n",ghost1.ghost_state[i], ghost1.ghost_x[i],ghost1.ghost_y[i],ghost1.isdevil[i]);
    }
    fprintf(fp ,"%s %d %d\n",current_player.player_name, current_player.number_of_shoot, current_player.consumed_time);
   // int k = any_ball_active();
   // fprintf(fp , "%d\n" ,k);
    fprintf(fp , "%d %d %d\n" , easy_selected , medium_selected ,hard_selected);
    fprintf(fp ,"%d\n", pause_display);
    fprintf(fp, "%d %d %d %d\n", bonus_ball.bonus_x, bonus_ball.bonus_y,bonus_ball.change_y,bonus_ball.state);
     fclose(fp);



}
void load_game()
{



    FILE *fp;


    fp = fopen("saved_game.txt", "r");

    fscanf(fp, "%d\n%d\n%d\n%d\n" , &somoy,&counter, &n,&m);
    for(int i = 0; i < n ; ++i)
    {
                fscanf(fp ,"%lf %lf %lf %lf %lf\n",&block[i].block1,&block[i].blockx1,
                &block[i].blocky1 , &block[i].blockp1,&block[i].dx);
    }

    for(int  i = 0 ; i < m;++i)
    {

        fscanf(fp,"%lf %lf %lf %lf %lf\n", &ball[i].ball_x ,&ball[i].ball_y,&ball[i].dx,&ball[i].dy,&ball[i].temp1);

    }


    fscanf(fp ,"%d %d %d\n",&shooterL.laser_count,&shooterL.shooter_x,&shooterL.shooter_y );
    for(int   i = 0 ; i < 10;++i)
    {
        fscanf(fp,"%d %d %d\n",&shooterL.laser_x[i], &shooterL.laser_y[i],&shooterL.laser_state[i] );
    }

        fscanf(fp  , "%d" , &numofghost);

    for(int  i =0; i< 10;++i)
    {

        fscanf(fp,"%d %d %d %d\n",&ghost1.ghost_state[i], &ghost1.ghost_x[i],&ghost1.ghost_y[i],&ghost1.isdevil[i]);
    }

    fscanf(fp ,"%s %d %d\n",&current_player.player_name, &current_player.number_of_shoot, &current_player.consumed_time);
   // int k = any_ball_active();
   // fscanf(fp , "%d\n" ,k);

    fscanf(fp , "%d %d %d\n" , &easy_selected , &medium_selected ,&hard_selected);
    fscanf(fp , "%d\n" , &pause_display);
    fscanf(fp, "%d %d %d %d\n", &bonus_ball.bonus_x, &bonus_ball.bonus_y,&bonus_ball.change_y,&bonus_ball.state);
     fclose(fp);;


}
int highscore_board(){
    int flag = 0;
    int p_number=0;
    FILE *fp;
    if(easy_selected)
    fp=fopen("data_easy.txt","r");
    else if(medium_selected)
        fp = fopen("data_medium.txt", "r");
    else if(hard_selected)
        fp = fopen("data_hard.txt" , "r");
    while(fscanf(fp,"%s %d %d",& leaders[p_number].player_name,&leaders[p_number].number_of_shoot,&leaders[p_number].consumed_time)!=EOF)
        p_number++;
    fclose(fp);





        strcpy(leaders[p_number].player_name,current_player.player_name);
        leaders[p_number].number_of_shoot = current_player.number_of_shoot;
        leaders[p_number].consumed_time = current_player.consumed_time;
        p_number++;
        for(int i=0;i<p_number-1;i++){
            for(int j=0;j<p_number-1-i;j++){
                if(leaders[j].number_of_shoot > leaders[j+1].number_of_shoot){
                    char temp[20];
                    int tempScore;
                    tempScore=leaders[j].number_of_shoot;
                    leaders[j].number_of_shoot=leaders[j+1].number_of_shoot;
                    leaders[j+1].number_of_shoot=tempScore;
                    strcpy(temp,leaders[j].player_name);
                    strcpy(leaders[j].player_name,leaders[j+1].player_name);
                    strcpy(leaders[j+1].player_name,temp);
                    int temptime ;
                    temptime  = leaders[j].consumed_time;
                    leaders[j].consumed_time = leaders[j+1].consumed_time;
                    leaders[j+1].consumed_time = temptime;

                }
                else if(leaders[j].number_of_shoot==leaders[j+1].number_of_shoot
                        &&leaders[j].consumed_time > leaders[j+1].consumed_time)
                {
                    char temp[20];
                    int tempScore;
                    tempScore=leaders[j].number_of_shoot;
                    leaders[j].number_of_shoot=leaders[j+1].number_of_shoot;
                    leaders[j+1].number_of_shoot=tempScore;
                    strcpy(temp,leaders[j].player_name);
                    strcpy(leaders[j].player_name,leaders[j+1].player_name);
                    strcpy(leaders[j+1].player_name,temp);
                    int temptime ;
                    temptime  = leaders[j].consumed_time;
                    leaders[j].consumed_time = leaders[j+1].consumed_time;
                    leaders[j+1].consumed_time = temptime;
                }


            }
        }


    if(easy_selected)
    fp=fopen("data_easy.txt","w");
    else if(medium_selected)
        fp = fopen("data_medium.txt", "w");
    else if(hard_selected)
        fp = fopen("data_hard.txt" , "w");
    for(int i=0;i<p_number-1;i++)
        fprintf(fp,"%s %d %d\n", leaders[i].player_name, leaders[i].number_of_shoot,leaders[i].consumed_time);
    fclose(fp);


}

void ball_bonus()
 {
     if(m < 4)
     {

         bonus_ball.state = 1;
         bonus_ball.bonus_x = (bonus_ball.bonus_x + 2)%750;
       if(bonus_ball.bonus_x > 700)
       {


         if(bonus_ball.bonus_y ==600 && bonus_ball.change_y)

         {
            bonus_ball.change_y =0 ;
            bonus_ball.bonus_y = 400;
         }
         else if(bonus_ball.bonus_y == 500  && bonus_ball.change_y)
         {
             bonus_ball.bonus_y = 600;
             bonus_ball.change_y = 0 ;


                //printf("%d\n", bonus_ball.bonus_y);

         }
         else if(bonus_ball.bonus_y == 400 && bonus_ball.change_y)
         {   bonus_ball.change_y = 0 ;
             bonus_ball.bonus_y = 500;

         }
       }
       else
       {

           bonus_ball.change_y =1 ;
       }


     }
     else
     {

         bonus_ball.state = 0;
         bonus_ball.bonus_x = 0;
         bonus_ball.bonus_y = 500;
         bonus_ball.change_y = 1;;
     }


 }
   void newball(int b1, int b2)
   {
       ball[b1].ball_x = bonus_ball.bonus_x;
       ball[b1].ball_y = bonus_ball.bonus_y ;
       ball[b1].dx = 0;
       ball[b1].dy = -5;
       ball[b2].dx= 0;
       ball[b2].dy = -10;
       ball[b1].temp1 =1;
       ball[b2].temp1 = 1;



   }
void print_LB()
{
    for(int i = 0 ; i < 6;++i)
    {

        player_stand[i].player_name[0]  ='\0';
        player_stand[i].consumed_time = 0;
        player_stand[i].number_of_shoot = 0;

    }

    int p_number=0;
    FILE *fp;
    if(easy_selected)
    fp=fopen("data_easy.txt","r");
    else if(medium_selected)
        fp = fopen("data_medium.txt", "r");
    else if(hard_selected)
        fp = fopen("data_hard.txt" , "r");
    while(fscanf(fp,"%s %d %d",& player_stand[p_number].player_name,&player_stand[p_number].number_of_shoot,&player_stand[p_number].consumed_time)!=EOF)
        p_number++;
    fclose(fp);
    return;



}


void loading()
{

    if(loading_timer < 16)
        loading_timer++;

    else
    {
        loading_timer = 0;
    }
}
int any_ball_active()
{

    for(int  i = 0  ; i  <  m; ++i)
    {

        if(ball[i].temp1)
        {
            return 1;
        }
    }
    return 0;
}

void timer()
{

     somoy++;

}

void changeopeningvideo()
{

    startingtimer++;
}
void laser_shooting_initialize()
{


    shooterL.laser_count =  0;
    for(int  i = 0 ; i < 10; ++i)
    {
        shooterL.laser_state[i] = 0;
    }
    shooterL.shooter_x = 350;
    shooterL.shooter_y = 0;


}
void  ghost_initialize()
{
     int tempx = 650/numofghost;
     int tempy = 400/numofghost;
     ghost1.ghost_x[0] = 0;
     ghost1.ghost_y[0] =400;
     ghost1.ghost_state[0] = 1;

   for(int  i = 1 ; i  < numofghost ; ++i)
   {
       ghost1.ghost_state[i]= 1;
       ghost1.ghost_x[i] = ghost1.ghost_x[i-1]  + tempx;


   }
   int  j  =2;
   for(int i = 1; i < numofghost ; ++i)
   {

       ghost1.ghost_y[i] = 300 + (ghost1.ghost_y[i-1] + j *tempy)%300;
       j+=2;
   }
}
void ghost_move()
{
    timer_for_ghost_blinking = (timer_for_ghost_blinking + 1)%500 ;

    if(!any_ball_active())
    {



        for(   int i  = 0 ; i < numofghost; ++i)
        {

            if(ghost1.ghost_state[i])
            {

                ghost1.ghost_x[i] = (ghost1.ghost_x[i] + 1) % 650;



            }
        }
    }

}

void laser_shooting()
{

  if(!any_ball_active() ) {
    shooterL.laser_count =  0;
    return ;
  }
  for(int  i = 0 ; i< 10; ++i)
  {

   if(shooterL.laser_state[i])
   {


      shooterL.laser_y[i]+=10;
      for(int j = 0 ;  j < numofghost; ++j)
      {
         /* if(shooterL.laser_x[i] > block[j].blockx1 && shooterL.laser_x[i] < block[j].blockx1 + 30
             && shooterL.laser_y[i] > block[j].blocky1 && shooterL.laser_y[i] < block[j].blocky1 + 30)*/
          if(shooterL.laser_x[i] > ghost1.ghost_x[j] && shooterL.laser_x[i] < ghost1.ghost_x[j] + 50
             && shooterL.laser_y[i] > ghost1.ghost_y[j] && shooterL.laser_y[i] < ghost1.ghost_y[j]+50)
          {

             // block[j].blockp1-= 2 ;
             ghost1.ghost_state[j] = 0;;
              shooterL.laser_state[i] = 0 ;

             // Show_explosion();

          }

      }
      if(shooterL.laser_x[i]  > 700)
      {
          shooterL.laser_state[i] = 0;

      }

   }
  }



}
void show_devil_ghost(int i)

{
    if(ghost1.isdevil[i] < 30 && ghost1.isdevil[i]!=0)
    {

        ghost1.isdevil[i]++;
    }
    else
    {


        ghost1.isdevil[i] =  0;
    }
}
void iCover()
{
    pause_display = 0;
    pointer = 0 ;
    current_player.consumed_time = 0;
    current_player.number_of_shoot = 0;
    somoy = 0;
    counter=0;
    ball_bonus1 = 0;

 //   n=10;
    m=6;
    game_over =  0;
    shooterL.laser_count = 0;
    if(easy_selected) n =5, numofghost = 1 , ghost_initialize();
    else if(medium_selected ) n = 10, numofghost = 3,ghost_initialize();
    else if(hard_selected)  n = 15, numofghost = 5, ghost_initialize();


   angle=3.1415/2;
    FILE *p;
	p = fopen("block_build.txt", "r");
	    for(int i=0;i<n;i++)
	{
	    block[i].block1=0;
	    //block[i].blockx1=50+rand()%600;
        //block[i].blocky1=400+rand()%200;

        fscanf(p ,"%lf %lf\n", &block[i].blockx1, &block[i].blocky1);


	    block[i].blockp1=10;
	    block[i].dx=  2;
	    block[i].color=0;

	}
	fclose(p);

	for(int j=0;j<m;j++)
    {
         ball[j].ball_x=350;
         ball[j].ball_y=5;
         ball[j].ang=angle;
         ball[j].dx=2*cos(ball[j].ang);
         ball[j].dy=2*sin(ball[j].ang);
         ball[j].temp1=0;

    }

}

void level_change()
{

    if(easy_selected == 1)
    {

        medium_selected = 1;
        easy_selected = 0 ;
        hard_selected = 0;
        iCover();
        ghost_initialize();
        laser_shooting_initialize();
        step = 3;

    }
    else if(medium_selected == 1)
    {
        easy_selected = 0;
        medium_selected = 0;
        hard_selected = 1;
        iCover();
        ghost_initialize();
        laser_shooting_initialize();
        step = 3;


    }
    else if(hard_selected == 1)
    {
        //final_picture_display = 1;
       step = 1;

       iCover();
       ghost_initialize();
       laser_shooting_initialize() ;
       for(int i = strlen(print_name)-1; i >=0;--i)
       {

           print_name[i]='\0';
       }


    }

}

void iDraw()
{

    if(step == 12) /// a page to choose level
    ///if(level_display)
    {


       if(easy_selected)
       {

           iShowBMP(0,0,"level_display2.bmp");
       }
       else if(medium_selected)
       {
           iShowBMP(0,0,"level_display3.bmp");

       }
       else if(hard_selected)
       {
           iShowBMP(0,0,"level_display4.bmp");
       }
    }


    if (step==0)
        {
       iClear();
       show_bmp();



        }

   // iShowBMP(0 , 0, "new game.BMP");
   if(step==1)
    {

    iClear();
    iShowBMP(0 , 0, "new_game1.bmp");
    if(new_game_selected)
    {
        iShowBMP(0, 0, "new_game2.bmp");

    }
    if(level_selected)
    {

        iShowBMP(0, 0, "new_game3.bmp");
    }
    if(LB_selected)
    {

        iShowBMP(0,0,"new_game4.bmp");
    }
    if(rules_selected)
    {
          iShowBMP(0,0,"new_game5.bmp");

    }

    if(quit_selected)
    {
        iShowBMP(0,0,"new_game6.bmp");
                        exit(0);

    }
    if(rules_display)
    {

       iShowBMP(0,0,"rules.bmp");

    }
   // iText(350, 10 , "LOAD SAVED GAME", GLUT_BITMAP_HELVETICA_18);
    //iSetColor(230,123,7);
    //iFilledRectangle(200,Y,180,20);
    //iSetColor(5,100,0);
    //iText(250,350,"NEW GAME",GLUT_BITMAP_HELVETICA_18);
     //iText(250,300,"LEVEL",GLUT_BITMAP_HELVETICA_18);

    }

    if (step==2)
        {
          iClear();
          iSetColor(rand()%255, rand()%255, rand()%255);
          iText(250,450, "ENTER YOUR NAME" , GLUT_BITMAP_HELVETICA_18);
          iText(250 , 400, print_name ,GLUT_BITMAP_HELVETICA_18 );


          iSetColor(rand()%256,rand()%256,rand()%256);
          iText(250,350,"ARE YOU READY?",GLUT_BITMAP_TIMES_ROMAN_24);
          iText(250,300,"Press Enter to Start",GLUT_BITMAP_TIMES_ROMAN_24);
          iCover();
          somoy =  0;
          iSetColor(255,0,0);
          iText(10 , 10, "HOME",GLUT_BITMAP_TIMES_ROMAN_24);
        }
    if(step==3)
    {


       iClear();

       if(game_over)
       {
         iShowBMP(0 , 0 ,"game_over.bmp");

       }

        else
       {





        iShowBMP(0, 0 ,"bck3.bmp");

         for(int i =0 ;  i < m;++i)
            {

                iSetColor(255, 255 ,255);
                iFilledCircle(350 + (i*15) , 690, 5);
            }
        int current =0;

	//iClear();
//toString(somoy, tym);
        char* strrr;
        strrr  = itoa(somoy , tym ,10);
        iText(50, 650,strrr,GLUT_BITMAP_TIMES_ROMAN_24);
        char* temp1;
        temp1 = itoa(counter , str, 10);
        iText(620,680,"TOTAL KICKS");
        iText(650,650,temp1);
        for(int i=0;i<n;i++)
        {
            if (block[i].blockp1>0)
                {

                       //iFilledRectangle(block[i].blockx1,block[i].blocky1,30,30);
                    iShowBMP(block[i].blockx1, block[i].blocky1, "download.bmp");
                    iSetColor(160, 240, 239);

                    char *temp2;
                    temp2 = itoa(block[i].blockp1, str, 10);

                    iText(block[i].blockx1+10,block[i].blocky1+10, str,GLUT_BITMAP_HELVETICA_10);
                    block[i].block1=1;

                }
           else
               block[i].block1=0;
         for(int j=0;j<m;j++)
                {

                    iSetColor(255,0,0);
                  //iShowBMP2(ball[j].ball_x-10, ball[j].ball_y-10 , "ball.bmp", 175);
                  iFilledCircle(ball[j].ball_x,ball[j].ball_y,10 , 50);
                }


         for(int j=0;j<m;j++)
             if (ball[j].temp1!=0)  current=1;
         if (current==0)
                {
                    iSetColor(0,255,255);
                    iLine(350,5,350+1000*cos(angle),1000*sin(angle));

                }


        }

      if(any_ball_active())
         {
              iShowBMP2(shooterL.shooter_x, shooterL.shooter_y , "laser_shooter.bmp", 170);

              for(int  i  = 0 ; i < 10 ;++i)
            {

               if(shooterL.laser_state[i])
               {


                 iShowBMP2(shooterL.laser_x[i] , shooterL.laser_y[i]  , "laser.bmp"  , 2);
               }
            }
          }

            if(bonus_ball.state)
            {

                iShowBMP(bonus_ball.bonus_x,bonus_ball.bonus_y,"bonus_bricks.bmp");

            }

            for(int  i = 0 ; i  < numofghost ; ++i)
            {
                if(ghost1.ghost_state[i])
                    {
                        if(ghost1.isdevil[i])
                        {
                          show_devil_ghost(i);
                          iShowBMP2(ghost1.ghost_x[i], ghost1.ghost_y[i], "devil_ghost.bmp", 175 );

                        }
                        else
                        {




                            if(timer_for_ghost_blinking < 50 && timer_for_ghost_blinking > 0)
                            iShowBMP2(ghost1.ghost_x[i] , ghost1.ghost_y[i] , "ghost1.bmp" , 170) ;// ghost1.eye[i] = (ghost1.eye[i] + 1)%4;
                            else if(timer_for_ghost_blinking < 175 && timer_for_ghost_blinking >= 50)
                            iShowBMP2(ghost1.ghost_x[i] , ghost1.ghost_y[i] , "ghost2.bmp" , 170) ;// ghost1.eye[i] =(ghost1.eye[i] + 1)%4;
                            else if(timer_for_ghost_blinking < 350 && timer_for_ghost_blinking >=175)
                            iShowBMP2(ghost1.ghost_x[i] , ghost1.ghost_y[i] , "ghost3.bmp" , 170);//  ghost1.eye[i] = (ghost1.eye[i] + 1)%4;
                            else if(timer_for_ghost_blinking<500 && timer_for_ghost_blinking >=350)
                            iShowBMP2(ghost1.ghost_x[i] , ghost1.ghost_y[i] , "ghost4.bmp" , 170) ;
                        // ghost1.eye[i] = (ghost1.eye[i] + 1)%4;
                        }
                    }

            }



            if(pause_display)
            {

                iShowBMP(0,0,"pause_scene.bmp");

            }

            if(asking_save_game)
            {

                iShowBMP(0,0,"saving_game.bmp");
            }

    for(j=0;j<n;j++)
        if (block[j].block1!=0) break;

    if (j==n)
        {
            current_player.number_of_shoot = counter;
            current_player.consumed_time = somoy;
            counter =  0;
            somoy = 0;
            loading_timer = 0 ;
            step=4;
        }

        }
}

 if(step==4)

  {

     iClear();
     char *temp3,*temp4;
     char str2[100];
     temp3 = itoa(current_player.number_of_shoot , str, 10);
     temp4 = itoa(current_player.consumed_time , str2 , 10) ;
     iSetColor(rand()%255,rand()%255,rand()%255 );



     if(loading_timer >=0 && loading_timer < 2)iShowBMP(0,0,"loading1.bmp");
     if(loading_timer >=2 && loading_timer < 5)iShowBMP(0,0,"loading2.bmp");
     if(loading_timer >=5 && loading_timer < 7) iShowBMP(0,0,"loading3.bmp");
     if(loading_timer >=7 && loading_timer < 9) iShowBMP(0,0,"loading4.bmp");
     if(loading_timer >=9 && loading_timer < 11) iShowBMP(0,0,"loading5.bmp");
     if(loading_timer >=11 && loading_timer < 13) iShowBMP(0,0,"loading6.bmp");
     if(loading_timer >=13 && loading_timer <= 15) iShowBMP(0,0,"loading7.bmp");




        iText(200,450,"NUMBER OF KICKS",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(rand()%155+100,rand()%155+100,rand()%155+100 );
        iText(300,400,temp3,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(rand()%155+100,rand()%155+100,rand()%155+100 );
        iText(200, 350,"TOTAL TIME TAKEN",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(rand()%155+100,rand()%155+100,rand()%155+100 );
        iText(300,300, temp4, GLUT_BITMAP_TIMES_ROMAN_24);
        if(loading_timer == 16)
        {
            highscore_board();
            level_change();

        }




   }
   if(LB_display)///leader_board_display
   {
       iClear();
       char str1[50], str2[50];

       if(easy_selected)
       {
           iShowBMP(0,0,"easy_lb.bmp");


       }
       else if(medium_selected)
       {

           iShowBMP(0,0,"MEDIUM_lb.bmp");

       }
       else if(hard_selected)
       {
           iShowBMP(0,0,"HARD_lb.bmp");
       }
       for(int  i = 0 ; i < 6;++i)
       {

            itoa(player_stand[i].number_of_shoot, str1, 10);


            itoa(player_stand[i].consumed_time, str2, 10);
            if(player_stand[i].number_of_shoot )

            {
                iText(280 , 440 - (i*65), str1, GLUT_BITMAP_TIMES_ROMAN_24);
                iText(520 , 440 -(i*65), str2, GLUT_BITMAP_TIMES_ROMAN_24);
                iText(20 ,440-(i*65), player_stand[i].player_name,GLUT_BITMAP_TIMES_ROMAN_24);
            }
       }

       iSetColor(255, 0,0);
        iText(10 , 10, "HOME",GLUT_BITMAP_TIMES_ROMAN_24);
   }



}
void blockchange()
{
    for(int j=0;j<n;j++)

    {
        ///this part is only for demo
    for(int  i = 0 ; i < n; ++i)
    {
        if(i!= j && block[i].blockp1 && block[j].blockp1)
        {

            if(abs(block[i].blockx1 - block[j].blockx1) < 30 && abs(block[i].blocky1 - block[j].blocky1)< 30 )
            {

                block[i].dx = -block[i].dx;
                block[j].dx = -block[j].dx;
            }
        }
    }
    block[j].blockx1+=block[j].dx;
    if(block[j].blockx1  > 670 || block[j].blockx1 < 0)
    {

        block[j].dx = -block[j].dx;
    }
    }

}
void ballChange()
{

    for(int j=0;j<m;j++)
        {
            if (ball[j].temp1==1)
            {
                //ball[j].ball_x +=ball[j].dx;
                ball[j].ball_y +=ball[j].dy;
               // if(ball[j].ball_x > 690 || ball[j].ball_x < 10) ball[j].dx = -ball[j].dx ;
                if(ball[j].ball_x+abs(ball[j].dx)> 700 || ball[j].ball_x -abs(ball[j].dx)< 0)  ball[j].dx=-ball[j].dx;
                if(ball[j].ball_y > 700) ball[j].dy=-ball[j].dy;
                 ball[j].ball_x +=ball[j].dx;
                if (ball[j].ball_y<0)
                    {
                        ball[j].temp1=0;
                        ball[j].ball_x=350;
                        ball[j].ball_y=10;
                        ball[j].ang=3.1415/2;
                    }
            for(int i=0;i<n;i++) //in for loop full
                {
                    if (ball[j].ball_x+ball[j].dx+5>=block[i].blockx1-5 && ball[j].ball_x+ball[j].dx-5<=block[i].blockx1+30+5 &&
                    ball[j].ball_y+ball[j].dy+5>=block[i].blocky1-5 && ball[j].ball_y+ball[j].dy-5<=block[i].blocky1+30+5 &&block[i].block1==1)
                        {
                            if (ball[j].ball_x<=block[i].blockx1-5) {
                                    ball[j].dx=-ball[j].dx;
                                    ball[j].ball_x=block[i].blockx1-5;
                            }
                            else if(ball[j].ball_x>block[i].blockx1+30+5) {
                                    ball[j].dx=-ball[j].dx;
                                    ball[j].ball_x=block[i].blockx1+30+5;
                            }
                            else if (ball[j].dy>=0) {
                                    ball[j].dy=-ball[j].dy;
                                    ball[j].ball_y=block[i].blocky1-5;
                            }

                            else if (ball[j].dy<0) {
                                    ball[j].dy=-ball[j].dy;
                                    ball[j].ball_y=block[i].blocky1+30+5;
                            }
                            block[i].blockp1--;

                        }
                }
                 int co_x = ball[j].ball_x;
                 int co_y = ball[j].ball_y;
                for(int  i = 0 ; i < numofghost; ++i)
                {
                    if(ghost1.ghost_state[i] )
                    {


                        if(co_x  >  ghost1.ghost_x[i] && co_x < ghost1.ghost_x[i] + 50 )
                        {

                            if(ghost1.ghost_y[i] - co_y  < 10 && ghost1.ghost_y[i] - co_y > 0 )
                        {

                          if(m>1)
                            {
                                ghost1.isdevil[i] = 1;
                                m--;
                            }
                          else
                            {
                              game_over = 1;

                            }

                        }
                        }
                    }


                }
                if (ball[j].ball_x+ball[j].dx+5>=bonus_ball.bonus_x-5 && ball[j].ball_x+ball[j].dx-5<=bonus_ball.bonus_x+30+5 &&
                    ball[j].ball_y+ball[j].dy+5>=bonus_ball.bonus_y-5 && ball[j].ball_y+ball[j].dy-5<=bonus_ball.bonus_y+30+5 &&
                    bonus_ball.state==1)
                        {
                            if (ball[j].ball_x<=bonus_ball.bonus_x-5) {
                                    ball[j].dx=-ball[j].dx;
                                    ball[j].ball_x=bonus_ball.bonus_x-5;

                                    newball(m, m+1);
                                    m+=2;
                                    bonus_ball.state =0;

                                    }
                            else if(ball[j].ball_x>bonus_ball.bonus_x+30+5) {
                                    ball[j].dx=-ball[j].dx;
                                    ball[j].ball_x=bonus_ball.bonus_x+30+5;
                                    newball(m,m+1);
                                    m+=2;
                                    bonus_ball.state =0;
                                    }
                            else if (ball[j].dy>=0) {
                                    ball[j].dy=-ball[j].dy;
                                    ball[j].ball_y=bonus_ball.bonus_y-5;
                                    newball(m,m+1);
                                    m+=2;
                                    bonus_ball.state =0;
                                    }
                            else if (ball[j].dy<0) {
                                    ball[j].dy=-ball[j].dy;
                                    ball[j].ball_y=bonus_ball.bonus_y+30+5;
                                    newball(m,m+1);
                                    m+=2;
                                    bonus_ball.state =0;
                                    }


                        }

              //ball[j].ball_x +=ball[j].dx;
              //ball[j].ball_y +=ball[j].dy;


            }
        }
}


void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
    if(step == 1)
    {

        if(mx > 40 && mx < 350 )
        {

            if(my > 610 && my < 680 && button ==GLUT_LEFT_BUTTON &&state == GLUT_DOWN )
            {

                new_game_selected = 1;
                iCover();

                laser_shooting_initialize();
                ghost_initialize();
            }
            if(my > 610 && my < 680 && button ==GLUT_LEFT_BUTTON &&state == GLUT_UP )
            {

                ///start_new_game = 1;
                step = 2;
                pause_display = 0;
                new_game_selected = 0;
            }
            else if(my > 525 && my < 585 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {

                level_selected = 1;
                new_game_selected = 0;
            }
             else if(my > 525 && my < 585 && button == GLUT_LEFT_BUTTON && state == GLUT_UP)
            {


                level_display =   1;

                step = 12;
                new_game_selected = 0;
                level_selected = 0;
            }
             else if(my  > 435 && my < 505 && button == GLUT_LEFT_BUTTON &&state == GLUT_DOWN)
            {

                LB_selected = 1;
                level_selected = 0;
                new_game_selected = 0;
                level_display = 0;
            }
             else if(my  > 435 && my < 505 && button == GLUT_LEFT_BUTTON &&state == GLUT_UP)
            {
                LB_display = 1;
                print_LB();
                LB_selected = 0;
                rules_display = 0;

                level_selected = 0;
                rules_selected = 0;
                level_display = 0;
                new_game_selected = 0;
                step = -1;
            }
            else if(my  > 350 && my < 420 && button == GLUT_LEFT_BUTTON &&state == GLUT_DOWN)
            {

                rules_selected = 1;
                level_selected = 0;
                new_game_selected = 0;
                level_display = 0;
            }
             else if(my  > 350 && my < 420 && button == GLUT_LEFT_BUTTON &&state == GLUT_UP)
            {

               rules_display = 1;

                level_selected = 0;
                rules_selected = 0;
                level_display = 0;
                new_game_selected = 0;
            }
            else if(my > 250 && my < 335)
            {

                quit_selected = 1;
                rules_selected = 0;
                rules_display = 0;
                level_selected = 0;
                new_game_selected = 0;
            }


        }
        if(mx > 350 && mx < 700&& my >50 &&my < 250)
        {
            if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)
            {


                step = 3;
                load_game();
                pause_display = 0;

            }
        }



    }

    if(rules_display &&  step == 1)
      {

          if(mx> 10 && mx < 200 && my > 10 && my  < 100 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
          {

              rules_display = 0;
          }
      }
    if(level_display)
    {

        if(mx > 190 && mx < 610 )
        {
            if(my  > 530 && my < 580 && button == GLUT_LEFT_BUTTON &&state == GLUT_DOWN )
            {

                easy_selected = 1;
                iCover();
                numofghost = 1;
                ghost_initialize();
                laser_shooting_initialize();

                medium_selected = 0;
                hard_selected = 0;

            }
            else if( my > 460  &&  my < 520 && button == GLUT_LEFT_BUTTON &&state == GLUT_DOWN)
            {

                medium_selected = 1;

                iCover();
                numofghost = 3;
                ghost_initialize();
                laser_shooting_initialize();

                easy_selected =  0;
                hard_selected = 0;

            }
            else if(my > 370 && my < 450 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {

                hard_selected = 1 ;
                iCover();
                numofghost =5;
                ghost_initialize();
                laser_shooting_initialize();
                easy_selected = 0;
                medium_selected = 0;

            }

        }
        if(mx  > 10 && mx < 140)
        {

            if(my >590 && my < 690&& button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {

                step = 1;

            }
        }
    }

    if(game_over)
    {

        if(my>20 && my < 100)
        {

            if(mx > 0 && mx < 250)
            {

                game_over = 0;
                iCover();
                step = 3;

            }
            else if(mx > 520 && mx < 700)
            {

                step = 1;
                iCover() ;
                ghost_initialize();

                for(int i = strlen(print_name)-1 ; i >=0; --i)
                {

                    print_name[i] = '\0';
                }


            }
        }
    }
    if(step == 2)
    {
        if(mx  > 10 && mx < 120 && my > 0  && my < 40 && state == GLUT_DOWN)
        {

            step = 1;
            for(int i = strlen(print_name)-1; i >=0 ; --i)
            {

                print_name[i] = '\0';
            }
        }

    }
    if(LB_display)
    {

        if(mx  > 10 && mx < 120 && my > 0  && my < 40 && state == GLUT_DOWN)
        {

            step = 1;
            LB_display = 0;

        }
    }
    if(pause_display)
    {
        if(my>50 && my <150)
        {


            if(mx >10 && mx < 260 &&button==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {

                iResumeTimer(0);
                iResumeTimer(1);
                iResumeTimer(2);
                iResumeTimer(3);
                iResumeTimer(4);
                iResumeTimer(5);
                iResumeTimer(6);
                iResumeTimer(7);
                pause_display = 0;
            }
            if(mx >450 && mx < 700 && button ==GLUT_LEFT_BUTTON && state == GLUT_UP)
            {

                asking_save_game = 1 ;
                pause_display = 0;
            }
        }

    }
    if(asking_save_game)
        {

          if(my > 70 && my < 230)
             {


                if(mx >20 && mx < 240 && button ==GLUT_LEFT_BUTTON && state ==GLUT_UP)
                 {
                    save_game();
                    iCover();
                    iResumeTimer(0);
                    iResumeTimer(1);
                    iResumeTimer(2);
                    iResumeTimer(3);
                    iResumeTimer(4);
                    iResumeTimer(5);
                    iResumeTimer(6);
                    iResumeTimer(7);
                    asking_save_game = 0;

                    for(int i = strlen(print_name)-1; i >= 0; --i)
                    {

                        print_name[i] = '\0';
                    }


                    step = 1;
                }
                if(mx > 450 && mx <700 && state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
                {

                    iCover();
                    iResumeTimer(0);
                    iResumeTimer(1);
                    iResumeTimer(2);
                    iResumeTimer(3);
                    iResumeTimer(4);
                    iResumeTimer(5);
                    iResumeTimer(6);
                    iResumeTimer(7);
                    pause_display = 0;
                for(int i = strlen(print_name)-1; i >= 0; --i)
                {

                    print_name[i] = '\0';
                }
                    asking_save_game = 0;

                   step = 1;

                }
            }
        }





}


void iKeyboard(unsigned char key)
{   if(key=='\r' && step==3 && any_ball_active()==0)
    {


    counter++;
    pointer = 1;
    for(int j=0;j<m;j++)
    {
        ball[j].temp1=1;
    }
    ball[0].dx=(8)*cos(angle);
    ball[0].dy=(8)*sin(angle);
    ball[1].dx=(9)*cos(angle);
    ball[1].dy=(9)*sin(angle);
    ball[2].dx=(10)*cos(angle);
    ball[2].dy=(10)*sin(angle);
    ball[3].dx=(11)*cos(angle);
    ball[3].dy=(11)*sin(angle);
    ball[4].dx=(12)*cos(angle);
    ball[4].dy=(12)*sin(angle);
    ball[5].dx=(13)*cos(angle);
    ball[5].dy=(13)*sin(angle);
    laser_shooting_initialize();


    }

    else if (key=='\r' && step==2)
    {
         for(int i = 0; i < length;++i)
         {
             current_player.player_name[i] = print_name[i];
         }

        length = 0;

        step = 3;

    }
    else if(key!= '\r' && step==2)
    {

        print_name[length++]=key;

    }


    else if (key=='\r' && step==4) step=1;
if(key == 'a')
{

    if(any_ball_active() && pause_display == 0)
    {

        shooterL.shooter_x  = (shooterL.shooter_x - 5) % 700;

    }
}
if(key == 'd')
{

    if(any_ball_active() && pause_display==0)
    {

        shooterL.shooter_x  = (shooterL.shooter_x + 5) % 700;

    }
}
if(key == 'w' && pause_display == 0 )
{

    if(any_ball_active() && shooterL.laser_count < 10)
    {

            shooterL.laser_state[shooterL.laser_count] = 1;

          shooterL.laser_x[shooterL.laser_count] = shooterL.shooter_x + 17;
          shooterL.laser_y[shooterL.laser_count++] = 70;
          shooterL.laser_count%=10;



    }
}
if(key == 'p' && step==3)
{
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iPauseTimer(3);
    iPauseTimer(4);
    iPauseTimer(5);
    iPauseTimer(6);
    iPauseTimer(7);
}
if(key=='r'&&  step==3)
{

    iResumeTimer(0);
    iResumeTimer(1);
    iResumeTimer(2);
    iResumeTimer(3);
    iResumeTimer(4);
    iResumeTimer(5);
    iResumeTimer(6);
    iResumeTimer(7);
}
if(key == '\ ' && step == 3)
{
    pause_display = 1;
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iPauseTimer(3);
    iPauseTimer(4);
    iPauseTimer(5);
    iPauseTimer(6);
    iPauseTimer(7);
}
if(key == 'n')
{

    for(int i = 0 ; i< n;++i)
    {
        block[i].blockp1 = 0;
    }
    counter = 10;
    somoy = 30;
}
	//place your codes for other keys here

}


void iSpecialKeyboard(unsigned char key)
{
    if (key==GLUT_KEY_LEFT)
    {
        if(angle < 2.618)
        angle+=0.01;

    }
    if (key==GLUT_KEY_RIGHT)
    {   if(angle > 0.5236)
        angle-=0.01;

    }
    if(step==1 && key==GLUT_KEY_DOWN) Y=295;
    if (step==12 && key==GLUT_KEY_DOWN) {if (X>250) X-=50; else X=350;}
    if (step==12 && key==GLUT_KEY_UP) {if (X<350) X+=50; else X=250;}


	if(key == GLUT_KEY_END)
        {
            exit(0);
        }




}


int main()
{
    bloc block[n];

    laser_shooting_initialize();///for demo only
    ghost_initialize();
    laser_shooting_initialize();
    iSetTimer(10, changeopeningvideo);
    iSetTimer(0,ballChange);
    iSetTimer(1000, timer);
    iSetTimer( 1 , ghost_move );
    iSetTimer(300 , loading);
    iSetTimer(0, ball_bonus);






    iSetTimer(1,blockchange);
    iSetTimer(1  ,laser_shooting);

	iInitialize(700, 700, "BricksBreaking");
	return 0;
}


