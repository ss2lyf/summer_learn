#include <iostream>
#include<malloc.h>
using namespace std;
typedef struct node
{struct node* lchild;
    struct node* rchild;
    int data;
}node;

node* create_node(int num)
{
    node *middle;
    middle=(node*)malloc(sizeof(node));
    middle->lchild=NULL;
    middle->rchild=NULL;
    middle->data=num;
            return middle;
}

void add_node(node*a,int num)
{    if(num>a->data)
    {
        if(a->rchild==NULL)
        {
       a->rchild=create_node(num);
        }else{
        add_node(a->rchild,num);
        }
    }else if(num<a->data)
    {
        if(a->lchild==NULL)
        {
          a->lchild=create_node(num);
        }else{
        add_node(a->lchild,num);
        }
    }
}


void f_travle(node * a)
{
    cout<<a->data<<" ";
    if(a->lchild!=NULL)
    {
        f_travle(a->lchild);
    }
    if(a->rchild!=NULL)
    {
        f_travle(a->rchild);
    }
}
void m_travle(node * a)
{
    if(a->lchild!=NULL)
    {
        m_travle(a->lchild);
    }
     cout<<a->data<<" ";
    if(a->rchild!=NULL)
    {
        m_travle(a->rchild);
    }
}
void p_travle(node * a)
{
    if(a->lchild!=NULL)
    {
        p_travle(a->lchild);
    }
    if(a->rchild!=NULL)
    {
        p_travle(a->rchild);
    }
    cout<<a->data<<" ";
}


int main()
{
int num;
node * a;
int middle;
int i;
while((cin>>num)&&num!=NULL)
{
cin>>middle;
a=create_node(middle);
for(i=0;i<num-1;i++)
{
    cin>>middle;
add_node(a,middle);
}
f_travle(a);cout<<endl;
m_travle(a);cout<<endl;
p_travle(a);cout<<endl;
}
    return 0;
}
