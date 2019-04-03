#include<stdio.h>
#include<graphics.h>

int gd=DETECT,gm=0;
struct pt{
	int x;
	int y;
};
struct map{
	int a;
	int b;
};

void original(struct pt a[],struct map s[],int n,int ox,int oy){
	int i;
	for(i=0;i<n;i++){
		line(a[s[i].a].x+ox,a[s[i].a].y+oy,a[s[i].b].x+ox,a[s[i].b].y+oy);
	}
}

void reflect_x(struct pt a[],int n){
	int i;
	for(i=0;i<n;i++)
		a[i].x*=-1;
}

void reflect_y(struct pt a[],int n){
	int i;
	for(i=0;i<n;i++)
		a[i].y*=-1;
}

void reflect_xy(struct pt a[],int n){
	int i;
	for(i=0;i<n;i++){
		int t=a[i].x;
		a[i].x=a[i].y;
		a[i].y=t;
	}
}

void main(){
	int n,i,x,y;
	scanf("%d",&n);
	struct pt a[n],axis;
	struct map e[n];
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		a[i].x=x;
		a[i].y=y;
	}
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		e[i].a=x-1;
		e[i].b=y-1;
	}
	initgraph(&gd,&gm,0);
	original(a,e,n,0,0);
	reflect_xy(a,n);
	setcolor(4);
	original(a,e,n,0,0);
	delay(5000);
	closegraph();
	for(i=0;i<n;i++)
		printf("%d %d\n",a[i].x,a[i].y);
}

/*

3
100 150
200 250
100 250
1 2
1 3
3 2

*/
