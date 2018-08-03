#include <iostream>
#include<stack>
#include<vector>
using namespace std;
//既然数组的下表下标代表着数字，所以还是要注意什么时候用数组里面的内容，什么时候用数组的下标
int num=40000;
vector<int> table(num+1);
//还是要考虑下大小的问题，不然不一定是程序超时，很可能是不让你申请这么多
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
