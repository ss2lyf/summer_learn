#include <iostream>
#include <vector>
#include<algorithm>
#include<limits.h>
#include<math.h>
#include<iomanip>
using namespace std;
typedef struct road
{
    double a;
    double b;
    double d;
} road;
typedef struct point
{
    double x;
    double y;
} point;

int find_root(vector<int>&v,int a)
{
    if (v[a]!=-1)
    {
        int temp;
        temp=find_root(v,v[a]);
        v[a]=temp;
        return temp ;
    }
    else
    {
        return  a;
    }
}
bool cmp(road a,road b)
{
    return a.d<b.d;
}
void init(vector<int> &v,int num)
{
    int i;
    for(i=0; i<=num; i++)
    {
        v[i]=-1;
    }
}
int main()
{
    int num;
    int i,j;
    road temp_r;
    double temp;
    int temp_a,temp_b;
    double distance;
    distance=0;
    cin>>num;
    temp=(num*(num-1))/2;
    vector<int> v2(num+1);
    init(v2,num);
    vector<road> v;
    vector<point> v1(num);
    for(i=0; i<num; i++)
    {
        cin>>v1[i].x>>v1[i].y;
    }
    for(i=0; i<num-1; i++)
    {
        for(j=i+1; j<num; j++)
        {
            temp_r.a=i+1;
            temp_r.b=j+1;
            temp_r.d=sqrt((v1[i].x-v1[j].x)*(v1[i].x-v1[j].x)+(v1[i].y-v1[j].y)*(v1[i].y-v1[j].y));
            v.push_back(temp_r);
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(i=0; i<temp; i++)
    {
        temp_a=find_root(v2,v[i].a);
        temp_b=find_root(v2,v[i].b);
        if(temp_a!=temp_b)
        {
            v2[temp_a]=temp_b;
            distance+=v[i].d;
        }
    }
    cout<<fixed<<setprecision(2)<<distance<<endl;
    return 0;
}
