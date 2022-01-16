#include <iostream>
#include <cstdio>
using namespace std;
int f[1001] = {0}, n, m, sum = 0; 
// ��ʼ��
void init()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	return; 
} 
// ������쵼��
int getf(int v)
{
	if(f[v] == v)
	{
		return v;
	}
	else
	{
		// ·��ѹ����˳����·���������˵�boss��Ϊ����ҵ���boss�����������
		f[v] = getf(f[v]);
		return f[v]; 
	}
} 
// �ϲ������Ӽ��ĺ��� 
void merge(int v, int u)
{
	int t1, t2; // t1��t2�ֱ�Ϊv��u������쵼��
	
	t1 = getf(v);
	t2 = getf(u);
	
	// ������ǰ�ˣ�����������
	if(t1 != t2)
	{
		// ��ߵĺ������ϣ������ұ߼��ŵ��ռ���boss 
		f[t2] = t1;
	 } 
	 return; 
 } 

int main(void)
{
	int x, y, i; 
	scanf("%d %d", &n, &m);
	// ��ʼ�� 
	init(); 
	
	// ��ʼ�ϲ������Ż� 
	for(i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	
	// ɨ���ж��ٸ������ķ����Ż�
	for(i = 1; i <= n; i++)
	{
		if(f[i] == i)
		{
			sum++;
		}
	} 
	
	printf("%d", sum);
	
	return 0;
} 
