#include <iostream>
#include <cstring> 
using namespace std;
#define MAX  51
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
int n, m;
int start_x, start_y;
int end_x, end_y;
int m_map[MAX][MAX];
int vis[MAX][MAX];
int min_step = 99999999; 
void dfs(int a, int b, int step)
{
	if(a == end_x && b == end_y)
	{ // 到达终点 
		if(step < min_step)
		{ // 是否是较短的路径 
			min_step = step;
		}
		return; // 返回上一级 
	}
	for(int i = 0; i < 4; i ++)
	{
		int tmp_x = a + dir[i][0];
		int tmp_y = b + dir[i][1];
		if (tmp_x > 0 && tmp_x <= n && tmp_y > 0 && tmp_y <= m && !vis[tmp_x][tmp_y] && m_map[tmp_x][tmp_y] != 1)
		{ // 1是障碍物 
			vis[tmp_x][tmp_y] = 1; // 标记该点 
			dfs(tmp_x, tmp_y, step+1);
			vis[tmp_x][tmp_y] = 0; // 释放该点 
		} 
	} 
	return; 
}



int main(void)
{
	ios::sync_with_stdio(0);
	memset(vis, 0, sizeof(vis));
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%d", &m_map[i][j]);
		}
	}
	scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
	vis[start_x][start_y] = 1; // 标记起点已经走过 
	dfs(start_x, start_y, 0); // 刚开始走了0步 
	printf("%d\n", min_step);
	return 0;
}
