#include<iostream>
#include <vector>
using namespace std;
//8 46 200 83 24 211 86 61 67
//7 2 1 4 3 1 5 6
//Ҫ����һ����Ŀ��Ҫ���������������������������ȥ������Щ��İ�
int findLongest(vector<int> A, int n)
{
    // write code here
    vector<int> v (n);
    v[0]=1;
    int max_num=1;
    int i,j;
    for(i=1; i<n; i++)
    {
        //ÿ�μ��ų�ʼ��
        max_num=1;
        for(j=0; j<i; j++)
        {
            if(A[j]<A[i])
            {
                if(max_num<v[j]+1)
                {
                    max_num=v[j]+1;
                }
            }
        }
        v[i]=max_num;
    }

    max_num=v[0];
    for( i=0; i<n; i++)
    {
        if(max_num<v[i])
        {
            max_num=v[i];
        }
    }
    return max_num;
}
int main()
{
    vector <int> v;
    int num;
    while (true)
    {
        cin>>num;
        for(int i=0; i<num; i++)
        {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        cout<<findLongest(v,num)<<endl;;
        v.clear();
    }
}
