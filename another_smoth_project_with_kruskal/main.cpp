#include <iostream>
#include <vector>
#include<algorithm>
#include<limits.h>
using namespace std;
typedef struct road
{
    int a;
    int b;
    int d;
} road;
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
    int i;
    int a,b,d,temp;
    int temp_a,temp_b;
    int distance;
    distance=0;
    cin>>num;
    temp=(num*(num-1))/2;
    vector<int> v2(num+1);
    init(v2,num);
    vector<road> v(temp);
    for(i=0; i<temp; i++)
    {
        cin>>a>>b>>d;
        v[i].a=a;
        v[i].b=b;
        v[i].d=d;
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
    cout<<distance<<endl;
    return 0;
}
