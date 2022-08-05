/**
 * Making Change UVA - 166 
 * https://vjudge.net/problem/UVA-166
 *
 * 本题求使用硬币最少的方案，不是支付最少的硬币。在某些情况下，支付加找零可能会
 * 使用到较少的硬币。比如以下输入：
 * 2 4 2 0 1 0 0.55
 * 如果不要找零，需要4枚硬币；而支付1.05，则交易过程只需要3枚硬币（支付1+0.05两枚
 * 硬币，找零0.5一枚硬币）。
 *
 * 两个背包问题的组合。支付需要的最少硬币，这是一个多重背包；+找零需要的最少硬币，
 * 这是一个完全背包。假设花费是i，则答案在[i, i+1.95]之间找最小值。
 *
 * @File:   uva166.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-02
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int change[205], dp[6505];
int price[7] = {0, 5, 10, 20, 50, 100, 200};

int main(void)
{
	int n[7], a, b;
	int sum = 0, total;

	memset(change, 0x3f3f3f3f, sizeof(change));
	change[0] = 0;
	for (int i = 1; i <= 6; i++) {
		for (int j = price[i]; j <= 200; j++) {
			if (change[j - price[i]] || !(j - price[i]))
				change[j] = min(change[j], change[j - price[i]] + 1);
		}
	}

	while (scanf("%d%d%d%d%d%d", &n[1], &n[2], &n[3], &n[4], &n[5], &n[6])) {
		sum = 0;
		for (int i = 1; i <= 6; i++)
			sum += n[i] * price[i];
		if (sum == 0)
			break;

		scanf("%d.%d", &a, &b);
		total = 100 * a + b;

		memset(dp, 0x3f3f3f3f, sizeof(dp));
		dp[0] = 0;
		for (int i = 1; i <= 6; i++) {
			for (int k = 0; k < n[i]; k++) {
				for (int j = sum; j >= price[i]; j--)
					dp[j] = min(dp[j], dp[j - price[i]] + 1);
			}
		}

		int ans = dp[total];

		for (int i = 5; i < 200; i += 5) {
			int tmp = total + i;
			if (tmp > sum)
				break;
			ans = min(ans, dp[tmp] + change[i]);
		}
		printf("%3d\n", ans);
	}
	return 0;
}
