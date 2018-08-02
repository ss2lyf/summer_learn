#include<iostream>
#include<stack>
using namespace std;
int main()
{

//长点心眼吧，说不准就溢出了！！！
    long long num,a,b;
    long long middle,middle2;
    long long result=0;
    long long ten=1;
    cin>>num>>a>>b;
    middle=a+b;
    stack<char> s;
    while(true)
    {
        middle2=middle%num;
        middle=middle/num;
        s.push(middle2+'0');

        ten*=10;
        if(middle==0)
        {
            break;
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;

}
