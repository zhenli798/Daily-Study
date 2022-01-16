#include <iostream>

using namespace std;
const int MAX = 10;
int a[MAX]; // 标记 
int vis[MAX]; // 标记已经用过的数字 
int n; // 几个数字的全排列，同时也代表了几个盒子 

void Out(int a)    //输出外挂
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
void dfs(int step)
{
	if (step == n+1)
	{ // 走到了第n+1个盒子面前，实际上没有n+1个盒子
		 for(int i = 1; i <= n; i++)
		 {
		 	if(i != 1)
		 	{
		 		putchar(' ');
			}
			Out(a[i]);
		} 
		putchar('\n');
		return ; // 必须返回上一步 
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i]) // 可以多加一个条件,i>a[step-1],使每个数都比前一个数大 
		{
			vis[i] = 1;
			a[step] = i; // 将数字i放入第step个盒子中
			dfs(step+1);
			vis[i] = 0; // 将数字i取出来 
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

