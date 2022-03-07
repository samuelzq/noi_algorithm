#include <bits/stdc++.h>

using namespace std;

int Q[9][9];
int ans;

bool isvalid(int n, int r, int c)
{
	// 检查列是否有皇后互相冲突
	for (int i = 0; i < n; i++) {
		if (Q[i][c] == 'Q')
			return false;
	}

	// 检查右上方是否有皇后互相冲突
	for (int i = r - 1, j = c + 1;
		i >= 0 && j < n; i--, j++) {
		if (Q[i][j] == 'Q')
			return false;
	}

	// 检查左上方是否有皇后互相冲突
	for (int i = r - 1, j = c - 1;
		i >= 0 && j >= 0; i--, j--) {
		if (Q[i][j] == 'Q')
			return false;
	}
	return true;
}

void dfs(int n, int r)
{
	if (r == n) {
		ans++;
		return;
	}

	for (int c = 0; c < n; c++) {
		if (!isvalid(n, r, c))
			continue;
		Q[r][c] = 'Q';
		dfs(n, r + 1);
		Q[r][c] = '.';
	}
}

int main(void)
{
	int n;
	cin >> n;
	dfs(n, 0);
	cout << ans;
	return 0;
}
