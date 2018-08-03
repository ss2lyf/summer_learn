#include <iostream>
#include<stack>
#include<vector>
using namespace std;
//��Ȼ������±��±���������֣����Ի���Ҫע��ʲôʱ����������������ݣ�ʲôʱ����������±�
int num=40000;
vector<int> table(num+1);
//����Ҫ�����´�С�����⣬��Ȼ��һ���ǳ���ʱ���ܿ����ǲ�����������ô��
stack<int> s;
void make_table()
{
    int i,j;
    for(i=2; i<=num; i++)
    {
        table[i]=0;
    }
    for(i=2; i<=num; i++)
    {
        if(table[i]==0)
        {
            j=i;
            while(true)
            {
                if(i*j>num)
                {
                    break;
                }
                else
                {
                    table[i*j]=1;
                    j++;
                }
            }
        }
    }
    for(i=2; i<num; i++)
    {
        if(table[i]==0)
        {
            s.push(i);
        }
    }
}
int main()
{
    int input;
    int i;
    int count_num=0;
    make_table();
    vector <int> v;
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    cin>>input;
    i=2;
    while(i<=v.size()&&input!=1)
    {
        if(input%i==0)
        {
            input=input/i;
            count_num++;
        }
        else
        {
            i++;
        }
    }
    if(input!=1)
    {
        count_num++;
    }
    cout<<count_num<<endl;
    return 0;
}
