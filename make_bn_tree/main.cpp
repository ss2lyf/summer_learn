#include <iostream>
#include <malloc.h>
using namespace std;

/*INPUT
FDXEAG
XDEFAG
*/
typedef struct node
{
    struct node* lchild;
    struct node* rchild;
    char data;
} node;

node* createtree(string a,string b)
{
    node * middle;
    int temp;
    int position;
    if(a.size()>1)
    {
        position=b.find(a[0]);
        temp=b.size()-1-position;
        middle=(node*)malloc(sizeof(node));
        //�������о�����ѧ����֪��Ϊʲô����ֱ�����ַ������и�ֵ��
        middle->data=a[0];
        //��Ϊû��˵����ȫ������������һ��Ҫ�������������������������᲻����ֿյ����
        if(position!=0&&position!=a.size()-1)
        {
            middle->lchild=createtree(a.substr(1,position),b.substr(0,position));
            middle->rchild=createtree(a.substr(1+position,temp),b.substr(1+position,temp));
        }
        else if(position==0)
        {
            middle->rchild=createtree(a.substr(1+position,temp),b.substr(1+position,temp));
            middle->lchild=NULL;
        }
        else
        {

            middle->lchild=createtree(a.substr(1,position),b.substr(0,position));
            middle->rchild=NULL;
        }
    }
    else
    {
        middle=(node*)malloc(sizeof(node));

        middle->data=a[0];
        middle->lchild=NULL;
        middle->rchild=NULL;
    }
    return middle;
}
void p_travel(node * a)
{
    if(a->lchild!=NULL)
    {
        p_travel(a->lchild);
    }
    if(a->rchild!=NULL)
    {
        p_travel(a->rchild);
    }
    cout<<a->data;
}

int main()
{
    string s1,s2;
    while((cin>>s1)&&s1!="")
    {
        cin>>s2;
        node* a =createtree(s1,s2);
        p_travel(a);
        cout<<endl;
    }
    return 0;
}
