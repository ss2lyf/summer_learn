#include <iostream>
#include <malloc.h>
using namespace std;
/*�����㷨*/
int  quick_sort(int* a,int num)
{
    int f_point=1,l_point=num-1; //�Ӻ���ǰ�ĺʹ�ǰ�����ָ��
    int key=a[0];
    int middle;
    while(!(f_point>l_point))
    {
        while(a[f_point]<=key&&f_point<num)//����ȫ������һ�����ֵ����
        {
            f_point ++;
        }
        while(a[l_point]>key&&l_point>0)
        {
            l_point--;
        }
        if(!(f_point>l_point)) //û�дﵽ�����Ƴ�������ʱ��Ҫ���н���
        {
            middle=a[f_point];
            a[f_point]= a[l_point];
            a[l_point]=middle;
        }
    }
    if(l_point>0)  //�������ڷŵ�Ӧ�õ�λ��
    {
        middle=a[0];
        a[0]= a[l_point];
        a[l_point]=middle;
    }
    return l_point;
}
void quick_sort_main(int * a,int num)
{
    if(num>1)//���ٱ�֤���������ֲſ��������
    {
        int middle;
        middle=quick_sort(a,num);
        quick_sort_main(a,middle); //�ֱ����ǰһ���ֺͺ�һ���ֽ��еݹ����
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
    for(i=0; i<num; i++)  //������
    {
        cout<<a[i]<<"  ";
    }
    cout << "" << endl;



    return 0;
}
