#include <iostream>
#include<vector>
using namespace std;
vector <int>  v (1);


/*类似于0-1背包中带记忆的东西，不要用递归
不然自己怎么死的都不知道
*/
int compute (int num)
{
    if(num==1)
    {
        return v[0];
        cout<<"!"<<endl;
    }
    else
    {
        int middle;
        int middle1;
        middle=num/2;
        middle1=num-middle;
        return (compute(middle)*compute(middle1))%1000;
    }
}


int main()
{

    int a,b;
    int result;
    while(true)
    {
        cin>>a>>b;
        //卧槽又她妈的采坑，后三位只与a的后三位和b有关
        //然后书上是每求一次砍一次，比自己想的安全多了
        v[0]=a;
        b=b%1000;
        if(a==0&&b==0)
        {
            break;
        }
        if(a!=0&&b!=0)
        {
            result=compute(b);
            result=result%1000;
            if(result%10==0)
            {
                cout<<result/10<<endl;;
            }
            else if(result%100==0)
            {
                cout<<result/100<<endl;
            }
            else
            {
                cout<<result<<endl;
            }
        }
        else if(a==0)
        {
            cout<<"0"<<endl;
        }
        else
        {

            cout<<"1"<<endl;
        }
    }
    return 0;
}
