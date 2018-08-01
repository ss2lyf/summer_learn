#include <iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    int b=a+(a-1)*2;
    int i,j,j1=a,j2=b-a;
    cout<<j2<<endl;
    for(i=0; i<a; i++)
    {
        for(j=0; j<j2; j++)
        {
            cout<<" ";
        }
        j2-=2;
        for(j=0; j<j1; j++)
        {
            cout<<"*";
        }
        j1+=2;
        cout<<endl;
        return 0;
    }
