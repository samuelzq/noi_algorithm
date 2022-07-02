/**
 * 魔法宝石 计蒜客 - T1702
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T1702
 *
 * 0-1背包问题。
 *
 * @File:   T1702.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-06
 *
 **/
#include <iostream>
#include <cmath>

using namespace std;

const int M = 10005;
const int N = 3005;

#if 0
int w[N], v[N], dp[N][M] = {0, };

int main(void)
{
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	dp[1][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (w[i] <= j) {
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][m];
	return 0;
}
#else
int w[N], v[N], dp[M] = {0, };

int main(void)
{
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= w[i]; j--) {
			dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
		}
	}
	cout << dp[m];
	return 0;
}

#endif
