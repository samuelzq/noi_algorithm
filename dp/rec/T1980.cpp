// 找出每一次迭代的状态转换方程即可。

#include <iostream>

using namespace std;
const int mod = 19260817;
int main(void)
{
	long long f1, f2, ans, n;

	cin >> n;

	ans = f1 = f2 = 1;

	for (int i = 3; i <= n; i++) {
		ans = (f1 + f2) % mod;
		f1 = f2;
		f2 = ans;
	}
	cout << ans;
	return 0;
}
