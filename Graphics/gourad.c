#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#define dd double
#define N 11
struct pt{
    dd x;
    dd y;
    dd z;
};
dd ia=1,ka=0.1,ip=10,kd=0.1,ks=0.8;
dd dot(struct pt n,struct pt v){
    return n.x*v.x + n.y*v.y + n.z*v.z;
}
dd norm(struct pt v){
    return sqrt(dot(v,v));
}
dd cos_angle(struct pt n,struct pt v){
    dd p = dot(n,v);
    return (p/(norm(n)*norm(v)));
}
dd intensity(struct pt n,struct pt v){
    return ia*ka + ip*kd + ip*ks*cos_angle(v,n);
}
void main(){
    struct pt n[8];
    n[7].x=1;n[7].y=1;n[7].z=1;
    n[1].x=-5;n[1].y=-9;n[1].z=45; // a
    n[3].x=-4;n[3].y=-4;n[3].z=20; // c
    n[5].x=-9;n[5].y=5;n[5].z=45; // d
    n[0].x=0;n[0].y=0;n[0].z=56; // m
    // e
    n[6].x = (n[1].x+n[3].x+n[0].x);
    n[6].y=(n[1].y+n[3].y+n[0].y);
    n[6].z=(n[1].z+n[3].z+n[0].z);
    // f
    n[4].x = (n[5].x+n[3].x+n[0].x);
    n[4].y=(n[5].y+n[3].y+n[0].y);
    n[4].z=(n[5].z+n[3].z+n[0].z);
    // b
    n[2].x = (n[1].x+n[5].x+n[0].x);
    n[2].y=(n[1].y+n[5].y+n[0].y);
    n[2].z=(n[1].z+n[5].z+n[0].z);
    int i;
    for(i=1;i<7;i++){
        dd in = intensity(n[7],n[i]);
        printf("Intensity at %d %lf\n",i,in);
    }



}
