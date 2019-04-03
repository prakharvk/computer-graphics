#include <graphics.h>
#include <stdio.h>
#include <ctype.h>
void main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  float x0, y0, x1, y1;
  x0 = 2;
  y0 = 2;
  x1 = 50;
  y1 = 50;
  float dx = x1 - x0;
  float dy = y1 - y0;
  int steps = dx - 1;
  int i = 0;
  float xinc, yinc;
  xinc = dx / (float)steps;
  yinc = dy / (float)steps;
  int x = x0;
  int y = y0;
  putpixel(x, y, WHITE);
  float p0 = 2 * dy - dx;
  while (i < steps)
  {
    if (p0 < 0)
    {
      putpixel(x + 1, y, WHITE);
      p0 = p0 + 2 * dy;
    }
    else
    {
      putpixel(x + 1, y + 1, WHITE);
      p0 = p0 + 2 * dy - 2 * dx;
      y = y + 1;
    }
    i++;
    x += 1;
    delay(100);
  }
  delay(5000);
  closegraph();
}