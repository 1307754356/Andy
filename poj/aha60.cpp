#include<iostream>
#include<cstdlib>
// 9
// 2 3 5 8 9 10 18 26 32
//6
//�����ѭ���Ͳ���
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
        //���������ǵ�һ���ڵ㣬����ͷָ��ָ��˽ڵ�
        if(head==NULL)
            head=p;
        //����������һ���ڵ��ָ��ָ��˽ڵ�
        else
            q->next=p;
        //��qָ��pָ��Ľڵ㣨��p�ڳ�����������һ��������ڴ棩
        q=p;
    }

    //����һ�������֣��˴�Ĭ�ϸ������Ѿ�������ɣ�
    //�Ȳ��������ֱȲ��������Ԫ��
    int num;
    cin>>num;
    t=head;
    while(t!=NULL)
    {
        if(t->next->data > num)
        {
            //�����½ڵ㣬Ȼ��ֵ
            p=(struct node *)malloc(sizeof(struct node));
            p->data=num;
            //�����½ڵ�ͺ���Ľڵ�����
            p->next=t->next;
            //Ȼ����ǰ��Ľڵ������½ڵ�
            t->next=p;
            //������ϣ�����ѭ��
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
