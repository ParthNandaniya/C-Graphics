#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<dos.h>

void target(int target_position[6]);
void backScreen(int d, int bullet_random[10]);
void random_pixel(int pixel);
int touch(int targetposition[6],int p,int q);
void bullets_number(int bullet_random[10]);
int target_move(int target_position[6]);
int score(int s, int c);

int main()
{
	randomize();
	int gd = DETECT, gm;
	int xmax;
	int d, i = 0, no, target_no;
	int target_position[6], bullet_random[10];

	char ch, l[1];
	int p, q, c, s = 0;

	initgraph(&gd, &gm, "C:\\TC\\BGI");
	xmax = getmaxx();

	/////// Game Instruction  ///////////

	setcolor(3);
	outtextxy(215, 130,"THE GREAT GUEESSING GAME");
	setcolor(WHITE);
	outtextxy(125, 160, "** Use Provided Character to launch bullets **");
	setcolor(6);
	outtextxy(65, 190, "if your bullet touched .. }no 1. then SCORE will increment by 5");
	outtextxy(273, 210, "}no 2. then SCORE will increment by 2");
	outtextxy(273, 230, "}no 3. then SCORE will increment by 1");
	setcolor(GREEN);
	outtextxy(275, 270, "GOOD LUCK");
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
		bullet_random[i] = ( 97+random(27) );
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
				bullet_random[j] = ( 97+random(27) );
			}
		}
	}

	bullets_number(bullet_random);

	///////////   bullets    /////////////

	for(i = 0; i < xmax; i += 68)
	{
		/////// rectangle /////
		setfillstyle(XHATCH_FILL, BLUE);
		rectangle(i, 440, 22+i, 475);
		floodfill(11+i, 457, WHITE);


		////// triengle /////
		setfillstyle(XHATCH_FILL, RED);
		line(i, 440, 11+i,415);
		line(11+i, 415, 22+i, 440);
		line(i, 440, 22+i, 440);
		floodfill(11+i, 430, WHITE);
	}

    //////////////////////  Bottom Line  /////////////////////

    setcolor(RED);
    line(0, 478, xmax, 478);
    line(0, 477, xmax, 477);
    line(0, 476, xmax, 476);
    setcolor(WHITE);

    ////////////////////// Random Colorful Dots /////////////

    random_pixel(100);

    ///////////////  Call target   //////////////////

    target(target_position);

    ///////////////  Move  //////////////


	while(1)
	{
		ch = getch();
		d = ch;
		if(d == bullet_random[0])   // 1
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 1");
				sprintf(l, "%c",bullet_random[0]);
				outtextxy(9, 428-i, l);

				backScreen(d, bullet_random);
				target_position[6] = target_move(target_position);

				target(target_position);
				bullets_number(bullet_random);
			  //	targetMove(d, target_position);
				/////// rectangle /////
			     //	setfillstyle(XHATCH_FILL, BLUE);

				rectangle(0, 440-i, 22, 476-i);
			     //	floodfill(1, 441-i, WHITE);

				////// triengle /////
			   //	setfillstyle(XHATCH_FILL, RED);
				line(0, 440-i, 11,415-i);
				line(11, 415-i, 22, 440-i);
				line(0, 440-i, 22, 440-i);
			  //	floodfill(11, 430-i, WHITE);
				delay(20);
				p = 415 - i;
				q = 11;
				c = touch(target_position,p,q);
				s = score(s, c);
				if(c == 1 || c == 2 || c == 3)
				{
					break;
				}
			}
			sprintf(l, "SCORE = %d",s);
			outtextxy(282, 190, l);
		}
		if(d == bullet_random[1])   // 2
		{
			for(i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 2");
				sprintf(l, "%c",bullet_random[1]);
				outtextxy(9+(68), 428-i, l);
				backScreen(d, bullet_random);
				target_position[6] = target_move(target_position);

				target(target_position);
				bullets_number(bullet_random);
				/////// rectangle /////
			    //	setfillstyle(XHATCH_FILL, BLUE);
				rectangle(0+(68), 440-i, 22+(68), 476-i);
			   //	floodfill(1, 441-i, WHITE);

				////// triengle /////

			   //	setfillstyle(XHATCH_FILL, RED);
				line(0+(68), 440-i, 11+(68),415-i);
				line(11+(68), 415-i, 22+(68), 440-i);
				line(0+(68), 440-i, 22+(68), 440-i);
			   //	floodfill(11, 430-i, WHITE);
				delay(20);
				p = 415 - i;
				q = 11+(68);
				c = touch(target_position,p,q);
				s = score(s, c);
				if(c == 1 || c == 2 || c == 3)
				{
					break;
				}
			}
			sprintf(l, "SCORE = %d",s);
			outtextxy(282, 190, l);
		}
		if(d == bullet_random[2])   // 3
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 3");
				sprintf(l, "%c",bullet_random[2]);
				outtextxy(9+(2*68), 428-i, l);
				backScreen(d, bullet_random);
				target_position[6] = target_move(target_position);

				target(target_position);
				bullets_number(bullet_random);
				/////// rectangle /////
			    //	setfillstyle(XHATCH_FILL, BLUE);
				rectangle(0+(2*68), 440-i, 22+(2*68), 476-i);
			   //	floodfill(1, 441-i, WHITE);

				////// triengle /////

			   //	setfillstyle(XHATCH_FILL, RED);
				line(0+(2*68), 440-i, 11+(2*68),415-i);
				line(11+(2*68), 415-i, 22+(2*68), 440-i);
				line(0+(2*68), 440-i, 22+(2*68), 440-i);
			   //	floodfill(11, 430-i, WHITE);
				delay(20);
				p = 415 - i;
				q = 11+(2*68);
				c = touch(target_position,p,q);
				s = score(s, c);
				if(c == 1 || c == 2 || c == 3)
				{
					break;
				}
			}
			sprintf(l, "SCORE = %d",s);
			outtextxy(282, 190, l);
		}
		if(d == bullet_random[3])   // 4
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 4");
				sprintf(l, "%c",bullet_random[3]);
				outtextxy(9+(3*68), 428-i, l);
				backScreen(d, bullet_random);
				target_position[6] = target_move(target_position);

				target(target_position);
				bullets_number(bullet_random);
				/////// rectangle /////
			    //	setfillstyle(XHATCH_FILL, BLUE);
				rectangle(0+(3*68), 440-i, 22+(3*68), 476-i);
			   //	floodfill(1, 441-i, WHITE);

				////// triengle /////

			   //	setfillstyle(XHATCH_FILL, RED);
				line(0+(3*68), 440-i, 11+(3*68),415-i);
				line(11+(3*68), 415-i, 22+(3*68), 440-i);
				line(0+(3*68), 440-i, 22+(3*68), 440-i);
			   //	floodfill(11, 430-i, WHITE);
				delay(20);
				p = 415 - i;
				q = 11+(3*68);
				c = touch(target_position,p,q);
				s = score(s, c);
				if(c == 1 || c == 2 || c == 3)
				{
					break;
				}
			}
			sprintf(l, "SCORE = %d",s);
			outtextxy(282, 190, l);
		}
		if(d == bullet_random[4])   // 5
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 5");
				sprintf(l, "%c",bullet_random[4]);
				outtextxy(9+(4*68), 428-i, l);
				backScreen(d, bullet_random);
				target_position[6] = target_move(target_position);

				target(target_position);
				bullets_number(bullet_random);
				/////// rectangle /////
			    //	setfillstyle(XHATCH_FILL, BLUE);
				rectangle(0+(4*68), 440-i, 22+(4*68), 476-i);
			   //	floodfill(1, 441-i, WHITE);

				////// triengle /////

			   //	setfillstyle(XHATCH_FILL, RED);
				line(0+(4*68), 440-i, 11+(4*68),415-i);
				line(11+(4*68), 415-i, 22+(4*68), 440-i);
				line(0+(4*68), 440-i, 22+(4*68), 440-i);
			   //	floodfill(11, 430-i, WHITE);
				delay(20);
				p = 415 - i;
				q = 11+(4*68);
				c = touch(target_position,p,q);
				s = score(s, c);
				if(c == 1 || c == 2 || c == 3)
				{
					break;
				}
			}
			sprintf(l, "SCORE = %d",s);
			outtextxy(282, 190, l);
		}
		if(d == bullet_random[5])   // 6
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 6");
				sprintf(l, "%c",bullet_random[5]);
				outtextxy(9+(5*68), 428-i, l);
				backScreen(d, bullet_random);
				target_position[6] = target_move(target_position);

				target(target_position);
				bullets_number(bullet_random);
				/////// rectangle /////
			    //	setfillstyle(XHATCH_FILL, BLUE);
				rectangle(0+(5*68), 440-i, 22+(5*68), 476-i);
			   //	floodfill(1, 441-i, WHITE);

				////// triengle /////

			   //	setfillstyle(XHATCH_FILL, RED);
				line(0+(5*68), 440-i, 11+(5*68),415-i);
				line(11+(5*68), 415-i, 22+(5*68), 440-i);
				line(0+(5*68), 440-i, 22+(5*68), 440-i);
			   //	floodfill(11, 430-i, WHITE);
				delay(20);
				p = 415 - i;
				q = 11+(5*68);
				c = touch(target_position,p,q);
				s = score(s, c);
				if(c == 1 || c == 2 || c == 3)
				{
					break;
				}
			}
			sprintf(l, "SCORE = %d",s);
			outtextxy(282, 190, l);
		}
		if(d == bullet_random[6])   // 7
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 7");
				sprintf(l, "%c",bullet_random[6]);
				outtextxy(9+(6*68), 428-i, l);
				backScreen(d, bullet_random);
				target_position[6] = target_move(target_position);

				target(target_position);
				bullets_number(bullet_random);
				/////// rectangle /////
			    //	setfillstyle(XHATCH_FILL, BLUE);
				rectangle(0+(6*68), 440-i, 22+(6*68), 476-i);
			   //	floodfill(1, 441-i, WHITE);

				////// triengle /////

			   //	setfillstyle(XHATCH_FILL, RED);
				line(0+(6*68), 440-i, 11+(6*68),415-i);
				line(11+(6*68), 415-i, 22+(6*68), 440-i);
				line(0+(6*68), 440-i, 22+(6*68), 440-i);
			   //	floodfill(11, 430-i, WHITE);
				delay(20);p = 415 - i;
				q = 11+(6*68);
				c = touch(target_position,p,q);
				s = score(s, c);
				if(c == 1 || c == 2 || c == 3)
				{
					break;
				}
			}
			sprintf(l, "SCORE = %d",s);
			outtextxy(282, 190, l);
		}
		if(d == bullet_random[7])   // 8
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 8");
				sprintf(l, "%c",bullet_random[7]);
				outtextxy(9+(7*68), 428-i, l);
				backScreen(d, bullet_random);
				target_position[6] = target_move(target_position);

				target(target_position);
				bullets_number(bullet_random);
				/////// rectangle /////
			    //	setfillstyle(XHATCH_FILL, BLUE);
				rectangle(0+(7*68), 440-i, 22+(7*68), 476-i);
			   //	floodfill(1, 441-i, WHITE);

				////// triengle /////

			   //	setfillstyle(XHATCH_FILL, RED);
				line(0+(7*68), 440-i, 11+(7*68),415-i);
				line(11+(7*68), 415-i, 22+(7*68), 440-i);
				line(0+(7*68), 440-i, 22+(7*68), 440-i);
			   //	floodfill(11, 430-i, WHITE);
				delay(20);
				p = 415 - i;
				q = 11+(7*68);
				c = touch(target_position,p,q);
				s = score(s, c);
				if(c == 1 || c == 2 || c == 3)
				{
					break;
				}
			}
			sprintf(l, "SCORE = %d",s);
			outtextxy(282, 190, l);
		}
		if(d == bullet_random[8])   // 9
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 9");
				sprintf(l, "%c",bullet_random[8]);
				outtextxy(9+(8*68), 428-i, l);
				backScreen(d, bullet_random);
				target_position[6] = target_move(target_position);

				target(target_position);
				bullets_number(bullet_random);
				/////// rectangle /////
			    //	setfillstyle(XHATCH_FILL, BLUE);
				rectangle(0+(8*68), 440-i, 22+(8*68), 476-i);
			   //	floodfill(1, 441-i, WHITE);

				////// triengle /////

			   //	setfillstyle(XHATCH_FILL, RED);
				line(0+(8*68), 440-i, 11+(8*68),415-i);
				line(11+(8*68), 415-i, 22+(8*68), 440-i);
				line(0+(8*68), 440-i, 22+(8*68), 440-i);
			   //	floodfill(11, 430-i, WHITE);
				delay(20);
				p = 415 - i;
				q = 11+(8*68);
				c = touch(target_position,p,q);
				s = score(s, c);
				if(c == 1 || c == 2 || c == 3)
				{
					break;
				}
			}
			sprintf(l, "SCORE = %d",s);
			outtextxy(282, 190, l);
		}
		if(d == bullet_random[9])   // 0
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 0");
				sprintf(l, "%c",bullet_random[9]);
				outtextxy(9+(9*68), 428-i, l);
				backScreen(d,bullet_random);
				target_position[6] = target_move(target_position);

				target(target_position);
				bullets_number(bullet_random);
				/////// rectangle /////
			    //	setfillstyle(XHATCH_FILL, BLUE);
				rectangle(0+(9*68), 440-i, 22+(9*68), 476-i);
			   //	floodfill(1, 441-i, WHITE);

				////// triengle /////

			   //	setfillstyle(XHATCH_FILL, RED);
				line(0+(9*68), 440-i, 11+(9*68),415-i);
				line(11+(9*68), 415-i, 22+(9*68), 440-i);
				line(0+(9*68), 440-i, 22+(9*68), 440-i);
			   //	floodfill(11, 430-i, WHITE);
				delay(20);
				p = 415 - i;
				q = 11+(9*68);
				c = touch(target_position,p,q);
				s = score(s, c);
				if(c == 1 || c == 2 || c == 3)
				{
					break;
				}
			}
			sprintf(l, "SCORE = %d",s);
			outtextxy(282, 190, l);
		}
		if(d ==  27)   // ESC
		{
			return 0;
		}
	   //	if(d != bullet_random[10])
	   //	{
	//		printf("Please enter the right alphabet");
	   //	}
	}

   closegraph();
   getch();
   return 0;
}

