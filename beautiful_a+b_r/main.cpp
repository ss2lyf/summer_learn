#include <iostream>
#include<vector>
using namespace std;
vector <int>  v (1);


/*������0-1�����д�����Ķ�������Ҫ�õݹ�
��Ȼ�Լ���ô���Ķ���֪��
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
        //�Բ�������Ĳɿӣ�����λֻ��a�ĺ���λ��b�й�
        //Ȼ��������ÿ��һ�ο�һ�Σ����Լ���İ�ȫ����
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
