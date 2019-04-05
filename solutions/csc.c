#include<stdio.h>
#include<graphics.h>
int gd=DETECT,gm=0;

int code(int x,int y,int xmin,int xmax,int ymin,int ymax){
	int r=0;
	if(x<xmin)
		r=r|(1<<0);
	if(x>xmax)
		r=r|(1<<1);
	if(y>ymax)
		r=r|(1<<2);
	if(y<ymin)
		r=r|(1<<3);
	return r;
}

void main(){
	int x1,y1,x2,y2,i;
	int xmin,xmax,ymin,ymax;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	scanf("%d %d %d %d",&xmin,&xmax,&ymin,&ymax);
	int r1=code(x1,y1,xmin,xmax,ymin,ymax);
	int r2=code(x2,y2,xmin,xmax,ymin,ymax);
	int c=r1&r2;
//	printf("%d %d %d\n",r1,r2,c);

	initgraph(&gd,&gm,0);
	line(x1,y1,x2,y2);

	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	line(xmax,ymin,xmin,ymin);


	if(r1==0 && r2==0){
		printf("No clipping required\n");
	}else if(c!=0){
		printf("Entire line is outside\n");
		x1=x2=0;
		y1=y2=0;
	}else{
		for(i=0;i<4;i++){
			int b1=r1&(1<<i);
			int b2=r2&(1<<i);
			int x,y;
			double m=(1.0*(y2-y1))/(x2-x1);
	
			if(b1!=b2){
				if(i==0){
					x=xmin;
					y=y1+m*(xmin-x1);
					if(x1<xmin){
						x1=x;y1=y;
					}else{
						x2=x;y2=y;
					}
				}
				else if(i==1){
					x=xmax;
					y=y1+m*(xmax-x1);
					if(x1>xmax){
						x1=x;y1=y;
					}else{
						x2=x;y2=y;
					}

				}else if(i==2){
					y=ymax;
					x=x1+((ymax-y1)*1.0)/m;
					if(y1>ymax){
						x1=x;y1=y;
					}else{
						x2=x;y2=y;
					}

				}else{
					y=ymin;
					x=x1+((ymin-y1)*1.0)/m;
					if(y1<ymin){
						x1=x;y1=y;
					}else{
						x2=x;y2=y;
					}

				}
			}
			r1=code(x1,y1,xmin,xmax,ymin,ymax);
			r2=code(x2,y2,xmin,xmax,ymin,ymax);
			//printf("%d %d %d %d %d\n",i,x1,y1,x2,y2);

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

100 50 200 250
100 200 100 200
*/
