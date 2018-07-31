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
        if(want>a[middle]) //����ں�һ��Ļ�����ȥ��һ����
        {
            return  bn_search( num-num/2-1, a,middle+1,e_point,want);
        }
        else if(want==a[middle]) //���ڵĻ��ͷ���
        {
            return middle;
        }
        else  //��Ȼ���ں�һ����
        {
            return bn_search( num/2, a,b_point,middle-1,want);
        }
    }
    else  //��ֻ��һ������ʱ��
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
    sort(a,a+num); //�۰����֮ǰ������
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
