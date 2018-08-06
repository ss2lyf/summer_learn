#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 1001
#define INF 0x3f3f3f3f

int n,m,adj[N][N],cost[N][N],visit[N],lowdis[N],lowcos[N];

void dijkstra(int s, int t)
{
    memset(visit,0,sizeof(visit));
    visit[s] = 1;
    lowdis[s] = lowcos[s] = 0;
    for(int i=1;i<=n;i++)
        if(i != s)
        {
            lowdis[i] = adj[s][i];
            lowcos[i] = cost[s][i];
        }
    int pos = s;
    for(int i=1;i<n;i++)
    {
        int mindis = INF;
        for(int j=1;j<=n;j++)
            if(!visit[j] && lowdis[j] < mindis)
            {
                mindis = lowdis[j];
                pos = j;
            }
        if(mindis == INF)
            break;
        visit[pos] = 1;
        for(int j=1;j<=n;j++)
            if(adj[pos][j] != INF && cost[pos][j] != INF && (lowdis[j] >= lowdis[pos] + adj[pos][j]))
            {
                if((lowdis[j] == lowdis[pos] + adj[pos][j] && lowcos[j] > lowcos[pos] + cost[pos][j]) || (lowdis[j] > lowdis[pos] + adj[pos][j]))
                    lowcos[j] = lowcos[pos] + cost[pos][j];
                lowdis[j] = lowdis[pos] + adj[pos][j];
            }
    }
    printf("%d %d\n",lowdis[t],lowcos[t]);
}

int main()
{
    while(scanf("%d %d",&n,&m) != EOF)
    {
        if(n == 0 && m == 0)
            break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                adj[i][j] = cost[i][j] = INF;
        while(m--)
        {
            int a,b,d,p;
            scanf("%d %d %d %d",&a,&b,&d,&p);
            if(d < adj[a][b])
            {
                adj[a][b] = adj[b][a] = d;
                cost[a][b] = cost[b][a] = p;
            }
            else if(d == adj[a][b] && p < cost[a][b])
                cost[a][b] = cost[b][a] = p;
        }
        int s,t;
        scanf("%d %d",&s,&t);
        dijkstra(s,t);
    }
    return 0;
}
