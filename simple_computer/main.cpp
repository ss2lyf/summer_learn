#include <iostream>
#include<stack>
#include<stdlib.h>
#include<stdio.h>
#include <iomanip>
using namespace std;
//Ϊ�˱�֤����˳������ң�ʹ������ջ���ı���ջ��˳�򣬾�����ȫ������
stack <double> number;
stack <double>number_temp;
stack <char> operation;
stack <char>operation_temp;
/*�����õĲ���˵��*/
double compute(double a,double b,char op)
{
    if(op=='+')
    {
        return a+b;
    }
    else if(op=='*')
    {
        return a*b;
    }
    else if(op=='/')
    {
        return a/b;
    }
    else if(op=='-')
    {
        return a-b;
    }
    return 0;

}
/*׼���������Ͳ��������ѽ����ջ*/
void compute_main()
{
    double num1,num2;
    char op;
    op=operation.top();
    operation.pop();
    num1=number.top();
    number.pop();
    num2=number.top();
    number.pop();
    number.push(compute(num1,num2,op));

}
int main()
{


    double number_buf;
    char operation_buf;
    while(true)
    {
        while(true)
        {
            cin>>number_buf;
            {
                if(number_buf==0)//����0����ͽ�����
                {

                    exit(0);

                }
                else
                {

                    number_temp.push(number_buf);
                }
            }
            operation_buf=getchar();//һ�����������������ǿո��������滹Ҫ�ٶ�һ�²��ܶ���������
            {

                if(operation_buf!='\n')
                {
                    operation_buf=getchar();
                    operation_temp.push(operation_buf);
                    getchar();
                }
                else
                {
                    break;
                }
            }
        }
//���¾��ǰ�����ջ��������
        while(!number_temp.empty())
        {
            number.push(number_temp.top());
            number_temp.pop();
        }
        while(!operation_temp.empty())
        {
            operation.push(operation_temp.top());
            operation_temp.pop();
        }


        while(true)
        {
            if(operation.size()>1) //��ջ���滹���������ϵ�Ԫ�ص�ʱ��
            {
                operation_buf=operation.top();
                operation.pop();
                //���д�Ĳ���  ̫�ã������������������Ļ���Ӧ����дһ���Ƚ����ȼ��ĺ���
                if((operation_buf=='+'||operation_buf=='-')&&(operation.top()=='*'||operation.top()=='/'))
                {
                    //������ȼ����ں���ģ��Ȱ���Ӧ�Ķ�����ջ��������������ӽ���
                    number_buf=number.top();
                    number.pop();
                    compute_main();
                    //�������˰�֮ǰ�ķŻ�ȥ
                    operation.push(operation_buf);
                    number.push(number_buf);
                }
                else
                {
                    //���������ȼ����⣬�Ȱ�ȡ������������Ż�ȥ��������
                    operation.push(operation_buf);
                    compute_main();
                }
            }
            else   //���ջ����ֻ��һ������������ô����֮�������ʽ�϶�������
            {
                compute_main();
                break;
            }
        }
        cout<<fixed<<setprecision(2)<<number.top()<<endl;
        number.pop();//����£�������������
    }
    return 0;
}
