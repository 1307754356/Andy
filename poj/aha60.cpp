#include<iostream>
#include<cstdlib>
// 9
// 2 3 5 8 9 10 18 26 32
//6
//链表的循环和插入
using namespace std;
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int i,n,a;
    struct node *head;
    head=NULL;
    struct node *p,*q,*t;
    cin>>n;
    while(n--)
    {
        cin>>a;
        p=(struct node *)malloc(sizeof(struct node));
        p->data=a;
        p->next=NULL;
        //若创建的是第一个节点，则令头指针指向此节点
        if(head==NULL)
            head=p;
        //否则，则让上一个节点的指针指向此节点
        else
            q->next=p;
        //让q指向p指向的节点（让p腾出手来接受下一个申请的内存）
        q=p;
    }

    //插入一个新数字（此处默认该链表已经排序完成）
    //先查找至发现比插入数大的元素
    int num;
    cin>>num;
    t=head;
    while(t!=NULL)
    {
        if(t->next->data > num)
        {
            //创建新节点，然后赋值
            p=(struct node *)malloc(sizeof(struct node));
            p->data=num;
            //先让新节点和后面的节点相连
            p->next=t->next;
            //然后让前面的节点链接新节点
            t->next=p;
            //插入完毕，跳出循环
            break;
        }
        t=t->next;
    }

    t=head;
    while(t!=NULL)
    {
        cout<<t->data<<endl;
        t=t->next;
    }


    return 0;
}
