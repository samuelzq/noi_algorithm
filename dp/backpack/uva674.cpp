/**
 * Coin Change UVA - 674
 * https://vjudge.net/problem/UVA-674
 *
 * 完全背包，零钱凑整。
 *
 * @File:   uva674.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-26
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int c[5] = {50, 25, 10, 5, 1};
long long dp[8000];

int main(void)
{
	int m;

	dp[0] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = c[i]; j <= 8000; j++)
			dp[j] += dp[j - c[i]];

	while (scanf("%d", &m) != EOF)
		printf("%lld\n", dp[m]);
	return 0;
}
