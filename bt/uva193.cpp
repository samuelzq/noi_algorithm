/**
 * https://vjudge.net/problem/UVA-193
 *
 * 这是一道组合型题目，遍历所有可能的组合，找出一种最长的。
 *
 * @File:   uva193.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-04-02
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 101;
int mp[N][N];
int p[N];
int out[N];
int ans;
int len;
int n;

// 检测当前节点是否可以放出组合
bool check(int x, int s)
{
	for (int i = 1; i < s; i++) {
		if (mp[x][p[i]]) // 与已经存在的节点连同
			return false;
	}
	return true;
}

void dfs(int d, int s)
{
	if (d == n + 1) {
		if (s > ans) {
			ans = s;
			for (int i = 1; i < s; i++)
				out[i] = p[i];
		}
		return;
	}

	if (check(d, s)) {
		p[s] = d;
		dfs(d + 1, s + 1);
	}
	dfs(d + 1, s);
}

int main(void)
{
	int m;

	cin >> m;
	while (m--) {
		int k;
		cin >> n >> k;
		memset(mp, 0, sizeof(mp));
		while (k--) {
			int x, y;
			cin >> x >> y;
			mp[x][y] = mp[y][x] = 1;
		}
		ans = 0;
		memset(p, 0, sizeof(p));
		dfs(1, 1);
		cout << ans - 1 << '\n';
		for (int i = 1; i < ans - 1; i++)
			cout << out[i] << ' ';
		cout << out[ans - 1] << '\n';
	}
	return 0;
}
