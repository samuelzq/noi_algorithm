/**
 * Circuit Nets UVA - 10505
 * https://vjudge.net/problem/UVA-10505
 *
 * 利用并查集解二分图。
 *
 * @File:   uva10505.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-08
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 202;
int p[2 * N];
bool r[2 * N];
int tot[2 * N];

void intialize()
{
	for (int i = 1; i < 2 * N; i++) {
		p[i] = i;
		r[i] = false;
		tot[i] = 0;
	}
}
int find(int x)
{
	if (x == p[x])
		return x;
	int px = find(p[x]);
	p[x] = px;
	r[x] = r[px];
	return px;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		intialize();
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int m;
			cin >> m;
			while (m--) {
				int x;
				cin >> x;
				if (x > n)
					continue;
				int pi, px, ei, ex;
				pi = find(i);
				px = find(x);
				ei = find(i + n);
				ex = find(x + n);
				if (pi == px) {
					r[pi] = r[px] = true;
					r[ei] = r[ex] = true;
				} else {
					(ei > px) ? p[ei] = px : p[px] = ei;
					(ex > pi) ? p[ex] = pi : p[pi] = ex;
				}
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int px, py;
			px = find(i);
			py = find(px + n);
			tot[px] += (r[px] == 0 && r[py] == 0);
		}
		for (int i = 1; i <= n; i++) {
			if (p[i] == i) {
				int px = find(i+n);
				ans += max(tot[i], tot[px]);
				p[px] = i;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}