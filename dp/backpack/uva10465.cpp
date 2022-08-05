/**
 * Homer Simpson UVA - 10465
 * https://vjudge.net/problem/UVA-10465
 *
 * 完全背包。
 * 变化是需要尽量装满背包。
 *
 * @File:   uva10465.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-25
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int dp[N];

int main(void)
{
	int a[2], t;

	while (cin >> a[0] >> a[1] >> t) {
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i * a[0] <= t; i++)
			dp[i * a[0]] = i;

		for (int i = 1; i * a[1] <= t; i++)
			dp[i * a[1]] = max(dp[i * a[1]], i);

		for (int i = 0; i < 2; i++) {
			for (int j = a[i]; j <= t; j++) {
				if (dp[j - a[i]])
					dp[j] = max(dp[j], dp[j - a[i]] + 1);
			}
		}

		int i = t;
		while (dp[i] == 0 && i > 0)
			i--;
		cout << dp[i];
		if (i < t)
			cout << ' ' << t - i;
		cout << '\n';
	}
	return 0;
}
