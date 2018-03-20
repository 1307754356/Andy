
struct student  *sortList(struct student *sort_head) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    //����鲢����
    if(sort_head == NULL || sort_head->next == NULL) return sort_head;
    else {
        //����ָ���ҵ��м�ڵ�
        struct student *fast, *slow;
        slow=sort_head;
        fast=sort_head;
        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        fast = sortList(sort_head);//ǰ�������
        slow = sortList(slow);//��������
        return sortmerge(fast, slow);
    }

}
// merge two sorted list to one
struct student *sortmerge( struct student *sort_head1, struct student *sort_head2) {
    if(sort_head1 == NULL)
        return sort_head2;
    if(sort_head2 == NULL)
        return sort_head1;
    struct student *res, *p ;
    if(sort_fc_head(sort_head1,sort_head2)) {

        res = sort_head1;
        sort_head1 = sort_head1->next;
    } else {
        res = sort_head2;
        sort_head2 = sort_head2->next;
    }
    p = res;

    while(sort_head1 != NULL && sort_head2 != NULL) {
        if(sort_fc_head(sort_head1,sort_head2)) { //CMP�޸ĵĵط�
            p->next = sort_head1;
            sort_head1 = sort_head1->next;
        } else {
            p->next = sort_head2;
            sort_head2 = sort_head2->next;
        }
        p = p->next;
    }
    if(sort_head1 != NULL)p->next = sort_head1;
    else if(sort_head2 != NULL)p->next = sort_head2;
    return res;
}
  //  1.ѧ��\n2.����\n3.�Ա�\n4.����\n5.����\n6.��ѧ\n7.Ӣ��\n���롮8�����˳�\n");




//ѧ������
int cmp1(struct student *A,struct student *B)
{
    return (A->num > B->num) ;
}

//��������
int cmp2(struct student *A,struct student *B)
{
    return strcmp(A->name,B->name) > 0 ;
}

//�Ա�
int cmp3(struct student *A,struct student *B)
{
    return A->sex > B->sex ;
}

//����
int cmp4(struct student *A,struct student *B)
{
    return strcmp(A->minzu,B->minzu) > 0;
}

//����
int cmp5(struct student *A,struct student *B)
{
    return A->score[0] > B->score[0];
}

//��ѧ
int cmp6(struct student *A,struct student *B)
{
    return A->score[1] > B->score[1];
}

// Ӣ��
int cmp7(struct student *A,struct student *B)
{
    return A->score[2] > B->score[2];
}

//�ܷ�
//int cmp8(struct student *A,struct student *B)
//{
//    return A->num - B->num;
//}
//
////ƽ����
//int cmp9(struct student *A,struct student *B)
//{
//    return A->num - B->num;
//}
