#include<stdio.h>
#include<graphics.h>

int abs(int c){
	if(c < 0)return -c;
	return c;
}

void dda(int x0, int y0, int x1, int y1){
	int dx = x1-x0, dy = y1-y0;
	int steps;
	int i;
	if(abs(dx) > abs(dy) )
		steps=abs(dx);
	else
		steps=abs(dy);

	float xi,yi;

	xi=dx/(1.0*steps);
	yi=dy/(1.0*steps);
	float x = x0, y = y0;	
	
	for(i=0;i<steps;i++){
		putpixel(x, y, WHITE);
		x+=xi;
		y+=yi;
	}
}

int main(){
	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,NULL);
	
	dda(40, 40, 40, 100);
	
	getch();
	closegraph();
	
	return 0;
}
