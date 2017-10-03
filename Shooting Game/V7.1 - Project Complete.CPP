#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<dos.h>

int target(int target_position[6], int transperant[6]);
void backScreen(int d, int bullet_random[10], int x[10], int z);
void random_pixel(int pixel);
int touch(int targetposition[6],int p,int q);
void bullets_number(int bullet_random[10], int z);// z is for right left move
int target_move(int target_position[6]);
int score(int s, int c);

int main()
{
	randomize();
	int gd = DETECT, gm;
	int xmax,ymax;
	int d, i = 0, no, target_no;
	int target_position[6], bullet_random[10];

	char ch, l[1];
	int p, q, c, s = 0;
	int x[10],z = 0;  // z for moving bullets left and right
	int transperant[6];

	for(i = 0; i < 10; i++)
	{
		x[i] = 0;	/// initally 0 fo recognize top
	}

	 // transperant 3 different value for different time
	 // for appearing random time
	for(i = 0; i < 3; i++)
	{
		transperant[i] = random(50);
		// 40 is for creating different time instead of 60
	}
	transperant[3] = transperant[0];
	transperant[4] = transperant[1]; // [0],[1],[2] can change but
	transperant[5] = transperant[2]; // [3],[4],[5] is fixed

	initgraph(&gd, &gm, "C:\\TC\\BGI");
	xmax = getmaxx();
	ymax = getmaxy();

	/////// Game Instruction  ///////////

	setcolor(3);
	outtextxy(215, 130,"THE GREAT GUEESSING GAME");
	setcolor(WHITE);
	outtextxy(125, 160, "** Use Provided Character to launch bullets **");
	outtextxy(70, 175, "(if new game will start the keyword  on the bullets will changed)");
	setcolor(6);
	outtextxy(65, 210, "if your bullet will touch .. }no 1. then SCORE will increment by 5");
	outtextxy(300, 230, "}no 2. then SCORE will increment by 2");
	outtextxy(300, 250, "}no 3. then SCORE will increment by 1");
	setcolor(WHITE);
	outtextxy(100, 270, "Press 1 (bullets will MOVE LEFT) & Press 0 (bullets will MOVE RIGHT)");
	outtextxy(110, 290, "NOTE : use numeric keys to left, right move (below function keys)");
	setcolor(GREEN);
	outtextxy(275, 320, "GOOD LUCK");
	setcolor(WHITE);

	//////  assign target position  /////

	for(i = 0; i < 3; i++)
	{
		target_position[i] = random(xmax-68);
	}
	// [3],[5] is 0 for starting from right direction
	//   [2]   is 1 for starting from left direction
	target_position[3] = 0;  // for refference in target no 1
	target_position[4] = 1;  // for refference in target no 2
	target_position[5] = 0;  // for refference in target no 3

	//////  bullets numebers  //////

	for(i = 0; i < 10; i++)
	{
		bullet_random[i] = ( 97+random(26) );
		// 97 is ascii value of a
	}
	// for ignoring same alphabets buttom
	int j = 0;
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if(i == j)
			{
				continue;
			}
			if(bullet_random[i] == bullet_random[j])
			{
				bullet_random[j] = ( 97+random(26) );
			}
		}
	}

	bullets_number(bullet_random,z);

	///////////   bullets    /////////////

	for(i = 0; i < xmax; i += 68)
	{
		/////// rectangle /////
		setfillstyle(1, BLUE);
		rectangle(i, 440, 22+i, 475);
		floodfill(11+i, 457, WHITE);


		////// triengle /////
		setfillstyle(9, RED);
		line(i, 440, 11+i,415);
		line(11+i, 415, 22+i, 440);
		line(i, 440, 22+i, 440);
		floodfill(11+i, 430, WHITE);
	}

    //////////////////////  Bottom Line  /////////////////////

    setcolor(6); // orange
    line(0, ymax, xmax/3, ymax);
    line(0, ymax-1, xmax/3, ymax-1);
    line(0, ymax-2, xmax/3, ymax-2);
    setcolor(WHITE);
    line(xmax/3, ymax, 2*(xmax/3), ymax);
    line(xmax/3, ymax-1, 2*(xmax/3), ymax-1);
    line(xmax/3, ymax-2, 2*(xmax/3), ymax-2);
    setcolor(GREEN);
    line(2*(xmax/3), ymax, xmax, ymax);
    line(2*(xmax/3), ymax-1, xmax-1, ymax-1);
    line(2*(xmax/3), ymax-2, xmax-1, ymax-1);
    setcolor(WHITE);

    ////////////////////// Random Colorful Dots /////////////

    random_pixel(100);

    ///////////////  Call target   //////////////////

    target(target_position, transperant);

    ///////////////  Move  //////////////


	while(1)
	{
		ch = getch();
		d = ch;
		if(d == bullet_random[0])   // 1
		{
			if(x[0] == 0)
			{
				for( i = 0; i < 420; i += 5)
				{
					clearviewport();
					outtextxy(250,160,"You Lunched no. 1");
					sprintf(l, "%c",bullet_random[0]);
					outtextxy(9+z, 428-i, l);

					x[0] = 1;
					backScreen(d, bullet_random,x,z);
					target_position[6] = target_move(target_position);

					transperant[6] = target(target_position, transperant);
					bullets_number(bullet_random,z);
					/////// rectangle /////
				     //	setfillstyle(XHATCH_FILL, BLUE);
				    //	rectangle(0, 440-i, 22, 476-i);
				     //	floodfill(1, 441-i, WHITE);

					////// triengle /////
				   //	setfillstyle(XHATCH_FILL, RED);
					line(0+z, 440-i, 11+z,415-i);
					line(11+z, 415-i, 22+z, 440-i);
					line(0+z, 440-i, 22+z, 440-i);
				  //	floodfill(11, 430-i, WHITE);
					delay(20);
					p = 415 - i;
					q = 11 + z;
					c = touch(target_position,p,q);
					s = score(s, c);
					if(c == 1 || c == 2 || c == 3)
					{
						break;
					}
				  }
			}
			else
			{
				setcolor(RED);
				outtextxy(140, 310, "YOU HAD ONLY ONE CHANCE TO LAUNCH NO.1 BULLET");
			    //	setcolor(WHITE);
			}
		}
		if(d == bullet_random[1])   // 2
		{
			if(x[1] == 0)
			{
				for(i = 0; i < 420; i += 5)
				{
					clearviewport();
					outtextxy(250,160,"You Lunched no. 2");
					sprintf(l, "%c",bullet_random[1]);
					outtextxy(9+(68)+z, 428-i, l);
					x[1] = 1;
					backScreen(d, bullet_random,x,z);
					target_position[6] = target_move(target_position);

					transperant[6] = target(target_position, transperant);
					bullets_number(bullet_random,z);
					/////// rectangle /////
				    //	setfillstyle(XHATCH_FILL, BLUE);
				    //	rectangle(0+(68), 440-i, 22+(68), 476-i);
				   //	floodfill(1, 441-i, WHITE);

					////// triengle /////

				   //	setfillstyle(XHATCH_FILL, RED);
					line(0+(68)+z, 440-i, 11+(68)+z,415-i);
					line(11+(68)+z, 415-i, 22+(68)+z, 440-i);
					line(0+(68)+z, 440-i, 22+(68)+z, 440-i);
				   //	floodfill(11, 430-i, WHITE);
					delay(20);
					p = 415 - i;
					q = 11+(68) + z;
					c = touch(target_position,p,q);
					s = score(s, c);
					if(c == 1 || c == 2 || c == 3)
					{
						break;
					}
				}
			}
			else
			{
				setcolor(RED);
				outtextxy(140, 310, "YOU HAD ONLY ONE CHANCE TO LAUNCH NO.2 BULLET");
			    //	setcolor(WHITE);
			}
		}
		if(d == bullet_random[2])   // 3
		{
			if(x[2] == 0)
			{
				for( i = 0; i < 420; i += 5)
				{
					clearviewport();
					outtextxy(250,160,"You Lunched no. 3");
					sprintf(l, "%c",bullet_random[2]);
					outtextxy(9+(2*68)+z, 428-i, l);
					x[2] = 1;
					backScreen(d, bullet_random,x,z);
					target_position[6] = target_move(target_position);

					transperant[6] = target(target_position, transperant);
					bullets_number(bullet_random,z);
					/////// rectangle /////
				    //	setfillstyle(XHATCH_FILL, BLUE);
				    //	rectangle(0+(2*68), 440-i, 22+(2*68), 476-i);
				   //	floodfill(1, 441-i, WHITE);

					////// triengle /////

				   //	setfillstyle(XHATCH_FILL, RED);
					line(0+(2*68)+z, 440-i, 11+(2*68)+z,415-i);
					line(11+(2*68)+z, 415-i, 22+(2*68)+z, 440-i);
					line(0+(2*68)+z, 440-i, 22+(2*68)+z, 440-i);
				   //	floodfill(11, 430-i, WHITE);
					delay(20);
					p = 415 - i;
					q = 11+(2*68) + z;
					c = touch(target_position,p,q);
					s = score(s, c);
					if(c == 1 || c == 2 || c == 3)
					{
						break;
					}
				}
			}
			else
			{
				setcolor(RED);
				outtextxy(140, 310, "YOU HAD ONLY ONE CHANCE TO LAUNCH NO.3 BULLET");
			    //	setcolor(WHITE);
			}
		}
		if(d == bullet_random[3])   // 4
		{
			if(x[3] == 0)
			{
				for( i = 0; i < 420; i += 5)
				{
					clearviewport();
					outtextxy(250,160,"You Lunched no. 4");
					sprintf(l, "%c",bullet_random[3]);
					outtextxy(9+(3*68)+z, 428-i, l);
					x[3] = 1;
					backScreen(d, bullet_random,x,z);
					target_position[6] = target_move(target_position);

					transperant[6] = target(target_position, transperant);
					bullets_number(bullet_random,z);
					/////// rectangle /////
				    //	setfillstyle(XHATCH_FILL, BLUE);
				    //	rectangle(0+(3*68), 440-i, 22+(3*68), 476-i);
				   //	floodfill(1, 441-i, WHITE);

					////// triengle /////

				   //	setfillstyle(XHATCH_FILL, RED);
					line(0+(3*68)+z, 440-i, 11+(3*68)+z,415-i);
					line(11+(3*68)+z, 415-i, 22+(3*68)+z, 440-i);
					line(0+(3*68)+z, 440-i, 22+(3*68)+z, 440-i);
				   //	floodfill(11, 430-i, WHITE);
					delay(20);
					p = 415 - i;
					q = 11+(3*68) + z;
					c = touch(target_position,p,q);
					s = score(s, c);
					if(c == 1 || c == 2 || c == 3)
					{
						break;
					}
				}
			}
			else
			{
				setcolor(RED);
				outtextxy(140, 310, "YOU HAD ONLY ONE CHANCE TO LAUNCH NO.4 BULLET");
			    //	setcolor(WHITE);
			}
		}
		if(d == bullet_random[4])   // 5
		{
			if(x[4] == 0)
			{
				for( i = 0; i < 420; i += 5)
				{
					clearviewport();
					outtextxy(250,160,"You Lunched no. 5");
					sprintf(l, "%c",bullet_random[4]);
					outtextxy(9+(4*68)+z, 428-i, l);
					x[4] = 1;
					backScreen(d, bullet_random,x,z);
					target_position[6] = target_move(target_position);

					transperant[6] = target(target_position, transperant);
					bullets_number(bullet_random,z);
					/////// rectangle /////
				    //	setfillstyle(XHATCH_FILL, BLUE);
				    //	rectangle(0+(4*68), 440-i, 22+(4*68), 476-i);
				   //	floodfill(1, 441-i, WHITE);

					////// triengle /////

				   //	setfillstyle(XHATCH_FILL, RED);
					line(0+(4*68)+z, 440-i, 11+(4*68)+z,415-i);
					line(11+(4*68)+z, 415-i, 22+(4*68)+z, 440-i);
					line(0+(4*68)+z, 440-i, 22+(4*68)+z, 440-i);
				   //	floodfill(11, 430-i, WHITE);
					delay(20);
					p = 415 - i;
					q = 11+(4*68) + z;
					c = touch(target_position,p,q);
					s = score(s, c);
					if(c == 1 || c == 2 || c == 3)
					{
						break;
					}
				}
			}
			else
			{
				setcolor(RED);
				outtextxy(140, 310, "YOU HAD ONLY ONE CHANCE TO LAUNCH NO.5 BULLET");
			    //	setcolor(WHITE);
			}
		}
		if(d == bullet_random[5])   // 6
		{
			if(x[5] == 0)
			{
				for( i = 0; i < 420; i += 5)
				{
					clearviewport();
					outtextxy(250,160,"You Lunched no. 6");
					sprintf(l, "%c",bullet_random[5]);
					outtextxy(9+(5*68)+z, 428-i, l);
					x[5] = 1;
					backScreen(d, bullet_random,x,z);
					target_position[6] = target_move(target_position);

					transperant[6] = target(target_position, transperant);
					bullets_number(bullet_random,z);
					/////// rectangle /////
				    //	setfillstyle(XHATCH_FILL, BLUE);
				   //	rectangle(0+(5*68), 440-i, 22+(5*68), 476-i);
				   //	floodfill(1, 441-i, WHITE);

					////// triengle /////

				   //	setfillstyle(XHATCH_FILL, RED);
					line(0+(5*68)+z, 440-i, 11+(5*68)+z,415-i);
					line(11+(5*68)+z, 415-i, 22+(5*68)+z, 440-i);
					line(0+(5*68)+z, 440-i, 22+(5*68)+z, 440-i);
				   //	floodfill(11, 430-i, WHITE);
					delay(20);
					p = 415 - i;
					q = 11+(5*68) + z;
					c = touch(target_position,p,q);
					s = score(s, c);
					if(c == 1 || c == 2 || c == 3)
					{
						break;
					}
				}
			}
			else
			{
				setcolor(RED);
				outtextxy(140, 310, "YOU HAD ONLY ONE CHANCE TO LAUNCH NO.6 BULLET");
			    //	setcolor(WHITE);
			}
		}
		if(d == bullet_random[6])   // 7
		{
			if(x[6] == 0)
			{
				for( i = 0; i < 420; i += 5)
				{
					clearviewport();
					outtextxy(250,160,"You Lunched no. 7");
					sprintf(l, "%c",bullet_random[6]);
					outtextxy(9+(6*68)+z, 428-i, l);
					x[6] = 1;
					backScreen(d, bullet_random,x,z);
					target_position[6] = target_move(target_position);

					transperant[6] = target(target_position, transperant);
					bullets_number(bullet_random,z);
					/////// rectangle /////
				    //	setfillstyle(XHATCH_FILL, BLUE);
				    //	rectangle(0+(6*68), 440-i, 22+(6*68), 476-i);
				   //	floodfill(1, 441-i, WHITE);

					////// triengle /////

				   //	setfillstyle(XHATCH_FILL, RED);
					line(0+(6*68)+z, 440-i, 11+(6*68)+z,415-i);
					line(11+(6*68)+z, 415-i, 22+(6*68)+z, 440-i);
					line(0+(6*68)+z, 440-i, 22+(6*68)+z, 440-i);
				   //	floodfill(11, 430-i, WHITE);
					delay(20);p = 415 - i;
					q = 11+(6*68) + z;
					c = touch(target_position,p,q);
					s = score(s, c);
					if(c == 1 || c == 2 || c == 3)
					{
						break;
					}
				}
			}
			else
			{
				setcolor(RED);
				outtextxy(140, 310, "YOU HAD ONLY ONE CHANCE TO LAUNCH NO.7 BULLET");
			    //	setcolor(WHITE);
			}
		}
		if(d == bullet_random[7])   // 8
		{
			if(x[7] == 0)
			{
				for( i = 0; i < 420; i += 5)
				{
					clearviewport();
					outtextxy(250,160,"You Lunched no. 8");
					sprintf(l, "%c",bullet_random[7]);
					outtextxy(9+(7*68)+z, 428-i, l);
					x[7] = 1;
					backScreen(d, bullet_random,x,z);
					target_position[6] = target_move(target_position);

					transperant[6] = target(target_position, transperant);
					bullets_number(bullet_random,z);
					/////// rectangle /////
				    //	setfillstyle(XHATCH_FILL, BLUE);
				    //	rectangle(0+(7*68), 440-i, 22+(7*68), 476-i);
				   //	floodfill(1, 441-i, WHITE);

					////// triengle /////

				   //	setfillstyle(XHATCH_FILL, RED);
					line(0+(7*68)+z, 440-i, 11+(7*68)+z,415-i);
					line(11+(7*68)+z, 415-i, 22+(7*68)+z, 440-i);
					line(0+(7*68)+z, 440-i, 22+(7*68)+z, 440-i);
				   //	floodfill(11, 430-i, WHITE);
					delay(20);
					p = 415 - i;
					q = 11+(7*68) + z;
					c = touch(target_position,p,q);
					s = score(s, c);
					if(c == 1 || c == 2 || c == 3)
					{
						break;
					}
				}
			}
			else
			{
				setcolor(RED);
				outtextxy(140, 310, "YOU HAD ONLY ONE CHANCE TO LAUNCH NO.8 BULLET");
			    //	setcolor(WHITE);
			}
		}
		if(d == bullet_random[8])   // 9
		{
			if(x[8] == 0)
			{
				for( i = 0; i < 420; i += 5)
				{
					clearviewport();
					outtextxy(250,160,"You Lunched no. 9");
					sprintf(l, "%c",bullet_random[8]);
					outtextxy(9+(8*68)+z, 428-i, l);
					x[8] = 1;
					backScreen(d, bullet_random,x,z);
					target_position[6] = target_move(target_position);

					transperant[6] = target(target_position, transperant);
					bullets_number(bullet_random,z);
					/////// rectangle /////
				    //	setfillstyle(XHATCH_FILL, BLUE);
				    //	rectangle(0+(8*68), 440-i, 22+(8*68), 476-i);
				   //	floodfill(1, 441-i, WHITE);

					////// triengle /////

				   //	setfillstyle(XHATCH_FILL, RED);
					line(0+(8*68)+z, 440-i, 11+(8*68)+z,415-i);
					line(11+(8*68)+z, 415-i, 22+(8*68)+z, 440-i);
					line(0+(8*68)+z, 440-i, 22+(8*68)+z, 440-i);
				   //	floodfill(11, 430-i, WHITE);
					delay(20);
					p = 415 - i;
					q = 11+(8*68) + z;
					c = touch(target_position,p,q);
					s = score(s, c);
					if(c == 1 || c == 2 || c == 3)
					{
						break;
					}
				}
			}
			else
			{
				setcolor(RED);
				outtextxy(140, 310, "YOU HAD ONLY ONE CHANCE TO LAUNCH NO.9 BULLET");
			    //	setcolor(WHITE);
			}
		}
		if(d == bullet_random[9])   // 0
		{
			if(x[9] == 0)
			{
				for( i = 0; i < 420; i += 5)
				{
					clearviewport();
					outtextxy(250,160,"You Lunched no. 10");
					sprintf(l, "%c",bullet_random[9]);
					outtextxy(9+(9*68)+z, 428-i, l);
					x[9] = 1;
					backScreen(d,bullet_random,x,z);
					target_position[6] = target_move(target_position);

					transperant[6] = target(target_position, transperant);
					bullets_number(bullet_random,z);
					/////// rectangle /////
				    //	setfillstyle(XHATCH_FILL, BLUE);
				//	rectangle(0+(9*68), 440-i, 22+(9*68), 476-i);
				   //	floodfill(1, 441-i, WHITE);

					////// triengle /////

				   //	setfillstyle(XHATCH_FILL, RED);
					line(0+(9*68)+z, 440-i, 11+(9*68)+z,415-i);
					line(11+(9*68)+z, 415-i, 22+(9*68)+z, 440-i);
					line(0+(9*68)+z, 440-i, 22+(9*68)+z, 440-i);
				   //	floodfill(11, 430-i, WHITE);
					delay(20);
					p = 415 - i;
					q = 11+(9*68) + z;
					c = touch(target_position,p,q);
					s = score(s, c);
					if(c == 1 || c == 2 || c == 3)
					{
						break;
					}
				}
			}
			else
			{
				setcolor(RED);
				outtextxy(140, 310, "YOU HAD ONLY ONE CHANCE TO LAUNCH NO.10 BULLET");
			    //	setcolor(WHITE);
			}
		}
		if(d == 49)  // no.1 key
		{
			z -= 8;

			clearviewport();
			outtextxy(150,290,"Left Move");
			backScreen(d, bullet_random,x,z);

			transperant[6] = target(target_position, transperant);
			bullets_number(bullet_random,z);
		}
		if(d == 48)  // no.0 key
		{
			z += 8;

			clearviewport();
			outtextxy(350,290,"Right Move");
			backScreen(d, bullet_random,x,z);

			transperant[6] = target(target_position, transperant);
			bullets_number(bullet_random,z);
		}

		if(d ==  27)   // ESC
		{
			return 0;
		}
	   //	if(d != bullet_random[10])
	   //	{
	//		printf("Please enter the right alphabet");
	   //	}
		sprintf(l, "SCORE = %d",s);
		outtextxy(282, 190, l);

		transperant[0] = transperant[3];
		transperant[1] = transperant[4];
		transperant[2] = transperant[5];
		transperant[6] = target(target_position, transperant);
	}

   closegraph();
   getch();
   return 0;
}

