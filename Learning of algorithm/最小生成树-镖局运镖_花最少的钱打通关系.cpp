#include <iostream>
#include <algorithm>
using namespace std;
struct edge
{
	// ������ 
	int a; 
	int b;
	int c; // ���м����	
};
const int MAX = 20;
struct edge plan[MAX]; // ��m������һ���m��1
int m, n; // ����ķ������ͳ��и���
int f[MAX] = {0}; // ��n������һ���n��1
int sum; // ����������
int coun; // ����·�� 
// �õ����鼯�ķ����ж��������Ƿ���ͨ 
void init()
{ 
    // ��ʼ�� 
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
}
int getF(int v)
{
	if(f[v] == v)
	{
		return v;
	}
	else
	{
		f[v] = getF(f[v]);
		return f[v];
	}
}
int merge(int v, int u)
{
	int t1 = getF(v);
	int t2 = getF(u);
	
	if(t1 != t2)
	{  // v��u����ͨ 
		f[t2] = t1;
		return 1; 
	}
	return 0; // ����ͨ 
}
int cmp(struct edge a, struct edge b)
{
	return a.c < b.c; 
} 

int main(void)
{
	ios::sync_with_stdio(0);
	sum = 0;
	coun = 0;
	cin >> n >> m;
	init(); // ��ʼ�� 
	for(int i = 0; i < m; ++i)
	{
		cin >> plan[i].a >> plan[i].b >> plan[i].c;
	}
	sort(plan, plan+m, cmp);
	for(int i = 0; i < m; ++i)
	{
		if(merge(plan[i].a, plan[i].b))
		{
			coun++;
			sum += plan[i].c; 
		}
		if(coun == n-1)
		{
			break;
		}
	}
	cout << sum << endl;
	return 0; 
} 
