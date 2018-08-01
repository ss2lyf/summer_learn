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

int  mfkbackpack_r(int i,int j)
{
    if(i!=0&&j!=0)
    {
        {
            int middle1,middle2;
            middle1=mfkbackpack_r(i-1,j);
            //因为要用到，先递归计算
            if(j<weight[i])//物品比背包总重量重，就别放了
            {
                return middle1;
            }
            else
            {
                middle2=mfkbackpack_r( i-1, j-weight[i])+value[i];
                //下面要用到计算了这个之后的矩阵，所以先递归计算
                if((middle2)<middle1)
                    //相比较，看要不要把这个放进去
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
    else  //当背包质量为0和物品没有装的时候，返回0
    {
        return 0;
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
    cout << "Max_value is: " <<mfkbackpack_r(num,package_weight)<< endl;
    return 0;
}
