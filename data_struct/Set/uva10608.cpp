/**
 * Friends UVA - 10608
 * https://vjudge.net/problem/UVA-10608
 *
 * 并查集。
 * 合并的同时统计不同集合的大小。
 *
 * @File:   uva10608.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-15
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 500005;
int p[N];
int size[N];
int ans = 0;

int find(int x)
{
	if (x == p[x])
		return x;
	else
		return p[x] = find(p[x]);
}

void merge(int x, int y)
{
	int px, py;

	px = find(x);
	py = find(y);

	if (px == py)
		return;

	size[py] += size[px];
	size[px] = 0;
	p[px] = py;
	ans = max(ans, size[py]);
}

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		int n, m;

		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			p[i] = i;
			size[i] = 1;
		}

		ans = 1;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			merge(x, y);
		}
		cout << ans << '\n';
	}
	return 0;
}
