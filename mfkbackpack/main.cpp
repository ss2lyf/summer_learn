#include <iostream>
#include<vector>
using namespace std;


/*input data
也就是输入的测试数据了，因为数组之类的为全局变量，所以还是需要提前写好
第一个为重量，第二个为价值
2 12
1 10
3 20
2 15
*/
int num=4; //物品数量
int package_weight=5; //背包承重
vector <int> weight(num+1); //存放每个物品的重量
vector <int> value(num+1);  //存放每个物品的价值
vector<vector<int> > table (num+1,vector<int> (package_weight+1));
//二维数组，存放的是当考虑到第i个物品的时候，且背包的承重为j的时候的最有的值

void mfkbackpack(int i,int j)
{
    if(i!=0&&j!=0)
    {
        if(table[i][j]<0)
            //当还没有尝试这个物品对应的这个重量的时候
        {
            mfkbackpack( i-1, j);
            //因为以下两种情况都需要哲哥，所以提前计算了，相当于递归

            if(j<weight[i])//物品比背包总重量重，就别放了
            {

                table[i][j]=table[i-1][j];
            }
            else
            {
                mfkbackpack( i-1, j-weight[i]);
                //下面要用到计算了这个之后的矩阵，所以先递归计算
                if((table[i-1][j-weight[i]]+value[i])<table[i-1][j])
                    //相比较，看要不要把这个放进去
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
    for(i=1; i<=num; i++) //为了方便下标的问题，还是浪费一个空间
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
