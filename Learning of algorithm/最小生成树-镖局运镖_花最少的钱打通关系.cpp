#include <iostream>
#include <algorithm>
using namespace std;
struct edge
{
	// 方案数 
	int a; 
	int b;
	int c; // 城市间距离	
};
const int MAX = 20;
struct edge plan[MAX]; // 由m决定，一般比m大1
int m, n; // 输入的方案数和城市个数
int f[MAX] = {0}; // 由n决定，一般比n大1
int sum; // 花费银子数
int coun; // 已用路数 
// 用到并查集的方法判断两个点是否连通 
void init()
{ 
    // 初始化 
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
	{  // v、u不连通 
		f[t2] = t1;
		return 1; 
	}
	return 0; // 已连通 
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
	init(); // 初始化 
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
