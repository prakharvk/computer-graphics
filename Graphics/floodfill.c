#include<stdio.h>
#include<graphics.h>
struct pt{
	int x;
	int y;
};
struct map{
		int a;
		int b;
};
int gd=DETECT,gm=0;
void original(struct pt a[],struct map s[],int n,int c){
	int i;
	for(i=0;i<n;i++){
		line(a[s[i].a].x,a[s[i].a].y,a[s[i].b].x,a[s[i].b].y);
	}
}
void ffill(int x,int y,int c){
	if(x<0 || y<0)
		return;
	if(getpixel(x,y)==c)
		return;
	putpixel(x,y,c);
	ffill(x-1,y,c);
	ffill(x+1,y,c);
	ffill(x,y-1,c);
	ffill(x,y+1,c);
}
void main(){
	int n,i,x,y;
	scanf("%d",&n);

	struct pt a[n];
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
	x=(float)(a[0].x+a[1].x+a[2].x)/3.0;
	y=(float)(a[0].y+a[1].y+a[2].y)/3.0;
	initgraph(&gd,&gm,0);
	original(a,e,n,15);
	ffill(x,y,15);
	delay(4000);
	closegraph();
}
/*
3
100 100
200 200
100 200
1 2
1 3
3 2

*/
