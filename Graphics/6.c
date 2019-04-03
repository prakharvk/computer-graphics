#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>

int gd=DETECT,gm=0;


void dellipse(int x,int y,int a,int b){
	int i=0,j=b;
	float p;
	p=b*b - a*a*b + (0.25)*a*a;
	while(i*b*b<=a*a*j){
		putpixel(x+i,x+j,WHITE);
		putpixel(x-i,x+j,WHITE);
		putpixel(x+i,x-j,WHITE);
		putpixel(x-i,x-j,WHITE);

		if(p<0){
			p=p + 2*b*b*(i+1)+b*b;
		}else{
			p=p + 2*b*b*(i+1)-2*a*a*(j-1)+b*b;
			j--;
		}
		i++;
	}

	p=b*b*(i+0.5)*(i+0.5) + a*a*(j-1)*(j-1)-a*a*b*b;

	while(j>=0){
		putpixel(x+i,x+j,WHITE);
		putpixel(x-i,x+j,WHITE);
		putpixel(x+i,x-j,WHITE);
		putpixel(x-i,x-j,WHITE);

		if(p>=0){
			p=p-2*a*a*(j-1)-a*a;
		}else{
			p=p+2*b*b*(i+1)-2*a*a*(j-1)+a*a;
			i++;
		}
		j--;
	}


}

void main(){
	initgraph(&gd,&gm,0);
	dellipse(100,100,40,80);
	delay(3000);
	closegraph();
}
