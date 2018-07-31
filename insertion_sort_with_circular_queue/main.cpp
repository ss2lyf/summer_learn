#include <iostream>
#include <malloc.h>
using namespace std;

/*node的结构体*/
typedef  struct node
{
    int data;
    struct node * next;
} node;

/*插入排序*/
node * b_insertion_sort(node * a,node * end_node,int num)
{
    int i,j;
    if(num>1)
    {
        node * now=end_node->next->next,*now_pre=end_node->next;
        node *middle;
        for(i=0; i<num-1; i++)
        {
            node *insert_position=end_node;
            while((insert_position->next)->data<now->data&&insert_position->next!=now)
//寻找合适的插入位置
            {
                insert_position=insert_position->next;
            }
            if(insert_position->next==now)//插入到前面一段的末尾的情况
            {
                now=now->next;
                now_pre=now_pre->next;
            }
            else if( insert_position==now)//对于位置不用变动的队尾的处理
            {
            }
            else   //正常的删除与插入
            {
                now_pre->next=now->next;
                middle=insert_position->next;
                insert_position->next=now;
                now->next=middle;
                now=now_pre->next;
            }
        }
//end_node=now_pre;//更新队尾的位置
        return end_node->next;
    }
}
int main()
{
    int num;
    int i;
    cout<<"Please input the num you want to sort: " ;
    cin>>num;
    node* a,*begin_node,*end_node;
    node *middle;
    cout<<"init_input: ";
    a=(node*)malloc(sizeof(node));
    a->data=rand()%100;
    begin_node=a;
    for(i=0; i<num-1; i++)
    {
        middle=(node*)malloc(sizeof(node));
        middle->data=rand()%100;
        a->next=middle;
        a=a->next;
    }
    cout<<endl;
    end_node=a;
    a->next=begin_node;
    a=begin_node;

    for(i=0; i<num; i++)
    {
        cout<<a->data<<"  ";
        a=a->next;
    }
    begin_node=b_insertion_sort(a,end_node,num);
    a=begin_node;
    cout<<endl;
    cout<<"result : ";
    for(i=0; i<num; i++)
    {
        cout<<a->data<<"  ";
        a=a->next;
    }
    cout<<endl;
    return 0;
}
