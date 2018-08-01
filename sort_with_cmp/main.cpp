#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


typedef struct student{
    string name;
    int age;
    int score;

}student;
bool cmp(student a,student b)
{
    if(a.score!=b.score)
    {
        return a.score<b.score;
    }else {

        if(a.name!=b.name)
        {return a.name<b.name;
        }else{
        return a.age<b.age;}
    }

}
int main()
{
    int num;
    char n;
    int i;
    cin>>num;
    vector <student> a (num);
    for(i=0;i<num;i++)
    {
 cin>>a[i].name>>a[i].age>>a[i].score;
    }
    sort(a.begin(),a.end(),cmp);
 for(i=0;i<num;i++)
    {
       cout<<a[i].name<<" "<<a[i].age<<" "<<a[i].score<<endl;
    }
    return 0;
}
