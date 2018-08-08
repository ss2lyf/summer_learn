#include <iostream>

using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int m [101][101];
    int a_num=a.size();
    int b_num=b.size();
    int i,j;
//要记着还是要初始化完全哈
    for(i=0; i<=a_num; i++)
    {
        m[i][0]=0;
    }
    for(j=0; j<=b_num; j++)
    {
        m[0][j]=0;
    }
    for(i=1; i<=a_num; i++)
    {
        for(j=1; j<=b_num; j++)
        {
            if(a[i-1]==b[j-1])
            {
                m[i][j]=m[i-1][j-1]+1;
            }
            else
            {
                //多看看有没有一些函数可以使用啥的
                m[i][j]=max(m[i-1][j],m[i][j-1]);
            }
        }
    }
    for(i=1; i<=a_num; i++)
    {
        for(j=1; j<=b_num; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << m[a_num][b_num]<< endl;
    return 0;
}
