#include <iostream>
#define offset 2000
#define unreach -9999999
using namespace std;
int m[101][4001];
int value[101];
int main()
{
    int case_num;
    int num;
    int i,j,k,temp;
    bool zero=false;
    cin>>case_num;
    for(k=0;k<case_num;k++)
    {   zero=false;
        cin>>num;
        //num=num_temp;
        for(i=1;i<=num;i++)
        {cin>>temp;
            if(temp==0){
                    num--;
                    i--;
            zero=true;
            }else{
            value[i]=temp;
            }
        }
        for(i=0;i<=4000;i++)
        {
            m[0][i]=unreach;
        }
        m[0][0+offset]=0;
        for(i=1;i<=num;i++)
        {
            for(j=-2000;j<=4000;j++)
            {
             int temp1=unreach;
             int temp2=unreach;
             int temp3=unreach;
             if(j-value[i]>=-2000)
             {
                 temp1=m[i-1][offset+j-value[i]]+value[i];
             }
              if(j+value[i]<=2000)
             {
                 temp2=m[i-1][offset+j+value[i]]+value[i];
             }
            temp3=m[i-1][offset+j];
             temp=max(temp1,temp2);
             temp=max(temp,temp3);
             m[i][offset+j]=temp;
            }
        }

if(m[num][offset]==0)
{
    if(zero)
    {
  cout<<"0"<<endl;
    }else{
    cout<<"-1"<<endl;
    }
}else{
cout<<m[num][offset]/2<<endl;
}








    }



    return 0;
}
