#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

	line(33,170,50,152);
	line(50,152,80,152);
	line(80,152,100,170);
	line(50,152,50,170);
	line(80,152,80,170);

	rectangle(25,170,105,184);
	circle(45,192,8);
	circle(85,192,8);
	line(0,200,640,200);

	for (int i = 0; i < 480; i += 2)
	{
		line(33+i,170,50+i,152);
        line(50+i,152,80+i,152);
        line(80+i,152,100+i,170);
        line(50+i,152,50+i,170);
        line(80+i,152,80+i,170);

        rectangle(25+i,170,105+i,184);
        circle(45+i,192,8);
        circle(85+i,192,8);
        line(0,200,640,200);
		delay(40);

		if (i == 478)
			break;

		cleardevice();
	}
	getch();
	closegraph();
	return 0;
}
