#include <iostream>
#include<iomanip>
using namespace std;

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


void compute_bigint(bigint a,bigint b)
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

    print_bigint(a);



}

int main()
{
    string a,b;
    bigint a_i,b_i;
    cin>>a>>b;
    a_i.int_size=0;
    b_i.int_size=0;
    make_bigint(a,&a_i);
    make_bigint(b,&b_i);
    compute_bigint(a_i,b_i);
    return 0;
}
