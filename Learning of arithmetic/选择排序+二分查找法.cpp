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
	
	cout << "请输入元素个数" << endl;
	cin >> n; // 输入元素个数 
	
	int *p = new int [n]; //利用指针创建长度为n的动态数组空间
	inputArray(p, n); //调用函数输入数组元素 
	rangeArray(p, n); // 调用函数给数组元素排序
	outputArray(p, n); // 打印数组 
	
	cout << "请输入需要查找元素" << endl; 
	cin >> num;
	location = findNum(p, n, num);
	cout << "该元素位于有序数列中第" << location << "个" << endl; 
	return 0;
} 

void inputArray(int *p, int n)
{
	cout << "请输入数组元素" << endl;
	for(int *i = p; i < p + n; i++)
	{
		cin >> *i;
	}
	return;
}
void rangeArray(int *p, int n)
{ // 选择排序 
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
	cout << "有序数列为：" << endl;
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
