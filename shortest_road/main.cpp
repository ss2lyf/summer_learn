#include <iostream>
#include<limits>
using namespace std;

int main()
{
    int a[100][100];
    int num,num1,i,j,k,temp_a,temp_b,temp_d;
    cin>>num>>num1;
    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            a[i][j]=1001;
            //注意溢出问题，如果题目中给了限定，还是不要皮
        }
    }
    for(i=0; i<num1; i++)
    {
        cin>>temp_a>>temp_b>>temp_d;
        a[temp_a-1][temp_b-1]=temp_d;
        a[temp_b-1][temp_a-1]=temp_d;
    }
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
    }
    cout<<a[0][num-1];
    return 0;
}
