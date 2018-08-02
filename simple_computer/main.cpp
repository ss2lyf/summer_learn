#include <iostream>
#include<stack>
#include<stdlib.h>
#include<stdio.h>
#include <iomanip>
using namespace std;
//为了保证运算顺序从左到右，使用两个栈来改变入栈的顺序，就是完全反过来
stack <double> number;
stack <double>number_temp;
stack <char> operation;
stack <char>operation_temp;
/*计算用的不多说了*/
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
/*准备操作数和操作符并把结果入栈*/
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
                if(number_buf==0)//读到0程序就结束了
                {

                    exit(0);

                }
                else
                {

                    number_temp.push(number_buf);
                }
            }
            operation_buf=getchar();//一般情况下这个读到的是空格，所以下面还要再读一下才能读到操作符
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
//以下就是把两个栈都翻个个
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
            if(operation.size()>1) //当栈里面还有两个以上的元素的时候
            {
                operation_buf=operation.top();
                operation.pop();
                //这个写的不是  太好，如果还有其他运算符的话，应该再写一个比较优先级的函数
                if((operation_buf=='+'||operation_buf=='-')&&(operation.top()=='*'||operation.top()=='/'))
                {
                    //如果优先级低于后面的，先把相应的东西出栈，运算结束后再扔进来
                    number_buf=number.top();
                    number.pop();
                    compute_main();
                    //计算完了把之前的放回去
                    operation.push(operation_buf);
                    number.push(number_buf);
                }
                else
                {
                    //不存在优先级问题，先把取出来的运算符放回去，再运算
                    operation.push(operation_buf);
                    compute_main();
                }
            }
            else   //如果栈里面只有一个操作符，那么算完之后，这个算式肯定结束了
            {
                compute_main();
                break;
            }
        }
        cout<<fixed<<setprecision(2)<<number.top()<<endl;
        number.pop();//清空下，结束，美滋滋
    }
    return 0;
}
