#include<iostream>
#include<vector>
using namespace std;

//Ҫע�⣬vector���Ĳ��ǵ�ַ����Σ�յ�
//����һ��Ҫע�⣬���ѭ��ʲô���������ʱ����Կ����ǲ���ѭ���������зֺ�
void init(vector<int> &v,int num)
{
    int i;
    for(i=0; i<=num; i++)
    {
        v[i]=-1;
    }
}
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
int count_road(vector<int> &v,int num)
{
    int result=0;
    int i;
    for(i=1; i<=num; i++)
    {
        if(v[i]==-1)
        {
            result++;
        }
    }
    return result;
}
void compute_road(vector<int> &v,int a,int b)
{
    int temp_a,temp_b;
    temp_a=find_root(v,a);
    temp_b=find_root(v,b);
    if(temp_a!=temp_b)
    {
        v[temp_a]=temp_b;
    }
}
int main()
{
    //while(true)
    {
        int num,num1,temp1,temp2,i;
        cin>>num;
        vector<int> v(num+1);
        init(v,num);
        cin>>num1;
        for(i=0; i<num1; i++)
        {
            cin>>temp1>>temp2;
            compute_road(v,temp1,temp2);
        }
        cout<<count_road(v,num)-1<<endl;
        v.clear();
    }
    return 0;
}





