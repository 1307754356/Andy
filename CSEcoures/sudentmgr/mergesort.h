
struct student  *sortList(struct student *sort_head) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    //链表归并排序
    if(sort_head == NULL || sort_head->next == NULL) return sort_head;
    else {
        //快慢指针找到中间节点
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
        fast = sortList(sort_head);//前半段排序
        slow = sortList(slow);//后半段排序
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
        if(sort_fc_head(sort_head1,sort_head2)) { //CMP修改的地方
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
  //  1.学号\n2.姓名\n3.性别\n4.民族\n5.语文\n6.数学\n7.英语\n输入‘8’以退出\n");




//学号排序
int cmp1(struct student *A,struct student *B)
{
    return (A->num > B->num) ;
}

//姓名排序
int cmp2(struct student *A,struct student *B)
{
    return strcmp(A->name,B->name) > 0 ;
}

//性别
int cmp3(struct student *A,struct student *B)
{
    return A->sex > B->sex ;
}

//民族
int cmp4(struct student *A,struct student *B)
{
    return strcmp(A->minzu,B->minzu) > 0;
}

//语文
int cmp5(struct student *A,struct student *B)
{
    return A->score[0] > B->score[0];
}

//数学
int cmp6(struct student *A,struct student *B)
{
    return A->score[1] > B->score[1];
}

// 英语
int cmp7(struct student *A,struct student *B)
{
    return A->score[2] > B->score[2];
}

//总分
//int cmp8(struct student *A,struct student *B)
//{
//    return A->num - B->num;
//}
//
////平均分
//int cmp9(struct student *A,struct student *B)
//{
//    return A->num - B->num;
//}
