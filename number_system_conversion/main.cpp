#include <iostream>
#include<stack>
using namespace std;

int main()
{
    int a,b;
    string num;
    stack <char> result;
    int middle;
    int i,j;
    int sum=1;
    long long  temp=0;
    cin>>a>>num>>b;
    for(i=num.size()-1; i>=0; i--)
    {
        if(num[i]=='a'||num[i]=='A')
        {
            temp+=(10*sum);
        }
        else if(num[i]=='b'||num[i]=='B')
        {
            temp+=(11*sum);

        }
        else if(num[i]=='c'||num[i]=='C')
        {
            temp+=(12*sum);
        }
        else if(num[i]=='d'||num[i]=='D')
        {
            temp+=(13*sum);
        }
        else if(num[i]=='e'||num[i]=='E')
        {
            temp+=(14*sum);
        }
        else if(num[i]=='f'||num[i]=='F')
        {
            temp+=(15*sum);
        }
        else
        {
            temp+=((num[i]-'0')*sum);
        }
        sum*=a;
    }
    sum=1;
    while(true)
    {
        middle=temp%b;
        temp=temp/b;

        switch(middle)
        {
        case 15:
            result.push('F');
            break;
        case 14:
            result.push('E');
            break;
        case 13:
            result.push('D');
            break;
        case 12:
            result.push('C');
            break;
        case 11:
            result.push('B');
            break;
        case 10:
            result.push('A');
            break;
        default:
            result.push(middle+'0');
            break;
        }
        if(temp==0)
        {
            break;
        }
    }
    while(!result.empty())
    {
        cout<<result.top();
        result.pop();
    }
    cout<<endl;
    return 0;
}
