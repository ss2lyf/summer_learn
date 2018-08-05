#include <iostream>
#include <vector>
#include<algorithm>
#include<limits.h>
using namespace std;
int m [101][101];
/*input
3
1 2 1
1 3 2
2 3 4

4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 1
*/
//要注意对于prim算法来说，要是使用矩阵的话，要通两边都得通，就是矩阵中相对应的两个位置都要设置成相同的值
int main()
{

    int num;
    int i,j,i1;
    int a,b,c;
    int min_i,min_j;
    int distance;
    vector<int> v;
    int min_d;
    distance=0;
    cin>>num;
    for(i=0; i<=num; i++)
    {
        for(j=0; j<=num; j++)
        {
            m[i][j]=INT_MAX;
        }
    }
    for(i=(num*(num-1))/2; i>0; i--)
    {
        cin>>a>>b>>c;
        m[a][b]=c;
        m[b][a]=c;
    }
    v.push_back(1);
    while(v.size()<num)
    {
        min_d=INT_MAX;
        for(i1=0; i1<v.size(); i1++)
        {
            i=v[i1];
            for(j=1; j<=num; j++)
            {
                if(min_d>m[i][j]&&(find(v.begin(), v.end(), j) == v.end()))
                {
                    min_i=i;
                    min_j=j;
                    min_d=m[i][j];
                }
            }
        }
        v.push_back(min_j);
        m[min_i][min_j]=INT_MAX;
        distance+=min_d;
    }
    cout<<distance<<endl;
    return 0;
}
