#include <iostream>

using namespace std;

int main()
{
    int a1[20];
    int a2[20];
    int num1,num2,i,j;
    int point1=0,point2=0;
    int result=0;
    int ten=1;
    cin>>num1>>num2;
    while(true)
    {
        if(num1/ten!=0)
        {
            a1[point1]=num1%(ten*10)/ten;
            point1++;
            ten*=10;
        }
        else
        {

            break;
        }
    }
    ten=1;
    while(true)
    {
        if(num2/ten!=0)
        {
            a2[point2]=num2%(ten*10)/ten;
            //���ϵķ�ʽ��ÿ�ΰ�num����10����Ҳ��֪������������Ľ�������ٶȻ᲻���࣬���о����ϵ�Ҫ��һЩ
            point2++;
            ten*=10;
        }
        else
        {
            break;
        }
    }

    for(i=0; i<point1; i++)
    {
        for(j=0; j<point2; j++)
        {
            result+=(a1[i]*a2[j]);
        }
    }
    cout<<result<<endl;
    return 0;
}
