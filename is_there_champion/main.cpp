#include <iostream>
#include<map>
/*input
3
Alice Bob
Smith John
Alice Smith
5
a c
c d
d e
b e
a d
0
*/
int a[10001];
using namespace std;
map <string,int>m;
int main()
{
    int num;
    int i;
    int id,id_a,id_b;
    int count_num;
    string temp1,temp2;
    while(cin>>num)
    {
        if(num==0)
        {
            break;
        }
        m.clear();
        id=0;
        count_num=0;
        for(i=0; i<=1000; i++)
        {
            a[i]==0;
        }
        for(i=0; i<num; i++)
        {
            cin>>temp1>>temp2;
            if(m.find(temp1)==m.end())
            {
                m[temp1]=id;
                //id_a=id;
                id++;
            }
            else
            {
                //id_a=m[temp1];
            }
            if(m.find(temp2)==m.end())
            {
                m[temp2]=id;
                id_b=id;
                id++;
            }
            else
            {
                id_b=m[temp2];
            }
            a[id_b]++;
        }
        for(i=0; i<num; i++)
        {
            if(a[i]==0)
            {
                count_num++;
            }
            if(count_num>1)
            {
                break;
            }
        }
        if(count_num>1)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
