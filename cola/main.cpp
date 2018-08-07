#include <iostream>
#include<queue>
#include<stdio.h>
int key[101][101][101];
using namespace std;
//写完代码自己看下有没有问题先，这样比出错后debug要强得多
typedef struct point
{
    int m;
    int n;
    int s;
    int time;

} point;
queue<point> q;
/* input
7 4 3
4 1 3
*/
int m_full,n_full,s_full;

void push_point(int time,int m,int n,int s)
{
    point temp;
    if(key[m][n][s]==-1)
    {
        temp.m=m;
        temp.n=n;
        temp.s=s;
        temp.time=time+1;
        q.push(temp);
        key[m][n][s]=temp.time;
    }
}
void find_way(point a)
{
    int m,n,s;
    int time;
    m=a.m;
    n=a.n;
    s=a.s;
    time=a.time;
    if(s!=0)
    {
        if(m!=m_full)
        {
            if(s>(m_full-m))
            {
                push_point(time,m_full,n,s-(m_full-m));

            }
            else
            {
                push_point(time,m+s,n,0);
            }
        }
        if(n!=n_full)
        {
            if((s>n_full-n))
            {
                push_point(time,m,n_full,s-(n_full-n));

            }
            else
            {
                push_point(time,m,n+s,0);
            }
        }
    }
    if(m!=0)
    {
        if(s!=s_full)
        {
            if(m>(s_full-s))
            {
                push_point(time,m-(s_full-s),n,s_full);

            }
            else
            {
                push_point(time,0,n,s+m);

            }

        }
        if(n!=n_full)
        {

            if(m>(n_full-n))
            {
                push_point(time,m-(n_full-n),n_full,s);

            }
            else
            {
                push_point(time,0,n+m,s);

            }
        }
    }
    if(n!=0)
    {
        if(m!=m_full)
        {
            if(n>(m_full-m))
            {
                push_point(time,m_full,n-(m_full-m),s);

            }
            else
            {
                push_point(time,m+n,0,s);
            }
            if(s!=s_full)
            {
                if(n>(s_full-s))
                {
                    push_point(time,m,n-(s_full-s),s_full);

                }
                else
                {
                    push_point(time,m,0,s+n);

                }
            }
        }
    }
}

int main()
{

    int t,loop,loop_i;
    int i,j,k,temp=-1;
    point temp_point;
    scanf("%d%d%d",&s_full,&n_full,&m_full);
    for(i=0; i<=100; i++)
    {
        for(j=0; j<=100; j++)
        {
            for(k=0; k<=100; k++)
            {
                key[i][j][k]=-1;
            }
        }
    }

    temp_point.m=0;
    temp_point.n=0;
    temp_point.s=s_full;
    temp_point.time=0;
    q.push(temp_point);
    key[0][0][s_full]=0;
    while(!q.empty())
    {
        if(((q.front().m==q.front().s)&&q.front().n==0)||((q.front().n==q.front().s)&&q.front().m==0))
        {
            temp=q.front().time;
            break;
        }
        find_way(q.front());
        q.pop();
    }
    if(temp==-1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<temp<<endl;
    }
    return 0;
}
