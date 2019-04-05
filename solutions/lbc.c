#include<stdio.h>
#include<graphics.h>
#include<math.h>

int gd=DETECT,gm=0;

double min(double a,double b){
	return (a<b)?a:b;
}

double max(double a,double b){
	return (a>b)?a:b;
}

void main(){
	int x1,y1,x2,y2,i;
	int xmin,xmax,ymin,ymax;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	scanf("%d %d %d %d",&xmin,&xmax,&ymin,&ymax);

	int dx=x2-x1,dy=y2-y1;
	int p1=-dx,q1=x1-xmin;
	int p2=dx,q2=xmax-x1;
	int p3=-dy,q3=y1-ymin;
	int p4=dy,q4=ymax-y1;
	double u1=0.0,u2=1.0;

	initgraph(&gd,&gm,0);
	line(x1,y1,x2,y2);

	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	line(xmax,ymin,xmin,ymin);

	if((p1==0 && q1<0) || (p2==0 && q2<0) || (p3==0 && q3<0) || (p4==0 && q4<0)){
		printf("Line is outside\n");
		x1=y1=0;
		x2=y2=0;
	}else{
		if(p1<0)
			u1=max(u1,(q1*1.0)/p1);
		else
			u2=min(u2,(q1*1.0)/p1);
		if(p2<0)
			u1=max(u1,(q2*1.0)/p2);
		else
			u2=min(u2,(q2*1.0)/p2);
		if(p3<0)
			u1=max(u1,(q3*1.0)/p3);
		else
			u2=min(u2,(q3*1.0)/p3);
		if(p4<0)
			u1=max(u1,(q4*1.0)/p4);
		else
			u2=min(u2,(q4*1.0)/p4);

		if(u1>u2){
			printf("Line is outside\n");
			x1=y1=0;
			x2=y2=0;
		}else{
			int x=x1,y=y1;
			x1=x+u1*dx;y1=y+u1*dy;
			x2=x+u2*dx;y2=y+u2*dy;

		}
	}
	//printf("%d %d\n",x1,y1);
	//printf("%d %d\n",x2,y2);

	setcolor(4);
	line(x1,y1,x2,y2);
	delay(4000);
	closegraph();
}
/*

100 50 200 210
100 200 100 200

*/
