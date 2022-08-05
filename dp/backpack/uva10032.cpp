/**
 * Tug of War UVA - 10032
 * https://vjudge.net/problem/UVA-10032
 *
 * 0-1背包。
 * dp[i][j]表示i个人是否可以组成重量j。如果i-1个人便可以组成j，那么i个人自然
 * 也能组成j；如果i-1个人能组成j-p[i]，那么加上第i个人，总重便是j。因此转移方程为：
 * dp[i][j] = dp[i][j-1] | dp[i - 1][j - p[i]]。
 *
 * 由于总人数不会超过50人，因此可以利用bitmap对数组进行压缩。
 * dp[i]表示可以组成总重量i的可能人数，每一bit对应一种可能，比如bit1为1，表示
 * 1个人就可以组成i这个重量。
 *
 * 最后在所有可以由接近半数人数凑成的方案中，找最接近一半总和的结果。
 *
 * @File:   uva10032.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-27
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int p[N];
long long dp[550 * N];

int main(void)
{
	int t;

	cin >> t;
	for (int l = 0; l < t; l++) {
		int n, total;
		cin >> n;
		total = 0;
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			total += p[i];
		}
		memset(dp, 0, sizeof(dp));

		int n1, m1;
		n1 = n / 2;
		m1 = (total + 1) / 2;
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = total; j >= p[i]; j--)
				dp[j] |= dp[j - p[i]] << 1;
		int maxp, minp;
		maxp = 5000;
		minp = -5000;

		for (int i = total; i > 0; i--) {
			if (!dp[i])
				continue;
			for (int j = 0; j <= (n + 1) / 2; j++) {
				if ((dp[i] & 1ll << j ) && abs(n - 2 * j) <= 1) {
					if (abs(total - 2 * i) < maxp - minp) {
						maxp = max(total - i, i);
						minp = total - maxp;
					}
				}
			}
		}
		if (l > 0)
			cout << '\n';
		cout << minp << ' ' << maxp << '\n';
	}
	return 0;
}
