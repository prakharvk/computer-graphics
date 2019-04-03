#include<stdio.h>
#include<graphics.h>
struct pt{
    dd x;
    dd y;
    dd z;
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

}
