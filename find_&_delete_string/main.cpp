#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include<stdio.h>
using namespace std;

/*input
in
#include
int main()
{


printf("Hi");}
}
*/
int main()
{
    string s;
    cin>>s;
    transform(s.begin(),s.end(),s.begin(),::tolower);
cout<<s<<endl;
   char p_temp[10000];
   string p,middle;
   int position;
   getchar();
   while(gets(p_temp))
   {
       p=p_temp;
    middle=p;
       transform(p.begin(),p.end(),p.begin(),::tolower);
       position=p.find(s,0);
       while(position!=-1)
       {
    p.erase(position,s.size());
    middle.erase(position,s.size());
    position=p.find(s,0);
       }
       position=middle.find(" ",0);
while(position!=-1)
       {
    middle.erase(position,1);
    position=middle.find(s,0);
       }
cout<<middle<<endl;
   }
    return 0;
}
