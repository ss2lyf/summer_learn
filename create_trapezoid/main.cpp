#include <iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    int b=a+(a-1)*2;
    int i,j,j2=b-a;
    for(i=0; i<a; i++)
    {
        for(j=0; j<b; j++)
        {
            if(j<j2)
            {
                cout<<" ";
            }
            else
            {
                cout<<"*";
            }
        }
        j2-=2;
        cout<<endl;
    }
    return 0;
}
