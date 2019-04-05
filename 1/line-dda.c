#include <graphics.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  float x0, y0, x1, y1;
  x0 = 50;
  y0 = 2;
  x1 = 400;
  y1 = 100;
  float dx = x1 - x0;
  float dy = y1 - y0;
  float steps = dx > dy ? dx : dy;
  float i = 0;
  float xinc, yinc;
  xinc = dx / (float)steps;
  yinc = dy / (float)steps;
  float x = x0;
  float y = y0;
  while (i < steps)
  {
    putpixel(x, y, WHITE);
    x = x + xinc;
    y = y + yinc;
    i++;
  }
  getch();  
  return 0;
}