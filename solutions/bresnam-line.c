#include <graphics.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  float x0 = 2, y0 = 2, x1 = 500, y1 = 100;

  float dx = x1 - x0;
  float dy = y1 - y0;
  int steps = dx - 1;
  int i = 0;
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
  }

  getch();
  closegraph();
  
  return 0;
}