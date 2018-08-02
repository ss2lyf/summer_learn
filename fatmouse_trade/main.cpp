#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*
这个问题就是先找性价比高的去拿就对了
*/
typedef struct grocery
{
    int sum;
    int price;
    double key;
} grocery;



bool cmp (grocery a,grocery b)
{
    return a.key>b.key;
}

/*input

5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
*/

int main()
{
    int money,num,i;
    double bought;
    while(true)
    {
        cin>>money>>num;
        if(num==-1||money==-1)
        {
            break;
        }
        bought=0;
        vector <grocery> a(num);
        for(i=0; i<num; i++)
        {
            cin>>a[i].sum>>a[i].price;
            a[i].key=double(a[i].sum)/a[i].price;
        }
        sort(a.begin(),a.end(),cmp);
        for(i=0; i<num; i++)
        {
            if(money>=a[i].price)
            {
                money-=a[i].price;
                bought+=a[i].sum;
            }
            else
            {
                bought+=(double(money)/a[i].price)*a[i].sum;
                break;
            }
        }
        cout<<bought<<endl;
        a.clear();//注意要释放空间，不然会死
    }
    return 0;
}
