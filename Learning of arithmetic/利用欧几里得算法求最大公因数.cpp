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
	
	cout << "��������������" << endl; 
	cin >> a >> b;
	
	cout << a << "��" << b << "���Լ��Ϊ��" << computeFactor(a, b) << endl; 
	return 0; 
} 
