#include<stdio.h>
#include<graphics.h>
#include<math.h>
int gd=DETECT,gm=0;
double PI=acos(-1.0);
struct pt{
	int x;
	int y;
};
struct map{
	int a;
	int b;
};
void original(struct pt a[],struct map s[],int n){
	int i;
	for(i=0;i<n;i++){
		line(a[s[i].a].x,a[s[i].a].y,a[s[i].b].x,a[s[i].b].y);
	}
}

void matmul(double a[3][3],int b[3],int c[3]){
    int i,j,k;
    for(i=0;i<3;i++){
        c[i]=0;
        for(j=0;j<3;j++)
            c[i]+=a[i][j]*b[j];
    }
}

void scale(int p[3],int sx,int sy){
    double a[3][3];
    int pt[3];
    memset(a,0,sizeof(a));
    a[0][0]=sx;
    a[1][1]=sy;
    a[2][2]=1;
    matmul(a,p,pt);
    p[0]=pt[0];
    p[1]=pt[1];
}

void rotate(int p[3],double rad){
    rad=(rad*PI)/180.0;
    double a[3][3];
    int pt[3];
    memset(a,0,sizeof(a));
    a[0][0]=cos(rad);
    a[0][1]=-sin(rad);
    a[1][0]=sin(rad);
    a[1][1]=cos(rad);
    a[2][2]=1;
    matmul(a,p,pt);
    p[0]=pt[0];
    p[1]=pt[1];
}

void shear(int p[3],int k,int f){
    double a[3][3];
    int pt[3];
    memset(a,0,sizeof(a));
    if(f){
        a[0][0]=1;
        a[0][1]=k;
        a[1][1]=1;
    }else{
        a[1][0]=k;
        a[1][1]=1;
        a[0][0]=1;
    }
    a[2][2]=1;
    matmul(a,p,pt);
    p[0]=pt[0];
    p[1]=pt[1];
}

void rotate_fig(struct pt a[],int n,double rad){
    int i;
    for(i=0;i<n;i++){
        int p[3];
        p[0]=a[i].x;
        p[1]=a[i].y;
        p[2]=1;
        rotate(p,rad);
        a[i].x=p[0];
        a[i].y=p[1];
    }
}

void shear_fig(struct pt a[],int n,int k,int f){
    int i;
    for(i=0;i<n;i++){
        int p[3];
        p[0]=a[i].x;
        p[1]=a[i].y;
        p[2]=1;
        shear(p,k,f);
        a[i].x=p[0];
        a[i].y=p[1];
    }
}
void scale_fig(struct pt a[],int n,int sx,int sy){
    int i;
    for(i=0;i<n;i++){
        int p[3];
        p[0]=a[i].x;
        p[1]=a[i].y;
        p[2]=1;
        scale(p,sx,sy);
        a[i].x=p[0];
        a[i].y=p[1];
    }
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
    initgraph(&gd,&gm,0);
    original(a,e,n);
    scale_fig(a,n,2,1);
    setcolor(4);
    original(a,e,n);
    delay(4000);
    closegraph();
    for(i=0;i<n;i++)
        printf("%d %d\n",a[i].x,a[i].y);
}
/*

4
50 50
50 100
100 50
100 100
1 2
1 3
4 2
4 3

*/
