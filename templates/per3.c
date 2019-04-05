#include<stdio.h>
#include<graphics.h>
#include<math.h>
double P = acos(-1);
int gd=DETECT,gm=0;
struct pt{
    int x;
    int y;
    int z;
};
struct edge{
    int m;
    int n;
};
void init(struct pt *p,int x,int y,int z){
    p->x=x;p->y=y;p->z=z;
}
void init1(struct edge *e,int p,int q){
    e->m=p;
    e->n=q;
}
struct pt project3(struct pt a,int cx,int cy,int cz){
    double d = a.x*(-1.0/cx) + a.y*(-1.0/cy) + a.z*(-1.0/cz) + 1;
    a.x/=d;
    a.y/=d;
    a.z=0;
    return a;
}
void main(){
    struct pt p[9];
    struct edge e[14];
    int s=100;
    init(&p[1],-s,s,-s);
    init(&p[2],s,s,-s);
    init(&p[3],s,-s,-s);
    init(&p[4],-s,-s,-s);
    init(&p[5],-s,s,s);
    init(&p[6],s,s,s);
    init(&p[7],s,-s,s);
    init(&p[8],-s,-s,s);

    init1(&e[1],1,2);init1(&e[2],1,4);init1(&e[3],1,5);
    init1(&e[4],2,3);init1(&e[5],2,6);
    init1(&e[6],3,4);init1(&e[7],3,7);
    init1(&e[8],4,8);
    init1(&e[10],5,6);init1(&e[11],5,8);
    init1(&e[12],6,7);
    init1(&e[13],7,8);

    int i;

    for(i=1;i<=8;i++)
        p[i]=project3(p[i],-10,-10,10);

    for(i=1;i<=8;i++)
        printf("%d %d %d\n",p[i].x,p[i].y,p[i].z);


    initgraph(&gd,&gm,0);
    for(i=1;i<=13;i++){
        if(p[e[i].m].z==0 && p[e[i].n].z==0)
            line(100+5*p[e[i].m].x,
                100+5*p[e[i].m].y,
                100+5*p[e[i].n].x,
                100+5*p[e[i].n].y);
    }
    delay(s00);
    closegraph();

}
