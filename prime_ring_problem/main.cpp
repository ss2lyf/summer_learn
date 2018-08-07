#include <iostream>
#include<vector>
using namespace std;
int num;
int prime[13]= {2,3,5,7,11,13,17,19,23,29,31,37,41};
//�����ٵ�ʱ�����ȷʵ��������Ҫȷ���Լ�д���ǶԵ�
bool is_prime(int number)
{

    for( int i=0; i<num; i++)
    {
        if(prime[i]==number)
        {
            return true;
        }
    }
    return false;
}

void find_prime(vector <int> &v,vector <int> &key)
{
    int i;
    if(v.size()==num)
    {
        bool flag=is_prime(v[num-1]+v[0]);
        if(flag)
        {
            for( i=0; i<num; i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        for(i=1; i<=num; i++)
        {
            if(key[i]!=true)
            {

                if(is_prime(v.back()+i))
                {
                    key[i]=true;
                    v.push_back(i);
                    find_prime(v,key);
                    //�������������Ͳ�����ʹ��ָ�������~
                    key[i]=false;
                    v.pop_back();
                }
            }
        }
    }
}

int main()
{

    int i;
    int count_case=1;
    while((cin>>num)&&num!=NULL)
    {
        cout<<"Case "<<count_case<<":"<<endl;
        count_case++;
        vector<int> key (num+1);
        vector<int >v;
        for(i=0; i<=num; i++)
        {
            key[i]=false;
        }
        key[1]=true;
        v.push_back(1);
        find_prime(v,key);
        v.clear();
        key.clear();
    }
    return 0;
}
