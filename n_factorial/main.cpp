#include <iostream>
#include<iomanip>
#include <string>
#include <stdlib.h>
#include<stack>
using namespace std;
stack<char> s;
typedef struct bigint
{
    int digit[1000];
    int int_size;

} bigint;

void make_bigint( string a,bigint* a_i)
{
    int middle;
    int ten=1;
    a_i->int_size=0;
    while(true)
    {
        middle=a.size();
        a_i->digit[a_i->int_size]=0;
        if(middle-4>=0)
        {
            a_i->digit[a_i->int_size]+=a[middle-1]-'0';
            a_i->digit[a_i->int_size]+=(a[middle-2]-'0')*10;
            a_i->digit[a_i->int_size]+=(a[middle-3]-'0')*100;
            a_i->digit[a_i->int_size]+=(a[middle-4]-'0')*1000;
            a_i->int_size++;
            a=a.substr(0,middle-4);
        }
        else if (middle>0)
            //注意大于零和等于零不能按照相同的方式去处理
        {
            for(ten=1; middle>0; middle--)
            {
                a_i->digit[a_i->int_size]+=(a[middle-1]-'0')*ten;
                ten*=10;
            }
            a_i->int_size++;
            break;
        }
        else
        {
            break;
        }
    }
}

void print_bigint(bigint a)
{
    int i;
    for(i=a.int_size-1; i>=0; i--)
    {
        if(i<a.int_size-1)
        {
            cout<<setfill('0')<<setw(4)<<a.digit[i];
        }
        else
        {
            cout<<a.digit[i];
        }
    }
    cout<<endl;
}

bigint compute_bigint_plus(bigint a,bigint b)
{
    bigint c;
    int f=0;
    int i;
    int middle;
//这里是大的放前面，以小的为准，书上的做法是反正没有数的地方都是0
//所以以大的位数为准，个人认为书上的简单但是循环次数多。
    if(a.int_size<b.int_size)
    {
        c=a;
        a=b;
        b=c;
    }
    for(i=0; i<b.int_size; i++)
    {
        middle=f+a.digit[i]+b.digit[i];
        if(middle>=10000)
        {
            f=1;
            a.digit[i]=middle%10000;
        }
        else
        {
            f=0;
            a.digit[i]=middle;
        }
    }
    //处理位数多的进位的问题
    for(; i<a.int_size; i++)
    {
        if (f==1)
        {
            middle=f+a.digit[i];
            if(middle>=10000)
            {
                f=1;
                a.digit[i]=middle%10000;
            }
            else
            {
                f=0;
                a.digit[i]=middle;
            }
        }


        else
        {

            break;
        }

    }
    if(f==1)//大于最大的数的长度的仅为
    {
        a.digit[i]=1;
        a.int_size++;
    }

    return a;

}

bigint compute_bigint_mul(bigint a,bigint b)
{
    int a_temp;
    int i,j;
    int f=0;
    int middle;
    bigint temp,result;
    make_bigint( "0",&result);
    make_bigint( "0",&temp);
    for(i=0; i<a.int_size; i++)
    {
        temp.int_size=0;

        for(j=0; j<i; j++)
        {
            temp.digit[j]=0;
            temp.int_size++;
        }
        f=0;
        a_temp=a.digit[i];
        for(j=0; j<b.int_size; j++)
        {
            middle=f+a_temp*b.digit[j];
            f=middle/10000;
            if(f)
            {
                temp.digit[temp.int_size]=middle%10000;
            }
            else
            {

                temp.digit[temp.int_size]=middle;
            }
            temp.int_size++;
        }
        if(f>0)
        {
            temp.digit[temp.int_size]=f;
            temp.int_size++;
        }
        result=compute_bigint_plus(result,temp);
    }
    return result;

}

string  int_to_string(int a)
{
    char middle;
    string str;
    do
    {
        middle=(a%10)+'0';
        s.push(middle);

        a=a/10;
    }
    while(a!=0);

    while(!s.empty())
    {
        str=str+s.top();
        s.pop();
    }
    return str;
}

int main()
{
    int a;
    string a_temp;
    bigint a_i;
    bigint result;
    cin>>a;
    make_bigint("1",&result);
    for(; a>1; a--)
    {
        a_temp=int_to_string(a);
        make_bigint(a_temp,&a_i);
        result=compute_bigint_mul(result,a_i);
    }
    print_bigint(result);

    return 0;
}
