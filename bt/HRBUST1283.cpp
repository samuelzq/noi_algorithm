/**
 * https://vjudge.net/problem/HRBUST-1283
 *
 * @File:   HRBUST1283.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;

char Q[9][9];
int ans;
int n;

bool isvalid(int r, int c)
{
	for (int i = c - 1; i >= 0; i--) {
		if (Q[r][i] == 'X')
			break;
		if (Q[r][i] == 'Q')
			return false;
	}
	// 检查列是否有皇后互相冲突
	for (int i = r - 1; i >= 0; i--) {
		if (Q[i][c] == 'X')
			break;
		if (Q[i][c] == 'Q')
			return false;
	}

	// 检查右上方是否有皇后互相冲突
	for (int i = r - 1, j = c + 1;
		i >= 0 && j < n; i--, j++) {
		if (Q[i][j] == 'X')
			break;
		if (Q[i][j] == 'Q')
			return false;
	}

	// 检查左上方是否有皇后互相冲突
	for (int i = r - 1, j = c - 1;
		i >= 0 && j >= 0; i--, j--) {
		if (Q[i][j] == 'X')
			break;
		if (Q[i][j] == 'Q')
			return false;
	}
	return true;
}

void dfs(int p, int tmp)
{
	int c, r;
	if (p == n*n) {
		return;
	}

	ans = max(ans, tmp);
	p++;
	r = p / n;
	c = p % n;

	dfs(p, tmp);
	if (Q[r][c] == '.' && isvalid(r, c)) {
		Q[r][c] = 'Q';
		dfs(p, tmp + 1);
		Q[r][c] = '.';
	}
}

int main(void)
{
	while (cin >> n && n) {
		ans = 0;
		for (int i = 0; i < n; i++)
			cin >> Q[i];
		dfs(0, 0);
		if (Q[0][0] == '.') {
			Q[0][0] = 'Q';
			dfs(0, 1);
			Q[0][0] = '.';
		}
		cout << ans << '\n';
	};

	return 0;
}
