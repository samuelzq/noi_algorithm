/**
 * Let Me Count The Ways UVA - 357
 * https://vjudge.net/problem/UVA-357
 *
 * 完全背包、零钱凑整。
 * 先将所有结果推导出来，然后根据输入依次输出结果。
 *
 * @File:   uva357.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-26
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int c[5] = {1, 5, 10, 25, 50};
long long dp[30003];

void change(int m)
{
	dp[0] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = c[i]; j <= m; j++) {
			dp[j] = dp[j] + dp[j - c[i]];
		}
}

int main(void)
{
	int t;
	change(30000);
	while (scanf("%d", &t) != EOF) {
		if (dp[t] > 1)
			printf("There are %lld ways to produce %d cents change.\n", dp[t], t);
		else
			printf("There is only %lld way to produce %d cents change.\n", dp[t], t);
	}
	return 0;
}
