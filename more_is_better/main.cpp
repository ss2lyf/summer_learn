#include<iostream>
#include<vector>
using namespace std;

/*Ҫע�⣬vector���Ĳ��ǵ�ַ����Σ�յ�
����һ��Ҫע�⣬���ѭ��ʲô���������ʱ����Կ����ǲ���ѭ���������зֺ�
Ҫע�⣬vector�Ҳ�֪������������Ļ�������ܣ�������������һά����Ҳ������һ����ά����,
��һ���鷳���ڶ�������ܶ���֪����ô���ģ�oom
�е�ʱ���ù��м�ģ������������ֵ��ʱ�򣬶�������⣬��һ�������µ����е��˵����Ѷ�Ӧ����ȣ�
���ǲ���Ҫ�����ҵ�һ�����ܼ�¼���ֵ������
*/
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

void compute_road(vector<int> &v,int a,int b)
{
    int temp_a,temp_b;

}
int main()
{
    //while(true)
    {
        int num,num1,temp1,temp2,temp_a,temp_b,i;
        int max_num=0;
        num=10000000;
        vector<int> v(num+1);
        vector<int> s(num+1);

        init(v,num);
        for(i=1;i<=num;i++)
        {
            s[i]=1;
        }
        cin>>num1;
        for(i=0; i<num1; i++)
        {
            cin>>temp1>>temp2;
           temp_a=find_root(v,temp1);
          temp_b=find_root(v,temp2);
    if(temp_a!=temp_b)
    {
        v[temp_a]=temp_b;
        s[temp_b]=s[temp_b]+s[temp_a];
    }
        }

        for(i=1;i<=num;i++)
        {
            if(max_num<s[i])
            {
                max_num=s[i];
            }
        }
        cout<<max_num<<endl;
        v.clear();
        s.clear();
    }
    return 0;
}





