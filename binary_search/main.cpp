#include <iostream>
#include<malloc.h>
#include<algorithm>
using namespace std;

int bn_search(int num,int* a,int want)
{
    int middle;
    int b_point=0,e_point=num-1; //两个指针
    while(b_point<=e_point)
    {
        middle=b_point+(e_point-b_point)/2;
        if(want>a[middle])
        {
            b_point=middle+1;
        }
        else if (want==a[middle])
        {
            return middle;
        }
        else
        {
            e_point=middle-1;
        }
    }
    return -1; // 如果没有找到相应的位置的话，就返回-1
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
    location=bn_search(num,a,want);
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
