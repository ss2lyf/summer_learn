#include <iostream>
#include<vector>
using namespace std;
typedef struct node
{
    int waste_time;
    int value;
}node;
/*
10 110
2
1 1
30 50

10 110
2
1 1
50 30

1 6
2
10 3
20 4

*/
int m [1001];
int main()
{int time,time1,time2;
int num;
int i,j;
int waste_time;
int value;
vector<node> v;
node temp;
cin>>time1>>time2>>num;
time=time2-time1;
for(i=1;i<=num;i++)
{
cin>>value>>waste_time;
temp.waste_time=waste_time;
temp.value=value;
v.push_back(temp);
}
for(i=0;i<=time;i++)
{
    m[i]=50001;
}
m[0]=0;//第一个不是0的话状态转移不了的,而且第一个绝对是0，因为没装东西啊。
for(i=1;i<=num;i++)
{
    temp=v.back();
     v.pop_back();
     waste_time=temp.waste_time;
     value=temp.value;
for(j=waste_time;j<=time;j++)
{//直接从waste_time开始，这样就不会出现装不下去的情况了
    //因为要把包完全装满，如果装不进去的话，那就没法装了
       if(m[j-waste_time]!=50001)
        {
     m[j]=min(m[j-waste_time]+value,m[j]);}
}
}
  for(j=0;j<=time;j++)
    {
        cout<<m[j]<<" ";
    }
    cout<<endl;
if(m[time]!=50001)
{cout<<"The minimum amount of money in the piggy-bank is "m[time]<<"."endl;}else{
cout<<"This is impossible."<<endl;
}
    return 0;
}
