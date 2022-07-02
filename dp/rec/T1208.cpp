// 令f(m,n)表示m个苹果放到n个盘子里有多少种放法，下面分类讨论:
//
// m<n时，至少有n-m个盘子空着(这些空盘子并不影响最后的结果，因为每种方法都带有着
// 些空盘子)。只考虑m个苹果放m个盘子   f(m,n)=f(m,m)
//
// m>n时,按是否有空盘子 分2种情况：
//   a.假设至少一个盘子空着，相当于f(m,n)=f(m,n-1)
//   b.所有的盘子都有苹果，假设每个盘子可以先放一个，问题就变成：
//     m-n个苹果放到n个盘子，即f(m,n)=f(m-n,n)
//总的放法为二者之和， f(m,n)=f(m,n-1)+f(m-n,n)
//
//临界条件
//  n=1时，所有苹果都放在同一个盘子里   f(m,n)=1
//  m=0时，没有苹果 f(m,n)=1

#include <iostream>

using namespace std;
const int M = 11;
const int N = 11;
int memo[M][N];
int f(int m, int n)
#if 0
{
	int ret;
	if (m == 0)
		return 1;//没有苹果
	if (n == 1)
		return 1;//只有一个盘子

	if (memo[m][n])
		return memo[m][n];
	if (m < n)//苹果数量少于盘子数量
		ret = f(m,m);
	else //苹果数量多于盘子数量或者等于
		ret = f(m, n-1) + f(m-n, n);
	memo[m][n] = ret;
	return ret;
}
#else
{
	int ret;

	for (int i = 1; i <= n; i++)
		memo[0][i] = 1; //没有苹果
	for (int i = 1; i <= m; i++)
		memo[i][1] = 1; //只有一个盘子

	for (int i = 1; i <= m; i++) {
		for (int j = 2; j <= n; j++) {
			if (i < j)
				memo[i][j] = memo[i][i];
			else
				memo[i][j] = memo[i][j - 1] + memo[i - j][j];
		}
	}
	return memo[m][n];
}
#endif

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		int m,n;
		cin >> m>> n;
		cout << f(m, n) << endl;
	}
	return 0;
}
