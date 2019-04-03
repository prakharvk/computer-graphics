#include<stdio.h>
#include<graphics.h>
int gd=DETECT,gm=0;

void main(){
	int x1,y1,x2,y2,m1,m2;
	scanf("%d %d",&x1,&y1);
	scanf("%d %d",&x2,&y2);
	scanf("%d %d",&m1,&m2);
	double x,y;	
	double t=0.0;
	initgraph(&gd,&gm,0);
	for(;t<=1;t=t+0.001){
		x=(2*t*t*t-3*t*t+1)*x1+(-2*t*t*t+3*t*t)*x2+(t*t*t-2*t*t+t)*m1+(t*t*t-t*t)*m2;
		y=(2*t*t*t-3*t*t+1)*y1+(-2*t*t*t+3*t*t)*y2+(t*t*t-2*t*t+t)*m1+(t*t*t-t*t)*m2;
		putpixel((int)x,(int)y,15);
	}
	delay(4000);
	closegraph();
}
/*
	
10 10
200 100
300 -1000

*/
