#include <iostream>
#include <vector>
#include<queue>
using namespace std;
/*input
8 2
2 100 4
4 100 2
*/
typedef struct rice
{
    int weight;
    int cost;
} rice;
int a[2001];
int main()
{
    queue<rice> q;
    int n,m,num;
    cin>>n>>m;
    int p,h,c,k;
    int i,j;
    rice temp;
    //这个拆分的思想可谓是相当的牛逼了
    for(i=0; i<m; i++)
    {
        cin>>p>>h>>c;
        k=1;
        while(c-k>0)
        {
            c-=k;
            temp.cost=k*p;
            temp.weight=h*k;
            q.push(temp);
            k=k*2;
        }
        temp.cost=c*p;
        temp.weight=c*h;
        q.push(temp);
    }
    num=q.size();
    for(i=0; i<=num; i++)
    {
        a[i]=0;
    }
    for(i=1; i<=num; i++)
    {
        temp=q.front();
        q.pop();
        p=temp.cost;
        h=temp.weight;
        for(j=n; j>=p; j--)
        {
            a[j]=max(a[j],a[j-p]+h);
        }
        for(int k=0; k<=n; k++)
        {
            cout<<a[k]<<" ";
        }
        cout<<endl;
    }
    cout << a[n] << endl;
    return 0;
}
