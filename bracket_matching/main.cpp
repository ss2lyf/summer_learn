#include <iostream>
#include<stack>
#include<stdio.h>
using namespace std;
/*��ƥ����� $����ƥ����ǣ�
��Ŀ��Ҫ���ǲ���ƥ���������Ϊ��
����ƥ���������Ϊ$
�������Ŀ�е�Ҫ�󣬽���ջ��ֻӦ����λ�ã�����Ӧ�������š�
��Ȼ�������������ܼ򵥵Ľ���ˡ�
*/
int main()
{

    stack <int> s;
char middle;
   char a[100]={0};
   int i=0,num=0;
while((middle=getchar())!='\n')
    {
       a[num]=middle;
       num++;
    }

    num--;
    cout<<a<<endl;


    for(i=0;i<num;i++)
    {

        if(a[i]==')')
        {
         if(s.empty())
         {
             cout<<"?";
         }else{
         s.pop();
         cout<<"$";

         }
        }else if(a[i]=='(')

        {

            s.push(a[i]);
            cout<<" ";


        }else{

        cout<<" ";
        }


    }
    cout<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
