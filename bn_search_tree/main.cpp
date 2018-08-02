#include <iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
typedef struct node
{
    struct node* lchild;
    struct node* rchild;
    int data;
} node;
/*这个题目没什么可以多说的，就是要注意正确处理数字和字符之间的关系就ok
*/
string f="",m="";
node* create_node(int num)
{
    node *middle;
    middle=(node*)malloc(sizeof(node));
    middle->lchild=NULL;
    middle->rchild=NULL;
    middle->data=num;
    return middle;
}

node * add_node(node*a,int num)
{
    if(a==NULL)
    {
        a=create_node(num);

    }
    else
    {

        if(num>a->data)
        {
            a->rchild= add_node(a->rchild,num);

        }
        else if(num<a->data)
        {
            a->lchild=add_node(a->lchild,num);
        }

    }
    return a;
}


void f_travle(node * a)
{
    f=f+char(a->data+'0');
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
    m=m+char(a->data+'0');
    if(a->rchild!=NULL)
    {
        m_travle(a->rchild);
    }
}


int main()
{
    int num;
    node * a=NULL;//注意指针的初始值不会是NULL
    string fa,ma;
    int middle;
    int i;
    char ch;
    while(true)
    {
        //使用全局变量的时候一定要注意及时初始化
        f="";
        m="";
        cin>>num;
        if(num==0)
        {
            break;
        }
        getchar();
        while((ch=getchar())!='\n')
        {
            middle=ch;
            a=add_node(a,middle-'0');
        }
        f_travle(a);
        m_travle(a);
        fa=f;
        ma=m;
        for(i=0; i<num; i++)
        {
            node *b=NULL;//因为free了，所以最好每次循环都重新申请一个
            f="";
            m="";
            while((ch=getchar())!='\n')
            {
                middle=ch;
                b=add_node(b,middle-'0');
            }
            f_travle(b);
            m_travle(b);
            //在c++中，可以用等号来直接判断两个字符是否相等
            if(f==fa&&m==ma)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
            free(b);

        }
    }
    return 0;
}
