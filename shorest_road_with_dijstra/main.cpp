#include <iostream>
#include <vector>
#include<algorithm>
#include<limits.h>
using namespace std;
int m [101][101];
/*input
3 3
1 2 5
2 3 5
3 1 2

5 7
1 2 3
1 4 7
2 4 2
2 3 4
3 4 5
4 5 4
3 5 6
*/
//我的天，终于写完了
//不要把dijkstra和floyd混淆了
int main()
{

    int num,num1;
    int i,j,temp,temp1;
    int a,b,c;
    int min_d;
    cin>>num;
    vector<int> key;
    vector<int> distance(num+1);
    for(i=0;i<=num;i++)
    {
        distance[i]=1001;
    }
    distance[1]=0;
    for(i=0;i<=num;i++)
    {
        for(j=0;j<=num;j++)
        {
            if(i==j)
            //自己到自己还是老老实实弄成0
            {m[i][j]=0;}
            else{m[i][j]=1001;}
        }
    }
    cin>>num1;
    for(i=0; i<num1; i++)
    {
        cin>>a>>b>>c;
        m[a][b]=c;
        m[b][a]=c;
    }
    key.push_back(1);
while(key.size()<num){
        temp=key.size();
    //for(i=0; i<temp; i++)
    //旧的节点周围的最小的之前就已经找过了，只需要找最新的就行了
    {
        temp1=key[temp-1];
        for(j=1; j<=num; j++)
        {
            if(distance[j]>distance[temp1]+m[temp1][j])
            {
                distance[j]=distance[temp1]+m[temp1][j];
            }
        }
    }
    min_d=INT_MAX;
    for(i=1;i<=num;i++)
    {
        if(distance[i]<min_d&&find(key.begin(),key.end(),i)==key.end())
        {
            min_d=distance[i];
            temp=i;
        }
}
  key.push_back(temp);
}
//输出1到每一个点的距离，然后结束，卧槽，终于tmd结束了，日
for(i=1;i<=num;i++){
cout<<distance[i]<<endl;}
    return 0;
    }


