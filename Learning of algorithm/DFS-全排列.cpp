#include <iostream>

using namespace std;
const int MAX = 10;
int a[MAX]; // ��� 
int vis[MAX]; // ����Ѿ��ù������� 
int n; // �������ֵ�ȫ���У�ͬʱҲ�����˼������� 

void Out(int a)    //������
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
void dfs(int step)
{
	if (step == n+1)
	{ // �ߵ��˵�n+1��������ǰ��ʵ����û��n+1������
		 for(int i = 1; i <= n; i++)
		 {
		 	if(i != 1)
		 	{
		 		putchar(' ');
			}
			Out(a[i]);
		} 
		putchar('\n');
		return ; // ���뷵����һ�� 
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i]) // ���Զ��һ������,i>a[step-1],ʹÿ��������ǰһ������ 
		{
			vis[i] = 1;
			a[step] = i; // ������i�����step��������
			dfs(step+1);
			vis[i] = 0; // ������iȡ���� 
		}
	} 
} 



int main(void)
{
	ios::sync_with_stdio(0);
	cin >> n;
	dfs(1); 
	
	return 0;
} 

