#include <iostream>
#include<stack>
#include<vector>
using namespace std;
//一般涉及到数学的问题都会让人很难受
//然后设计到看上去很弱智的问题，很多都会考溢出或者效率问题
int num=1000;
vector<int> table(num+1);
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
    int n,a,n_temp1,n_temp2,a_temp;
    //要注意保存之后可能会被更改而且还会被再次用到的变量
    int i;
    int middle;
    int min_num=1000;
    make_table();
    vector <int> v;
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    cin>>n>>a;
    n_temp2=n;
    a_temp=a;
    vector<int > n_v(n+1);
    vector <int> a_v(a+1);
    for(i=0; i<=n; i++)
    {
        n_v[i]=0;
    }
    for(i=0; i<=a; i++)
    {
        a_v[i]=0;
    }
    for(; n>1; n--)
    {
        n_temp1=n;
        i=2;
        while(i<=v.size()&&n_temp1!=1)
        {
            if(n_temp1%i==0)
            {
                n_temp1=n_temp1/i;
                n_v[i]++;

            }
            else
            {
                i++;
            }
        }
    }

    i=2;
    while(i<=v.size()&&a!=1)
    {
        if(a%i==0)
        {
            a=a/i;
            a_v[i]++;

        }
        else
        {
            i++;
        }
    }
    for(i=2; i<=a_temp; i++)
    {
        if(a_v[i]!=0)
        {
            middle=n_v[i]/a_v[i];
            if(n_v[i]/a_v[i]<min_num)
            {
                min_num=n_v[i]/a_v[i];
            }
            if(middle==0)
            {
                break;
            }
        }
    }
    cout<<min_num<<endl;
    return 0;
}
