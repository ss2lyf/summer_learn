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
void merge_sort(int *b,int f_end,int s_end)
{
    int* a=(int*)malloc(sizeof(int)*s_end);
    if(s_end>1)
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
        copy_merge(b,a,s_end);
    }
}


/*处理归并的一系列操作*/
void merge_main(int num,int* a)
{

    int first_num,second_num;
    if(num>1)//如果只有一个数就返回
    {
        first_num=num/2;
        second_num=num-first_num;
        merge_main(first_num,a);
        merge_main(second_num,a+first_num);
        merge_sort(a,first_num,num);
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
    cout<<"final_result:  ";
    for(i=0; i<num; i++)  //输出结果
    {
        cout<<a[i]<<"  ";
    }
    cout << "" << endl;
    return 0;
}
