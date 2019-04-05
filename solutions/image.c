#include<stdio.h>
#include<math.h>
#include<graphics.h>

double PI = acos(-1);

int R[200][200]={0}, G[200][200]={0}, B[200][200]={0};
int H[200][200]={0}, S[200][200]={0}, I[200][200]={0};

int gd=DETECT,gm=0;
int min(int a,int b){
	return (a<b)?a:b;
}

void cl(int x,int y,int r,int g,int b){
	R[x][y] = r;
	G[x][y] = g;
	B[x][y] = b;
}


void ffill(int x,int y,int xc,int yc,int a,int b,int rc,int gc,int bc){
	if( (b*b*x*x + a*a*y*y - a*a*b*b >= 0) || (R[x+xc][y+yc]==rc && B[xc+x][yc+y]==bc && G[xc+x][yc+y]==gc) )
		return;
	cl(x+xc,y+yc,rc,gc,bc);
	ffill(x-1,y,xc,yc,a,b,rc,gc,bc);
	ffill(x+1,y,xc,yc,a,b,rc,gc,bc);
	ffill(x,y+1,xc,yc,a,b,rc,gc,bc);
	ffill(x,y-1,xc,yc,a,b,rc,gc,bc);

}
void dellipse(int x,int y,int a,int b,int rc,int gc,int bc){
	int i=0,j=b,p;
	p=b*b+(0.5)*a*a-a*a*b;
	while(i*b*b<=a*a*j){
		cl(x+i,x+j,rc,gc,bc);
		cl(x-i,x+j,rc,gc,bc);
		cl(x+i,x-j,rc,gc,bc);
		cl(x-i,x-j,rc,gc,bc);


		if(p<0){
			p=p+b*b*(2*i+1)+2*b*b;
		}else{
			p=p+2*b*b*(i+1)-2*a*a*(j-1)+b*b;
			j--;
		}
		i++;
	}

	p=b*b*(i+0.5)*(i+0.5) + a*a*(j-1)*(j-1)-a*a*b*b;

	while(j>=0){
		cl(x+i,x+j,rc,gc,bc);
		cl(x-i,x+j,rc,gc,bc);
		cl(x+i,x-j,rc,gc,bc);
		cl(x-i,x-j,rc,gc,bc);


		if(p>=0){
			p=p-a*a*(2*j-1)+2*a*a;
		}else{
			p=p-2*a*a*(j-1)+2*b*b*(i+1)+a*a;
			i++;
		}
		j--;
	}
}

int main(){
	int i,j;
	for(i=0; i<200; i++){
		for(j=0; j<200; j++)
			cl(i,j,50,10,200);
	}
	dellipse(100,100,50,35,10,200,50);
	dellipse(100,100,25,25,200,50,10);
	ffill(0,0,100,100,50,35,10,200,50);
	ffill(0,0,100,100,25,25,200,50,10);


	FILE *f;
	f = fopen("rgb.ppm","w");
	fprintf(f, "P3# CREATOR: GIMP PNM Filter Version 1.1\n200 200\n255\n");

	for(i=0; i<200; i++){
		for(j=0; j<200; j++){
			fprintf(f,"%d ",R[i][j]);
			fprintf(f,"%d ",G[i][j]);
			fprintf(f,"%d ",B[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);

	for(i=0;i<200;i++){
		for(j=0;j<200;j++){
			double n = 0.5*(2*R[i][j]-B[i][j]-G[i][j]);
			double d = (R[i][j]-G[i][j])*(R[i][j]-G[i][j]) + (R[i][j]-B[i][j])*(G[i][j]-B[i][j]);
			double theta = acos(n/sqrt(d))*(180.0/acos(-1))  ;
			if(B[i][j]<=G[i][j])
				H[i][j]=theta;
			else
				H[i][j]=360-theta;
			S[i][j]=1-(3*(min(R[i][j],min(B[i][j],G[i][j]))))/(R[i][j]+B[i][j]+G[i][j]);
			I[i][j]=(R[i][j]+B[i][j]+G[i][j])/3;
		}
	}
	f = fopen("hsi.ppm","w");
	fprintf(f, "P3# CREATOR: GIMP PNM Filter Version 1.1\n200 200\n200\n");

	for(i=0; i<200; i++){
		for(j=0; j<200; j++){
			fprintf(f,"%d ",H[i][j]);
			fprintf(f,"%d ",S[i][j]);
			fprintf(f,"%d ",I[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);

	for(i=0;i<200;i++){
		for(j=0;j<200;j++){
			S[i][j]*=1.1;
			I[i][j]+=50;
		}
	}
	//
	// f = fopen("hsi_1.ppm","w");
	// fprintf(f, "P3# CREATOR: GIMP PNM Filter Version 1.1\n200 200\n200\n");
	//
	// for(i=0; i<200; i++){
	// 	for(j=0; j<200; j++){
	// 		fprintf(f,"%d ",H[i][j]);
	// 		fprintf(f,"%d ",S[i][j]);
	// 		fprintf(f,"%d ",I[i][j]);
	// 	}
	// 	fprintf(f, "\n");
	// }
	// fclose(f);
	//
	for(i=0;i<200;i++){
		for(j=0;j<200;j++){
			if(H[i][j]<120){

				double n=S[i][j]*cos((H[i][j]*PI)/(180.0));
				double d=cos((60-H[i][j])/(180.0)*PI);


				B[i][i]=I[i][j]*(1-S[i][j]);
				R[i][j]=I[i][j]*(1+(n/d));
				G[i][j]=3*I[i][j]-(R[i][j]+B[i][j]);


			}else if(H[i][j]>=120 && H[i][j]<240){
				H[i][j]-=120;

				double n=S[i][j]*cos((H[i][j]*PI)/(180.0));
				double d=cos((60-H[i][j])/(180.0)*PI);

				R[i][j]=I[i][j]*(1-S[i][j]);
				G[i][j]=I[i][j]*(1+(n/d));
				B[i][j]=3*I[i][j]-(R[i][j]+G[i][j]);

			}else{
				H[i][j]-=240;
				double n=S[i][j]*cos((H[i][j]*PI)/(180.0));
				double d=cos((60-H[i][j])/(180.0)*PI);

				G[i][j]=I[i][j]*(1-S[i][j]);
				B[i][j]=I[i][j]*(1+(n/d));
				R[i][j]=3*I[i][j]-(B[i][j]+G[i][j]);
			}
		}
	}

	f = fopen("rgb_1.ppm","w");
	fprintf(f, "P3# CREATOR: GIMP PNM Filter Version 1.1\n200 200\n255\n");

	for(i=0; i<200; i++){
		for(j=0; j<200; j++){
			fprintf(f,"%d ",R[i][j]);
			fprintf(f,"%d ",G[i][j]);
			fprintf(f,"%d ",B[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	return 0;
}
