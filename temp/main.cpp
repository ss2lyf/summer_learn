#include<iostream>
#include<vector>
using namespace std;
int main()
{

    int num;
    vector <int > a(200);
    int i;
    int want;
    int position;
    while((cin>>num)&&num!=NULL){
    position=-1;
    for(i=0;i<num;i++)
    {
        cin>>a[i];
    }
    cin>>want;
    for(i=0;i<num;i++)
    {
       if(want==a[i])
       {position=i;
           break;}
    }
        cout<<position<<endl;

    }

    return 0;


}
