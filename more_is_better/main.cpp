#include<iostream>
#include<vector>
using namespace std;

/*要注意，vector传的不是地址，很危险的
还有一定要注意，如果循环什么的有问题的时候可以看看是不是循环语句后面有分号
要注意，vector我不知道，但是数组的话，如果能，尽量申请两个一维数组也别申请一个二维数组,
第一是麻烦，第二是亦可能都不知道怎么死的，oom
有的时候不用管中间的，比如你求最大值的时候，对于这个题，在一个集合下的所有的人的朋友都应该像等，
但是不重要，你找到一个点能记录最大值就行了
*/
void init(vector<int> &v,int num)
{
    int i;
    for(i=0; i<=num; i++)
    {
        v[i]=-1;
    }
}
int find_root(vector<int>&v,int a)
{
    if (v[a]!=-1)
    {
        int temp;
        temp=find_root(v,v[a]);
        v[a]=temp;
        return temp ;
    }
    else
    {
        return  a;
    }
}

void compute_road(vector<int> &v,int a,int b)
{
    int temp_a,temp_b;

}
int main()
{
    //while(true)
    {
        int num,num1,temp1,temp2,temp_a,temp_b,i;
        int max_num=0;
        num=10000000;
        vector<int> v(num+1);
        vector<int> s(num+1);

        init(v,num);
        for(i=1;i<=num;i++)
        {
            s[i]=1;
        }
        cin>>num1;
        for(i=0; i<num1; i++)
        {
            cin>>temp1>>temp2;
           temp_a=find_root(v,temp1);
          temp_b=find_root(v,temp2);
    if(temp_a!=temp_b)
    {
        v[temp_a]=temp_b;
        s[temp_b]=s[temp_b]+s[temp_a];
    }
        }

        for(i=1;i<=num;i++)
        {
            if(max_num<s[i])
            {
                max_num=s[i];
            }
        }
        cout<<max_num<<endl;
        v.clear();
        s.clear();
    }
    return 0;
}





