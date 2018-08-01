#include <iostream>
using namespace std;

int main()
{
    int num;
    int k=0;
    char out[2];;
    char now;
    char temp;
    int i,j1,i1;
    while((cin>>num)&&num!=NULL)
    {
        if(k)
            cout<<endl;
        ++k;
        if(num>1)
        {
            cin>>out[0]>>out[1];
            if((num+1)%4==0)
            {
                now=1;
            }
            else
            {
                now=0;
            }
            cout<<" ";
            for(i=0; i<(num-2); i++)
            {
                cout<<out[now];
            }
            cout<<" "<<endl;
            for(i=0; i<(num-1)/2; i++)
            {
                j1=i+1;

                for(i1=0; i1<num; i1++)
                {
                    cout<<out[now];
                    if((i1+1)==(num-(i+1)))
                    {
                        j1=i+1;
                    }
                    if(j1>0)
                    {
                        now=1-now;
                        j1--;
                    }
                }
                cout<<endl;
            }
            for(i=(num-1)/2-2; i>=0; i--)
            {
                j1=i+1;

                for(i1=0; i1<num; i1++)
                {
                    cout<<out[now];
                    if((i1+1)==(num-(i+1)))
                    {
                        j1=i+1;
                    }
                    if(j1>0)
                    {
                        now=1-now;
                        j1--;
                    }
                }
                cout<<endl;
            }
            cout<<" ";
            for(i=0; i<(num-2); i++)
            {
                cout<<out[now];
            }
            cout<<" "<<endl;

        }
        else
        {
            cin>>out[0]>>out[1];
            cout<<out[0]<<endl;
        }
    }
    return 0;
}
