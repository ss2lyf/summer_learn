#include <iostream>
#include<vector>
using namespace std;

/*input data
Ҳ��������Ĳ��������ˣ���Ϊ����֮���Ϊȫ�ֱ��������Ի�����Ҫ��ǰд��
��һ��Ϊ�������ڶ���Ϊ��ֵ
2 12
1 10
3 20
2 15
*/
int num=4; //��Ʒ����
int package_weight=5; //��������
vector <int> weight(num+1); //���ÿ����Ʒ������
vector <int> value(num+1);  //���ÿ����Ʒ�ļ�ֵ

int  mfkbackpack_r(int i,int j)
{
    if(i!=0&&j!=0)
    {
        {
            int middle1,middle2;
            middle1=mfkbackpack_r(i-1,j);
            //��ΪҪ�õ����ȵݹ����
            if(j<weight[i])//��Ʒ�ȱ����������أ��ͱ����
            {
                return middle1;
            }
            else
            {
                middle2=mfkbackpack_r( i-1, j-weight[i])+value[i];
                //����Ҫ�õ����������֮��ľ��������ȵݹ����
                if((middle2)<middle1)
                    //��Ƚϣ���Ҫ��Ҫ������Ž�ȥ
                {
                    return middle1;
                }
                else
                {
                    return middle2;
                }
            }
        }

    }
    else  //����������Ϊ0����Ʒû��װ��ʱ�򣬷���0
    {
        return 0;
    }
}

int main()
{
    cout<<"grocerys num is:" <<num<<"  the Backpack load bearing is : "<<package_weight<<endl<<"Please input the grocery's weight & value :"<<endl;
    int i,j;
    for(i=1; i<=num; i++) //Ϊ�˷����±�����⣬�����˷�һ���ռ�
    {
        cin>>weight[i]>>value[i];
    }
    cout << "Max_value is: " <<mfkbackpack_r(num,package_weight)<< endl;
    return 0;
}
