#include<iostream>
#include<graphics.h>
using namespace std;



//LINE DRAWING : DDA
void DDA(int X0,int Y0,int X1,int Y1)
{
    int dx = X1-X0;
    int dy = Y1-Y0;

    int steps = abs(dx)>abs(dy)?abs(dx):abs(dy);
    float Xinc = dx/(float(steps));
    float Yinc = dy/(float(steps));

    float X = X0;
    float Y = Y0;

    for(int i=0 ; i<=steps ; i++)
    {
    	putpixel(X,Y,WHITE);
    	X += Xinc;
    	Y += Yinc;
	}
}



//LINE DRAWING : BRESENHAM
void BRESENHAM_LINE(int X0,int Y0,int X1,int Y1)
{
//    This function will draw a line from
//    (X0,Y0) and (X1,Y1)

    int dx = X1-X0;
    int dy = Y1-Y0;

    int d = 2*dy-dx;
    int x = X0, y = Y0;
    putpixel(x,y,WHITE);

    while(x<X1)
    {
        if(d<0)
            d += 2*dy;
        else
            d += 2*(dy-dx),y++;

        x++;
        putpixel(x,y,WHITE);
    }
}



//LINE DRAWING : MID-POINT
void MIDPOINT_LINE(int X0,int Y0,int X1,int Y1)
{
//    This function will draw a line from
//    (X0,Y0) and (X1,Y1)
    
    int dx = X1-X0;
    int dy = Y1-Y0;
    
    int d = 2*dy-dx;
    int x = X0, y = Y0;
    putpixel(x,y,WHITE);
    
    while(x<X1)
    {
        if(d<0)
            d += 2*dy;
        else
            d += 2*(dy-dx),y++;
            
        x++;
        putpixel(x,y,WHITE);
    }
}