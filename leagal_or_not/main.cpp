#include <iostream>
#include<vector>
using namespace std;
typedef struct node
{
    int a;
    int b;
}node;
int main()
{

int num1,num2,i,j;
node temp;
cin>>num1>>num2;
vector<int > v1(num1);
vector <node> v2;

for(i=0;i<num1;i++)
{
    v1[i]=0;
}

for(i=0;i<num2;i++)
{cin>>temp.a;
cin>>temp.b;
v2.push_back(temp);
v1[temp.b]++;
}
while(true){
int position=-1;
for(i=0;i<num1;i++)
{
    if(v1[i]==0)
    {
         position=i;
        break;

    }

}
if(position!=-1)
{
    v1[i]=-1;
    for(j=0;j<v2.size();j++)
    {
        if(v2[j].a==i)
        {
            v1[v2[j].b]--;
        v2.erase(v2.begin() + j);
        }

    }



}else{

break;
}
}


if(v2.size()!=0)
{
    cout<<"no"<<endl;

}else{

cout<<"yes"<<endl;

}



    return 0;
}
