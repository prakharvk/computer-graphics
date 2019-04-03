#include<stdio.h>
#include<graphics.h>
int gd=DETECT,gm=0;
int xmin_in(int x,int y,int xmin){
	return (x>xmin)?1:0;
}
int xmax_in(int x,int y,int xmax){
	return (x<xmax)?1:0;
}
int ymin_in(int x,int y,int ymin){
	return (y>ymin)?1:0;
}
int ymax_in(int x,int y,int ymax){
	return (y<ymax)?1:0;
}
int x_intersect(int xw,int x1,int y1,int x2,int y2){
	if(x1==x2)
		return 1e9;
	double d;
	d=((xw-x1)*1.0)/(x2-x1);
	return y1+d*(y2-y1);
}
int y_intersect(int yw,int x1,int y1,int x2,int y2){
	if(y1==y2)
		return 1e9;
	double d;
	d=((yw-y1)*1.0)/(y2-y1);
	return x1+d*(x2-x1);
}
void poly(int x[],int y[],int n){
	printf("Polygon\n");
	int i;
	for(i=0;i<n;i++)
		printf("%d %d\n",x[i],y[i]);
}
void draw(int x[],int y[],int n){
	int i;
	for(i=0;i<n-1;i++)
		line(x[i],y[i],x[i+1],y[i+1]);
}
void main(){
	int n,i;
	scanf("%d",&n);
	int x[1+n],y[1+n];
	for(i=0;i<n;i++)
		scanf("%d %d",&x[i],&y[i]);
	x[n]=x[0];y[n]=y[0];
	n++;
	int xmin,xmax,ymin,ymax;
	scanf("%d %d %d %d",&xmin,&xmax,&ymin,&ymax);
	int a,b;
	int x1[n],y1[n];
	int m=0;
	initgraph(&gd,&gm,0);
	draw(x,y,n);
	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	line(xmax,ymin,xmin,ymin);

	for(i=0;i<n-1;i++){
		int c1=xmin_in(x[i],y[i],xmin);
		int c2=xmin_in(x[i+1],y[i+1],xmin);
		if(c1==1 && c2==1){
			x1[m]=x[i+1];
			y1[m]=y[i+1];
			m++;
		}
		else if(c1==1 && c2==0){
			a=xmin;
			b=x_intersect(xmin,x[i],y[i],x[i+1],y[i+1]);
			x1[m]=a;
			y1[m]=b;
			m++;
		}
		else if(c1==0 && c2==1){
			a=xmin;
			b=x_intersect(xmin,x[i],y[i],x[i+1],y[i+1]);
			x1[m]=a;y1[m]=b;
			x1[m+1]=x[i+1];y1[m+1]=y[i+1];
			m+=2;
		}
	}
	for(i=0;i<m;i++){
		x[i]=x1[i];
		y[i]=y1[i];
	}
	x[m]=x1[0];
	y[m]=y1[0];
	m++;
	n=m;
	m=0;



	for(i=0;i<n-1;i++){
		int c1=xmax_in(x[i],y[i],xmax);
		int c2=xmax_in(x[i+1],y[i+1],xmax);
		if(c1==1 && c2==1){
			x1[m]=x[i+1];
			y1[m]=y[i+1];
			m++;
		}
		else if(c1==1 && c2==0){
			a=xmax;
			b=x_intersect(xmax,x[i],y[i],x[i+1],y[i+1]);
			x1[m]=a;
			y1[m]=b;
			m++;
		}
		else if(c1==0 && c2==1){
			a=xmax;
			b=x_intersect(xmax,x[i],y[i],x[i+1],y[i+1]);
			x1[m]=a;y1[m]=b;
			x1[m+1]=x[i+1];y1[m+1]=y[i+1];
			m+=2;
		}
	}
	for(i=0;i<m;i++){
		x[i]=x1[i];
		y[i]=y1[i];
	}
	x[m]=x1[0];
	y[m]=y1[0];
	m++;
	n=m;
	m=0;
	setcolor(4);
	draw(x,y,n);
	delay(4000);

	/*
	for(i=0;i<n-1;i++){
		int c1=ymax_in(x[i],y[i],ymax);
		int c2=ymax_in(x[i+1],y[i+1],ymax);
		if(c1==1 && c2==1){
			x1[m]=x[i+1];
			y1[m]=y[i+1];
			m++;
		}
		else if(c1==1 && c2==0){
			b=ymax;
			a=y_intersect(ymax,x[i],y[i],x[i+1],y[i+1]);
			x1[m]=a;
			y1[m]=b;
			m++;
		}
		else if(c1==0 && c2==1){
			b=ymax;
			a=y_intersect(ymax,x[i],y[i],x[i+1],y[i+1]);
			x1[m]=a;y1[m]=b;
			x1[m+1]=x[i+1];y1[m+1]=y[i+1];
			m+=2;
		}
	}
	for(i=0;i<m;i++){
		x[i]=x1[i];
		y[i]=y1[i];
	}
	x[m]=x1[0];
	y[m]=y1[0];
	m++;
	n=m;
	m=0;
	for(i=0;i<n-1;i++){
		int c1=ymin_in(x[i],y[i],ymin);
		int c2=ymin_in(x[i+1],y[i+1],ymin);
		if(c1==1 && c2==1){
			x1[m]=x[i+1];
			y1[m]=y[i+1];
			m++;
		}
		else if(c1==1 && c2==0){
			b=ymin;
			a=y_intersect(ymin,x[i],y[i],x[i+1],y[i+1]);
			x1[m]=a;
			y1[m]=b;
			m++;
		}
		else if(c1==0 && c2==1){
			b=ymin;
			a=y_intersect(ymin,x[i],y[i],x[i+1],y[i+1]);
			x1[m]=a;y1[m]=b;
			x1[m+1]=x[i+1];y1[m+1]=y[i+1];
			m+=2;
		}
	}
	for(i=0;i<m;i++){
		x[i]=x1[i];
		y[i]=y1[i];
	}
	x[m]=x1[0];
	y[m]=y1[0];
	m++;
	n=m;
	m=0;
	setcolor(4);
	draw(x,y,n);
	delay(4000);
	*/
	closegraph();

}
/*

4
200 50
150 150
250 150
300 50
100 200 100 200

*/


/*

8
100 70
200 100
100 200
50 100
15 300
150 450
350 100
200 30
30 300 50 400


*/