void backScreen(int d, int bullet_random[10])
   {
	   ///////////////////////////  Gun   ////////////////////////

	 int xmax,ymax,target;
	 int i = 0;

	 xmax = getmaxx();
	 ymax = getmaxy();

	 if(d == bullet_random[0])
	 {
		 for(i = 0;i < xmax; i += 68)
		 {
			if(i == 0)
			{
				continue;
			}
			/////// rectangle /////
		     //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i, 440, 22+i, 476);
		     //	floodfill(1+i, 441, WHITE);

			////// triengle /////

		     //	setfillstyle(XHATCH_FILL, RED);
			line(i, 440, 11+i,415);
			line(11+i, 415, 22+i, 440);
			line(i, 440, 22+i, 440);
		    //	floodfill(11+i, 430, WHITE);
		 }
	 }
	 if(d == bullet_random[1])
	 {
		 for(i = 0;i < xmax; i += 68)
		 {
			if(i == 68)
			{
				continue;
			}
			/////// rectangle /////
		    //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i, 440, 22+i, 476);
		    //	floodfill(1+i, 441, WHITE);

			////// triengle /////

		    //	setfillstyle(XHATCH_FILL, RED);
			line(i, 440, 11+i,415);
			line(11+i, 415, 22+i, 440);
			line(i, 440, 22+i, 440);
		    //	floodfill(11+i, 430, WHITE);
		 }
	 }
	 if(d == bullet_random[2])
	 {
		 for(i = 0;i < xmax; i += 68)
		 {
			if(i == (2*68))
			{
				continue;
			}
			/////// rectangle /////
		     //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i, 440, 22+i, 476);
		     //	floodfill(1+i, 441, WHITE);

			////// triengle /////

		    //	setfillstyle(XHATCH_FILL, RED);
			line(i, 440, 11+i,415);
			line(11+i, 415, 22+i, 440);
			line(i, 440, 22+i, 440);
		    //	floodfill(11+i, 430, WHITE);
		 }
	 }
	 if(d == bullet_random[3])
	 {
		 for(i = 0;i < xmax; i += 68)
		 {
			if(i == (3*68))
			{
				continue;
			}
			/////// rectangle /////
		     //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i, 440, 22+i, 476);
		     //	floodfill(1+i, 441, WHITE);

			////// triengle /////

		     //	setfillstyle(XHATCH_FILL, RED);
			line(i, 440, 11+i,415);
			line(11+i, 415, 22+i, 440);
			line(i, 440, 22+i, 440);
		    //	floodfill(11+i, 430, WHITE);
		 }
	 }
	 if(d == bullet_random[4])
	 {
		 for(i = 0;i < xmax; i += 68)
		 {
			if(i == (4*68))
			{
				continue;
			}
			/////// rectangle /////
		    //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i, 440, 22+i, 476);
		    //	floodfill(1+i, 441, WHITE);

			////// triengle /////

		    //	setfillstyle(XHATCH_FILL, RED);
			line(i, 440, 11+i,415);
			line(11+i, 415, 22+i, 440);
			line(i, 440, 22+i, 440);
		    //	floodfill(11+i, 430, WHITE);
		 }
	 }
	 if(d == bullet_random[5])
	 {
		 for(i = 0;i < xmax; i += 68)
		 {
			if(i == (5*68))
			{
				continue;
			}
			/////// rectangle /////
		   //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i, 440, 22+i, 476);
		   //	floodfill(1+i, 441, WHITE);

			////// triengle /////

		    //	setfillstyle(XHATCH_FILL, RED);
			line(i, 440, 11+i,415);
			line(11+i, 415, 22+i, 440);
			line(i, 440, 22+i, 440);
		    //	floodfill(11+i, 430, WHITE);
		 }
	 }
	 if(d == bullet_random[6])
	 {
		 for(i = 0;i < xmax; i += 68)
		 {
			if(i == (6*68))
			{
				continue;
			}
			/////// rectangle /////
		   //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i, 440, 22+i, 476);
		   //	floodfill(1+i, 441, WHITE);

			////// triengle /////

		    //	setfillstyle(XHATCH_FILL, RED);
			line(i, 440, 11+i,415);
			line(11+i, 415, 22+i, 440);
			line(i, 440, 22+i, 440);
		    //	floodfill(11+i, 430, WHITE);
		 }
	 }
	 if(d == bullet_random[7])
	 {
		 for(i = 0;i < xmax; i += 68)
		 {
			if(i == (7*68))
			{
				continue;
			}
			/////// rectangle /////
		  //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i, 440, 22+i, 476);
		  //	floodfill(1+i, 441, WHITE);

			////// triengle /////

		  //	setfillstyle(XHATCH_FILL, RED);
			line(i, 440, 11+i,415);
			line(11+i, 415, 22+i, 440);
			line(i, 440, 22+i, 440);
		   //	floodfill(11+i, 430, WHITE);
		 }
	 }
	 if(d == bullet_random[8])
	 {
		 for(i = 0;i < xmax; i += 68)
		 {
			if(i == (8*68))
			{
				continue;
			}
			/////// rectangle /////
		  //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i, 440, 22+i, 476);
		   //	floodfill(1+i, 441, WHITE);

			////// triengle /////

		  //	setfillstyle(XHATCH_FILL, RED);
			line(i, 440, 11+i,415);
			line(11+i, 415, 22+i, 440);
			line(i, 440, 22+i, 440);
		  //	floodfill(11+i, 430, WHITE);
		 }
	 }
	 if(d == bullet_random[9])
	 {
		 for(i = 0;i < xmax; i += 68)
		 {
			if(i == (9*68))
			{
				continue;
			}
			/////// rectangle /////
		  //	setfillstyle(XHATCH_FILL, BLUE);
			rectangle(i, 440, 22+i, 476);
		   //	floodfill(1+i, 441, WHITE);

			////// triengle /////

		  //	setfillstyle(XHATCH_FILL, RED);
			line(i, 440, 11+i,415);
			line(11+i, 415, 22+i, 440);
			line(i, 440, 22+i, 440);
		 //	floodfill(11+i, 430, WHITE);
		 }
	 }

	//////////////////////  Bottom Line  /////////////////////

	setcolor(RED);
	line(0, ymax, xmax, ymax);
	line(0, ymax-1, xmax, ymax-1);
	line(0, ymax-2, xmax, ymax-2);
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

void target(int target_position[6])   //////   default 3   //////
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
    }
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

void bullets_number(int bullet_random[10])
{

	char c[1];

	sprintf(c, "%c",bullet_random[0]);
     //	store [0] as string in c,so we can use in outtextxy without any error
	outtextxy(9, 400, c);
	sprintf(c, "%c",bullet_random[1]);
	outtextxy(9+(68), 400, c);
	sprintf(c, "%c",bullet_random[2]);
	outtextxy(9+(2*68), 400, c);
	sprintf(c, "%c",bullet_random[3]);
	outtextxy(9+(3*68), 400, c);
	sprintf(c, "%c",bullet_random[4]);
	outtextxy(9+(4*68), 400, c);
	sprintf(c, "%c",bullet_random[5]);
	outtextxy(9+(5*68), 400, c);
	sprintf(c, "%c",bullet_random[6]);
	outtextxy(9+(6*68), 400, c);
	sprintf(c, "%c",bullet_random[7]);
	outtextxy(9+(7*68), 400, c);
	sprintf(c, "%c",bullet_random[8]);
	outtextxy(9+(8*68), 400, c);
	sprintf(c, "%c",bullet_random[9]);
	outtextxy(9+(9*68), 400, c);
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