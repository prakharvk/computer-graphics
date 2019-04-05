
#include <stdio.h>
#include <graphics.h>

void boundaryFill8(int x, int y, int fill_color,int boundary_color) 
{ 
	if(getpixel(x, y) != boundary_color && 
	getpixel(x, y) != fill_color) 
	{ 
		putpixel(x, y, fill_color); 
		boundaryFill8(x + 1, y, fill_color, boundary_color); 
		boundaryFill8(x, y + 1, fill_color, boundary_color); 
		boundaryFill8(x - 1, y, fill_color, boundary_color); 
		boundaryFill8(x, y - 1, fill_color, boundary_color);
	} 
} 

int main() 
{
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); 
	setcolor(4);
	line(100, 30, 70, 70);
	line(50, 70, 70, 70);
	line(50, 70, 30, 150);
	line(150, 150, 30, 150);
	line(150, 150, 100, 30); 
	boundaryFill8(100, 100, 2, 4); 
	getch(); 
	closegraph(); 
	return 0; 
} 
