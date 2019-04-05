#include<stdio.h>
#include<graphics.h>

void mid(int x0, int y0, int x1, int y1){
	int dx = x1 - x0, dy = y1 - y0, d;
	if(dy < dx)
		d = dy - (dx / 2);
	else
		d = dx - (dy / 2);

	putpixel(x0,y0,WHITE);
	if(dy < dx){
		while(x0 <x1) {
			x0 ++;
			if(d < 0)
				d = d + dy;
			else
				d = d + dy - dx;
			y0 ++;
			putpixel(x0, y0, WHITE);
		}
	}else{
		while(y0 < y1){
			y0 ++;
			if(d < 0)
				d = d + dx;
			else
				d = d + dx - dy;
			x0 ++;
			putpixel(x0, y0, WHITE);
		}
	}
		
}

int main(){
    int gd=DETECT,gm=0;

	initgraph(&gd,&gm,NULL);
	mid(0,0,50,300);
	
	getch();
	return 0;
}
