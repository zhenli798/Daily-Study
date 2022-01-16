#include <iostream>

using namespace std;
int computeFactor(int a, int b)
{
	int c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void)
{
	int a, b;
	
	cout << "清输入两个整数" << endl; 
	cin >> a >> b;
	
	cout << a << "和" << b << "最大公约数为：" << computeFactor(a, b) << endl; 
	return 0; 
} 
