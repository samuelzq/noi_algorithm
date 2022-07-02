/**
 * Bessie 的体重问题 计蒜客 - T1704
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T1704
 *
 * 经典0-1背包问题。
 *
 * @File:   T1704.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-06
 *
 **/
#include <iostream>
#include <cmath>

using namespace std;

const int H = 45005;
const int N = 5005;
int dp[H] = {0, };
int w[N];

int main(void)
{
	int h, n;

	cin >> h >> n;

	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		for (int j = h; j >= w[i]; j--)
			dp[j] = max(dp[j - w[i]] + w[i], dp[j]);
	}
	cout << dp[h];
	return 0;
}
