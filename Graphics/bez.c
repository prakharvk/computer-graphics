#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
int gd = DETECT, gm=0;
void bezier (int x[4], int y[4]){
    int i;
    double t;
    for (t = 0.0; t < 1.0; t += 0.0005){
		double xt = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
		double yt = pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
		putpixel (xt, yt, WHITE);
	}
 	for (i=0; i<4; i++)
		putpixel (x[i], y[i], YELLOW);
}

void main(){
    int x[4], y[4];
    int i;
    for (i=0; i<4; i++)
		scanf ("%d %d",&x[i],&y[i]);
	initgraph(&gd,&gm,0);
    bezier(x,y);
	delay(1000);
	closegraph();
}
/*

100 25
100 50
100 75
100 100

*/
