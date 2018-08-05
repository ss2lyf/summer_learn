#include<iostream>
#include<vector>
using namespace std;



void init(vector<int> v,int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        v[i]=-1;
    }
}
int count_road(vector<int> v,int num)
{
int result=0;
for(i=0;i<num;i++)
{
   if(v[i]==-1)
   {
       result++;
   }
}
return result;
}
void compute_road(vector<int> v,int a,int b)
{
    if(a<b)
    {
        v[b-1]=a-1;
    }else{
    v[a-1]=b-1;
    }
}
int main()
{
  while(true){
int num,num1,temp1,temp2;
cin>>num;
vector<int> v(num);
init(v,num);
cin>>num1;
for(i=0;i<num2)
{cin>>temp1>>temp2;
compute_road(v,temp1,temp2)

}

cout<<count_road(v,num)<<endl;
v.clear();

   } return 0;
}