void backScreen(int d, int bullet_random[10], int x[10], int z)
{
	   ///////////////////////////  Gun   ////////////////////////

	 int xmax,ymax,target;
	 int i = 0, j = 0;

	 xmax = getmaxx();
	 ymax = getmaxy();

	 if(d == bullet_random[0])
	 {
		 for(i = 0;i < xmax; i += 68,j++)
		 {
			/////// rectangle /////
		     //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i+z, 440, 22+i+z, 476);
		     //	floodfill(1+i, 441, WHITE);

			////// triengle /////
			if(x[j] == 0)
			{
			    //	setfillstyle(XHATCH_FILL, RED);
				line(i+z, 440, 11+i+z,415);
				line(11+i+z, 415, 22+i+z, 440);
				line(i+z, 440, 22+i+z, 440);
			 //	floodfill(11+i, 430, WHITE);
			}
		 }
	 }
	 j = 0;
	 if(d == bullet_random[1])
	 {
		 for(i = 0;i < xmax; i += 68,j++)
		 {
			/////// rectangle /////
		    //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i+z, 440, 22+i+z, 476);
		    //	floodfill(1+i, 441, WHITE);

			////// triengle /////
			if(x[j] == 0)
			{
			     //	setfillstyle(XHATCH_FILL, RED);
				line(i+z, 440, 11+i+z,415);
				line(11+i+z, 415, 22+i+z, 440);
				line(i+z, 440, 22+i+z, 440);

				//	floodfill(11+i, 430, WHITE);
			}
		 }
	 }
	 j = 0;
	 if(d == bullet_random[2])
	 {
		 for(i = 0;i < xmax; i += 68,j++)
		 {
			/////// rectangle /////
		     //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i+z, 440, 22+i+z, 476);
		     //	floodfill(1+i, 441, WHITE);

			////// triengle /////

			if(x[j] == 0)
			{
			     //	setfillstyle(XHATCH_FILL, RED);
				line(i+z, 440, 11+i+z,415);
				line(11+i+z, 415, 22+i+z, 440);
				line(i+z, 440, 22+i+z, 440);
			    //	floodfill(11+i, 430, WHITE);
			}
		 }
	 }
	 j = 0;
	 if(d == bullet_random[3])
	 {
		 for(i = 0;i < xmax; i += 68,j++)
		 {
			/////// rectangle /////
		     //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i+z, 440, 22+i+z, 476);
		     //	floodfill(1+i, 441, WHITE);

			////// triengle /////

			if(x[j] == 0)
			{
			//	setfillstyle(XHATCH_FILL, RED);
				line(i+z, 440, 11+i+z,415);
				line(11+i+z, 415, 22+i+z, 440);
				line(i+z, 440, 22+i+z, 440);
			    //	floodfill(11+i, 430, WHITE);
			}
		 }
	 }
	 j = 0;
	 if(d == bullet_random[4])
	 {
		 for(i = 0;i < xmax; i += 68,j++)
		 {
			/////// rectangle /////
		    //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i+z, 440, 22+i+z, 476);
		    //	floodfill(1+i, 441, WHITE);

			////// triengle /////

			if(x[j] == 0)
			{
			     //	setfillstyle(XHATCH_FILL, RED);
				line(i+z, 440, 11+i+z,415);
				line(11+i+z, 415, 22+i+z, 440);
				line(i+z, 440, 22+i+z, 440);
			    //	floodfill(11+i, 430, WHITE);
			}
		 }
	 }
	 j = 0;
	 if(d == bullet_random[5])
	 {
		 for(i = 0;i < xmax; i += 68,j++)
		 {
			/////// rectangle /////
		   //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i+z, 440, 22+i+z, 476);
		   //	floodfill(1+i, 441, WHITE);

			////// triengle /////

			if(x[j] == 0)
			{
			     //	setfillstyle(XHATCH_FILL, RED);
				line(i+z, 440, 11+i+z,415);
				line(11+i+z, 415, 22+i+z, 440);
				line(i+z, 440, 22+i+z, 440);
			    //	floodfill(11+i, 430, WHITE);
			}
		 }
	 }
	 j = 0;
	 if(d == bullet_random[6])
	 {
		 for(i = 0;i < xmax; i += 68,j++)
		 {
			/////// rectangle /////
		   //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i+z, 440, 22+i+z, 476);
		   //	floodfill(1+i, 441, WHITE);

			////// triengle /////

			if(x[j] == 0)
			{
			     //	setfillstyle(XHATCH_FILL, RED);
				line(i+z, 440, 11+i+z,415);
				line(11+i+z, 415, 22+i+z, 440);
				line(i+z, 440, 22+i+z, 440);
			    //	floodfill(11+i, 430, WHITE);
			}
		 }
	 }
	 j = 0;
	 if(d == bullet_random[7])
	 {
		 for(i = 0;i < xmax; i += 68,j++)
		 {
			/////// rectangle /////
		  //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i+z, 440, 22+i+z, 476);
		  //	floodfill(1+i, 441, WHITE);

			////// triengle /////

			if(x[j] == 0)
			{
			     //	setfillstyle(XHATCH_FILL, RED);
				line(i+z, 440, 11+i+z,415);
				line(11+i+z, 415, 22+i+z, 440);
				line(i+z, 440, 22+i+z, 440);
			    //	floodfill(11+i, 430, WHITE);
			}
		 }
	 }
	 j = 0;
	 if(d == bullet_random[8])
	 {
		 for(i = 0;i < xmax; i += 68,j++)
		 {
			/////// rectangle /////
		  //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i+z, 440, 22+i+z, 476);
		   //	floodfill(1+i, 441, WHITE);

			////// triengle /////

			if(x[j] == 0)
			{
			     //	setfillstyle(XHATCH_FILL, RED);
				line(i+z, 440, 11+i+z,415);
				line(11+i+z, 415, 22+i+z, 440);
				line(i+z, 440, 22+i+z, 440);
			    //	floodfill(11+i, 430, WHITE);
			}
		 }
	 }
	 j = 0;
	 if(d == bullet_random[9])
	 {
		 for(i = 0;i < xmax; i += 68,j++)
		 {
			/////// rectangle /////
		  //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i+z, 440, 22+i+z, 476);
		   //	floodfill(1+i, 441, WHITE);

			////// triengle /////
			if(x[j] == 0)
			{
			     //	setfillstyle(XHATCH_FILL, RED);
				line(i+z, 440, 11+i+z,415);
				line(11+i+z, 415, 22+i+z, 440);
				line(i+z, 440, 22+i+z, 440);
			    //	floodfill(11+i, 430, WHITE);
			}
		 }
	 }
	 j = 0;
	 if(d == 48 || d == 49)
	 {
		for(i = 0; i < xmax; i += 68,j++)
		 {
			/////// rectangle /////
		  //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i+z, 440, 22+i+z, 476);
		   //	floodfill(1+i, 441, WHITE);

			////// triengle /////
			if(x[j] == 0)
			{
				 //	setfillstyle(XHATCH_FILL, RED);
				line(i+z, 440, 11+i+z,415);
				line(11+i+z, 415, 22+i+z, 440);
				line(i+z, 440, 22+i+z, 440);
			    //	floodfill(11+i, 430, WHITE);
			}

		 }
	 }
	 j = 0;

	//////////////////////  Bottom Line  /////////////////////

	setcolor(RED);
	line(0, ymax, xmax/3, ymax);
	line(0, ymax-1, xmax/3, ymax-1);
	line(0, ymax-2, xmax/3, ymax-2);
	setcolor(GREEN);
	line(xmax/3, ymax, 2*(xmax/3), ymax);
	line(xmax/3, ymax-1, 2*(xmax/3), ymax-1);
	line(xmax/3, ymax-2, 2*(xmax/3), ymax-2);
	setcolor(BLUE);
	line(2*(xmax/3), ymax, xmax, ymax);
	line(2*(xmax/3), ymax-1, xmax-1, ymax-1);
	line(2*(xmax/3), ymax-2, xmax-1, ymax-1);
	setcolor(WHITE);

	////////////////////// Random Colorful Dots /////////////

	random_pixel(100);

}

   //////////////////// Target ( default 3) /////////////////////

