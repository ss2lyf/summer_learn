#include <iostream>

using namespace std;
//既然数组的下表下标代表着数字，所以还是要注意什么时候用数组里面的内容，什么时候用数组的下标
int main()
{
    int table[10001]= {0} ;
    int num;
    cin>>num;
    table[1]=1;
    int i,j;
    for(i=2; i<=num; i++)
    {

        if(table[i]==0)
        {
            j=2;
            //教材上使用的是从i*i开始的，因为i*(i-1)的一定被标注过了
            //我认为还应该有更省时间的做法
            while(true)
            {
                if(i*j>num)
                {
                    break;
                }
                else
                {

                    table[i*j]=1;
                    j++;
                }
            }
        }

    }
    for(i=2; i<num; i++)
    {
        if(table[i]==0&&(i%10==1))
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}
