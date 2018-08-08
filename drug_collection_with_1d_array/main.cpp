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
int m [1001];
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
cin>>waste_time>>value;
temp.waste_time=waste_time;
temp.value=value;
v.push_back(temp);
}
for(i=0;i<=time;i++)
{
    m[i]=0;
}

  for(j=0;j<=time;j++)
    {
        cout<<m[j]<<" ";
    }
    cout<<endl;

for(i=1;i<=num;i++)
{
    temp=v.back();
     v.pop_back();
     waste_time=temp.waste_time;
     value=temp.value;
//书上写的是这样的
//for(j=time;j>=waste_time;j--)
//这样就不用出现判断语句的问题了，因为只有一位数组，所以也不用拷贝，但是感觉会越界
//hummm,按照书上写的把，不然会出现问题的，因为如果按照之前写的利用in来判断的话，会造成过早不更新，具体自己试下
//用例  2 200 4 400 2 200
   /* for(j=1;j<=time;j++)
    {
        if(in)
            {if(j-waste_time>=0)
        {
             if(m[j-waste_time]+value>m[j])
            {in=false;}
            m[j]=max(m[j-waste_time]+value,m[j]);

        }}else{

        m[j]=m[j-1];


        }
    }*/

    for(j=time;j>=waste_time;j--)
    {
        m[j]=max(m[j-waste_time]+value,m[j]);
    }

//下面这种就是完全背包了
/*
for(j=waste_time;j<=time;j++)
{
     m[j]=max(m[j-waste_time]+value,m[j]);
}
 */

}




cout<<m[time]<<endl;



    return 0;
}
