/**
 * 买书 计蒜客 - T1225
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T1225
 *
 * 完全背包问题，求背包装物的种类。
 * 假设背包的总容量为n，某件商品体积为m1, m2, ..., mn。
 * 则f(n) = f(n-m1) + f(n-m2) + ... + f(n-mn)。
 *
 * @File:   T1225.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-02
 *
 **/
#include <iostream>
#include <cmath>

using namespace std;

const int N = 1105;
int v[4] = {10, 20, 50, 100};
int dp[N] = {0, };

int main(void)
{
	int n;

	cin >> n;

	if (n % 10) {
		cout << 0;
		return 0;
	}

	dp[100] = 1;

	n += 100;
	for (int j = 0; j < 4; j++) {
		for (int i = 100; i <= n; i += 10) {
			dp[i] = dp[i - v[j]] + dp[i];
		}
	}
	cout << dp[n];
	return 0;
}