int target_move(int target_position[6])
{
	//target_position[3] is taken for refference in target no. 1
	//target_position[4] is taken for refference in target no. 2
	//target_position[5] is taken for refference in target no. 3
	if(target_position[0])
	{
		if(target_position[3] == 0)
		{
			target_position[0] += 8;
			if(target_position[0] > 565 && target_position[0] < 575)
			{
				target_position[3] = 1;
			}
		}
		else
		{
			target_position[0] -= 8;
			if(target_position[0] > 0 && target_position[0] < 10)
			{
				target_position[3] = 0;
			}
		}
	}
	if(target_position[1])
	{
		if(target_position[4] == 0)
		{
			target_position[1] += 6;
			if(target_position[1] > 565 && target_position[1] < 575)
			{
				target_position[4] = 1;
			}
		}
		else
		{
			target_position[1] -= 6;
			if(target_position[1] > 0 && target_position[1] < 10)
			{
				target_position[4] = 0;
			}
		}
	}
	if(target_position[2])
	{
		if(target_position[5] == 0)
		{
			target_position[2] += 4;
			if(target_position[2] > 565 && target_position[2] < 575)
			{
				target_position[5] = 1;
			}
		}
		else
		{
			target_position[2] -= 4;
			if(target_position[2] > 0 && target_position[2] < 10)
			{
				target_position[5] = 0;
			}
		}
	}

	return(target_position[6]);
}

