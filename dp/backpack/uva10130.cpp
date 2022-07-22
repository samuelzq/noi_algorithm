/**
 * SuperSale UVA - 10130
 * https://vjudge.net/problem/UVA-10130
 *
 * 0-1背包。最终结果是每个人最优结果之和。
 * 背包问题DP解法的一个特点是：容量为W的背包的最优解依赖于所有容量小于W的背包。
 * 因此在推断容积W的结果的同时也能够得到所有小于W的背包对应的结果。
 *
 * @File:   uva10130.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-18
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 1004;
int dp[50], mw[105], p[N], w[N];

int main(void)
{
	int t;

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i] >> w[i];

		int g, out, maxmw;
		cin >> g;
		maxmw = out = 0;
		memset(mw, 0, sizeof(mw));
		for (int i = 0; i < g; i++) {
			cin >> mw[i];
			maxmw = max(mw[i], maxmw);
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int j = maxmw; j >= w[i]; j--)
				dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
		}

		for (int i = 0; i < g; i++)
			out += dp[mw[i]];
		cout << out << '\n';
	}
	return 0;
}
