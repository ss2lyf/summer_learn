#include <iostream>
#include<queue>
#include<stdio.h>
int m[50][50][50];
int key[50][50][50];
using namespace std;
typedef struct point
{
    int x;
    int y;
    int z;
    int time;

} point;
queue<point> q;
/* input
3 3 4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0

*/

void push_point(point p,int a,int b,int c)
{
    int x,y,z,time;
    x=p.x+a;
    y=p.y+b;
    z=p.z+c;
    time=p.time;
    point temp;
    if(m[x][y][z]!=1&&key[x][y][z]==-1)
    {
        temp.x=x;
        temp.y=y;
        temp.z=z;
        temp.time=time+1;
        q.push(temp);
        key[x][y][z]=temp.time;
    }
}
void find_way(point a,int x,int y,int z)
{
    if(a.x>0)
    {
        push_point(a,-1,0,0);
    }
    if(a.x<x)
    {
        push_point(a,1,0,0);
    }
    if(a.y>0)
    {
        push_point(a,0,-1,0);
    }
    if(a.y<y)
    {
        push_point(a,0,1,0);
    }
    if(a.z>0)
    {
        push_point(a,0,0,-1);
    }
    if(a.z<z)
    {
        push_point(a,0,0,1);
    }
}


int main()
{
    int x,y,z;
    int t,loop,loop_i;
    int i,j,k,temp;
    point temp_point;
    scanf("%d",&loop);
    for(loop_i=0; loop_i<loop; loop_i++)
    {
        scanf("%d%d%d%d",&x,&y,&z,&t);
        for(i=0; i<x; i++)
        {
            for(j=0; j<y; j++)
            {
                for(k=0; k<z; k++)
                {
                    scanf("%d",&temp);
                    m[i][j][k]=temp;
                    key[i][j][k]=-1;
                }
            }
        }
        x--;
        y--;
        z--;
        temp_point.x=0;
        temp_point.y=0;
        temp_point.z=0;
        temp_point.time=00;
        q.push(temp_point);
        key[0][0][0]=0;

        while(!q.empty())
        {
            find_way(q.front(),x,y,z);
            q.pop();
        }

        if(key[x][y][z]>t)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<key[x][y][z]<<endl;
        }

    }
    return 0;
}
