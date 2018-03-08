//��ǳ������չʾ
//ǳ����ָ���ǽ�ֱֵ�ӵؿ�������һ������
//���ָ����ָ�����鲻ͬ���ڴ棬Ȼ��ֻ��Ӧ���

//������½�һ���ѣ�
//Ȼ���ͨ��ѭ���ķ����Ѷ��е�һ��һ�������ݿ���ȥ��
//�����Ϳ��Ա������޸Ŀ������������ʱ��
//ͬʱ�ı��˱��������������
#include<iostream>
using namespace std;

//������ Array
class Array
{
public:
    Array(int _count)
    {
        m_iCount =_count;
        m_pArr = new int [m_iCount];
        //��ʵ������ͬʱ�����ڴ�
        for(int i=0;i<m_iCount;i++)
            m_pArr[i]=i;
        //Ȼ�������������
        cout<<"Array()"<<endl;
    }
//    Array(const Array& arr)
//    {
//        cout<<"Array(const Array& arr)"<<endl;
//        m_pArr =arr.m_pArr;
//        m_iCount=arr.m_iCount;
//    }
     Array(const Array& arr)
     {
         m_iCount=arr.m_iCount;
         m_pArr =new int [m_iCount];
         for(int i=0;i<m_iCount;i++)
            m_pArr[i]= arr.m_pArr[i];
     }
    ~Array()
    {
        //���ٶ��󣬱����ڴ�й©
        delete []m_pArr;
        m_pArr=NULL;
        cout<<"~Array()"<<endl;
    }
    void setCount(int _count)
    {
         m_iCount=_count;
    }
    int getCount(void)
    {
        return m_iCount;
    }
    void printAddr()
    {
        cout<<"��ַ�ǣ� "<<m_pArr<<endl;
    }
    void printArr()
    {
        for(int i=0;i<m_iCount;i++)
        cout<<m_pArr[i]<<" ";
        cout<<endl;
    }
private:
    int m_iCount;
    int *m_pArr;
};
int main()
{
    Array arr1(5);
    arr1.printAddr();
    arr1.printArr();
    Array arr2(arr1);
    arr2.printAddr();
    arr2.printArr();
    return 0;
}

/*ǳ����������
Array()
��ַ�ǣ� 0xc0c98
Array(const Array& arr)
��ַ�ǣ� 0xc0c98
~Array()
~Array()

�ɼ���ǳ������ʹ������ָ��ָ��ͬһ���ڴ�
����ִ������������ʱ�򣬻ᱨ��ͬһ���ڴ��ͷ������Σ�
*/

/*���������
Array()
��ַ�ǣ� 0x2b00c98
��ַ�ǣ� 0x2b00cb8
~Array()
~Array()
�ɼ�������ǲ�ͬ�ĵ�ַ
*/
