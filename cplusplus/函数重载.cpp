/*��ͬһ��Χ�����������������Ƶ�ͬ��������
������Щͬ����������ʽ����
��ָ�����ĸ��������ͻ���˳��
���벻ͬ��
Ҳ����˵��ͬһ���������ɲ�ͬ�����㹦�ܡ�
��������غ�����
*/
#include <iostream>
using namespace std;
/**
  *�������ܣ�����a��b�����ֵ
  *a��b����������
  */
int getMax(int a, int b)
{
    return a > b ? a : b;
}

/**
  * �������ܣ����������е����ֵ
  * arr����������
  * count�����鳤��
  * �ú����Ƕ����溯��������
  */
int getMax(int arr[],int count)
{
    //����һ����������ȡ����ĵ�һ��Ԫ��
    int maxNum=arr[0];
	for(int i = 1; i < count; i++)
	{
        //�Ƚϱ�������һ��Ԫ�صĴ�С
		if(arr[i]>maxNum)
		{
            //��������е�Ԫ�ر�maxNum�����ȡ�����е�ֵ
			maxNum=arr[i];
		}
	}
	return maxNum;
}

int main(void)
{
    //����int���鲢��ʼ��
	int numArr[3] = {3, 8, 6};

    //�Զ�����int getMax(int a, int b)
	cout << getMax(3, 6) << endl;

    //�Զ����÷������������ֵ�ĺ������������е����ֵ
	cout << getMax(numArr,3) << endl;
	return 0;
}
