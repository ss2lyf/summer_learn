#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//����ڵ㣬�洢���������λ���Լ����ͬʱ��������������ɶ���ƣ��
typedef struct node
{
    int a;
    int b;
    int weight;
} node;
//�ȽϺ�����ϣ������Сƣ�����������
bool cmp(node a,node b)
{
    return a.weight<b.weight;
}
int main()
{
    int cost=0;
    int n,k;
    cin>>n>>k;
    int i;
    int temp;
    node node_temp;
    vector <int > v1 ;
    vector<node> v2;
    for(i=0; i<n; i++)
    {
        cin>>temp;
        v1.push_back(temp);
    }
//�Ȱ����еĻ�����������Ҿ��Ÿ����ϵ������һ����
    sort(v1.begin(),v1.end());
//����������������Ʒ֮��Ĳ�
    for(i=1; i<n; i++)
    {
        node_temp.a=i-1;
        node_temp.b=i;
        node_temp.weight=(v1[i]-v1[i-1])*(v1[i]-v1[i-1]);
        v2.push_back(node_temp);
    }
//���մ�С������
    sort(v2.begin(),v2.end(),cmp);
//��ѭ��û����˼��д��trueҲ����
    while(!v2.empty())
    {
        node_temp=v2.front();
        v2.erase( v2.begin( ));
        {
            //�����������Ʒ֮ǰ��û�����ߣ���������������ߣ�Ȼ�����£���ԭ�����б��-1���Ǳ����ߵ���˼
            if(v1[node_temp.a]!=-1&&v1[node_temp.b]!=-1)
            {
                v1[node_temp.a]=-1;
                v1[node_temp.b]=-1;
                cost+=node_temp.weight;
                k--;
            }
        }
//����n���ˣ�����
        if(k==0)
        {
            break;
        }
    }
    cout << cost<< endl;
    return 0;
}
