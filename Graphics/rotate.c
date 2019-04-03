#include <stdio.h>
#include <graphics.h>
#include <math.h>
int gd = DETECT, gm = 0;
const double PI = acos(-1.0);
struct pt
{
	int x;
	int y;
};
struct map
{
	int a;
	int b;
};

void original(struct pt a[], struct map s[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		line(a[s[i].a].x, a[s[i].a].y, a[s[i].b].x, a[s[i].b].y);
	}
}

void translate(struct pt a[], int n, int x, int y)
{
	int i;
	for (i = 0; i < n; i++)
	{
		a[i].x -= x;
		a[i].y -= y;
	}
}

struct pt rotate_pt(struct pt p, double rad)
{
	struct pt p1;
	p1.x = (float)(cos(rad) * (p.x) * 1.0 - sin(rad) * (p.y) * 1.0);
	p1.y = (float)(sin(rad) * (p.x) * 1.0 + cos(rad) * (p.y) * 1.0);
	return p1;
}

void rotate(struct pt s[], int n, double rad)
{
	int i;
	for (i = 0; i < n; i++)
		s[i] = rotate_pt(s[i], rad);
}

int main()
{
	int n, i, x, y;
	double rad;
	scanf("%d", &n);
	struct pt a[n], axis;
	struct map e[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		a[i].x = x;
		a[i].y = y;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		e[i].a = x - 1;
		e[i].b = y - 1;
	}
	scanf("%d %d", &x, &y);
	scanf("%lf", &rad);
	rad = (rad * PI) / 180.0;
	initgraph(&gd, &gm, 0);
	original(a, e, n);

	translate(a, n, x, y);
	rotate(a, n, rad);
	translate(a, n, -x, -y);

	setcolor(4);
	original(a, e, n);

	delay(5000);
	closegraph();
	for (i = 0; i < n; i++)
		printf("%d %d\n", a[i].x, a[i].y);

	return 0;
}

/*

3
100 100
200 200
100 200
1 2
1 3
3 2
50 50
-45

*/
