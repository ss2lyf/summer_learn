#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> v;


    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    while(true)
    {
        int n;
        cin>>n;
        int *m;
        m=find(v.begin(),v.end(),n);
        cout<<m<<endl;

    }


    return 0;
}
