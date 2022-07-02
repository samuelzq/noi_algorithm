/**
 * 献出心脏 计蒜客 - T3427
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T3427
 *
 * 多重0-1背包。
 *
 * @File:   T3427.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-06
 *
 **/
#include <iostream>
#include <cmath>

using namespace std;

int dp[1005][1005];
int s[1005], m[1005], h[1005];

int main(void)
{
	int n, b, c;

	cin >> n >> b >> c;

	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> m[i] >> h[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = b; j >= s[i]; j--) {
			for (int k = c; k >= m[i]; k--) {
				dp[j][k] = max(dp[j][k], dp[j - s[i]][k - m[i]] + h[i]);
			}
		}
	}

	cout << dp[b][c];
	return 0;
}
