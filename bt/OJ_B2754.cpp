// 题中有一个陷阱，深搜的时候是按列输出的，不是行输出.

#include <bits/stdc++.h>

using namespace std;

int Q[8][8];
int bq[92][8];
int ans = 0;

bool isvalid(int n, int r, int c)
{
	// 检查列是否有皇后互相冲突
	for (int i = 0; i < n; i++) {
		if (Q[i][c] == 1)
			return false;
	}

	// 检查右上方是否有皇后互相冲突
	for (int i = r - 1, j = c + 1;
		i >= 0 && j < n; i--, j++) {
		if (Q[i][j] == 1)
			return false;
	}

	// 检查左上方是否有皇后互相冲突
	for (int i = r - 1, j = c - 1;
		i >= 0 && j >= 0; i--, j--) {
		if (Q[i][j] == 1)
			return false;
	}
	return true;
}

void dfs(int n, int r)
{
	if (r == n) {
		if (ans > 0) {
			for (int i = 0; i < 8; i++) {
				if (bq[ans][i] == 0)
					bq[ans][i] = bq[ans-1][i];
			}
		}
		ans++;
		return;
	}

	for (int c = 0; c < n; c++) {
		if (!isvalid(n, r, c))
			continue;
		bq[ans][r] = c + 1;
		Q[r][c] = 1;
		dfs(n, r + 1);
		Q[r][c] = 0;
	}
}

int main(void)
{
	int n;
	dfs(8, 0);
	cin >> n;
	while (n--) {
		int i;
		cin >> i;
		for (int j = 0; j < 8; j++)
			cout << bq[i - 1][j];
		cout << '\n';
	}
	//cout << ans << '\n';
	return 0;
}
