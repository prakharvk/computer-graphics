#include<stdio.h>
#include<graphics.h>

int gd=DETECT,gm=0;

void bline(int x0,int y0,int x1,int y1){
	int dx,dy,p,i;
	dx=x1-x0;
	dy=y1-y0;
	p=2*dy-dx;
	for(i=0;i<dx;i++){
		putpixel(x0,y0,WHITE);
		if(p<0){
			p=p+2*dy;
			x0++;
		}else{
			p=p+2*(dy-dx);
			x0++;
			y0++;
		}
	}
}
		
void main(){
	initgraph(&gd,&gm,NULL);
	bline(2,2,100,105);
	getch();
}
