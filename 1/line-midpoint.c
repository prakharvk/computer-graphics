#include <graphics.h>
#include <stdio.h>
#include <ctype.h>
int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  float x0, y0, x1, y1;
  x0 = 0;
  y0 = 0;
  x1 = 10;
  y1 = 0;
  float dx = x1 - x0;
  float dy = y1 - y0;
  float D;
  if (dy < dx)
    D = dy - (dx / 2);
  else
    D = dx - (dy / 2);

  int x = x0;
  int y = y0;
  putpixel(x, y, WHITE);
  if (dy < dx)
  {
    while (x < x1)
    {
      x = x + 1;
      if (D < 0)
      {
        D = D + dy;
      }
      else
      {
        D = D + dy - dx;
	y = y +1;      
}
      putpixel(x, y, WHITE);
      delay(100);
    }
  }
  else
  {
    while (y < y1)
    {
      y = y + 1;
      if (D < 0)
      {
        D = D + dx;
      }
      else
      {
        D = D + dx - dy;
	x=x+1;      
}
      putpixel(x, y, WHITE);
      delay(100);
    }
  }
  delay(5000);
  closegraph();
return 0;
}
