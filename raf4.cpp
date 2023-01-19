#include <Windows.h>
 #include <MMSystem.h>
 // link the winmm
#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
# include "Gamestructure.h" //this is the header file for the structure
#define WIDTH 1200         //along x, has to be fullscreen
#define HEIGHT 800        //along y
#define Total_life 7


//***Note that if you add any extra thing in others code, you should comment like- N: blah blah/F: blah blah... I hope you get it

//All functions should be listed here with names in the comment
void headless_ghost_movement();       //Noshin
void womenib_movement();              //Noshin
void g1Movement();                    //Noshin
void g3Movement();                    //Noshin
void dragonMovement();                //Noshin
void g2Movement();                    //Noshin
void bossMovement();                  //Noshin
void ghostmove();                     //Shafayat
void fire_off() ;                     // Fahmid
void tostring(char str[], int num);   //Fahmid
void ghost_come();                    //Fahmid
void life_down();                     //Fahmid
void numtocharconvert(int num, char *p);    //Shafayat
int chartonumconvert(char * ch);     //Shafayat
void backbutton();                   // SHAFAYAT
void gameinitialize();               //SV Shafayat
void scoreupdate(char *name, int score); //SV Shafayat
void nameinputbox();                 // SV Shafayat
void structload();                   //SV Shafayat
void ghost_change() ;                // F
void soundoptions();                    //Shafayat
void boss_power();  // Fahmid

//***Note that any value you need, just about anything, don't fear to declare a variable for it. Try to name it elegantly

//Declare all the variables here with proper commenting
int dif_speed=0;
int headless_gx=1100,headless_gy=50;     // N : level 1-headless ghost position initialization
int headless_dgx=25,count=0,flag=1;  // N : level 1-headless position change
int headless_w=141;                       // N : ghost width
int n_pos=300;                            // N : new position after killing
int womenib_gx=0,womenib_gy=0;  // N : level 1-women in black 1 position initialization
int womenib_dgx=50,womenib_dgy=30;  // N : level 1-women in black positioon change
int womenib_w=100;       // N :woman width
int move_womanib=0;      // N :woman movement counting
int control_womenib_gx=womenib_gx+250,control_womenib_gy=womenib_gy+150;  // N : level 1-women in black control
int womenib_h=200;       // NV :women height
int t=500,g1_x=150, g1_y=100;   // N : dementor
int g1_w=133;                   // N : dementor width
int control_g1_x=g1_x+50,control_g1_y=g1_y+50,c=150;  // N : dementor movement control
int human_x=g1_x+400,human_y=g1_y;   // N : human movement control
int human_w=50;
int dg1_x=40,move_g1=0;  // N : axis change
int g3_x=50,g3_y=100;    // N : fire ghost
int g3_w=107;            // N : fire ghost width
int scoreshow=1;
int falg_b=0;
int fg3_x=g3_x+10,fg3_y=g3_y+150,move_g3=0;  // N
int flag3=0;  // N
int dragon_x=1200,dragon_y=600,move_dragon=0; // N : dragon
int dragon_h=215;   // N : dragon width
int g2_x=0,g2_y=0;   // N : woman in black 1
int control_g2_x=g2_x+100,control_g2_y=g2_y+100;  // N : woman in black 1 control
int dg2_x=1,dg2_y=3,move_g2=0;   // N : movement
int g2_w=80;  // N : ghost width
int g2_h=210;  // N : ghost height
int boss_x=0,boss_y=0;  // N : boss
int boss_dx=50,boss_dy=30;  // N : boss position change
int boss_w=280, boss_h=260;  // N : boss width
int count_shooting=0;   // N
int flag_col=0;   // N
int boss_firex=boss_x,boss_firey=boss_y+boss_h;  // N
int flag_power=0;  // N

int tempx, tempy; //S: for storing ghost position temporarily
int screenwidth, screenheight;      //S : self explainatory
int xchange, ychange;               //S : for changing ghost pos
int game_over=1; // F : for isettimmer off
int score_count=Total_life; // F : score int
char life_str[10]; // F : life string
int life_count=10; // F : life int
char score_str[10]; // F : score string
int xchange2, ychange2;   // F : for changing cloud pos
int flag_p=0;                      // F : pause or resume
int flag_w=0;                       // F : for firing vertical
int flag_w2=0;                      // F : for firing horizontal
int flag_r=0;                      // F : for red sky
int flag_g=1;                      // F : for ghost vanis
int flag_b=0;
int xchange3=WIDTH/2, ychange3=HEIGHT-200;   // F : for changing hero pos
int hero_w=248,hero_h=159 ;//F : hero widgh and hight
int ghost_w=150,ghost_h=199 ;//F : ghost widgh and hight
int dx =10, dy=10;                 //S: increment, decrement variable
int dx2 =10, dy2=10;                 //F: increment, decrement variable
int step=0;                         //S : this defines various states inside the app. For more info, check the wiki in github
int i, j;                           //S : Counter variable
int kill=1,temp=1,temp2=1; // F : for kill count ,temp for toggle
int flag_sp=0; // F : super power
int flag_sl=0 ;// F : special  life
int deathparam=0;          //S: 1 means ghost died, 0 means not
int sp_lifex=100;           //S: for position of special life power
int sp_lazerx=1000;          //S: for position of special lazer power
int win=0;          //S: for determinig if player won or not
int flag_b_p=0,flag_b_l=0; //  F : flag  for boss power
int boss_p_x=WIDTH/2 , boss_p_y=HEIGHT/2, boss_p_r=50; // F : boss circle power co-ordinate
int boss_p_c=50 , m_x=60; // F : change power range


int toggle_sound=1, toggle_sfx=0, toggle_difficulty=0; //S : toggles the on/off and difficulty buttons, also can be used to change sound and difficulty modes
int namelen=0; //S: SV for input namelength storing
int step1mode=0; //S: different modes in step 1, 0 means normal game, 1 means pause menu, 2 means exit prompt, 3 means after game over
int step1box=0;   //S: SV  for input box activation in step 1, 1 means active, 0 means deactive
char finalname[30], primaryname[30]; //S: SV for storing input name

struct playerdata player[5];        //S: for storing player info
FILE *file;

/*
	function iDraw() is called again and again by the system. **
*/
// Shafayat : button
char struct_highscore[15];  //S: for showing struct score
char buttonimages[][100]={"bin\\Debug\\pictures\\buttons\\startnewgame.bmp", "bin\\Debug\\pictures\\buttons\\options.bmp", "bin\\Debug\\pictures\\buttons\\highscores.bmp", "bin\\Debug\\pictures\\buttons\\developers.bmp",  "bin\\Debug\\pictures\\buttons\\help.bmp", "bin\\Debug\\pictures\\buttons\\exit.bmp", "bin\\Debug\\pictures\\buttons\\back.bmp", "bin\\Debug\\pictures\\buttons\\mainmenu.bmp", ""};  //S: char for button image location
char background[][100]={"", "bin\\Debug\\pictures\\background\\skyback.bmp", "bin\\Debug\\pictures\\background\\options1.bmp", "bin\\Debug\\pictures\\background\\leaderboardsbackground.bmp", "bin\\Debug\\pictures\\background\\creatorscity.bmp", "bin\\Debug\\pictures\\background\\help.bmp", "bin\\Debug\\pictures\\background\\grim.bmp", "bin\\Debug\\pictures\\background\\win.bmp",""};
char optionsbutton[][100]={ "bin\\Debug\\pictures\\buttons\\sound.bmp", "bin\\Debug\\pictures\\buttons\\sfx.bmp", "bin\\Debug\\pictures\\buttons\\difficulty.bmp",""};
char onoffbutton[][100]= { "bin\\Debug\\pictures\\buttons\\on.bmp", "bin\\Debug\\pictures\\buttons\\off.bmp",""};
char difficultylvl[][100]= { "bin\\Debug\\pictures\\buttons\\lvleasy.bmp", "bin\\Debug\\pictures\\buttons\\lvlmedium.bmp", "bin\\Debug\\pictures\\buttons\\lvlhard.bmp",""};
char creators[][100]={"bin\\Debug\\pictures\\creators\\buetlogo.bmp", "bin\\Debug\\pictures\\creators\\shahal.bmp", "bin\\Debug\\pictures\\creators\\fahmid.bmp", "bin\\Debug\\pictures\\creators\\noshin.bmp", "bin\\Debug\\pictures\\creators\\noshinhand.bmp", "bin\\Debug\\pictures\\creators\\SIR.bmp", ""};
char logo[][100]={"bin\\Debug\\pictures\\logo\\highscores.bmp", "bin\\Debug\\pictures\\logo\\howtoplay.bmp", ""};
char affirm[][100]={"bin\\Debug\\pictures\\buttons\\no.bmp","bin\\Debug\\pictures\\buttons\\yes.bmp", ""};
char heart[][100]={"bin\\Debug\\pictures\\logo\\heartlost.bmp", "bin\\Debug\\pictures\\logo\\heart.bmp", ""};

