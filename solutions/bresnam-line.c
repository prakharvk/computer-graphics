#include<stdio.h>
#include<graphics.h>

void bresnam_line(int x0, int y0, int x1, int y1){
	int dx, dy, p, i;
	dx = x1 - x0;
	dy = y1 - y0;
	p = 2 * dy - dx;
	
	int x = x0, y = y0;
	putpixel(x, y, WHITE);
    while(x<x1)
    {
        if(p < 0)
            p += 2*dy;
        else {
            p += 2*(dy-dx);
            y++;
        }
        x++;
        putpixel(x, y, WHITE);
    }
}
		
int main(){
	int gd = DETECT, gm = 0;
	initgraph(&gd, &gm, NULL);
	
	bresnam_line(2, 2, 106, 100);
	getch();

	return 0;
}
