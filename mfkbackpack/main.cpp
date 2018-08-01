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
vector<vector<int> > table (num+1,vector<int> (package_weight+1));
//��ά���飬��ŵ��ǵ����ǵ���i����Ʒ��ʱ���ұ����ĳ���Ϊj��ʱ������е�ֵ

void mfkbackpack(int i,int j)
{
    if(i!=0&&j!=0)
    {
        if(table[i][j]<0)
            //����û�г��������Ʒ��Ӧ�����������ʱ��
        {
            mfkbackpack( i-1, j);
            //��Ϊ���������������Ҫ�ܸ磬������ǰ�����ˣ��൱�ڵݹ�

            if(j<weight[i])//��Ʒ�ȱ����������أ��ͱ����
            {

                table[i][j]=table[i-1][j];
            }
            else
            {
                mfkbackpack( i-1, j-weight[i]);
                //����Ҫ�õ����������֮��ľ��������ȵݹ����
                if((table[i-1][j-weight[i]]+value[i])<table[i-1][j])
                    //��Ƚϣ���Ҫ��Ҫ������Ž�ȥ
                {
                    table[i][j]=table[i-1][j];
                }
                else
                {
                    table[i][j]= table[i-1][j-weight[i]]+value[i];
                }
            }
        }
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
    for(i=0; i<=num; i++)
    {
        for(j=0; j<=package_weight; j++)
        {
            if(i==0||j==0)
            {
                table[i][j]=0;
            }
            else
            {
                table[i][j]=-1;
            }
        }
    }

    mfkbackpack(num,package_weight);
    cout<<"the matrix is: "<<endl;
    for(i=0; i<=num; i++)
    {
        for(j=0; j<=package_weight; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "Max_value is: " <<table[num][package_weight]<< endl;
    return 0;
}
