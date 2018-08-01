#include <iostream>

using namespace std;

int main()
{

    /* input
    5
    0 2 1000 1 8
    6 0 3 2 1000
    1000 1000 0 4 1000
    1000 1000 2 0 3
    3 1000 1000 1000 0
    */
    int a[100][100];
    int num;
    cin>>num;
    int i,j;
    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            cin>>a[i][j];
        }
    }
    int k;
    for(k=0; k<num; k++)
    {
        for(i=0; i<num; i++)
        {
            for(j=0; j<num; j++)
            {
                if(a[i][j]>a[i][k]+a[k][j])
                {
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
         for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if(a[i][j]==1000)
            {cout<<"*  ";

        }else{

        cout<<a[i][j]<< "  ";
        }
        cout<<endl;
    }
    cout << "Hello world!" << endl;

    }
    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            cout<<a[i][j]<< " ";
        }
        cout<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
