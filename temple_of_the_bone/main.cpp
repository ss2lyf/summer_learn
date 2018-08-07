#include <iostream>
#include<stdio.h>
using namespace std;
//如果出现结果不正确，可以尝试着把状态打印出来，这样可以减少调试的时间
//就这个题目，可以打印出当到达终点的时候，所花费的时间
int m[100][100]= {0};
bool key[100][100];
int count_num=0;
int end_x,end_y;
int x,y,t;
bool yes=false;
int time=-1;
/*input
4 4 5
S.X.
..X.
..XD
....

5 5 12
...X.
.S...
XX...
.D...
.....

3 4 5
S.X.
..X.
...D

*/
void find_way(int x_t,int y_t)
{
    if(!(x_t<0||y_t<0||x_t>x-1||y_t>y-1))
    {
        if(m[x_t][y_t]>0&&key[x_t][y_t]==false)
        {
            key[x_t][y_t]=true;
            time++;
            if(x_t==end_x&&y_t==end_y&&time==t)
            {
                yes=true;
            }
            else
            {
                if(!yes)
                {
                    find_way(x_t-1,y_t);

                    if(!yes)
                    {
                        find_way(x_t,y_t-1);
                    }
                    if(!yes)
                    {
                        find_way(x_t,y_t+1);
                    }
                    if(!yes)
                    {
                        find_way(x_t+1,y_t);
                    }
                }
            }
//这一类的递归问题都记着要恢复之前的状态
            key[x_t][y_t]=false;
            time--;
        }
    }
}
int main()
{
    char temp;
    int begin_x,begin_y;
    scanf("%d%d%d",&x,&y,&t);
    getchar();
    int i,j;

    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            temp=getchar();
            if(temp=='.'||temp=='S'||temp=='D')
            {
                m[i][j]=1;
                if(temp=='S')
                {
                    begin_x=i;
                    begin_y=j;
                }
                if(temp=='D')
                {
                    end_x=i;
                    end_y=j;
                }
            }
            key[i][j]=false;
        }
        getchar();
    }


    find_way(begin_x,begin_y);
    if(yes)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}
