#include <iostream>

using namespace std;
//��Ȼ������±��±���������֣����Ի���Ҫע��ʲôʱ����������������ݣ�ʲôʱ����������±�
int main()
{
    int table[10001]= {0} ;
    int num;
    cin>>num;
    table[1]=1;
    int i,j;
    for(i=2; i<=num; i++)
    {

        if(table[i]==0)
        {
            j=2;
            //�̲���ʹ�õ��Ǵ�i*i��ʼ�ģ���Ϊi*(i-1)��һ������ע����
            //����Ϊ��Ӧ���и�ʡʱ�������
            while(true)
            {
                if(i*j>num)
                {
                    break;
                }
                else
                {

                    table[i*j]=1;
                    j++;
                }
            }
        }

    }
    for(i=2; i<num; i++)
    {
        if(table[i]==0&&(i%10==1))
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}
