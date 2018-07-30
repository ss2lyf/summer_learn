#include <iostream>
#include<malloc.h>
using namespace std;
/*复制数组b到数组a*/
void copy_merge(int *a,int *b,int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        a[i]=b[i];
    }
}
/* 归并排序的核心，a为结果存放位置，b为要归并的整个数组，
f_end 表示要归并的第一个数组的结束位置，s_end 表示要第二个数组的结束位置*/
void merge_sort(int* a,int *b,int f_end,int s_end)
{
    int point1=0,point2=f_end,point=0;
    {
        while(point1<f_end&&point2<s_end)//谁大放谁
        {
            if(b[point1]>b[point2])
            {
                a[point]=b[point2];
                point2++;
            }
            else
            {
                a[point]=b[point1];
                point1++;
            }
            point++;
        }
        if(point1==f_end)//如果是前一半先读完，则把后一办的剩余部分直接拷贝过去
        {
            while(point<s_end)
            {
                a[point]=b[point2];
                point2++;
                point++;
            }
        }
        else//与上面相反
        {
            while(point<s_end)
            {
                a[point]=b[point1];
                point1++;
                point++;
            }
        }
    }
}
/*处理归并的一系列操作*/
void merge_main(int num,int* a)
{

    int i;
    int b_num=num;
    if(num==1)//如果只有一个数就返回
    {
        cout<<"result:"<<a[0];
    }
    else
    {
        if(num%2==1) //如果个数是奇数的话，先减1变成偶数的
        {
            num--;
        }
        int merge_num=1;     //归并的个数
        int* temp_array;     //存储用的中间变量
        int point;           //数组的下标
        for(; merge_num*2<=num; merge_num*=2)//当至少能有两组归并的时候
        {
            point=0;
            temp_array=(int*)malloc(sizeof(int)*merge_num*2);
            do
            {
                merge_sort(temp_array,a+point,merge_num,merge_num*2);//对相应的位置进行归并
                copy_merge(a+point,temp_array,merge_num*2);
                point+=2*merge_num;//换下一个归并的位置
            }
            while(point<=(num-2*merge_num)); //当把能归并的组都归并了就结束
            free(temp_array); //释放空间
        }
        if(point<b_num) //把剩下的几个没有归并的归并进去
        {
            temp_array=(int*)malloc(sizeof(int)*b_num);
            merge_sort(temp_array,a,merge_num,b_num);
            copy_merge(a,temp_array,b_num);
        }
        free(temp_array);
        cout<<"final_result:  ";
        for(i=0; i<b_num; i++)  //输出结果
        {
            cout<<a[i]<<"  ";
        }
        cout << "" << endl;
    }
}
int main()
{
    int num;
    int i;
    cout<<"Please input the num you want to sort: " ;
    cin>>num;
    int* a=(int*)malloc(sizeof(int)*num);
    cout<<"init_input: ";
    for(i=0; i<num; i++)
    {
        a[i]=rand()%100;
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    merge_main(num,a);
    return 0;
}
