#include<iostream>
#include<cstdlib>
#include<ctime>
//��������������Ҫ stdlib  ͷ�ļ�
using namespace std;
int comp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    //�������Ҫ������
    //1. �������ӣ���������Ĭ��Ϊsrand(1)��
    //    ��һ��ѡ��ʱ����Ϊ���� ����������һ�ξͺ�
    //2. ʹ�����������ѡ��Χ�ڣ�a,b��֮�䣬����
    //    'rand()%(b-a+1) +a '  ����ʽ
    srand((unsigned)time(NULL));
    int num[10];
    for(int i=0;i<10;++i)
        num[i]=rand()%21;

    //��Ҫ�ĸ�����
    //1. ������Ԫ�صĵ�ַ
    //2. �������
    //3. ÿ��Ԫ�صĴ�С
    //4. ������
    //������ֵΪ������С�����ţ�
    //������ֵΪ������Ӵ�С�ţ�
    //Ϊ��������ν
    //���Լ��Ϊ a,bһǰһ����뺯��
    //return a - b ���൱��a < b ��С����ǰ
    //return b - a ���൱��b < a �������ǰ
    qsort(num,10,sizeof(int ),comp);
    for(int i=0;i<10;++i)
        cout<<num[i]<<endl;

    return 0;
}
