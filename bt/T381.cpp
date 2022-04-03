/**
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-381
 *
 * @File:   381.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 9;
int vc[N], vld[N+N], vrd[N+N];
int bq[N];
int board[N][N];
int ans = 0;

void dfs(int n, int r)
{
	if (r == n) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			sum += board[j][bq[j]];
		ans = max(ans, sum);
		return;
	}

	for (int c = 0; c < n; c++) {
		if (vc[c] || vld[c + r] || vrd[c - r + n])
			continue;
		bq[r] = c;
		vc[c] = 1;
		vld[c + r] = 1;
		vrd[c - r + n] = 1;
		dfs(n, r + 1);
		vc[c] = 0;
		vld[c + r] = 0;
		vrd[c - r + n] = 0;
	}
	return;
}

int main(void)
{
	int n;
	cin >> n;

	while (n--) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> board[i][j];
		ans = 0;
		dfs(8, 0);
		cout << ans << '\n';
	}
	return 0;
}
