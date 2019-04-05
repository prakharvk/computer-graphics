#include<bits/stdc++.h>
using namespace std;
int r[500][500],g[500][500],b[500][500];
float ka,Ia,kd,Id,ks,Il,Ns;
float vx,vy,vz;
float psx,psy,psz;
float nx,ny,nz;
float A,B,C,D;
struct EdgeBucket{
    int ymax,ydiff;
    float xofymin;
    float slopeinv;
    float iymax,iymin,curri;
};
struct EdgeTable{
    int no_of_buckets;
    EdgeBucket bukets[10];
};
struct line{
    int x1,x2,y1,y2;
};
bool comp(EdgeBucket eb1,EdgeBucket eb2){
    return eb1.xofymin<eb2.xofymin;
}
void insertedgeintotable(EdgeTable *receiver,int ymax,float xofymin,float minv,float iymin,float iymax,int ydiff,float curri){
    receiver->bukets[receiver->no_of_buckets].xofymin = xofymin;
    receiver->bukets[receiver->no_of_buckets].ymax = ymax;
    receiver->bukets[receiver->no_of_buckets].slopeinv = minv;
    receiver->bukets[receiver->no_of_buckets].iymin=iymin;
    receiver->bukets[receiver->no_of_buckets].iymax=iymax;
    receiver->bukets[receiver->no_of_buckets].ydiff=ydiff;
    receiver->bukets[receiver->no_of_buckets].curri=curri;
    receiver->no_of_buckets++;
    sort(receiver->bukets,receiver->bukets+receiver->no_of_buckets,comp);
}
float calculatez(float x,float y){
	return (-A*x-B*y-D)/C;
}
float modvalue(float x,float y,float z){
	return sqrt(x*x+y*y+z*z);
}
float calculateintensity(float x,float y,float z){
	float vxdash = vx-x;
	float vydash = vy-y;
	float vzdash = vz-z;
	float mod = modvalue(vxdash,vydash,vzdash);
	vxdash/=mod;
	vydash/=mod;
	vzdash/=mod;
	float lx = psx-x;
	float ly = psy-y;
	float lz = psz-z;
	mod = modvalue(lx,ly,lz);
	lx/=mod;
	ly/=mod;
	lz/=mod;
	float rx = (2*nx*lx+2*ny*ly+2*nz*lz)*nx-lx;
	float ry = (2*nx*lx+2*ny*ly+2*nz*lz)*ny-ly;
	float rz = (2*nx*lx+2*ny*ly+2*nz*lz)*nz-lz;
	mod = modvalue(rx,ry,rz);
	rx/=mod;
	ry/=mod;
	rz/=mod;
	cout<<(rx*vxdash+ry*vydash+rz*vzdash)<<endl;
	return ka*Ia+kd*Id+ks*Il*pow((rx*vxdash+ry*vydash+rz*vzdash),Ns);

}
void insertlineintotable(struct line l,EdgeTable table[]){
    if(l.y1==l.y2){
        return;
    }
    float m,minv,xofymin,iymax,iymin,curri,xmax;
    int ymax,scanline,ydiff;
    if(l.x1==l.x2){
        minv = 0.000000;
    }else{
        m = (float)(l.y2-l.y1)/(float)(l.x2-l.x1);
        minv = 1.0/m;
    }
    if(l.y1<l.y2){
    	xofymin = l.x1;
    	ymax = l.y2;
    	scanline = l.y1;
    	ydiff = l.y2-l.y1;
    	xmax = l.x2;

    }else{
        xofymin = l.x2;
        ymax = l.y1;
        scanline = l.y2;
        ydiff = l.y1-l.y2;
        xmax = l.x1;
    }
    float zmin = calculatez(xofymin,ymax-ydiff);
    float zmax = calculatez(xmax,ymax);
    cout<<zmin<<" "<<zmax<<endl;
    curri = iymin = calculateintensity(xofymin,ymax-ydiff,zmin);
    iymax = calculateintensity(xmax,ymax,zmax);
    insertedgeintotable(&table[scanline],ymax,xofymin,minv,iymin,iymax,ydiff,curri);
}
void removetuplebyymax(EdgeTable *activeTable,int ymax){
    for(int i=0;i<activeTable->no_of_buckets;i++){
    	//cout<<activeTable->bukets[i].ymax<<endl;
        if(activeTable->bukets[i].ymax==ymax){
            for(int j=i;j<activeTable->no_of_buckets-1;j++){
                activeTable->bukets[j]=activeTable->bukets[j+1];
            }
            activeTable->no_of_buckets--;
            i--;
        }

    }
}
void updateslope(EdgeTable *activeTable){
    for(int i=0;i<activeTable->no_of_buckets;i++){
        activeTable->bukets[i].xofymin+=activeTable->bukets[i].slopeinv;
        activeTable->bukets[i].curri+=(activeTable->bukets[i].iymax-activeTable->bukets[i].iymin)/(float)(activeTable->bukets[i].ydiff);
    }
}
void scanline(EdgeTable activeTable,EdgeTable table[]){
    for(int i=0;i<500;i++){
        for(int j=0;j<table[i].no_of_buckets;j++){
            insertedgeintotable(&activeTable,table[i].bukets[j].ymax,
                                table[i].bukets[j].xofymin,table[i].bukets[j].slopeinv,table[i].bukets[j].iymin,
								table[i].bukets[j].iymax,table[i].bukets[j].ydiff,
								table[i].bukets[j].curri);
        }
        removetuplebyymax(&activeTable,i);
        //cout<<i<<" "<<activeTable.no_of_buckets<<endl;
        sort(activeTable.bukets,activeTable.bukets+activeTable.no_of_buckets,comp);
        for(int j=1;j<activeTable.no_of_buckets;j++){
            if(j%2){
            	float i1 = activeTable.bukets[j-1].curri;
            	float i2 = activeTable.bukets[j].curri;
            	float intensity = activeTable.bukets[j-1].curri;
            	float x2 = activeTable.bukets[j].xofymin;
            	float x1 = activeTable.bukets[j-1].xofymin;
                for(int k=x1;k<=x2;k++){
                    r[k][i] = max(max(0,(int)intensity),min(255,(int)intensity));
                    //cout<<r[k][i]<<endl;
                    intensity+=(i2-i1)/(x2-x1);
                }
            }
        }
        updateslope(&activeTable);
    }
}
int main(){
	cout<<"enter number of edges"<<endl;
	int num;
	cin>>num;
	cout<<"Enter A,B,C,D coefficients of plane"<<endl;
	cin>>A>>B>>C>>D;
	cout<<"Enter x,y and z components of normal vector of plane"<<endl;
	cin>>nx>>ny>>nz;
	cout<<"Enter values Ka, Ia, Kd, Id, ks, Il, Ns: "<<endl;
	cin>>ka>>Ia>>kd>>Id>>ks>>Il>>Ns;
	cout<<"Enter position of eye x, y and z component"<<endl;
	cin>>vx>>vy>>vz;
	cout<<"Enter position of point source x,y and z component"<<endl;
	cin>>psx>>psy>>psz;
   EdgeTable table[500],activeTable;
   activeTable.no_of_buckets=0;
   for(int i=0;i<500;i++){
            table[i].no_of_buckets = 0;
        for(int j=0;j<500;j++){
            r[i][j]=g[i][j]=b[i][j]=0;
        }
    }
   	  line k;
   	  cout<<"enter x1 y1 x2 y2 of edges"<<endl;
    for(int i=0;i<num;i++){
        cin>>k.x1>>k.y1>>k.x2>>k.y2;
        insertlineintotable(k,table);
    }

    scanline(activeTable,table);
    FILE *fp = fopen("C:\\Users\\khobaib\\Desktop\\scanline.ppm","wb");
    fprintf(fp,"P3\n500 500\n255\n");
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            fprintf(fp,"%d %d %d ",r[j][i],g[j][i],b[j][i]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    return 0;
}
/*
 Test case
3
0 0 1 0
0 0 1
0.01 100 0.01 100 0.8 100000 2
1 1 1
0 0 10000
10 200 100 300
100 300 200 100
200 100 10 200
*/
 */
