#include <iostream>

using namespace std;

int main(void)
{
	int arr[10]={10,5,6,4,3,2,2,4,5,3};
	for(int i = 0; i < 9;i++)//����n-1�μ��� 
	{
	     	for(int k = 0;k<(9-i);k++)//ÿһ�α������ϴ�����ƶ����Ҷ�. 
	     	{
	     		if(arr[k]>arr[k+1])
	     		{
	     			int t = arr[k];
	     			arr[k] = arr[k+1];
	     			arr[k+1] = t;
				 }
			 }
	}
	for(int i = 0; i<10;i++)
	{
		cout << arr[i] << " ";
	}
	
	return 0;
 } 
