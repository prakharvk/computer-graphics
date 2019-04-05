#include<bits/stdc++.h>
using namespace std;
float refresh[1000][1000];
int r[1000][1000],g[1000][1000],b[1000][1000];
struct EdgeTuple{
	float xofymin,minv;
	int ymax;
};
struct EdgeTable{
	int count;
	EdgeTuple bucket[10];
};
bool comp(EdgeTuple a,EdgeTuple b){
	return a.xofymin<b.xofymin;
}
void insertintotable(EdgeTable *edgetable,int ymax,float xofymin,float minv){
	edgetable->bucket[edgetable->count].ymax = ymax;
	edgetable->bucket[edgetable->count].xofymin = xofymin;
	edgetable->bucket[edgetable->count].minv = minv;
	edgetable->count++;
	//cout<<ymax<<" "<<xofymin<<" "<<minv<<endl;
	sort(edgetable->bucket,edgetable->bucket+edgetable->count,comp);
}
void makeEdgeTuple(EdgeTable table[],int x1,int y1,int x2,int y2){
	float m,minv,xofymin;
	int ymax,scanline;
	if(y1==y2)
		return;
	if(x1==x2){
		minv = 0.000000;
	}else{
		m = (float)(y2-y1)/(float)(x2-x1);
		minv =  1.0/m;
	}
	if(y1<y2){
		ymax = y2;
		xofymin = x1;
		scanline = y1;
	}else{
		ymax = y1;
		xofymin = x2;
		scanline = y2;
	}
	// cout<<ymax<<" "<<xofymin<<" "<<minv<<" yesss"<<endl;
	insertintotable(&table[scanline],ymax,xofymin,minv);
}
void removefromactivelist(EdgeTable *activeList,int i){
	for(int j=0;j<activeList->count;j++){
		if(i==activeList->bucket[j].ymax){
			for(int k=j;k<activeList->count-1;k++){
				activeList->bucket[k]=activeList->bucket[k+1];
			}
			activeList->count--;
			j--;
		}
	}
}
float zatx1(float x,float y,float a,float b,float c,float d){
	return (-d-a*x-b*y)/c;
}
void updatexofymin(EdgeTable *activeList){
	for(int i=0;i<activeList->count;i++){
		activeList->bucket[i].xofymin = activeList->bucket[i].xofymin+activeList->bucket[i].minv;
	}
}
void scanline(EdgeTable *activeList,EdgeTable table[],int color,float A,float B,float C,float D){
	for(int i=0;i<1000;i++){
		for(int j=0;j<table[i].count;j++){
			cout<<table[i].bucket[j].ymax<<" "<<table[i].bucket[j].xofymin<<" "<<table[i].bucket[j].minv<<endl;
			insertintotable(activeList,table[i].bucket[j].ymax,table[i].bucket[j].xofymin,
					table[i].bucket[j].minv);

		}
		removefromactivelist(activeList,i);
		sort(activeList->bucket,activeList->bucket+activeList->count,comp);
		for(int j=1;j<activeList->count;j++){
			if(j%2){
				int x1=activeList->bucket[j-1].xofymin;
				int x2=activeList->bucket[j].xofymin;
				float z = zatx1(x1,i,A,B,C,D);
				for(int k=x1;k<=x2;k++){
					if(z>refresh[i][k]){
						if(color==1){
							r[i][k]=255;
						}else if(color==2){
							g[i][k]=255;
						}else{
							b[i][k]=255;
						}
						refresh[i][k]=z;
					}
					z = z - A/C;
				}
			}
		}
		updatexofymin(activeList);

	}
}
int main(){
	EdgeTable table[1000],activeList;
	for(int i=0;i<1000;i++){
			table[i].count=0;
		}
		activeList.count=0;
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			refresh[i][j]=INT_MIN;
			r[i][j]=g[i][j]=b[i][j]=0;
		}
	}
	cout<<"Enter number of edges of first surface"<<endl;
	int numEdge;
	cin>>numEdge;
	cout<<"Enter edges "<<endl;
	for(int i=0;i<numEdge;i++){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		makeEdgeTuple(table,x1,y1,x2,y2);
	}

	cout<<"enter A,B,C and D coefficients of plane"<<endl;
	float A,B,C,D;
	cin>>A>>B>>C>>D;
	scanline(&activeList,table,1,A,B,C,D);
	for(int i=0;i<1000;i++){
		table[i].count=0;
	}
	activeList.count=0;
	cout<<"Enter number of edges of second polygon"<<endl;
	cin>>numEdge;
	cout<<"enter egdes"<<endl;
	for(int i=0;i<numEdge;i++){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		makeEdgeTuple(table,x1,y1,x2,y2);
	}
	cout<<"enter A,B,C and D coefficients of plane"<<endl;
	cin>>A>>B>>C>>D;
	scanline(&activeList,table,2,A,B,C,D);
	FILE *fp = fopen("C:\\Users\\khobaib\\Desktop\\zbuffer.ppm","wb");
	fprintf(fp,"P3\n1000 1000\n255\n");
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			fprintf(fp,"%d %d %d ",r[j][i],g[j][i],b[j][i]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	return 0;
}
