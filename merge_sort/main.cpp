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
void merge_sort(int* a,int *b,int f_end,int s_end)
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
}
/*����鲢��һϵ�в���*/
void merge_main(int num,int* a)
{

    int i;
    int b_num=num;
    if(num==1)//���ֻ��һ�����ͷ���
    {
        cout<<"result:"<<a[0];
    }
    else
    {
        if(num%2==1) //��������������Ļ����ȼ�1���ż����
        {
            num--;
        }
        int merge_num=1;     //�鲢�ĸ���
        int* temp_array;     //�洢�õ��м����
        int point;           //������±�
        for(; merge_num*2<=num; merge_num*=2)//��������������鲢��ʱ��
        {
            point=0;
            temp_array=(int*)malloc(sizeof(int)*merge_num*2);
            do
            {
                merge_sort(temp_array,a+point,merge_num,merge_num*2);//����Ӧ��λ�ý��й鲢
                copy_merge(a+point,temp_array,merge_num*2);
                point+=2*merge_num;//����һ���鲢��λ��
            }
            while(point<=(num-2*merge_num)); //�����ܹ鲢���鶼�鲢�˾ͽ���
            free(temp_array); //�ͷſռ�
        }
        if(point<b_num) //��ʣ�µļ���û�й鲢�Ĺ鲢��ȥ
        {
            temp_array=(int*)malloc(sizeof(int)*b_num);
            merge_sort(temp_array,a,merge_num,b_num);
            copy_merge(a,temp_array,b_num);
        }
        free(temp_array);
        cout<<"final_result:  ";
        for(i=0; i<b_num; i++)  //������
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
