#include<stdio.h>
#include<graphics.h>
int gd=DETECT,gm=0;
struct pt{
    int x;
    int y;
    int z;
};
struct pt orthx(struct pt p){
    p.x=0;
    return p;
}
struct pt orthy(struct pt p){
    p.y=0;
    return p;
}
struct pt orthz(struct pt p){
    p.z=0;
    return p;
}
void main(){
    int x=50,y=50,h=100,w=100;
    initgraph(&gd,&gm,0);

    line(x,y,x+w,y);
	line(x,y,x,y+h);
	line(x+w,y,x+w,y+h);
	line(x,y+h,x+w,y+h);
    delay(4000);
    closegraph();
}
