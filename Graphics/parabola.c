#include<stdio.h>
#include<graphics.h>
int gd=DETECT,gm=0;

void tr(int x,int y,int ox,int oy,int c){
    putpixel(x+ox,y+oy,c);

}

void para(int a){
    int i=0,j=0;
    double d=-0.5;
    for(;j<2*a;j++){
        tr(i,j,0,250,15);
        tr(i,-j,0,250,15);
        if(d>0){
            d=d+(2*j+3)/(4.0*a)-1;
            i++;
        }else{
            d=d+(2*j+3)/(4.0*a);
        }
    }
    d=2*a-0.25;
    for(i=a;i<250;i++){
        tr(i,j,0,250,4);
        tr(i,-j,0,250,4);
        if(d>0){
            d=d+4*a-(2*j+2);
            j++;
        }else{
            d=d+4*a;
        }
    }
}

void main(){
    initgraph(&gd,&gm,0);
    para(50);
    delay(5000);
    closegraph();
}
