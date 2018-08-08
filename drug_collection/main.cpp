#include <iostream>
#include<vector>
using namespace std;
typedef struct node
{
    int waste_time;
    int value;
}node;
/*
70 3
71 100
69 1
1 2
*/
int m [101][1001];
int main()
{int time;
int num;
int i,j;
int waste_time;
int value;
vector<node> v;
node temp;
cin>>time>>num;
for(i=1;i<=num;i++)
{
    m[i][0]=0;
 cin>>waste_time>>value;
temp.waste_time=waste_time;
temp.value=value;
v.push_back(temp);
}
for(i=0;i<=time;i++)
{
    m[0][i]=0;
}
for(i=1;i<=num;i++)
{
    temp=v.back();
     v.pop_back();
     waste_time=temp.waste_time;
     value=temp.value;

    for(j=1;j<=time;j++)
    {
        if(j-waste_time>=0)
        {
            m[i][j]=max(m[i-1][j-waste_time]+value,m[i-1][j]);
        }else{


        m[i][j]=m[i-1][j];

        }
    }
}
/*for(i=0;i<=num;i++)
{
    for(j=0;j<=time;j++)
    {
        cout<<m[i][j]<<" ";
    }
    cout<<endl;
}
*/
cout<<m[num][time]<<endl;



    return 0;
}
