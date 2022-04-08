/**
 * https://vjudge.net/problem/UVA-639
 *
 * 一种更简洁的做法是从(0, 0)开始依次遍历每一个格子，选或不选。
 *
 * @File:   uva639.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 5;
char board[N][N];
char used[N][N];
int ans;
int n;

void dfs(int d, int sum)
{
	if (d >= n) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i< n; i++) {
		int j;

		if (used[d][i] || board[d][i] == 'X')
			continue;

		for (j = d - 1; j >= 0; j--) {
			if (board[j][i] == 'X') {
				j = -1;
				break;
			}
			if (used[j][i] == 1)
				break;
		}
		if (j >= 0)
			continue;

		for (j = i - 1; j >= 0; j--) {
			if (board[d][j] == 'X') {
				j = -1;
				break;
			}
			if (used[d][j] == 1)
				break;
		}
		if (j >= 0)
			continue;

		for (j = i + 1; j < n; j++) {
			if (board[d][j] == 'X') {
				j = N;
				break;
			}
			if (used[d][j] == 1)
				break;
		}
		if (j < n)
			continue;

		used[d][i] = 1;
		dfs(d, sum + 1);
		dfs(d + 1, sum + 1);
		used[d][i] = 0;
	}
	dfs(d + 1, sum);
}

int main(void)
{
	while (cin >> n && n) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];

		ans = 0;
		memset(used, 0, sizeof(used));
		dfs(0, 0);
		cout << ans << '\n';
	}
	return 0;
}
