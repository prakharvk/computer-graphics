#include<stdio.h>
#include<graphics.h>
int gd=DETECT,gm=0;
void tr(int x,int y,int ox,int oy,int c){
    putpixel(x+ox,y+oy,c);

}
void hyper(int a,int b){
    int i=0,j=0;
    double d=a*a+(a*a)/(b*b*1.0)-0.25;
    do{
        // tr(i,j,0,150,15);
        // tr(i,-j,0,150,15);
        printf("%d %d\n",i,j);
        if(d>0){
            d=d+((2*j+3)*a*a)/(b*b*1.0)-(2*i+2);
            i++;
        }else{
            d=d+((2*j+3)*a*a)/(b*b*1.0);
        }
        j++;
    }while(i<=a/(sqrt(a*a-b*b)));
}

void main(){
    //initgraph(&gd,&gm,0);
    //hyper(,);
    delay(5000);
    //closegraph();
}
