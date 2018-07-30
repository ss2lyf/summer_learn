#include <iostream>
#include<malloc.h>
using namespace std;
/*��������b������a*/
void copy_merge(int *a,int *b,int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        a[i]=b[i];
    }
}
/* �鲢����ĺ��ģ�aΪ������λ�ã�bΪҪ�鲢���������飬
f_end ��ʾҪ�鲢�ĵ�һ������Ľ���λ�ã�s_end ��ʾҪ�ڶ�������Ľ���λ��*/
void merge_sort(int *b,int f_end,int s_end)
{
    int* a=(int*)malloc(sizeof(int)*s_end);
    if(s_end>1)
    {
        int point1=0,point2=f_end,point=0;
        {
            while(point1<f_end&&point2<s_end)//˭���˭
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
            if(point1==f_end)//�����ǰһ���ȶ��꣬��Ѻ�һ���ʣ�ಿ��ֱ�ӿ�����ȥ
            {
                while(point<s_end)
                {
                    a[point]=b[point2];
                    point2++;
                    point++;
                }
            }
            else//�������෴
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


/*����鲢��һϵ�в���*/
void merge_main(int num,int* a)
{

    int first_num,second_num;
    if(num>1)//���ֻ��һ�����ͷ���
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
    for(i=0; i<num; i++)  //������
    {
        cout<<a[i]<<"  ";
    }
    cout << "" << endl;
    return 0;
}
