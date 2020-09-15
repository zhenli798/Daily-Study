#include <iostream>
#include <cstdio>
using namespace std;
int f[1001] = {0}, n, m, sum = 0; 
// 初始化
void init()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	return; 
} 
// 找最高领导人
int getf(int v)
{
	if(f[v] == v)
	{
		return v;
	}
	else
	{
		// 路径压缩，顺带把路上遇见的人的boss改为最后找到的boss，即被提拔了
		f[v] = getf(f[v]);
		return f[v]; 
	}
} 
// 合并两个子集的函数 
void merge(int v, int u)
{
	int t1, t2; // t1、t2分别为v和u的最高领导人
	
	t1 = getf(v);
	t2 = getf(u);
	
	// 后浪推前浪，擒贼先擒王
	if(t1 != t2)
	{
		// 左边的后来居上，成了右边集团的终极大boss 
		f[t2] = t1;
	 } 
	 return; 
 } 

int main(void)
{
	int x, y, i; 
	scanf("%d %d", &n, &m);
	// 初始化 
	init(); 
	
	// 开始合并犯罪团伙 
	for(i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	
	// 扫描有多少个独立的犯罪团伙
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
