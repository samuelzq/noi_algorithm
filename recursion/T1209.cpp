// 根据最后剩余的列数，我们将本问题分成两种情况：
//
// A：最后剩余一列，那么假设把这列去掉后，其铺砖情况与n-1时的情况一样
// B：最后剩余两列，那么把这两列先去掉后和n-2的情况一样

#include <iostream>

using namespace std;

int a[251] = {0};  //  保存中间计算结果，否则会重复递归导致TLE

int f(int c)
{
	int ans;
	if (a[c])
		return a[c];
	if (c == 1)
		ans = 1;
	else if (c == 2)
		ans = 3;
	else if (c == 3)
		ans = 5;
	else {
		ans = 2 * f(c - 2) + f(c - 1);
		ans %= 100007;
	}
	a[c] = ans;
	return ans;
}

int main(void)
{
	int n;
	cin >> n;
	if (n == 0)
		cout << 0;
	else
		cout << f(n);
	return 0;
}
