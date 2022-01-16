#include <iostream>

using namespace std;

int main(void)
{
	int arr[10]={10,5,6,4,3,2,2,4,5,3};
	for(int i = 0; i < 9;i++)//遍历n-1次即可 
	{
	     	for(int k = 0;k<(9-i);k++)//每一次遍历将较大的数移动到右端. 
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
