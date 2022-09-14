/**
 * Paths through the Hourglass UVA - 10564
 * https://vjudge.net/problem/UVA-10564
 *
 * dp[i][j][s]记录遍历到第i行第j个格子时，累加和为s的方案数。
 * 由于需要输出路径，因此从下至上统计dp[i][j][s]。
 * 需要注意上下两个三角形，左右移动时j值的变化方式是不一样的。
 *
 * @File:   uva10564.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-08
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 21;
const int S = 500;
#define LL long long

LL dp[2 * N - 1][N][S];
LL mp[2 * N - 1][N];

int main(void)
{
	int n, s;

	while (cin >> n >> s && s + n) {
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n - i; j++)
				cin >> mp[i][j];
		for (int i = n; i < 2 * n - 1; i++)
			for (int j = 0; j < i - n + 2; j ++)
				cin >> mp[i][j];

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
			dp[2 * n - 2][i][mp[2 * n - 2][i]] = 1;

		for (int i = 2 * n - 3; i >= n - 1; i--) {
			for (int j = 0; j < i - n + 2; j++)
				for (int k = mp[i][j]; k <= s; k++) {
					int tmp = k - mp[i][j];
					dp[i][j][k] += dp[i + 1][j][tmp];
					dp[i][j][k] += dp[i + 1][j + 1][tmp];
				}
		}

		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < n - i; j++)
				for (int k = mp[i][j]; k <= s; k++) {
					int tmp = k - mp[i][j];
					if (j == 0) {
						dp[i][j][k] = dp[i + 1][j][tmp];
					} else {
						dp[i][j][k] += dp[i + 1][j][tmp];
						dp[i][j][k] += dp[i + 1][j - 1][tmp];
					}
				}
		}

		int st = -1;
		LL ans = 0;
		for (int i = 0; i < n; i++)
			if (dp[0][i][s]) {
				ans += dp[0][i][s];
				if (st < 0)
					st = i;
			}
		cout << ans << '\n';
		if (!ans) {
			cout << '\n';
			continue;
		}

		int tmp = s;
		cout << st << ' ';
		for (int i = 1; i < n - 1; i++) {
			int r, l;

			tmp -= mp[i - 1][st];
			if (st == 0) {
				cout << 'R';
				continue;
			}
			l = dp[i][st - 1][tmp];
			r = dp[i][st][tmp];

			if (l == 0) {
				cout << 'R';
			} else {
				st--;
				cout << 'L';
			}
		}

		if (st > 0)
			cout << 'L';
		else
			cout << 'R';
		tmp -= mp[n - 2][st];
		st = 0;
		for (int i = n; i < 2 * n - 1; i++) {
			int r, l;
			tmp -= mp[i - 1][st];
			r = dp[i][st + 1][tmp];
			l = dp[i][st][tmp];

			if (l == 0) {
				st++;
				cout << 'R';
			} else {
				cout << 'L';
			}
		}
		cout << '\n';
	}
	return 0;
}
