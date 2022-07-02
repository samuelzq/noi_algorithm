/**
 * 严酷的训练 计蒜客 - T1739
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T1739
 *
 * 0-1背包问题。
 *
 * @File:   T1739.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-06
 *
 **/
#include <iostream>
#include <cmath>

using namespace std;

int dp[5005];
int t[5005], x[5005], y[5005];

int main(void)
{
	int k1, k2, m, n, p;

	cin >> k1 >> k2 >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		if (k1 > k2)
			t[i] /= (k1 / k2);
		else if (k1 < k2)
			t[i] *= (k2 / k1);
	}

	for (int i = 1; i <= m; i++)
		cin >> x[i] >> y[i];

	cin >> p;
	for (int i = 1; i <= m; i++) {
		for (int j = p; j >= t[x[i]]; j--) {
			dp[j] = max(dp[j - t[x[i]]] + y[i], dp[j]);
		}
	}
	cout << dp[p];
	return 0;
}