int target(int target_position[6], int transperant[6])
  //////   default 3   //////  3 transperant value for 3 different target
{
    int j = random(16);
    int i = 0, k = 0;
    char target_no1[] = "1";
    char target_no2[] = "2";
    char target_no3[] = "3";

    if(j == 0 || j == 14 || j == 15)   // for ignor black color
    {
	j = 1;
    }
    for(i = 0; i <= 60; i += 30,j++,k++)
    {
	if(transperant[k] <= (2 * transperant[k+3]))
	{
		setcolor(j);
		rectangle(target_position[k], i, target_position[k]+67, 10+i);
		if(k == 0)
		{
			outtextxy(target_position[k]+33, i+2, target_no1);
		}
		if(k == 1)
		{
			outtextxy(target_position[k]+33, i+2, target_no2);
		}
		if(k == 2)
		{
			outtextxy(target_position[k]+33, i+2, target_no3);
		}
		transperant[k]++;
	}
	else
	{
		if(transperant[k] == (3 * transperant[k+3]))
		{
			transperant[k] = transperant[k+3];
		}
		transperant[k]++;
	}
    }
    return transperant[6];
}

void random_pixel(int pixel)
{
	int n = 0, xmax, ymax;
	xmax = getmaxx();
	ymax = getmaxy();
	while(n < pixel)
	{
		putpixel(random(xmax), random(ymax), random(15));
		n++;
	}
}

 //////////////////   when touch target  //////////////