void iDraw()
{
	iClear();

    //iShowBMP(0,0,"bin\\debug\\picture\\BG1.bmp");

    if(step==0)  //for the main menu. Other step values mean the following buttons of the menu(Given below gradually):
    {
        iShowBMP(0, 0, background[1]);
        for(i=0; i<6; i++)      //S: for showing button images
        {
            iShowBMP2(WIDTH/2 - 154-20+(i*10), 2*HEIGHT/3 - (i*90),  buttonimages[i], 0);

        }
    }

    //for the main menu. Other step values mean the following buttons of the menu(Given below gradually):
    else if(step==1)        //start new game button
    {
        if(kill>55) flag=6;
        if(toggle_difficulty==0) dif_speed=0;
        else if (toggle_difficulty==1)  dif_speed=30;
        else dif_speed=60;
        if(life_count<=0)
        {
            game_over=0;
            scoreshow=0;
        }

        //*****Part where ghost dies after shooting at targer*****
        if((flag_w||flag_w2)&&step1mode==0)
        {

            if(flag==0)     //Women in Black ghost; motion: angular
            {
                if(flag_w==1&&(xchange3)<(womenib_gx+womenib_w)&&(xchange3)>womenib_gx)
                {
                    score_count+=2000; // N : if kill 2000 point plus

                    womenib_gx-=n_pos;
                    womenib_gy=0;

                    deathparam=1;
                }
                if(flag_w2==1&& (HEIGHT-135)<(womenib_gy+womenib_h)&&(HEIGHT-135)>womenib_gy)
                {
                    score_count=score_count+2000;

                    womenib_gx-=n_pos;
                    womenib_gy=0;

                    deathparam=1;
                }
            }
            else if(flag==1)     //Headless ghost on horse onscreen; motion: HORSE
            {
                if(flag_w==1&&(xchange3)<(headless_gx+headless_w)&&(xchange3)>headless_gx)
                {
                    score_count+=1000; // N : if kill 1000 point plus

                    headless_gx=1200;

                    deathparam=1;
                }
            }
            else if(flag==2)        //Dementor WITH HUMAN; Motion: HORIZONTAL WALKING
            {
                if(flag_w==1&&(xchange3)<(g1_x+g1_w)&&(xchange3)>g1_x)     //Dementor
                {
                    score_count+=2000; // N : if kill 2000 point plus

                    g1_x=g1_x+n_pos-200;
                    human_x=g1_x+400;
                    if(g1_x>=WIDTH) g1_x=-50;

                    deathparam=1;
                }
                if(flag_w==1&&(xchange3)<(human_x+human_w)&&(xchange3)>human_x)        //Human
                {
                    score_count-=3000; // N : if kill 3000 point minus

                    human_x=human_x+1200;       //for kicking human out of the screen

                    life_count--;
                }
            }
            else if(flag==3)        //Fire Ghost; Motion: HORIZONTAL WALKING, FIREBALL: VERTICAL FLIGHT
            {
                if(flag_w==1&&(xchange3)<(g3_x+g3_w)&&(xchange3)>g3_x)
                {
                    score_count+=1000; // N : if kill 1000 point plus

                    g3_x=g3_x+n_pos;
                    fg3_x=g3_x+10;

                    if(g3_x>WIDTH) g3_x=50;

                    deathparam=1;
                }
            }
            else if(flag==4)        //Dragon, motion: HORIZONTAL FLIGHT
            {
                if(flag_w2&&((HEIGHT-135)<(dragon_y+dragon_h)&&(HEIGHT-135)>dragon_y))
                {
                    score_count+=2000; // N : if kill 2000 point plus
                    dragon_x=1205;

                    deathparam=1;
                }
            }
            else if(flag==5)        //Zombie Woman; Motion: straight up
            {
                if(flag_w&&((xchange3)<(g2_x+g2_w)&&(xchange3)>g2_x))
                {
                    score_count+=1000; // N : if kill 1000 point plus

                    g2_x=g2_x+n_pos;
                    if(g2_x>WIDTH) g2_x=50;
                    g2_h=0;

                    deathparam=1;
                }
                else if(flag_w2&&((HEIGHT-135)<(g2_y+g2_h)&&(HEIGHT-135)>g2_y))
                {
                    score_count+=1000; // N : if kill 1000 point plus

                    g2_x=g2_x+n_pos;
                    if(g2_x>WIDTH) g2_x=50;
                    g2_h=0;

                    deathparam=1;
                }
            }
            else if(flag==6)        //BOSS; Motion: UNKNOWN
            {
                if(flag_w==1&&(xchange3)<(boss_x+boss_w)&&(xchange3)>boss_x)
                {
                    score_count+=1000; // N : if kill 2000 point plus
                    count_shooting++;

                    boss_x=boss_x+n_pos;
                    boss_y=boss_y+n_pos;
                }
                else if(flag_w2==1&&((ychange3+50)<(boss_y+boss_h)&&(ychange3+50)>(boss_y)))
                {
                    score_count+=1000; // N : if kill 2000 point plus
                    count_shooting++;

                    boss_x=boss_x+n_pos;
                    boss_y=boss_y+n_pos;
                }

                if(count_shooting>=15)
                {
                    game_over=0;
                    win=1;
                }
            }

        }

        // N : if the fire ball touches the hero then the score will be deducted
        if(flag==3&&(fg3_x>=xchange3)&&(fg3_x<=(xchange3+hero_w))&&(fg3_y==ychange3)) score_count-=1000;


        //This executes if Ghost dies
        if(deathparam)
            {
                srand(time(NULL));
                flag=rand()%5; // N : ghost vanishing after kill

                flag_col=1;
                kill++;
                flag_r=0 ; //N :  red sky off
                deathparam=0;
            }



        if(flag_r)      //Makes everything red for sometime
        {
            iSetColor(255,0,0);
        }


        //*****Show different Background part here*****
        if(kill>=0&&kill<10) iShowBMP(0,0,"bin\\debug\\images\\BACKGROUNDS\\10.bmp");
        else if(kill>=10&&kill<30) iShowBMP(0,0,"bin\\debug\\images\\BACKGROUNDS\\11.bmp");
        else if(kill>=30&&kill<55) iShowBMP(0,0,"bin\\debug\\images\\BACKGROUNDS\\13.bmp");
        else if(kill>=55) iShowBMP(0,0,"bin\\Debug\\images\\background\\boss background.bmp");  // N : boss


        //*****Shows cloud, which changes color when shot a ghost*****
        if(!flag_col) iSetColor(255,255,255);
        if(flag_col)  iSetColor(255,40,17);
        iFilledCircle(xchange2+100,HEIGHT,100);
        iFilledCircle(xchange2+380,HEIGHT,250);
        iFilledCircle(xchange2+680,HEIGHT,100);


        //*****This part is shooting lazer*****
        if(flag_w)
        {
            iSetColor(200, 0, 0);
            iFilledRectangle(xchange3, 0, 30, ychange3+30); // F : for fireing here 60.5 is hero height/2
            iSetColor(255, 0, 0);
            iFilledRectangle(xchange3+10, 0, 10, ychange3+30); // F : for fireing here 60.5 is hero height/2

            if(!toggle_sfx)
            Beep(500,100); // F : weapon sound
        }
        if(flag_w2)
        {
            iSetColor(200, 0, 0);
            iFilledRectangle(0, HEIGHT-150, WIDTH,30); // F : for fireing horizontal lazer
            iSetColor(255, 0, 0);
            iFilledRectangle(0, HEIGHT-140, WIDTH,10); // F : for fireing horizontal lazer

            if(!toggle_sfx)
            Beep(500,100); // F : weapon sound
        }


      //*****This part for decreasing life when touching ghosts*****
      if(flag==0)       //for woman in black angular movement
      {
          if((((womenib_gx>xchange3)&&(womenib_gx<xchange3+hero_w))||((((womenib_gx+womenib_w)>xchange3))&&(womenib_gx+womenib_w<xchange3+hero_w)))&&((womenib_gy+200>ychange3)&&(womenib_gy+200<ychange3+hero_h)))
          {
              life_count--;
          }
      }
      else if(flag==3)      //for fireball
      {
          if((fg3_y+13>ychange3)&&(fg3_y+13<(ychange3+hero_h)))
             {
                if(((fg3_x-13>xchange3)&&(fg3_x-13<(xchange3+hero_w)))||((fg3_x+13>xchange3)&&(fg3_x+13<(xchange3+hero_w))))
                {
                    life_count--;
                }
             }
      }
      else if(flag==4)      //for white soul dragon
      {
          if((xchange3+hero_w)>=dragon_x&&(xchange3+hero_w)<=dragon_x+295)
          {
              life_count--;
          }
      }
      else if(flag==5)
      {
          if((((g2_x>xchange3)&&(g2_x<xchange3+hero_w))||(((g2_x+g2_w>xchange3))&&(g2_x+g2_w<xchange3+hero_w)))&&((g2_y+g2_h>ychange3)&&(g2_y+g2_h<ychange3+hero_h)))
          {
              life_count--;
          }
      }
      else if(flag==6)
      {
          if((boss_y+257>ychange3)&&(boss_y+257<(ychange3+hero_h)))
          {
              if(((boss_x>xchange3)&&(boss_x<(xchange3+hero_w)))||((boss_x+boss_w>xchange3)&&(boss_x+boss_w<(xchange3+hero_w))))
              {
                  life_count--;
              }
          }
      }
    if(flag==6&&flag_b_l&&(kill>63&&kill<70))
    {
        if((xchange3+hero_w/2<(boss_p_x+150))&&(xchange3+hero_w/2>(boss_p_x-150)))
        life_count--;
         //  F: boss power 2 hero killing
    }

    // N : boss power kill
    if(flag_power==1&&xchange3>=boss_firex+boss_w/2-192&&xchange3<=boss_firex+boss_w/2+192)
     {
         life_count--;
     }
    // N : boss power
    if(flag==6&&(kill>=55&&kill<=63))
    {
        //if(kill%4==0)
         flag_power=1;
    }
       if(flag_power==1)
        {
               iSetColor(0,38,230);
               iFilledCircle(boss_firex-192+boss_w/2,boss_firey-boss_h/2,30);
               iSetColor(0,128,255);
               iFilledCircle(boss_firex-192+boss_w/2,boss_firey-boss_h/2,24);
               iSetColor(255,255,255);
               iFilledCircle(boss_firex-192+boss_w/2,boss_firey-boss_h/2,20);

               iSetColor(204,0,34);
               iFilledCircle(boss_firex,boss_firey,30);
               iSetColor(255,0,43);
               iFilledCircle(boss_firex,boss_firey,24);
               iSetColor(255,255,255);
               iFilledCircle(boss_firex,boss_firey,20);

               iSetColor(0,153,0);
               iFilledCircle(boss_firex+boss_w/2,boss_firey-boss_h/2+192,30);
               iSetColor(102,255,25);
               iFilledCircle(boss_firex+boss_w/2,boss_firey-boss_h/2+192,24);
               iSetColor(255,255,255);
               iFilledCircle(boss_firex+boss_w/2,boss_firey-boss_h/2+192,20);

               iSetColor(255,102,25);
               iFilledCircle(boss_firex+boss_w,boss_firey,30);
               iSetColor(255,85,51);
               iFilledCircle(boss_firex+boss_w,boss_firey,24);
               iSetColor(255,255,255);
               iFilledCircle(boss_firex+boss_w,boss_firey,20);

               iSetColor(230,0,153);
               iFilledCircle(boss_firex+boss_w/2+192,boss_firey-boss_h/2,30);
               iSetColor(255,0,212);
               iFilledCircle(boss_firex+boss_w/2+192,boss_firey-boss_h/2,24);
               iSetColor(255,255,255);
               iFilledCircle(boss_firex+boss_w/2+192,boss_firey-boss_h/2,20);

               iSetColor(42,128,0);
               iFilledCircle(boss_firex+boss_w,boss_firey-boss_h,30);
               iSetColor(136,204,0);
               iFilledCircle(boss_firex+boss_w,boss_firey-boss_h,24);
               iSetColor(255,255,255);
               iFilledCircle(boss_firex+boss_w,boss_firey-boss_h,20);

               iSetColor(25,0,77);
               iFilledCircle(boss_firex+boss_w/2,boss_firey-boss_h/2-192,30);
               iSetColor(0,43,128);
               iFilledCircle(boss_firex+boss_w/2,boss_firey-boss_h/2-192,24);
               iSetColor(255,255,255);
               iFilledCircle(boss_firex+boss_w/2,boss_firey-boss_h/2-192,20);

               iSetColor(255,77,77);
               iFilledCircle(boss_firex,boss_firey-boss_h,30);
               iSetColor(255,179,179);
               iFilledCircle(boss_firex,boss_firey-boss_h,24);
               iSetColor(255,255,255);
               iFilledCircle(boss_firex,boss_firey-boss_h,20);

        }

       //*****Showing all the BMPs*****
        iShowBMP2(xchange3, ychange3,"bin\\debug\\images\\CHARACTERS\\hero.bmp",0);       //F :Hero main
        if(!deathparam)
        {
            if(flag==0) iShowBMP2(womenib_gx,womenib_gy,"bin\\debug\\images\\CHARACTERS\\woman in black.bmp",0);  // N : woman in black
            else if(flag==1) iShowBMP2(headless_gx,headless_gy,"bin\\debug\\images\\CHARACTERS\\headless ghost.bmp",0);  // N :headless ghost
            else if(flag==2)   // N
            {
                iShowBMP2(g1_x,g1_y,"bin\\Debug\\images\\CHARACTERS\\g1..bmp",0);   // N : dementor
                iShowBMP2(human_x,human_y,"bin\\Debug\\images\\CHARACTERS\\human.bmp",0);  // N : human
                iSetColor(230, 38, 0);
                iText(10, 60, "Save the human", GLUT_BITMAP_TIMES_ROMAN_24);
            }
            else if(flag==3)
            {
                iShowBMP2(g3_x,g3_y,"bin\\Debug\\images\\CHARACTERS\\g3.bmp",0);
                iSetColor(255, 25, 25);
                iFilledCircle(fg3_x+20,fg3_y+20,26);
                iSetColor(255, 255, 0);
                iFilledCircle(fg3_x+20,fg3_y+20,20);
            }
            else if(flag==4)
            {
                iShowBMP2(dragon_x,dragon_y,"bin\\Debug\\images\\CHARACTERS\\dragon.bmp",0);  // N : dragon
                iText(10,80,"Avoid Dragon",GLUT_BITMAP_TIMES_ROMAN_24);
            }
            else if(flag==5) iShowBMP2(g2_x,g2_y,"bin\\Debug\\images\\CHARACTERS\\g2.bmp",0);  // N : women in black
            else if(flag==6)
            {
                iShowBMP2(boss_x,boss_y,"bin\\Debug\\images\\CHARACTERS\\boss.bmp",0);       // N : boss
                fg3_x=boss_p_x; fg3_y=boss_p_y;
                iFilledCircle(fg3_x+20,fg3_y+20,26);
                iSetColor(255, 255, 0);
                iFilledCircle(fg3_x+20,fg3_y+20,20);
            }
        }


        //*****This part works for special abitilies taking*****
        //For life increase power
        if(flag_sl==1&&game_over==1)        // F : power life plus
        {
            if(flag_w==1&& (xchange3)<(sp_lifex+50)&&(xchange3)>(sp_lifex-50))
            {
                flag_sl=0;

                sp_lifex+=200;
                if(sp_lifex>=1200) sp_lifex=100;

                life_count+=2;
                if(life_count>Total_life)
                {
                    life_count=Total_life;
                }
            }
        }

        //For super lazer power
        if(flag_sp==1&&game_over==1)        // F : power show
        {
            if(flag_w==1&& (xchange3)<(sp_lazerx+50)&&(xchange3)>(sp_lazerx-50))
            {
                flag_sp=0;

                sp_lazerx-=200;
                if(sp_lazerx<=0) sp_lazerx=1000;

                iSetColor(200,100,100);
                iFilledRectangle(100,0,100,WIDTH);
                iFilledRectangle(400,0,100,WIDTH);
                iFilledRectangle(800,0,100,WIDTH);
                iFilledRectangle(1100,0,100,WIDTH);

                iSetColor(255,220,220);
                iFilledRectangle(120,0,60,WIDTH);
                iFilledRectangle(420,0,60,WIDTH);
                iFilledRectangle(820,0,60,WIDTH);
                iFilledRectangle(1120,0,60,WIDTH);

                deathparam=1;
                score_count+=3000;
                if(!toggle_sfx)
                {
                    Beep(700,100);
                    Sleep(50);
                    Beep(700,100);
                    Sleep(50);
                    Beep(700,100);
                }
            }
        }
        if(flag==6&&(kill>63&&kill<70)) // F : 4  fire balls boss power
        {
                 if(flag_b_l)
                {
                iSetColor(rand()%255+200,10,100);
                iFilledRectangle(boss_p_x-boss_p_r+boss_p_r/2,boss_p_y,boss_p_r,HEIGHT);
                 iSetColor(255,255,255);
                 iFilledRectangle(boss_p_x-boss_p_r+boss_p_r/2+10,boss_p_y,boss_p_r-20,HEIGHT);

                //iSetColor(rand()%255+100,rand()%255+250,rand()%255);
               // iFilledRectangle(boss_p_x-boss_p_r+boss_p_r/2,boss_p_y-boss_p_c*2,boss_p_r,HEIGHT);

                iSetColor(100,rand()%255+200,100);
                iFilledRectangle(boss_p_x-boss_p_c*2-boss_p_r+boss_p_r/2,boss_p_y-boss_p_c*2,boss_p_r,HEIGHT);
                 iSetColor(255,255,255);
                iFilledRectangle(boss_p_x-boss_p_c*2-boss_p_r+boss_p_r/2+10,boss_p_y-boss_p_c*2,boss_p_r-20,HEIGHT);

                  iSetColor(100,100,rand()%255+200);
                iFilledRectangle(boss_p_x+boss_p_c*2-boss_p_r+boss_p_r/2,boss_p_y-boss_p_c*2,boss_p_r,HEIGHT);
                 iSetColor(255,255,255);
                 iFilledRectangle(boss_p_x+boss_p_c*2-boss_p_r+boss_p_r/2+10,boss_p_y-boss_p_c*2,boss_p_r-20,HEIGHT);
                }

                iSetColor(rand()%255+200,10,100);
                iFilledCircle(boss_p_x,boss_p_y,boss_p_r);
                iSetColor(255,255,255);
                iFilledCircle(boss_p_x,boss_p_y,boss_p_r-20);


                iSetColor(rand()%255+100,rand()%255+100,rand()%255+100);
                iFilledCircle(boss_p_x,boss_p_y-boss_p_c*4,boss_p_r);
                iSetColor(255,255,255);
                iFilledCircle(boss_p_x,boss_p_y-boss_p_c*4,boss_p_r-20);


               iSetColor(100,rand()%255+200,100);
                iFilledCircle(boss_p_x-boss_p_c*2,boss_p_y-boss_p_c*2,boss_p_r);
                iSetColor(255,255,255);
                iFilledCircle(boss_p_x-boss_p_c*2,boss_p_y-boss_p_c*2,boss_p_r-20);


               iSetColor(100,100,rand()%255+200);
                iFilledCircle(boss_p_x+boss_p_c*2,boss_p_y-boss_p_c*2,boss_p_r);
                iSetColor(255,255,255);
                iFilledCircle(boss_p_x+boss_p_c*2,boss_p_y-boss_p_c*2,boss_p_r-20);

                if(boss_p_x%80==0) flag_b_l=1; // f : for power off and on
                else flag_b_l=0;

        }


        if(kill%5==0) // F : sp power icon show
        {
            flag_sp=1;
            if(flag_sp)
            {
                iSetColor(255,100,100);
                if(temp)
                {
                    iFilledCircle(sp_lazerx,200,50);
                    temp=0;
                }
                else
                {
                    iFilledCircle(sp_lazerx,200,40);
                    temp=1;
                }
                 iSetColor(255,255,255);
                 iText(sp_lazerx,190,"P",GLUT_BITMAP_TIMES_ROMAN_24);
            }

        }
        if(kill%7==0) // F : sp life icon show
        {
            flag_sl=1;
            if(flag_sl)
            {
                iSetColor(200,200,100);
                if(temp)
                {
                    iFilledCircle(sp_lifex,200,50);
                    temp=0;
                }
                else
                {
                    iFilledCircle(sp_lifex,200,40);
                    temp=1;
                }
                 iSetColor(255,255,255);
                 iText(sp_lifex,190,"L",GLUT_BITMAP_TIMES_ROMAN_24);
            }

        }




        //*****For Showing life and score*****
        iSetColor(180,180,255);
        tostring(score_str,score_count);
        iText(WIDTH-200, HEIGHT-100, " SCORE = ", GLUT_BITMAP_TIMES_ROMAN_24); // F: score show
        iText(WIDTH-200, HEIGHT-150,   score_str, GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,0,0);
        iText(60, HEIGHT-100, "LIFE = ", GLUT_BITMAP_TIMES_ROMAN_24); // F: life show
        for(i=0; i<Total_life; i++)
        {
            if(life_count>i)
            {
                iShowBMP2(60, HEIGHT-150-(i*38), heart[1], 0);
            }
            else
            {
                iShowBMP2(60, HEIGHT-150-(i*38), heart[0], 0);
            }
        }
        if(flag==6)
        {
            iSetColor(255, 0, 0);
            iText(WIDTH/2-150, HEIGHT/8+60, "BOSS LIFE", GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(WIDTH/2-150, HEIGHT/8, 300, 50);
            iSetColor(200, 0, 0);
            iFilledRectangle(WIDTH/2-150, HEIGHT/8, 300-(count_shooting*20), 50);
        }



        //*****For Showing level number
        if(kill>=0&&kill<10)
        {

            iSetColor(255,255,255);
            iText(WIDTH-200, HEIGHT-250, "LEVEL 1", GLUT_BITMAP_TIMES_ROMAN_24); // F: lvl

        }
        else if (kill>=10&&kill<30)
        {
            iSetColor(255,255,255);
            iText(WIDTH-200, HEIGHT-250, "LEVEL 2", GLUT_BITMAP_TIMES_ROMAN_24); // F: lvl
        }
        else if (kill>=30&&kill<55)
        {
            iSetColor(255,255,255);
            iText(WIDTH-200, HEIGHT-250, "LEVEL 3", GLUT_BITMAP_TIMES_ROMAN_24); // F: lvl
        }
        else
        {
            iSetColor(255,255,255);
            iText(WIDTH-200, HEIGHT-250, " BOSS LEVEL", GLUT_BITMAP_TIMES_ROMAN_24); // F: lvl
        }


         iSetColor(255, 100, 255);
        iText(10, 40, " # # # NFS # # #A & D: Move , L: Vertical Fire, K: Horizontal Fire, P: Pause, R: Resume\n", GLUT_BITMAP_TIMES_ROMAN_24); //

        if(flag_w||flag_w2) // F : for wepon effect
        {

         iSetColor(255,0,0);
         iCircle(xchange3+10,ychange3+70,30);
          iSetColor(255,100,100);
         iCircle(xchange3+10,ychange3+70,50);
          iSetColor(255,200,200);
         iCircle(xchange3+10,ychange3+70,70);
        }
        //******For showing level starting
        if(kill==0)
        {
            iClear();
            iSetColor(0, 0, 0);
            iFilledRectangle(0, 0, WIDTH, HEIGHT);
            iSetColor(255, 0, 0);
            iText(WIDTH/2-15, HEIGHT/2, "LEVEL 1", GLUT_BITMAP_TIMES_ROMAN_24); // F: lvl
            kill++;
            Sleep(1000);
        }
        else if(kill==9)
        {
            iClear();
            iSetColor(0, 0, 0);
            iFilledRectangle(0, 0, WIDTH, HEIGHT);
            iSetColor(255, 0, 0);
            iText(WIDTH/2-15, HEIGHT/2, "LEVEL 2", GLUT_BITMAP_TIMES_ROMAN_24); // F: lvl
            kill++;
            Sleep(1000);
        }
        else if(kill==29)
        {
            iClear();
            iSetColor(0, 0, 0);
            iFilledRectangle(0, 0, WIDTH, HEIGHT);
            iSetColor(255, 0, 0);
            iText(WIDTH/2-15, HEIGHT/2, "LEVEL 3", GLUT_BITMAP_TIMES_ROMAN_24); // F: lvl
            kill++;
            Sleep(1000);
        }
        else if(kill==54)
        {
            iClear();
            iSetColor(0, 0, 0);
            iFilledRectangle(0, 0, WIDTH, HEIGHT);
            iSetColor(255, 0, 0);
            iText(WIDTH/2-50, HEIGHT/2, "BOSS LEVEL", GLUT_BITMAP_TIMES_ROMAN_24); // F: lvl
            kill++;
            Sleep(1000);
        }



        if(step1mode==1)
        {
            iSetColor(127, 127, 127);
            iFilledRectangle(WIDTH/8, 3*HEIGHT/8, 6*WIDTH/8, 5*HEIGHT/8);

            iSetColor(0, 0, 255);
            iText(WIDTH/2-134, 7*HEIGHT/8, " # # # PAUSE MENU # # #  ", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(WIDTH/2-100, 7*HEIGHT/8-25, "PRESS R FOR RESUME", GLUT_BITMAP_HELVETICA_18);

            soundoptions();
            iPauseTimer(0);
            iPauseTimer(1);
            iPauseTimer(2);
            iPauseTimer(3);

        }

        if(step1mode==2&&game_over==1) //for exiting game in middle of the game
        {
            iSetColor(127, 127, 127);
            iFilledRectangle(2*WIDTH/8, 2*HEIGHT/5, 5*WIDTH/8-65, 2*HEIGHT/5);

            iSetColor(255, 255, 255);
            iText(2*WIDTH/6+35, 4*HEIGHT/6, "ARE YOU SURE YOU WANT TO EXIT?", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(2*WIDTH/6+35, 4*HEIGHT/6-30, "ALL CURRENT DATA WILL BE LOST", GLUT_BITMAP_TIMES_ROMAN_24);

            iShowBMP2(2*WIDTH/6, 2*HEIGHT/4, affirm[1], 0);
            iShowBMP2(4*WIDTH/6, 2*HEIGHT/4, affirm[0], 0);
            iPauseTimer(0);
            iPauseTimer(1);
            iPauseTimer(2);
            iPauseTimer(3);

        }
        if(step1mode==0)
            backbutton();

        if(!game_over)
        {
            // F : pausing game and show game over

            iClear();

            if(win)
            {
                iShowBMP(0, 0, background[7]);

                iSetColor(0,255,0);
                iText(3*WIDTH/8, 5*HEIGHT/8, " # # # YOU WON # # # ", GLUT_BITMAP_TIMES_ROMAN_24);
            }

            else if(!win)
            {
                iShowBMP(0, 0, background[6]);

                iSetColor(0,255,0);
                iText(3*WIDTH/8, 5*HEIGHT/8, " # # # GAME OVER # # # ", GLUT_BITMAP_TIMES_ROMAN_24);
            }


            iText(3*WIDTH/8, 5*HEIGHT/8-40, " YOUR SCORE IS = ", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(3*WIDTH/8, 5*HEIGHT/8-80,    score_str, GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(0, 0,0);
            iText(3*WIDTH/8, 5*HEIGHT/8-120, "ENTER YOUR NAME, WARRIOR:",GLUT_BITMAP_TIMES_ROMAN_24);
            nameinputbox();
            iPauseTimer(0);
            iPauseTimer(1);
            iPauseTimer(2);
            iPauseTimer(3);

        }

    }
    else if(step==2)        //options button
    {
        iSetColor(255, 100, 255);
        iShowBMP(0, 0, background[2]);

        iShowBMP2(1*WIDTH/4, 1*HEIGHT/4, optionsbutton[2], 0);    //S: shows difficulty button
        iShowBMP2(2*WIDTH/4, 1*HEIGHT/4, difficultylvl[toggle_difficulty], 0); //S:shows easy button primarily

        soundoptions();

        iText(10, 40, " Options Menu", GLUT_BITMAP_TIMES_ROMAN_24);
        backbutton();
    }

    else if(step==3)        //High scores button
    {
        iSetColor(255, 255, 255);
        iShowBMP(0, 0, background[3]);
        iShowBMP2(WIDTH/2-240, HEIGHT-250,logo[0], 0);
        iText(10, 40, "High Scores Page", GLUT_BITMAP_TIMES_ROMAN_24); //
        backbutton();

        for(i=0; i<5; i++)
        {
            iSetColor(255, 0, 0);
            iText(2*WIDTH/8, ((2*HEIGHT)/4)-(i*40), player[i].serial, GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(255, 255, 255);
            iText(3*WIDTH/8, ((2*HEIGHT)/4)-(i*40), player[i].name, GLUT_BITMAP_TIMES_ROMAN_24);

            tostring(struct_highscore, player[i].score);
            iText(5*WIDTH/8, ((2*HEIGHT)/4)-(i*40), struct_highscore, GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }

    else if(step==4)        //Developers section
    {
        iSetColor(255, 100, 255);
        iShowBMP(0, 0, background[4]);
        iText(10, 40, "Developers Page", GLUT_BITMAP_TIMES_ROMAN_24);
        iShowBMP2(7*WIDTH/8-75, 6*HEIGHT/8, creators[0], 0);

        iSetColor(255, 255, 0);
        iText(WIDTH/4-75, 7*HEIGHT/8,"1. SHAFAYAT HOSSAIN MAJUMDER", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(WIDTH/4-75, 7*HEIGHT/8-30,"   STUDENT ID: 1705080", GLUT_BITMAP_HELVETICA_18);
        iText(WIDTH/4-75, 7*HEIGHT/8-55,"   CSE LEVEL-1 TERM-1", GLUT_BITMAP_HELVETICA_18);
        iShowBMP2(50, 6*HEIGHT/8, creators[1], 0);

        iSetColor(153, 217, 234);
        iText(WIDTH/4-75, 5*HEIGHT/8,"2. FAHMID AL RIFAT", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(WIDTH/4-75, 5*HEIGHT/8-30,"   STUDENT ID: 1705087", GLUT_BITMAP_HELVETICA_18);
        iText(WIDTH/4-75, 5*HEIGHT/8-55,"   CSE LEVEL-1 TERM-1", GLUT_BITMAP_HELVETICA_18);
        iShowBMP2(50, 4*HEIGHT/8, creators[2], 0);

        iSetColor(0, 255, 255);
        iText(WIDTH/4-75, 3*HEIGHT/8,"3. NOSHIN ULFAT", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(WIDTH/4-75, 3*HEIGHT/8-30,"   STUDENT ID: 1705089", GLUT_BITMAP_HELVETICA_18);
        iText(WIDTH/4-75, 3*HEIGHT/8-55,"   CSE LEVEL-1 TERM-1", GLUT_BITMAP_HELVETICA_18);
        iShowBMP2(50, 2*HEIGHT/8, creators[3], 0);
        //iText(3*WIDTH/4-50, 2*HEIGHT/8-30,"NOSHIN WAS TOO BUSY WITH HER HAND POSE :')");

        iSetColor(100+rand()%255, 25+rand()%255, 25+rand()%255);
        iFilledCircle(792, 501, 125);
        iText(WIDTH/2+100, 3*HEIGHT/8, "ADVISOR:", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(WIDTH/2+100, 3*HEIGHT/8-30,"DR. MD. SHOHRAB HOSSAIN", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(WIDTH/2+100, 3*HEIGHT/8-60, "ASSOCIATE PROFESSOR", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(WIDTH/2+100, 3*HEIGHT/8-90, "DEPT. OF CSE, BUET", GLUT_BITMAP_TIMES_ROMAN_24);
        iShowBMP2(WIDTH/2+100, 4*HEIGHT/8, creators[5], 0);

        backbutton();
    }

    else if(step==5)        //help button
    {
        iShowBMP(0, 0, background[5]);
        iShowBMP2(WIDTH/2-160, 6*HEIGHT/8+30, logo[1], 0);

        iSetColor(255, 0, 0);
        iText(3*WIDTH/8, 5*HEIGHT/8, "CHARACTER MOVEMENT:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(3*WIDTH/8, 4*HEIGHT/8, "SHOOTING HORIZONTAL:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(3*WIDTH/8, 4*HEIGHT/8-55, "SHOOTING VERTICAL :",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(3*WIDTH/8, 3*HEIGHT/8-20, "FOR PAUSE/ RESUME:",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255, 255, 255);
        iText(3*WIDTH/8, 5*HEIGHT/8-30, "LEFT: \"a\"  /  \" <-\"",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(3*WIDTH/8, 5*HEIGHT/8-55, "RIGHT: \"d\"/ \"->\"",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(3*WIDTH/8, 4*HEIGHT/8-30, "PRESS: \"l\"",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(3*WIDTH/8, 4*HEIGHT/8-30-55, "PRESS: \"k\"",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(3*WIDTH/8, 3*HEIGHT/8-50, "PAUSE: \"p\"        RESUME: \"r\"",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255, 255, 0);
        iText(10, 40, "Help Page", GLUT_BITMAP_TIMES_ROMAN_24);

        backbutton();
    }

    else if(step==6)        //exit button
    {
        exit(0);
    }


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
		if(step==0)     //S: When menu page is on screen
        {
            if(mx>=(WIDTH/2-154-20)&&mx<=(WIDTH/2+154-20)&&my>=(2*HEIGHT/3)&&(2*HEIGHT/3+74))
            {
                step= 1;
                gameinitialize();
            }
            else if(mx>=(WIDTH/2-154-10)&&mx<=(WIDTH/2+154-10)&&my>=(2*HEIGHT/3-90)&&(2*HEIGHT/3+74-90))
            {
                step= 2;
            }
            else if(mx>=(WIDTH/2-154)&&mx<=(WIDTH/2+154)&&my>=(2*HEIGHT/3-180)&&(2*HEIGHT/3+74-180))
            {
                step= 3;
            }
            else if(mx>=(WIDTH/2-154+10)&&mx<=(WIDTH/2+154+10)&&my>=(2*HEIGHT/3-270)&&(2*HEIGHT/3+74-270))
            {
                step= 4;
            }
            else if(mx>=(WIDTH/2-154+20)&&mx<=(WIDTH/2+154+20)&&my>=(2*HEIGHT/3-360)&&(2*HEIGHT/3+74-360))
            {
                step= 5;
            }
            else if(mx>=(WIDTH/2-154+30)&&mx<=(WIDTH/2+154+30)&&my>=(2*HEIGHT/3-450)&&(2*HEIGHT/3+74-450))
            {
                step= 6;
            }
        }
        if(step==1)  //S: if inside start new game
        {
            if(mx>=3*WIDTH/8&&mx<=3*WIDTH/8+400&&my>=5*HEIGHT/8-160&&my<=5*HEIGHT/8-160+30&&game_over==0)
            {
                step1box=1;
            }
        }
        if(step==2||(step==1&&step1mode==1)) //S: when options page is onscreen
        {
           if(mx>=(2*WIDTH/4)&&mx<=(2*WIDTH/4+120)&&my>=(3*HEIGHT/4)&&my<=(3*HEIGHT/4+58)) //S: for toggling sound
            {
                if(toggle_sound)

                {
                    toggle_sound=0;
                    PlaySound(0, 0, 0); // F : game music off
                }
                else
                {
                    toggle_sound=1;
                    PlaySound(TEXT("bg song.wav"), NULL, SND_LOOP|SND_ASYNC); // F : game music on
                }
            }
            if(mx>=(2*WIDTH/4)&&mx<=(2*WIDTH/4+120)&&my>=(2*HEIGHT/4)&&my<=(2*HEIGHT/4+58)) //S: for toggling sfx
            {
                if(toggle_sfx) toggle_sfx=0;
                else toggle_sfx=1;
            }
            if(mx>=(2*WIDTH/4)&&mx<=(2*WIDTH/4+120)&&my>=(1*HEIGHT/4)&&my<=(1*HEIGHT/4+58)) //S: for toggling difficulty
            {
                if(toggle_difficulty==2) toggle_difficulty=0;
                else toggle_difficulty++;
            }
        }

        if(step==2||step==3||step==4||step==5) // steps where back button will work, diverts to main page
        {
            if(mx>=(7*WIDTH/8)&&mx<=(7*WIDTH/8+151)&&my>=(HEIGHT/8)&&my<=(HEIGHT/8+64))
            {
                step=0; //iShowBMP2(7*WIDTH/8, HEIGHT/8, buttonimages[6], 0);
            }
        }
        if(step==1&&step1mode==0) //if back button is clicked in step 1, warning box will appear
        {
            if(mx>=(7*WIDTH/8)&&mx<=(7*WIDTH/8+151)&&my>=(HEIGHT/8)&&my<=(HEIGHT/8+64))
            {
                step1mode=2;
                iPauseTimer(0);
                iPauseTimer(1);
                iPauseTimer(2);
                iPauseTimer(3);
                scoreshow=0;
            }
        }
        if(step==1&&step1mode==2)  //for warning box yes no button
        {
            if(mx>=(2*WIDTH/6)&&mx<=(2*WIDTH/6+120)&&my>=(2*HEIGHT/4)&&my<=(2*HEIGHT/4+58))
            {
                step=0;

            }
            if(mx>=(4*WIDTH/6)&&mx<=(4*WIDTH/6+120)&&my>=(2*HEIGHT/4)&&my<=(2*HEIGHT/4+58))
            {
                step1mode=0;
                iResumeTimer(0);
                iResumeTimer(1);
                iResumeTimer(2);
                iResumeTimer(3);

                scoreshow=1;
            }
        }
        //if(mx>=&&mx<=&&my>=&&my<=)    S: layout to use for button clickability
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		printf("%d %d\n", mx, my);  //S: a small technique I use to find out position on the screen
	}
}



/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(step==1) //F: buttons declaring while in game
    {
        if(step1mode==0)
        {
            if(key=='q')
            {
                life_count+=3;
            }
             if(key=='m')
            {
                life_count--;
            }
            if(key=='n')
            {
                life_count++;
            }
            if(key == 'p')
            {
                //do something with 'p'

                flag_p=1;
                step1mode=1;
                iPauseTimer(0);
                iPauseTimer(1);
                iPauseTimer(2);
                iPauseTimer(3);
                scoreshow=0;
            }

            if(key == 'd') //F: move right
            {
                if((xchange3+hero_w)<=WIDTH+50)
                xchange3+=50;
            }

            if(key == 'a') // F : move left
            {
                if(xchange3>=50)
                xchange3-=50;
            }
            if(key == 'k') // F : vertical firing on
            {
                flag_w2=1;
            }
            if(key == 'l') // F : move left
            {
                flag_w=1;
            }
            if(key == 'o') // F : move left
            {
                flag=3;
            }
            if(key == 'b') // F : move left
            {
                kill++;
            }
             if(key == 'z') // F : move left
            {
                flag=6;
                kill=64;
            }
             if(key == 'x') // F : move left
            {
                flag=6;
                kill=55;
            }
        }
        if(key == 'r')
            {

                flag_p=0;
                step1mode=0;
                iResumeTimer(0);
                iResumeTimer(1);
                iResumeTimer(2);
                iResumeTimer(3);
                scoreshow=1;
            }

        if(game_over==0&&step1box==1) // S: for game over box name input
        {
            if(key == '\r')
            {
                step1box=0;
                strcpy(finalname, primaryname);
                printf("%s\n", finalname);
                for(i = 0; i < namelen; i++)
                    primaryname[i] = 0;
                namelen = 0;
                scoreupdate(finalname, score_count);
                step=3;
            }
            else
            {
                primaryname[namelen] = key;
                namelen++;
            }
	}
    }


	//place your codes for other keys here
}



/*
	function iSpecialKeyboard() is called whenever user hits special keys like-
	function keys, home, end, pg up, pg down, arrows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(step==1&&step1mode==0)
    {
       if(key == GLUT_KEY_RIGHT)
        {
            if((xchange3+hero_w)<=WIDTH+50)
                xchange3+=50;
        }

        else if(key == GLUT_KEY_LEFT)
        {
            if(xchange3>=150)
                xchange3-=50;
        }
    }

	if(key == GLUT_KEY_END)
	{

	}
	//place your codes for other keys here
}
void backbutton()
{
    iShowBMP2(7*WIDTH/8, HEIGHT/8, buttonimages[6], 0);
}
//turns off firing ammo
void fire_off()
{
    flag_w=0;
    flag_w2=0;
}


//This function loads the new score and name to the file
void scoreupdate(char *name, int score)
{
    int changeposition=-1;

    for(i=0; i<6; i++)
    {
        if(score>=player[i].score)
        {
            changeposition=i;
            break;
        }
    }

    for(i=4; i>changeposition; i--)
    {
        strcpy(player[i].name, player[i-1].name);
        player[i].score=player[i-1].score;
    }
    strcpy(player[changeposition].name, name);
    player[changeposition].score=score;

    if(changeposition!=-1)
    {
        file=fopen("bin\\Debug\\resources\\PLAYERDATA.txt", "w");

        for(i=0; i<5; i++)
        {
            fprintf(file, "%s %s %d\n", player[i].serial, player[i].name, player[i].score);
        }
        fclose(file);
    }
    structload();
}


/*this function loads the data from the file to the structure at the begining of the program*/
void structload()
{
    file=fopen("bin\\Debug\\resources\\PLAYERDATA.txt", "r");

    if(file==NULL)
    {
        printf("error in file reading\n");
        return;
    }
    for(i=0; i<5; i++)
    {
        fscanf(file, "%s %s %d",&player[i].serial, player[i].name, &player[i].score);
        // for direct showing on screen
    }
    fclose(file);
}
void tostring(char str[], int num)

{
    int i, rem, len = 0, n;
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

void ghost_come()
{
    flag_g=1;
    flag_sl=0;
    flag_sp=0;
}

//this function converts numbers to chars
void numtocharconvert(int num, char *p)
{
    int i, numlen=1, temp= num;
    do
    {
        temp/=10;
        numlen++;
    }while(temp);

    char ch[numlen];
    for(i=0; i<numlen-1; i++)
    {
        ch[i]=(num%10)+48;
        num/=10;
    }

    for(i=0; i<numlen-1; i++)
    {
        p[i]=ch[numlen-i-2];
    }

    p[numlen-1]='\0';

    return;
}

//this function converts chars to numbers
int chartonumconvert(char * ch)
{
    int len=strlen(ch);
    int i, num=0;

    for(i=0; i<len; i++)
    {
        num=(num*10)+ch[i]-48;
    }
    return num;
}

//this function initializes game to initial level and va lues
void gameinitialize()
{
        xchange=0, ychange=0;               //S : for changing ghost pos
        game_over=1; // F : for isettimmer off
        score_count=0; // F : score int
        life_count=Total_life; // F : life int
        xchange2=0; ychange2=0;   // F : for changing cloud pos
        flag_p=0;                      // F : pause or resume
        flag_w=0;                      // F : for firing
        flag_r=0;                      // F : for red sky
        flag_g=1;                      // F : for ghost vanis
        flag=1;
        kill=0;
        xchange3=WIDTH/2; ychange3=HEIGHT-200;   // F : for changing hero pos
        ghost_w=110;ghost_h=170 ;//F : ghost widgh and hight

        dif_speed=0;
        headless_gx=1100;headless_gy=50;     // N : level 1-headless ghost position initialization
        headless_dgx=25;count=0;flag=1;  // N : level 1-headless position change
        headless_w=141;                       // N : ghost width
        n_pos=300;                            // N : new position after killing
        womenib_gx=0,womenib_gy=0;  // N : level 1-women in black 1 position initialization
        womenib_dgx=50,womenib_dgy=30;  // N : level 1-women in black positioon change
        womenib_w=100;       // N :woman width
        move_womanib=0;      // N :woman movement counting
        control_womenib_gx=womenib_gx+250;control_womenib_gy=womenib_gy+150;  // N : level 1-women in black control
        womenib_h=200;       // NV :women height
        t=500;g1_x=150; g1_y=100;   // N : dementor
        g1_w=133;                   // N : dementor width
        control_g1_x=g1_x+50;control_g1_y=g1_y+50;c=150;  // N : dementor movement control
        human_x=g1_x+400;human_y=g1_y;   // N : human movement control
        human_w=50;
        dg1_x=10;move_g1=0;  // N : axis change
        g3_x=50;g3_y=100;    // N : fire ghost
        g3_w=107;            // N : fire ghost width
        scoreshow=1;
        falg_b=0;
        fg3_x=g3_x+10;fg3_y=g3_y+150;move_g3=0;  // N
        flag3=0;  // N
        dragon_x=1200;dragon_y=600;move_dragon=0; // N : dragon
        dragon_h=215;   // N : dragon width
        g2_x=0;g2_y=0;   // N : woman in black 1
        control_g2_x=g2_x+100;control_g2_y=g2_y+100;  // N : woman in black 1 control
        dg2_x=1;dg2_y=3;move_g2=0;   // N : movement
        g2_w=80;  // N : ghost width
        g2_h=210;  // N : ghost height
        boss_x=0;boss_y=0;  // N : boss
        boss_dx=50;boss_dy=30;  // N : boss position change
        boss_w=280;  // N : boss width
        count_shooting=0;
        flag_col=0;
        deathparam=0;          //S: 1 means ghost died, 0 means not
        sp_lifex;           //S: for position of special life power
        sp_lazerx;          //S: for position of special lazer power
        win=0;          //S: for determinig if player won or not

        namelen=0; //S: SV for input namelength storing
        step1mode=0; //S: SV  for input box activation in step 1, 1 means active, 0 means deactive
        step1box=0;
        iResumeTimer(0);
        iResumeTimer(1);
        iResumeTimer(2);
        iResumeTimer(3);
}

//This function draws the nameinput box
void nameinputbox()
{
    flag_b=0;
    iSetColor(150, 260, 150);
    if(flag_b)
    iSetColor(150, 180, 250);
	iFilledRectangle(3*WIDTH/8, 5*HEIGHT/8-160, 400, 30);
	iSetColor(0, 0, 0);
	if(step1box == 1)
	{
    	iSetColor(0, 0,255);
		iText(3*WIDTH/8+20, 5*HEIGHT/8-160+8, primaryname, GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0, 0, 0);
		iText(3*WIDTH/8+20, 5*HEIGHT/8-160-15, "**Click Enter to finish**");
	}
    else
    {
        iText(3*WIDTH/8+10, 5*HEIGHT/8-160+8, "Click to activate the box, enter to finish.");

    }
}

//for showing basic options
void soundoptions()
{
    iShowBMP2(1*WIDTH/4, 3*HEIGHT/4, optionsbutton[0], 0);    //S: shows sound button
    iShowBMP2(1*WIDTH/4, 2*HEIGHT/4, optionsbutton[1], 0);    //S: shows sfx button

    iShowBMP2(2*WIDTH/4, 3*HEIGHT/4, onoffbutton[!toggle_sound], 0); //S: shows on button primarily
    iShowBMP2(2*WIDTH/4, 2*HEIGHT/4, onoffbutton[toggle_sfx], 0); //S: shows on button primarily

}

/*This function moves the ghost. Better the coder remove it and add a new function*/
void ghost_change()
{
    flag=rand()%5;
}

void ghostmove()
{
	xchange += dx; //F : ghost
	xchange2+= dx2; // F : cloud
	//ychange += dy;
    ////ychange2 += dy2;
	if(xchange >(WIDTH -ghost_w)|| xchange < 0) dx = -dx;
	if(ychange > HEIGHT || ychange < 0)dy = -dy;
	if(xchange2 > WIDTH ) xchange2= 0;
	if(ychange2 > HEIGHT || ychange2 < 0) ychange2 = 0;
	if(scoreshow)
	score_count+=1;
	if(temp==0) temp=1;
    else if(temp==1) temp=0;
}

//N:level 1-headless ghost movement control function
void headless_ghost_movement()
{
    if(flag==0)     //woman in black angular flight
    {
        womenib_gx=womenib_gx+womenib_dgx+dif_speed;
        womenib_gy=womenib_gy+womenib_dgy+dif_speed;
        if(womenib_gx>WIDTH)
        {
            womenib_dgx=-100;
        }
        if(womenib_gx<0)
        {
            flag=rand()%5;
            womenib_gx=(rand()%5)*(WIDTH/7);
        }

        if(womenib_gy>HEIGHT) womenib_dgy=-60;
        if(womenib_gy<0) womenib_dgy=40;
    }

    else if(flag==1)        //Horse rider headless horse movement
    {
        headless_gx=headless_gx-headless_dgx-dif_speed;
        if(temp)
        {
            headless_gy=100;
            temp=0;
        }
        else
        {
            headless_gy=120;
            temp=1;
        }
        if(headless_gx<0)
        {
            flag=rand()%5;
            headless_gx=1200;
        }

    }

    else if(flag==2)        //dementor with human horizontal walking
        {
            g1_x+= dg1_x+dif_speed;
            human_x+=10;
            if(g1_x>WIDTH)
            {
                g1_x=-30;
                human_x=g1_x+400;
                flag=rand()%5;
            }

            if((g1_x+g1_w)==human_x)
            {
                score_count-=1000;
                human_x+=1200;
            }
        }

    else if(flag==3)        //fireball dragon
    {
        g3_x=g3_x+20+dif_speed;
        fg3_y=fg3_y+50+dif_speed;
        if(g3_x>WIDTH)
        {
            flag=rand()%5;
            g3_x=(rand()%8)*(WIDTH/10);
        }


        if(fg3_y>HEIGHT)
        {
            fg3_x=g3_x+10+dif_speed;
            fg3_y=250;
        }
    }

    else if(flag==4)        //white soul dragon
    {
       dragon_x=dragon_x-30-dif_speed;
       if(dragon_x<0)
       {
            flag=rand()%5;
            dragon_x=1200;
       }
    }

    else if(flag==5)        //vertical movement lady ghost
    {
        g2_y=g2_y+40;

        if(g2_y>HEIGHT)
        {
        g2_x=g2_x+100+dif_speed;
        g2_y=0;
        }

        if(g2_x>WIDTH)
        {
            flag=rand()%5;
            g2_x=200;
        }
	}

    else if(flag==6)
    {
        boss_x=boss_x+boss_dx+dif_speed;
        boss_y=boss_y+boss_dy+dif_speed;
        if(boss_x>WIDTH)
        {
            boss_dx=-100;
        }
        if(boss_x<0) boss_dx=70;
        if(boss_y>HEIGHT) boss_dy=-60;
        if(boss_y<0) boss_dy=40;
    }
}
void boss_power()
{
    boss_p_x+=m_x;
    if(boss_p_x>900)
    {
      m_x=-m_x;
    }
     if(boss_p_x<300)
    {
        m_x=-m_x;
    }
    if(flag_b_p)
    {
       boss_p_c+=20;
       flag_b_p=0;
    }
    else
    {
       boss_p_c-=20;
       flag_b_p=1;
    }

}

void flagcloud()  // N
{
    flag_col=1;
    if(flag_col==0) flag_col=1;
    if(flag_col==1) flag_col=0;
}

void flagPower()
{
    if(flag_power==1)
    {
        boss_firey=boss_firey+50;
        if(boss_firey>=800+192)
            {
              boss_firey=boss_y+boss_h;
              boss_firex=boss_x;
            }
    }
}

int main()
{
	//place your own initialization codes here.
//       iSetTimer(100, womenib_movement);         // N
      // iSetTimer(200, g1Movement);               // N
       //SetTimer(100, g3Movement);               // N
      //iSetTimer(10, dragonMovement);            // N
       //iSetTimer(100, g2Movement);               // N
      // iSetTimer(100, bossMovement);             // N
        iSetTimer(100,flagPower);
        iSetTimer(100, headless_ghost_movement);  // N : headless ghost movement
        iSetTimer(1000, flagcloud);  // N
        iSetTimer(200, ghostmove); // F
        iSetTimer(1000, fire_off); //F
        iSetTimer(10000, ghost_come); //F
        iSetTimer(1000, boss_power); // F
       // iSetTimer(20000, ghost_change);

    structload();       //loads the file inside the structure
    //DWORD screenwidth = GetSystemMetrics(SM_CXSCREEN);
    //DWORD screenheight = GetSystemMetrics(SM_CYSCREEN);


     if(toggle_sound)
   PlaySound(TEXT("bg song.wav"), NULL, SND_LOOP|SND_ASYNC); // F : game music


	iInitialize(WIDTH, HEIGHT, "KILL THORNE");     //someone find a game name, PLEASE

	return 0;
}
