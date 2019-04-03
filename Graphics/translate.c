#include<stdio.h>
#include<graphics.h>
int gd=DETECT,gm=0;

void mid(int x0,int y0,int x1,int y1,int c){
	int dx=x1-x0,dy=y1-y0,d;
	if(dy<dx)
		d=dy-(dx/2);
	else
		d=dx-(dy/2);
	putpixel(x0,y0,WHITE);
	if(dy<dx){
		while(x0<x1){
			x0++;
			if(d<0)
				d=d+dy;
			else
				d=d+dy-dx;
			y0++;
			putpixel(x0,y0,c);
		}
	}else{
		while(y0<y1){
			y0++;
			if(d<0)
				d=d+dx;
			else
				d=d+dx-dy;
			x0++;
			putpixel(x0,y0,c);
		}
	}

}

void translate(int x0,int y0,int x1,int y1,int s1,int s2){
	mid(x0,y0,x1,y1,15);
	x0+=s1;
	x1+=s1;
	y0+=s2;
	y1+=s2;
	mid(x0,y0,x1,y1,4);
}

void main(){
	initgraph(&gd,&gm,0);
	translate(5,5,100,80,50,150);
	delay(4000);
	closegraph();
}
