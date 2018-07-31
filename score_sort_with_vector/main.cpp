#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct student
{
    int id;
    int score;
} student;
bool cmp(student a,student b)
{
    if(a.score<b.score)
    {
        return true;
    }
    else if (a.score==b.score)
    {
        if(a.id<b.id)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    int num;
    int i;
    cin>>num;
    vector <student> a(num);
    for( i=0; i<num; i++)
    {
        cin>>a[i].id>>a[i].score;
    }
    sort(a.begin(),a.end(),cmp);
    for( i=0; i<num; i++)
    {
        cout<<a[i].id<<" "<<a[i].score<<endl;
    }
    return 0;
}
