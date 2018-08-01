#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i,user_num,book_num;
    cin>>user_num;
    cin>>book_num;
    vector <int> b(book_num+1);
    vector <int> u(user_num+1);
    for(i=0;i<=book_num;i++)
    {
        b[i]=0;
    }
    for(i=1;i<=user_num;i++)
    {cin>>u[i];
    b[u[i]]++;
    }

    for(i=1;i<=user_num;i++)
    {
    if(b[u[i]]==1)
    {
        cout<<"BeiJu"<<endl;
    }else{
    cout<<b[u[i]]-1<<endl;
    }
    }

    return 0;
}
