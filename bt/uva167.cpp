/**
 * https://vjudge.net/problem/UVA-167
 *
 * 典型的8皇后问题。
 *
 * @File:   uva167.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-06
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 8;
int board[9][9];
int v[N], h[N], xy[2 * N], yx[2 * N];
int ans;

void dfs(int d, int sum)
{
	if (d >= 8) {
		if (sum > ans)
			ans = sum;
		return;
	}

	for (int i = 0; i < N; i++) {
		int x, y;
		x = d;
		y = i;
		if (h[y] || xy[x + y] || yx[N + x - y])
			continue;
		v[x] = 1;
		h[y] = 1;
		xy[x + y] = 1;
		yx[N + x - y] = 1;
		dfs(d + 1, sum + board[x][y]);
		v[x] = 0;
		h[y] = 0;
		xy[x + y] = 0;
		yx[N + x - y] = 0;
	}
}

int main(void)
{
	int k;
	scanf("%d", &k);
	while (k--) {
		for (int i = 0; i < N; i++)
			for (int j  = 0; j < N; j++)
				scanf("%d", &board[i][j]);
		ans = 0;
		dfs(0, 0);
		printf("%5d\n", ans);
	}
	return 0;
}
