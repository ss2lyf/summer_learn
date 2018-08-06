#include <iostream>
#include <vector>
#include<algorithm>
#include<limits.h>
using namespace std;
int m [1001][1001];
/*input
3 3
1 2 5
2 3 5
3 1 2

5 7
1 2 3
1 4 7
2 4 2
2 3 4
3 4 5
4 5 4
3 5 6
*/
//�ҵ��죬����д����
//��Ҫ��dijkstra��floyd������
int main()
{

    int num,num1;
    int i,j,temp,temp1;
    int a,b,c,d;
    int min_d;
    cin>>num;
    vector<int> key;
    vector<int> distance(num+1);
    for(i=0; i<=num; i++)
    {
        distance[i]=INT_MAX;
    }

    for(i=0; i<=num; i++)
    {
        for(j=0; j<=num; j++)
        {
            if(i==j)
                //�Լ����Լ���������ʵʵŪ��0
            {
                m[i][j]=0;
            }
            else
            {
                m[i][j]=INT_MAX;
            }
        }
    }
    cin>>num1;
    for(i=0; i<num1; i++)
    {
        cin>>a>>b>>c>>d;
        //����ͼ�ܸ������ߣ������������Ҳ��ţ��
        if(c*10000+d<m[a][b])
        {
            m[a][b]=c*10000+d;
            m[b][a]=c*10000+d;
        }
        // m[b][a]=c+double(d)/1000000;
    }
    cin>>a>>b;
    distance[a]=0;
    key.push_back(a);
    while(key.size()<num)
    {
        temp=key.size();
        //for(i=0; i<temp; i++)
        //�ɵĽڵ���Χ����С��֮ǰ���Ѿ��ҹ��ˣ�ֻ��Ҫ�����µľ�����
        {
            temp1=key[temp-1];
            for(j=1; j<=num; j++)
            {
                //����þ���Ļ�������жϿ���ʡʱ��
                if(m[temp1][j]!=INT_MAX)
                {
                    if(distance[j]>distance[temp1]+m[temp1][j])
                    {
                        distance[j]=distance[temp1]+m[temp1][j];
                    }
                }
            }
        }
        min_d=INT_MAX;
        for(i=1; i<=num; i++)
        {
            if(distance[i]<min_d&&find(key.begin(),key.end(),i)==key.end())
            {
                min_d=distance[i];
                temp=i;
            }
        }
        key.push_back(temp);
    }
//���1��ÿһ����ľ��룬Ȼ��������Բۣ�����tmd�����ˣ���
    a=distance[b]/10000;
    b=distance[b]%10000;
    cout<<a<<" "<<b<<endl;
    return 0;
}


