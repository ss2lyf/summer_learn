#include <iostream>
#include<stack>
#include<stdio.h>
using namespace std;
/*能匹配的是 $不能匹配的是？
题目中要求是不能匹配的右括号为？
不能匹配的左括号为$
如果按题目中的要求，进出栈的只应该是位置，而不应该是括号。
不然这个题用数组就能简单的解决了。
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
