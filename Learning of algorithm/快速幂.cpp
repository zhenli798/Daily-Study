#include <iostream>

using namespace std;

#define ll long long 

// 计算x^n%mod 
ll quick_pow(ll x, ll n, ll mod)
{
	ll res = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			res *= x % mod;
		}
		x *= x % mod;
		n >>= 1;	
	}
	return res;
}
// 计算 x^n 
ll quick_pow(ll x, ll n)
{
	ll res = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			res *= x;
		}
		x *= x;
		n >>= 1;
	}
	return res;
}
// 计算方阵的快速幂 
// 方阵 
const int maxn = 1000;
int n; // 存放方阵阶数 
struct matrix
{
	ll m[maxn][maxn];
};
matrix mul(matrix x, matrix y)
{
	matrix tmp;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			tmp.m[i][j] = 0;
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				tmp.m[i][j] += x.m[i][k] * y.m[k][j];
			}
		}
	}
	return tmp;
}
matrix quick_pow(matrix x, int n)
{
	matrix res;
	for(int i = 1; i <= n; i++)
	{ // 得到单位阵 
		for(int j = 1; j <= n; j++)
		{
			if(i == j)
			{
				res.m[i][j] = 1;
			}
			else
			{
				res.m[i][j] = 0;
			}
		}
	} 
	
	while(n > 0)
	{
		if (n % 2 == 1)
		{
			res = mul(res, x);
		}
		x = mul(x, x);
		n >>= 1; 
	} 
	return res;
} 
// 方针快速幂取模运算 
matrix mul(matrix x, matrix y, ll mod)
{
	matrix tmp;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			tmp.m[i][j] = 0;
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				tmp.m[i][j] += (x.m[i][k] * y.m[k][j])%mod;
			}
			tmp.m[i][j] %= mod;
		}
	}
	return tmp;
 } 
matrix quick_pow(matrix x, ll n, ll mod)
{
	matrix res;
	for(int i = 1; i <= n; i++)
	{ // 得到单位阵 
		for(int j = 1; j <= n; j++)
		{
			if(i == j)
			{
				res.m[i][j] = 1;
			}
			else
			{
				res.m[i][j] = 0;
			}
		}
	} 
	
	while(n > 0)
	{
		if (n % 2 == 1)
		{
			res = mul(res, x, mod);
		}
		x = mul(x, x, mod);
		n >>= 1; 
	} 
	return res;
} 

/*
        （a+b)%mod = a%mod + b%mod
		(a*b)%mod = (a%mod) * (b%mod) 


*/ 
