#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct student
{

    string id;
    string name;
    string sex;
    string age;

} student;

bool cmp1 (student a,student b)
{
    return a.id<b.id;
}

int main()
{
    int num,select_num,i,middle;
    string want;
    int point1,point2,position;
    while((cin>>num)&&num!=NULL)
    {
        vector<student> s(num);
        for(i=0; i<num; i++)
        {
            cin>>s[i].id>>s[i].name>>s[i].sex>>s[i].age;
        }
        sort(s.begin(),s.end(),cmp1);

        cin>>select_num;
       for(i=0;i<select_num;i++)
       {
           point1=0;point2=num-1;
           position=-1;
           cin>>want;
          while(point1<=point2)
          {

              middle=(point1+point2)/2;
              if(s[middle].id==want)
              {
                position=middle;
                break;

              }else if(want<s[middle].id)
              {

                  point2=middle-1;
                  //二分查找的时候一定要记着重新确定范围的时候要去掉之前的中间的那个元素

              }else{


              point1=middle+1;
              }

          }
          if(position==-1)
          {
              cout<<"No Answer!"<<endl;
          }else{
          cout<<s[position].id<<" "<<s[position].name<<" "<<s[position].sex<<" "<<s[position].age<<endl;
       }
        s.clear();

    }}
    return 0;
}
