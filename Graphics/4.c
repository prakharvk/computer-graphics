#include<stdio.h>
#include<graphics.h>
int gd=DETECT,gm=0;

void dcircle(int x,int y,int r){
    int i=0,j=r;
    int d=3-2*r;
    while(i<=j){
        putpixel(x+i,y+j,WHITE);
        putpixel(x-i,y+j,WHITE);
        putpixel(x+i,y-j,WHITE);
        putpixel(x-i,y-j,WHITE);

        putpixel(x+j,y+i,WHITE);
        putpixel(x-j,y+i,WHITE);
        putpixel(x+j,y-i,WHITE);
        putpixel(x-j,y-i,WHITE);


        if(d>=0){
            d=d+10+4*(i-j);
            i++;
            j--;
        }else{
            d=d+6+4*i;
            i++;
        }
    }
}

void main(){
    initgraph(&gd,&gm,0);
    dcircle(100,100,50);
    delay(3000);
    closegraph();
}
