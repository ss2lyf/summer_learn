#include <iostream>
#include <malloc.h>
using namespace std;
/*核心算法*/
int  quick_sort(int* a,int num)
{
    int f_point=1,l_point=num-1; //从后往前的和从前往后的指针
    int key=a[0];
    int middle;
    while(!(f_point>l_point))
    {
        while(a[f_point]<=key&&f_point<num)//避免全部都是一个数字的情况
        {
            f_point ++;
        }
        while(a[l_point]>key&&l_point>0)
        {
            l_point--;
        }
        if(!(f_point>l_point)) //没有达到最后的推出条件的时候都要进行交换
        {
            middle=a[f_point];
            a[f_point]= a[l_point];
            a[l_point]=middle;
        }
    }
    if(l_point>0)  //将监视哨放到应该的位置
    {
        middle=a[0];
        a[0]= a[l_point];
        a[l_point]=middle;
    }
    return l_point;
}
void quick_sort_main(int * a,int num)
{
    if(num>1)//至少保证有两个数字才可以排序的
    {
        int middle;
        middle=quick_sort(a,num);
        quick_sort_main(a,middle); //分别对于前一部分和后一部分进行递归求解
        quick_sort_main(a+middle+1,num-middle-1);
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
    quick_sort_main(a,num);


    cout<<"final_result:  ";
    for(i=0; i<num; i++)  //输出结果
    {
        cout<<a[i]<<"  ";
    }
    cout << "" << endl;



    return 0;
}
