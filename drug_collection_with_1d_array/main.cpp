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
//����д����������
//for(j=time;j>=waste_time;j--)
//�����Ͳ��ó����ж����������ˣ���Ϊֻ��һλ���飬����Ҳ���ÿ��������Ǹо���Խ��
//hummm,��������д�İѣ���Ȼ���������ģ���Ϊ�������֮ǰд������in���жϵĻ�������ɹ��粻���£������Լ�����
//����  2 200 4 400 2 200
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

//�������־�����ȫ������
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
