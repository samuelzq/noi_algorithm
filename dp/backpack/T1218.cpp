/**
 * 数字组合 计蒜客 - T1218
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T1218
 *
 * 0-1背包问题，背包容量为t，求方案数。
 * 设k为背包当前的乃重量或最大容量，dp[k]为满足此限制的装法总和。
 * 第i个物品不放入时，dp[i][k] = dp[i-1][k]；第i个物品放入时，
 * dp[i][k] = dp[i-1][k-v[i]]。因此dp[i][k]=dp[i-1][k]+dp[i-1][k-v[i]]。
 *
 * @File:   T1218.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-02
 *
 **/
#include <iostream>

using namespace std;
int dp[1005] = {0, };

int main(void)
{
	int n, t;

	cin >> n >> t;

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		for (int k = t; k >= a; k--) {
			dp[k] += dp[k - a];
		}
	}
	cout << dp[t];
	return 0;
}
