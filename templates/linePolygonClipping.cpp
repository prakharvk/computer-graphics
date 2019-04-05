#include<iostream.h>
#include<conio.h>
#include<graphics.h>



//LINE CLIPPING : LIANG-BASKY
void lineClippingLB(float x0=300, float y0=50, float x1=50, float y1=300, float xmin=100, float xmax=200, float ymin=100, float ymax=200)
{
	double dx = x1 - x0;
	double dy = y1 - y0;
	float p[4], q[4];
	p[0] = -dx; p[1] = dx;
	p[2] = -dy;	p[3] = dy;

	q[0] = (x0 - xmin);
	q[1] = (xmax - x0);
	q[2] = (y0 - ymin);
	q[3] = (ymax - y0);

	for(int i=0 ; i<4 ; i++)
    {
        if(p[i]==0)
        {
            if(q[i]<0)
                return;
            if(q[i]>=0)
            {
                line(x0, y0, x1, y1);
                return;
            }
        }
    }
    float u1,u2;
    u1=0,u2=1;
	for(int i = 0; i<4 ; i++)
    {
        if(p[i]<0)
            u1 = max(u1,q[i]/p[i]);
        else
            u2= min(u2,q[i]/p[i]);
    }
    if(u1>u2)
        return;
	line(x0+u1*dx, y0+u1*dy, x0+u2*dx, y0+u2*dy);
}


//LINE CLIPPING : COHEN-SUTHERLAND
int computeCode(float xmin, float ymin, float xmax, float ymax, float x, float y)
{
	int code = 0;
	if (x < xmin) code |= 1;
	else if (x > xmax) code |= 2;
	if (y < ymin) code |= 4;
	else if (y > ymax) code |= 8;
	return code;
}

void cohenSutherlandClip(float xmin, float ymin, float xmax, float ymax, float x1, float y1, float x2, float y2)
{
	rectangle(xmin, ymin, xmax, ymax);
	int code1 = computeCode(xmin, ymin, xmax, ymax, x1, y1);
	int flag = 1, code2 = computeCode(xmin, ymin, xmax, ymax, x2, y2);
	while (1)
	{
		if((code1 == 0) && (code2 == 0)) { flag = 1; break; }
		else if(code1 & code2) break;
		else
		{
			int code_out;
			float x, y;
			if (code1 != 0) code_out = code1;
			else code_out = code2;
			if (code_out & 8) { x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1); y = ymax; }
			else if (code_out & 4) { x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1); y = ymin; }
			else if (code_out & 2) { y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1); x = xmax; }
			else if (code_out & 1) { y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1); x = xmin; }

			if (code_out == code1)
			{ x1 = x; y1 = y; code1 = computeCode(xmin, ymin, xmax, ymax, x1, y1); }
			else
			{ x2 = x; y2 = y; code2 = computeCode(xmin, ymin, xmax, ymax, x2, y2); }
		}
	}
	if(flag) line(x1,y1,x2,y2);
}



//POLYGON CLIPPING : SUTHERLAND-HODGMAN
float x_intersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	float num = (x1*y2 - y1*x2) * (x3-x4) - (x1-x2) * (x3*y4 - y3*x4);
	float den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
	return num/den;
}
float y_intersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	float num = (x1*y2 - y1*x2) * (y3-y4) - (y1-y2) * (x3*y4 - y3*x4);
	float den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
	return num/den;
}

void clip(float poly_points[][2], int &poly_size, float x1, float y1, float x2, float y2)
{
	float new_points[50][2]; int new_poly_size = 0;
	int i;
	for (i = 0; i < poly_size; i++)
	{
		int k = (i+1) % poly_size;
		float ix = poly_points[i][0], iy = poly_points[i][1];
		float kx = poly_points[k][0], ky = poly_points[k][1];
		float i_pos = (x2-x1) * (iy-y1) - (y2-y1) * (ix-x1);
		float k_pos = (x2-x1) * (ky-y1) - (y2-y1) * (kx-x1);
		if (i_pos < 0 && k_pos < 0)
		{
			new_points[new_poly_size][0] = kx;
			new_points[new_poly_size][1] = ky;
			new_poly_size++;
		}
		else if (i_pos >= 0 && k_pos < 0)
		{
			new_points[new_poly_size][0] = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_points[new_poly_size][1] = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_poly_size++;
			new_points[new_poly_size][0] = kx;
			new_points[new_poly_size][1] = ky;
			new_poly_size++;
		}
		else if (i_pos < 0 && k_pos >= 0)
		{
			new_points[new_poly_size][0] = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_points[new_poly_size][1] = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_poly_size++;
		}
	}
	poly_size = new_poly_size;
	for (i = 0; i < poly_size; i++)
	{
		poly_points[i][0] = new_points[i][0];
		poly_points[i][1] = new_points[i][1];
	}
}

void suthHodgClip(float poly_points[][2], int poly_size, float clipper_points[][2], int clipper_size)
{
	int i;
	for (i = 0; i < clipper_size; i++)
	{
		int k = (i+1) % clipper_size;
		clip(poly_points, poly_size, clipper_points[i][0], clipper_points[i][1], clipper_points[k][0], clipper_points[k][1]);
	}
	for (i = 0; i < poly_size; i++)
	{
		int k = (i+1) % poly_size;
		line(poly_points[i][0], poly_points[i][1], poly_points[k][0], poly_points[k][1]);
	}
}