int touch(int target_position[6],int p,int q)
{
	// target line ty = 0 ,30 , 60
	// tx = target_position [0], [1], [2]
	int tx1, tx2, tx3, ty1, ty2, ty3;
	tx1 = target_position[0];
	tx2 = target_position[1];
	tx3 = target_position[2];
	ty1 = 10;
	ty2 = 40;
	ty3 = 70;

	if(ty3 == p)
	{
		if(tx3 < q && q < tx3+68)
		{
			settextstyle(TRIPLEX_FONT, HORIZ_DIR, GREEN);
			outtextxy(265, 220, "You Touched 3");
			return 3;
		}
	}
	if(ty2 == p)
	{
		if(tx2 < q && q < tx2+68)
		{
			settextstyle(TRIPLEX_FONT, HORIZ_DIR, GREEN);
			outtextxy(265, 220, "You Touched 2");
			return 2;
		}
	}
	if(ty1 == p)
	{
		if(tx1 < q && q < tx1+68)
		{
			settextstyle(TRIPLEX_FONT, HORIZ_DIR, GREEN);
			outtextxy(265, 220, "You Touched 1");
			return 1;
		}
	}
	return 0;
}

void bullets_number(int bullet_random[10], int z) // z for right left move
{

	char c[1];
	sprintf(c, "%c",bullet_random[0]);
     //	store [0] as string in c,so we can use in outtextxy without any error
	outtextxy(8+z, 449, c);  // 8 taken for adjectment instead of 9
	sprintf(c, "%c",bullet_random[1]);
	outtextxy(8+(68)+z, 449, c);
	sprintf(c, "%c",bullet_random[2]);
	outtextxy(8+(2*68)+z, 449, c);
	sprintf(c, "%c",bullet_random[3]);
	outtextxy(8+(3*68)+z, 449, c);
	sprintf(c, "%c",bullet_random[4]);
	outtextxy(8+(4*68)+z, 449, c);
	sprintf(c, "%c",bullet_random[5]);
	outtextxy(8+(5*68)+z, 449, c);
	sprintf(c, "%c",bullet_random[6]);
	outtextxy(8+(6*68)+z, 449, c);
	sprintf(c, "%c",bullet_random[7]);
	outtextxy(8+(7*68)+z, 449, c);
	sprintf(c, "%c",bullet_random[8]);
	outtextxy(8+(8*68)+z, 449, c);
	sprintf(c, "%c",bullet_random[9]);
	outtextxy(8+(9*68)+z, 449, c);
}

int score(int s, int c)
{
 //	char s1[1];
	if(c == 1)
	{
		s += 5;
	}
	if(c == 2)
	{
		s += 3;
	}
	if(c == 3)
	{
		s += 1;
	}
	return s;
}