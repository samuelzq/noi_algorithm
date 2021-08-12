// 每次铺砖时考虑的情况大致类似，将本问题分成两种情况：
// A：最后剩余一列，那么假设把这列去掉后，其铺砖情况与n-1时的情况一样，
// 而加上后，也只有一种情况所以方法数位a[n-1]
// B：最后剩余两列，那么把这两列先去掉后和n-2的情况一样，加上这两列后
// 一共有三种情况：1*2竖着放2列，1*2横着放，2*2直接填满。因为1*2竖着放
// 和A情况重复，所以方法数为a[n-2]*2
// 综上：方法总数=a[n-1]+2*a[n-2]

#include <iostream>

using namespace std;

int a[251] = {0};

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
		ans = 2 * f(c - 2);
		ans += f(c - 1);
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
