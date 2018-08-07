#include <iostream>
#include<stdio.h>
using namespace std;
int m[100][100]= {0};
bool key[100][100];
int count_num=0;
int x,y;

/*input
3 5
*@*@*
**@**
*@*@*

1 8
@@****@*

5 5
****@
*@@*@
*@**@
@@@*@
@@**@

*/

void search_oil(int a,int b)
{
    if(a<0||a>=x||b<0||b>=y)
    {}
    else if(!key[a][b])
    {
        key[a][b]=true;
        if(m[a][b]==1)
        {
            search_oil(a-1,b);
            search_oil(a,b-1);
            search_oil(a+1,b);
            search_oil(a,b+1);
            search_oil(a-1,b-1);
            search_oil(a-1,b+1);
            search_oil(a+1,b+1);
            search_oil(a+1,b-1);
        }
    }
}

int main()
{
    char temp;
    scanf("%d%d",&x,&y);
    getchar();
    int i,j;
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            temp=getchar();
            if(temp=='@')
            {
                m[i][j]=1;
            }
            key[i][j]=false;
        }
        getchar();
    }
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            if(key[i][j]==false)
            {

                if(m[i][j]==1)
                {
                    search_oil(i,j);
                    count_num++;
                }
                else
                {
                    key[i][j]=true;
                }
            }
        }
    }
    cout<<count_num<<endl;
    return 0;
}
