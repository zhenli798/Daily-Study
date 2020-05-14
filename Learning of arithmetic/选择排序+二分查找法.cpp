#include <iostream>

using namespace std;
void inputArray(int *, int);
void rangeArray(int *, int); 
void outputArray(int *, int);
int findNum(int *, int, int);

int main(void)
{
	int n;
	int num; 
	int location;
	
	cout << "������Ԫ�ظ���" << endl;
	cin >> n; // ����Ԫ�ظ��� 
	
	int *p = new int [n]; //����ָ�봴������Ϊn�Ķ�̬����ռ�
	inputArray(p, n); //���ú�����������Ԫ�� 
	rangeArray(p, n); // ���ú���������Ԫ������
	outputArray(p, n); // ��ӡ���� 
	
	cout << "��������Ҫ����Ԫ��" << endl; 
	cin >> num;
	location = findNum(p, n, num);
	cout << "��Ԫ��λ�����������е�" << location << "��" << endl; 
	return 0;
} 

void inputArray(int *p, int n)
{
	cout << "����������Ԫ��" << endl;
	for(int *i = p; i < p + n; i++)
	{
		cin >> *i;
	}
	return;
}
void rangeArray(int *p, int n)
{ // ѡ������ 
	for(int *i = p; i < p + n -1; i++)
	{
		int min = *i;
		int *index = i;
		for(int *k = i + 1; k < p + n; k++)
		{
			if(*k < min)
			{
				min = *k;
				index = k; 
			}
		}
		int tmp = *index;
		*index = *i;
		*i = tmp;
	}
	return;
}
void outputArray(int *p, int n)
{
	cout << "��������Ϊ��" << endl;
	for(int *i = p; i < p + n; i++)
	{
		if(i != p)
			cout << " ";
		cout << *i;
	} 
}
int findNum(int *p, int n, int num)
{
	int max = n - 1;
	int min = 0;
	int middle;
	while(min <= max)
	{
		middle = (max + min)/2;
		if(p[middle] == num)
		{
			return middle + 1; 
		}
		else if(p[middle] < num)
		{
			min = middle + 1;
		}
		else
		{
			max = middle -1;
		}
	}
	return -1;
}
