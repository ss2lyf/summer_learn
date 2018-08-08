#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//定义节点，存储两个货物的位置以及如果同时拿这两个，会造成多少疲劳
typedef struct node
{
    int a;
    int b;
    int weight;
} node;
//比较函数，希望以最小疲劳损耗来排序
bool cmp(node a,node b)
{
    return a.weight<b.weight;
}
int main()
{
    int cost=0;
    int n,k;
    cin>>n>>k;
    int i;
    int temp;
    node node_temp;
    vector <int > v1 ;
    vector<node> v2;
    for(i=0; i<n; i++)
    {
        cin>>temp;
        v1.push_back(temp);
    }
//先把所有的货物排序，这个我觉着跟书上的理解是一样的
    sort(v1.begin(),v1.end());
//计算下两个相邻物品之间的差
    for(i=1; i<n; i++)
    {
        node_temp.a=i-1;
        node_temp.b=i;
        node_temp.weight=(v1[i]-v1[i-1])*(v1[i]-v1[i-1]);
        v2.push_back(node_temp);
    }
//按照大小拍下序
    sort(v2.begin(),v2.end(),cmp);
//这循环没大意思，写成true也可以
    while(!v2.empty())
    {
        node_temp=v2.front();
        v2.erase( v2.begin( ));
        {
            //如果这两个物品之前都没被提走，则把他们两个提走，然后标记下，在原数组中标记-1就是被提走的意思
            if(v1[node_temp.a]!=-1&&v1[node_temp.b]!=-1)
            {
                v1[node_temp.a]=-1;
                v1[node_temp.b]=-1;
                cost+=node_temp.weight;
                k--;
            }
        }
//搬了n件了，结束
        if(k==0)
        {
            break;
        }
    }
    cout << cost<< endl;
    return 0;
}
