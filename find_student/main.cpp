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

typedef struct want
{
    int id;
    string want_id;
    int want_index;
} want;
bool cmp1 (student a,student b)
{
    return a.id<b.id;
}
bool cmp2(want a,want b)
{
    return a.want_id<b.want_id;
}
bool cmp3(want a,want b)
{
    return a.id<b.id;
}
int main()
{
    int num,select_num,i,find_num,middle;
    int point1,point2;
    while((cin>>num)&&num!=NULL)
    {
        vector<student> s(num);
        for(i=0; i<num; i++)
        {
            cin>>s[i].id>>s[i].name>>s[i].sex>>s[i].age;
        }
        sort(s.begin(),s.end(),cmp1);

        cin>>select_num;
        vector <want> w(select_num);
        for(i=0; i<select_num; i++)
        {
            w[i].id=i;
            cin>>w[i].want_id;
            w[i].want_index=-1;
        }
        sort(w.begin(),w.end(),cmp2);
        point1=0;
        point2=0;
        find_num=0;
        while(find_num!=select_num)
        {
            if(w[point2].want_id==s[point1].id)
            {
                w[point2].want_index=point1;
                point2++;
                find_num++;
            }
            else if(w[point2].want_id>s[point1].id)
            {
                point1++;
            }
            else
            {
                point2++;
                find_num++;
            }
        }
        sort(w.begin(),w.end(),cmp3);
        for(i=0; i<select_num; i++)
        {
            if(w[i].want_index==-1)
            {
                cout<<"No Answer!"<<endl;
            }
            else
            {
                middle=w[i].want_index;
                cout<<s[middle].id<<" "<<s[middle].name<<" "<<s[middle].sex<<" "<<s[middle].age<<endl;
            }
        }

        s.clear();
        w.clear();

    }
    return 0;
}
