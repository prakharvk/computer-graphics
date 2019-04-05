#include<bits/stdc++.h>
using namespace std;

int red[201][201],green[201][201],blue[201][201];
double hue[201][201],sat[201][201],inten[201][201];
double PI=acos(-1);

void RGBTOHSI(int i,int j){
	double r=red[i][j],g=green[i][j],b=blue[i][j];
	double th=acos(0.5*(r-g+r-b)/sqrt((r-g)*(r-g)+(r-b)*(g-b)));
	th*=180;
	th/=PI;
	if(b<=g)
		hue[i][j]=th;
	else
		hue[i][j]=360-th;
	sat[i][j]=1-3.0*min(min(r,g),b)/(r+g+b);
	inten[i][j]=(r+g+b)/3;
}

double toRad(double deg){
	return deg*PI/180;
}

void HSITORGB(int i,int j){
	double h=hue[i][j];
	double s=sat[i][j];
	double I=inten[i][j];
	if(h<120){
		red[i][j]=I*(1+s*cos(toRad(h))/(cos(toRad(60-h))));
		blue[i][j]=I*(1-s);
		green[i][j]=3*I-red[i][j]-blue[i][j];
	}else if(h<240){
		h-=120;
		red[i][j]=I*(1-s);
		green[i][j]=I*(1+s*cos(toRad(h))/(cos(toRad(60-h))));
		blue[i][j]=3*I-red[i][j]-green[i][j];
	}else{
		h-=240;	
		blue[i][j]=I*(1+s*cos(toRad(h))/(cos(toRad(60-h))));;
		green[i][j]=I*(1-s);
		red[i][j]=3*I-green[i][j]-blue[i][j];
	}

}			

void modify(int i,int j){
	sat[i][j]*=1.1;
	inten[i][j]+=50;
}

int main(){
	ifstream ip("rgb_image.ppm");
	string s;
	getline(ip,s);
	int v;
	ip>>v>>v>>v;

	for(int i=1;i<=200;i++)
		for(int j=1;j<=200;j++)
			ip>>red[i][j]>>green[i][j]>>blue[i][j];	
	
	for(int i=1;i<=200;i++){
		for(int j=1;j<=200;j++){
			RGBTOHSI(i,j);
			modify(i,j);
	    }
	}
	
	for(int i=1;i<=200;i++){
		for(int j=1;j<=200;j++){
			HSITORGB(i,j);
		}
	}

	ofstream op("hsi_image.ppm");
	op<<"P3# CREATOR: GIMP PNM Filter Version 1.1"<<endl;
	op<<"200 200"<<endl;
	op<<"255"<<endl;

	for(int i=1;i<=200;i++){
		for(int j=1;j<=200;j++)
			op<<red[i][j]<<" "<<green[i][j]<<" "<<blue[i][j]<<"\t";
		op<<endl;
	};

	op.close();
	cout<<"done"<<endl;	
	
	return 0;	
}
