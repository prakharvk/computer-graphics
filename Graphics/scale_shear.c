#include <stdio.h>
#include <graphics.h>
struct pt
{
	int x;
	int y;
};
struct edge
{
	struct pt a;
	struct pt b;
};

int gd = DETECT, gm = 0;
void mid(int x0, int y0, int x1, int y1, int c)
{
	float dx = (x1 - x0) * 1.0, dy = (y1 - y0) * 1.0, d;
	if (dy < dx)
		d = dy - (dx / 2);
	else
		d = dx - (dy / 2);
	putpixel(x0, y0, c);
	if (dy < dx)
	{
		while (x0 < x1)
		{
			x0++;
			if (d < 0)
				d = d + dy;
			else
			{
				d = d + dy - dx;
				y0++;
			}
			putpixel(x0, y0, c);
		}
	}
	else
	{
		while (y0 < y1)
		{
			y0++;
			if (d < 0)
				d = d + dx;
			else
			{
				d = d + dx - dy;
				x0++;
			}
			putpixel(x0, y0, c);
		}
	}
}
void original(struct edge s[], int n, int c)
{
	int i;
	for (i = 0; i < n; i++)
	{
		mid(s[i].a.x, s[i].a.y, s[i].b.x, s[i].b.y, c);
	}
}

void scale_fig(struct edge s[], int n, int s1, int s2)
{
	int i;
	for (i = 0; i < n; i++)
	{
		s[i].a.x *= s1;
		s[i].a.y *= s2;
		s[i].b.x *= s1;
		s[i].b.y *= s2;
	}
}

void x_shear(struct edge s[], int n, int f)
{
	int i;
	for (i = 0; i < n; i++)
	{
		s[i].a.x += s[i].a.y * f;
		s[i].b.x += s[i].b.y * f;
	}
}

void y_shear(struct edge s[], int n, int f)
{
	int i;
	for (i = 0; i < n; i++)
	{
		s[i].a.y += s[i].a.x * f;
		s[i].b.y += s[i].b.x * f;
	}
}

int main()
{

	int n, i, x, y;
	struct pt e1, e2;
	scanf("%d", &n);
	struct edge p[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		e1.x = x;
		e1.y = y;
		scanf("%d %d", &x, &y);
		e2.x = x;
		e2.y = y;
		p[i].a = e1;
		p[i].b = e2;
	}

	initgraph(&gd, &gm, 0);

	original(p, n, 15);
	x_shear(p, n, 2);
	y_shear(p, n, 2);
	scale_fig(p, n, 2, 2);
	original(p, n, 4);
	delay(3000);
	closegraph();
	return 0;
}
/*

4
50 50 50 100
50 50 100 50
100 50 100 100
50 100 100 100


*/
