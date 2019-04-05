#include<iostream>
#include<graphics.h>
using namespace std;

int dirx[] = {-1,0,1,0};
int diry[] = {0,-1,0,1};

void FLOOD_FILL(int x,int y)
{
    if(x<0 || y<0)
        return;
    if(getpixel(x,y)== WHITE || getpixel(x,y)==YELLOW)
        return;

    putpixel(x,y,YELLOW);
    for(int i=0 ; i<4 ; i++)
    {
        int next_x = x + dirx[i];
        int next_y = y + diry[i];
        FLOOD_FILL(next_x,next_y);
    }
    return;
}



//POLYGON FILLING : SCANLINE
int n,x[1005],y[1005];
int vis[1005];

void SCAN_LINE()
{
    int y_min=1000,y_max=0;
    for(int i=0 ; i<n ; i++)
    {
        y_min = min(y_min,y[i]);
        y_max = max(y_max,y[i]);
    }

    if(y_min>y_max)
        return;

    for(int cur_y = y_min ; cur_y <= y_max ; cur_y++)
    {
        vector<float> vt;
        for(int i=0 ; i<n ; i++)
        {
            float x0 = x[i];
            float y0 = y[i];
            float x1 = x[(i+1)%n];
            float y1 = y[(i+1)%n];
            if(y0 == y1)
                continue;
            if(vis[i])
            {
                if(y[(i+1)%n]-y[i]>0)
                    y0++;
                else
                    y0--;
            }
            float xx;
            if(x0 == x1)
            {
                xx=x0;
                if((cur_y>=y0 && cur_y<=y1) || (cur_y>=y1 && cur_y<=y0))
                {
                    vt.push_back(xx);
                }
                continue;
            }
            xx = x1 + (cur_y-y1)*(x1-x0)/(y1-y0);

            if((xx>=x0 && xx<=x1) || (xx>=x1 && xx<=x0))
            {
                vt.push_back(xx);
            }
        }
        sort(vt.begin(),vt.end());
        for(int i=0 ; i<vt.size()-1 ; i+=2)
        {
            int ff = vt[i];
            int ss = vt[i+1];
            for(int j = ff ; j <= ss ; j++)
            {
                putpixel(j,cur_y,WHITE);
            }
        }
    }
}
