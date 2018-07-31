#include <iostream>
#include<malloc.h>
#include<algorithm>
using namespace std;

int bn_search(int num,int* a,int b_point,int e_point,int want)
{
    int middle;
    if(num>1)
    {
        middle=(num)/2+b_point;
        if(want>a[middle]) //如果在后一半的话，就去后一半找
        {
            return  bn_search( num-num/2-1, a,middle+1,e_point,want);
        }
        else if(want==a[middle]) //等于的话就返回
        {
            return middle;
        }
        else  //不然就在后一半找
        {
            return bn_search( num/2, a,b_point,middle-1,want);
        }
    }
    else  //当只有一个数的时候
    {

        if(a[b_point]==want)
        {
            return b_point;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    int num;
    int i;
    int want;
    int location;
    cout<<"Please input the num you want to init: " ;
    cin>>num;
    int* a=(int*)malloc(sizeof(int)*num);
    cout<<"init_input: ";
    for(i=0; i<num; i++)
    {
        a[i]=rand()%100;
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    sort(a,a+num); //折半查找之前先排序
    cout<<"sorted_input: ";
    for(i=0; i<num; i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;

    cout<<"Please input the num you want to search: " ;
    cin>>want;
    location=bn_search(num,a,0,num-1,want);
    if(location==-1)
    {
        cout<<"Sorry, we can't find the number you want."<<endl;
    }
    else
    {
        cout<<"The location of the number you want to find is at :"<<location+1<<endl ;
    }
    return 0;

}
