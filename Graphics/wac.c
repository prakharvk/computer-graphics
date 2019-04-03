#include<stdio.h>
#include<graphics.h>
int gd=DETECT,gm=0;

void main(){
	int n,i;
	scanf("%d",&n);
	int x[1+n],y[1+n];
	for(i=0;i<n;i++)
		scanf("%d %d",&x[i],&y[i]);
	x[n]=x[0];y[n]=y[0];
	n++;
}
