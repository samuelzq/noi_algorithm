/**
 * 干草出售 计蒜客 - T1748
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T1748
 *
 * 0-1背包问题。
 * 背包换成马车，装干草。
 *
 * @File:   T1748.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-06
 *
 **/
#include <iostream>
#include <cmath>

using namespace std;

const int C = 50005;
const int H = 5005;
int dp[C];

int main(void)
{
	int c, h, w;

	cin >> c >> h;

	for (int i = 1; i <= h; i++) {
		cin >> w;
		for (int j = c; j >= w; j--)
			dp[j] = max(dp[j - w] + w, dp[j]);
	}
	cout << dp[c];
	return 0;
}
