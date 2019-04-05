#include <graphics.h> 
#include <stdio.h> 

void flood(int x, int y, int new_col) 
{ 
	if (getpixel(x, y) == NULL) { 
		putpixel(x, y, new_col); 
		flood(x + 1, y, new_col); 
		flood(x - 1, y, new_col); 
		flood(x, y + 1, new_col); 
		flood(x, y - 1, new_col); 
	} 
} 

void floodFill(int x, int y, int new_col, int old_col) 
{ 
	if (getpixel(x, y) == old_col) { 
		putpixel(x, y, new_col); 
		floodFill(x + 1, y, new_col, old_col); 
		floodFill(x - 1, y, new_col, old_col); 
		floodFill(x, y + 1, new_col, old_col); 
		floodFill(x, y - 1, new_col, old_col); 
	} 
} 

int main() 
{ 
	int gd, gm = DETECT; 

	initgraph(&gd, &gm, ""); 
	setcolor(RED);
	line(100, 30, 70, 70);
	line(50, 70, 70, 70);
	line(50, 70, 30, 150);
	line(150, 150, 30, 150);
	line(150, 150, 100, 30);

	flood(100, 100, RED); 
	floodFill(100, 100, GREEN, RED); 
	getch(); 

	return 0; 
} 
