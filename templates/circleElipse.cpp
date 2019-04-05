#include<iostream>
#include<graphics.h>
using namespace std;



//MID POINT CIRCLE
void plot8(int x,int y,int XS=0,int YS=0)
{
	putpixel( x + XS,  y + YS, WHITE);
	putpixel(-x + XS,  y + YS, WHITE);
	putpixel( x + XS, -y + YS, WHITE);
	putpixel(-x + XS, -y + YS, WHITE);
	putpixel( y + XS,  x + YS, WHITE);
	putpixel(-y + XS,  x + YS, WHITE);
	putpixel( y + XS, -x + YS, WHITE);
	putpixel(-y + XS, -x + YS, WHITE);
	return;
}

void MIDPOINT_CIRCLE(int r,int XS=0,int YS=0)
{
//    This function will draw a ciclre of radius r
//    with center (XS,YS)
	int x = 0;
	int y = r;
	int p = 1-r;


    plot8(x,y,XS,YS);
	while(x<y)
	{
		if(p<0)
			p += 2*x + 3;
		else
			p += 2*x - 2*y + 5, y--;
		x++;
		plot8(x,y,XS,YS);
	}
	return;
}



//CIRCLE DRAWING : BRESENHAM'S
void BRESENHAM_CIRCLE(int r,int XS=0,int YS=0)
{
//    This function will draw a ciclre of radius r
//    with center (XS,YS)
	int x = 0;
	int y = r;
	int p = 3-2*r;

    plot8(x,y,XS,YS);
	while(x<y)
	{
		if(p<0)
			p += 4*x + 6;
		else
			p += 4*(x-y) + 6, y--;
		x++;
		plot8(x,y,XS,YS);
	}
	return;
}



//ELLIPSE DRAWING : MID POINT 
void plot4(int x,int y,int XS=0,int YS=0)
{
	putpixel( x + XS,  y + YS, WHITE);
	putpixel(-x + XS,  y + YS, WHITE);
	putpixel( x + XS, -y + YS, WHITE);
	putpixel(-x + XS, -y + YS, WHITE);
	return;
}

void MIDPOINT_ELLIPSE(int a,int b,int XS=0,int YS=0)
{
//    This function will draw an ellipse with major axis a
//    and minor axis b with center (XS,YS)
	float x = 0;
	float y = b;
	float a2 = a*a;
	float b2 = b*b;

	float p1 = b2 + a2*(0.25-b);
    plot4(x,y,XS,YS);

	while(b2*x<a2*y)
	{
		if(p1<0)
			p1 += b2*(2*x+3);
		else
			p1 += b2*(2*x+3)+a2*(-2*y+2), y--;
		x++;
		plot4(x,y,XS,YS);
	}

	float p2 = b2*(x+0.5)*(x+0.5) + a2*(y-1)*(y-1) -a2*b2;
	while(y>0)
    {
        if(p2<0)
			p2 += b2*(2*x+2)+a2*(-2*y+3), x++;
		else
			p2 += a2*(-2*y+3);
		y--;
		plot4(x,y,XS,YS);
    }
	return;
}



//