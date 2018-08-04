#include <iostream>
#include<iomanip>
#include <string>
#include <stdlib.h>
#include<stack>
using namespace std;
stack<char> s;
//д��о������˶�������
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

bigint compute_bigint_plus(bigint a,bigint b)
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
    return a;

}

bigint compute_bigint_mul(bigint b,int a)
{
    int i,j;
    int f=0;
    int middle;
    bigint temp,result;
    int temp_point;
    make_bigint( "0",&result);
    make_bigint( "0",&temp);
    //for(i=0;i<a.int_size;i++)
    {
        temp.int_size=0;

        //cout<<a_temp<<endl;
        for(j=0; j<b.int_size; j++)
        {
            middle=f+a*b.digit[j];
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

bigint compute_bigint_div(bigint a,int b)
{
    int middle;
    int r=0;
    int temp;
    int i;

    for(i=a.int_size-1; i>=0; i--)
    {
        temp=a.digit[i]+r*10000;
        r=temp%b;
        middle=temp/b;
        a.digit[i]=middle;
    }

    if(a.digit[a.int_size-1]==0&&a.int_size!=1)//һ��������36���������ѵ�һλ���հ�
    {
        a.int_size--;
    }
    return a;

}
int compute_bigint_mod(bigint a,int b)
{
    int middle;
    int r=0;
    int temp;

    int i;

    for(i=a.int_size-1; i>=0; i--)
    {
        temp=a.digit[i]+r*10000;
        r=temp%b;
        middle=temp/b;
        a.digit[i]=middle;
    }

    if(a.digit[a.int_size-1]==0&&a.int_size!=1)//һ��������36���������ѵ�һλ���հ�
    {
        a.int_size--;
    }
    return r;

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

void init(bigint & a)
{
a.digit[0]=0;
    a.int_size=1;

}
int main()
{
    int a,b,i;
    string str;
    int result;
    bigint temp,temp1,temp2;
    init(temp);
    cin>>a>>b>>str;
    temp2.digit[0]=1;
    temp2.int_size=1;
    for(i=str.size()-1; i>=0; i--)
    {
        if(str[i]<'A')
        {
            temp1=compute_bigint_mul(temp2,str[i]-'0');
        }
        else
        {
            temp1=compute_bigint_mul(temp2,str[i]-'A'+10);
        }
        temp=compute_bigint_plus(temp,temp1);
        temp2=compute_bigint_mul(temp2,a);
    }
    print_bigint(temp);
    while(true)
    {
        result=compute_bigint_mod(temp,b);
        if(result<10)
        {
            s.push(result+'0');
        }
        else
        {
            s.push(result-10+'a');
        }
        temp=compute_bigint_div(temp,b);
        if(temp.digit[0]==0&&temp.int_size==1)
        {
            break;
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    return 0;
}
