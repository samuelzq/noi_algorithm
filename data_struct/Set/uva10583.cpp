/**
 * Ubiquitous Religions UVA - 10583
 * https://vjudge.net/problem/UVA-10583
 *
 * 并查集基础题。
 * 合并相同的集合，输出最后集合的数目。
 *
 * @File:   uva10583.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-15
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 50005;
int p[N];
int group = N;

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
	group--;
	p[px] = py;
}

int main(void)
{
	int n, m, k;

	k = 1;
	while (cin >> n >> m && n) {
		for (int i = 1; i <= n; i++)
			p[i] = i;
		group = n;

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;

			merge(x, y);
		}
		cout << "Case " << k++ << ": " << group << '\n';
	}
	return 0;
}
