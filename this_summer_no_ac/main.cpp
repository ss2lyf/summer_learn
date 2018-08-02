#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//也不是找性价比，也不是找第一个，需要找的是结束的时间
typedef struct tv
{

    int begin_time;
    int end_time;

} tv;

bool cmp(tv a,tv b)
{
    return a.end_time<b.end_time;
}
/*input

12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0
*/
int main()
{
    int num,i;
    int time_now;

    int count_num;
    while((cin>>num)&&num!=0)
    {
        vector <tv> a(num);
        time_now=0;
        count_num=0;
        for(i=0; i<num; i++)
        {
            cin>>a[i].begin_time>>a[i].end_time;
        }

        sort(a.begin(),a.end(),cmp);
        i=0;
        while(i<num)
        {
            if(a[i].begin_time>=time_now)
            //注意时间的衔接
            {
                count_num++;
                time_now=a[i].end_time;
            }
            i++;
        }

        cout<<count_num<<endl;
        a.clear();
    }
    return 0;
}
