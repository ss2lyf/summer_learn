#include<iostream>
#include<queue>

using namespace std;
int main()
{


    int num,i;
    int middle,result;
    int temp1,temp2;
    priority_queue<int,vector<int>,greater<int> > q;
    while((cin>>num)&&num!=NULL)
    {
      result=0;
        for(i=0;i<num;i++)
        {

            cin>>middle;
            q.push(middle);
        }

        while(q.size()>1)
        {
            temp1=q.top();
            q.pop();
            temp2=q.top();
            q.pop();
            result+=(temp1+temp2);
            q.push(temp1+temp2);
        }


        q.pop();
        cout<<result<<endl;



    }






}
