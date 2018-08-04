#include <iostream>

using namespace std;




int main()
{

    int a,b;
    int result=1;
    while(true)
    {
        cin>>a>>b;
        //卧槽又她妈的采坑，后三位只与a的后三位和b有关
        //然后书上是每求一次砍一次，比自己想的安全多了
        a=a%1000;
        if(a==0&&b==0)
        {
            break;
        }
        if(a!=0&&b!=0)
        {

//还是不太理解到底是一种什么样的思想，应该是正好反着来的
//但是每次算出来的相加的位置和次数都刚好
//卧槽老子看懂了，最短的方式就是相当于求二进制，然后循环里面的过程相当于二进制编码。

            while(b!=0)
            {
                if(b%2==1)
                {

                    result*=a;
                    result=result%1000;
                }
                b=b/2;
                a*=a;
                a=a%1000;


            }











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
