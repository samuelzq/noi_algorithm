/**
 * https://vjudge.net/problem/UVA-539
 *
 * 从每一个节点出发，计算最长路径。需要考虑如何标记重复访问的路径。
 *
 * @File:   uva539.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-04-20
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 27;
int graph[N][N];
int pass[N][N];
int n;
int node[N];
int ans;

bool check(int v)
{
	for (int i = 0; i < n; i++) {
		if (graph[v][i] && (!pass[v][i] || !pass[i][v])) {
			return false;
		}
	}
	return true;
}

void dfs(int v, int len)
{
	if (check(v)) {
		ans = max(ans, len);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!graph[v][i] || pass[v][i] || pass[i][v])
			continue;
		pass[v][i] = pass[i][v] = 1;
		dfs(i, len + 1);
		pass[v][i] = pass[i][v] = 0;
	}
}

int main(void)
{
	int m;

	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == 0 || m == 0)
			break;
		memset(pass, 0, sizeof(pass));
		memset(graph, 0, sizeof(graph));
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			graph[x][y] = graph[y][x] = 1;
		}

		ans = 0;
		for (int i = 0; i < n; i++) {
			node[i] = 1;
			dfs(i, 0);
			node[i] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
