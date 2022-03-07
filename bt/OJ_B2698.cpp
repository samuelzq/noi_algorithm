/**
 * http://bailian.openjudge.cn/practice/2698?lang=en_US
 * https://vjudge.net/problem/OpenJ_Bailian-2698
 *
 * 题中有一个陷阱，深搜的时候是按列输出的，不是行输出
 *
 * @File:   OJ_B2698.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int Q[8][8];
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
		ans++;
		cout << "No. " << ans << '\n';
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 7; j++) {
				cout << Q[j][i] << ' ';
			}
			cout << Q[7][i] << '\n';

		}
		return;
	}

	for (int c = 0; c < n; c++) {
		if (!isvalid(n, r, c))
			continue;
		Q[r][c] = 1;
		dfs(n, r + 1);
		Q[r][c] = 0;
	}
}

int main(void)
{
	dfs(8, 0);
	//cout << ans << '\n';
	return 0;
}
