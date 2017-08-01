#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<dos.h>

void target(int target_position[2]);
void backScreen(int d, int target_position[2]);
void random_pixel(int pixel);
int touch(int targetposition[2],int p,int q);

main()
{
	randomize();
	int gd = DETECT, gm;
   	int xmax, ymax;
   	int d, i = 0, no, target_no;
   	int target_position[2];

 	char ch;
   	int p, q, c;

   	initgraph(&gd, &gm, "C:\\TC\\BGI");
   	xmax = getmaxx();
   	ymax = getmaxy();	

   	for(i = 0; i < 3; i++)
   	{
		target_position[i] = random(xmax-50);
	}

   	for(i = 0;i < xmax; i += 68)
   	{
		/////// rectangle /////
		setfillstyle(XHATCH_FILL, BLUE);
		rectangle(i, 440, 22+i, 476);
		floodfill(1+i, 441, WHITE);


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

    ////////////////////// Random Colorful Dots /////////////

    random_pixel(100);

    ///////////////  Call target   //////////////////

	target(target_position);

    ///////////////  Move  //////////////

	while(1)
	{
		ch = getch();
		d = ch;
		if(d == 49)   // 1
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 1");
				outtextxy(9, 450, "1");
				backScreen(d,target_position);
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
				if(c == 0)
				{
					break;
				}
			}
		}
		if(d == 50)   // 2
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 2");
				outtextxy(9+(68), 450, "2");
				backScreen(d,target_position);
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
				if(c == 0)
				{
					break;
				}
			}
		}
		if(d == 51)   // 3
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 3");
				outtextxy(9+(2*68), 450, "3");
				backScreen(d,target_position);
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
				if(c == 0)
				{
					break;
				}
			}
		}
		if(d == 52)   // 4
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 4");
				outtextxy(9+(3*68), 450, "4");
				backScreen(d,target_position);
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
				if(c == 0)
				{
					break;
				}
			}
		}
		if(d == 53)   // 5
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 5");
				outtextxy(9+(4*68), 450, "5");
				backScreen(d,target_position);
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
				if(c == 0)
				{
					break;
				}
			}
		}
		if(d == 54)   // 6
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 6");
				outtextxy(9+(5*68), 450, "6");
				backScreen(d,target_position);
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
				if(c == 0)
				{
					break;
				}
			}
		}
		if(d == 55)   // 7
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 7");
				outtextxy(9+(6*68), 450, "7");
				backScreen(d,target_position);
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
				if(c == 0)
				{
					break;
				}
			}
		}
		if(d == 56)   // 8
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 8");
				outtextxy(9+(7*68), 450, "8");
				backScreen(d,target_position);
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
				if(c == 0)
				{
					break;
				}
			}
		}
		if(d == 57)   // 9
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 9");
				outtextxy(9+(8*68), 450, "9");
				backScreen(d,target_position);
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
				q = 11+(7*68);
				c = touch(target_position,p,q);
				if(c == 0)
				{
					break;
				}
			}
		}
		if(d == 48)   // 0
		{
			for( i = 0; i < 420; i += 5)
			{
				clearviewport();
				outtextxy(250,160,"You Lunched no. 10");
				outtextxy(9+(9*68), 450, "10");
				backScreen(d,target_position);
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
				q = 11+(8*68);
				c = touch(target_position,p,q);
				if(c == 0)
				{
					break;
				}
			}
		}
		if(d == 27)   // ESC
		{
			return 0;
		}
	}

   getch();
   closegraph();
   return 0;
}

void backScreen(int d,int target_position[2])
   {
	   ///////////////////////////  Gun   ////////////////////////

	 int xmax,ymax,target;
	 int i = 0;

	 xmax = getmaxx();
	 ymax = getmaxy();

	 if(d == 49)
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
	 if(d == 50)
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
	 if(d == 51)
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
	 if(d == 52)
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
	 if(d == 53)
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
	 if(d == 54)
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
	 if(d == 55)
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
	 if(d == 56)
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
	 if(d == 57)
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
	 if(d == 48)
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

	////////////////////// Random Colorful Dots /////////////

	random_pixel(100);

	//////////////////// Target ( default 3) /////////////////////

	int j = random(16);
	int k = 0;
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
		rectangle(target_position[k], i, target_position[k]+50, 10+i);
		if(k == 0)
		{
			outtextxy(target_position[k]+25, i+2, target_no1);
		}
		else if(k == 1)
		{
			outtextxy(target_position[k]+25, i+2, target_no2);
		}
		else
		{
			outtextxy(target_position[k]+25, i+2, target_no3);
		}
	}
   }

void target(int target_position[2])   //////   default 3   //////
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
	rectangle(target_position[k], i, target_position[k]+50, 10+i);
	if(k == 0)
	{
		outtextxy(target_position[k]+25, i+2, target_no1);
	}
	if(k == 1)
	{
		outtextxy(target_position[k]+25, i+2, target_no2);
	}
	if(k == 2)
	{
		outtextxy(target_position[k]+25, i+2, target_no3);
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

int touch(int target_position[2],int p,int q)
{
	// target line ty = 0 ,30 , 60
	// tx = target_position [0], [1], [2]
	int tx1, tx2, tx3, ty1, ty2, ty3,i = 0;
	tx1 = target_position[0];
	tx2 = target_position[1];
	tx3 = target_position[2];
	ty1 = 10;
	ty2 = 40;
	ty3 = 70;

	if(ty3 == p)
	{
		if(tx3 < q && q < tx3+50)
		{
			settextstyle(TRIPLEX_FONT, HORIZ_DIR, GREEN);
			outtextxy(265, 220, "You touched 3");
			return 0;
		}
	}
	if(ty2 == p)
	{
		if(tx2 < q && q < tx2+50)
		{
			settextstyle(TRIPLEX_FONT, HORIZ_DIR, GREEN);
			outtextxy(265, 220, "You touched 2");
			return 0;
		}
	}
	if(ty1 == p)
	{
		if(tx1 < q && q < tx1+50)
		{
			settextstyle(TRIPLEX_FONT, HORIZ_DIR, GREEN);
			outtextxy(265, 220, "You touched 1");
			return 0;
		}
	}
	return 1;
}

