#include <iostream>

using namespace std;




int main()
{

    int a,b;
    int result=1;
    while(true)
    {
        cin>>a>>b;
        //�Բ�������Ĳɿӣ�����λֻ��a�ĺ���λ��b�й�
        //Ȼ��������ÿ��һ�ο�һ�Σ����Լ���İ�ȫ����
        a=a%1000;
        if(a==0&&b==0)
        {
            break;
        }
        if(a!=0&&b!=0)
        {

//���ǲ�̫��⵽����һ��ʲô����˼�룬Ӧ�������÷�������
//����ÿ�����������ӵ�λ�úʹ������պ�
//�Բ����ӿ����ˣ���̵ķ�ʽ�����൱��������ƣ�Ȼ��ѭ������Ĺ����൱�ڶ����Ʊ��롣

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
