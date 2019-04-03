#include<stdio.h>
#include<graphics.h>

int gd=DETECT,gm=0;
int abs(int c){
	if(c<0)return -c;
	return c;
}
void dda(int x0,int y0,int x1,int y1){
	int i,dx=x1-x0,dy=y1-y0;
	int steps;
	if(abs(dx) > abs(dy) )
		steps=abs(dx);
	else
		steps=abs(dy);
	int xi,yi;
	xi=dx/(1.0*steps);
	yi=dy/(1.0*steps);
	for(i=0;i<steps;i++){
		putpixel(x0,y0,WHITE);
		x0+=xi;
		y0+=yi;
	}
}

void main(){
	initgraph(&gd,&gm,NULL);
	dda(2,2,100,100);
	delay(3000);
	closegraph();
}
