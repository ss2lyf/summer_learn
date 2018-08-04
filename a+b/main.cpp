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
            //ע�������͵����㲻�ܰ�����ͬ�ķ�ʽȥ����
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
//�����Ǵ�ķ�ǰ�棬��С��Ϊ׼�����ϵ������Ƿ���û�����ĵط�����0
//�����Դ��λ��Ϊ׼��������Ϊ���ϵļ򵥵���ѭ�������ࡣ
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
    //����λ����Ľ�λ������
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
    if(f==1)//�����������ĳ��ȵĽ�Ϊ
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
