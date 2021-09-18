// 题目描述
// 给出一张 n 个点 m 条边的无向图，每个点的初始状态都为 0。
// 你可以操作任意一条边，操作结束后这条边的两个端点的状态都会改变，
// 由 0 变成 1 或由 1 变成 0。
//
// 你需要求出最少的操作次数，使得在所有操作完成之后所有 n 个点的状态都是 1。
//
// 输入格式
// 第一行两个整数 n, m。
//
// 之后 m 行，每行两个整数 a, b，表示在点 a, b 之间有一条边。
//
// 输出格式
// 一行一个整数，表示最少需要的操作次数。

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int n, m, ans = 0x7fffffff;
map<ll, int> f;
ll a[40];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		a[i] = (1ll << i);

	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		// 标记互通的结点
		a[u] |= (1ll << v);
		a[v] |= (1ll << u);
	}

	for (int i = 0; i < (1 << (n / 2)); ++i) {
		ll t = 0;
		int cnt = 0;
		for (int j = 0; j < n / 2; ++j) {
			if ((i >> j) & 1) {
				t ^= a[j];
				++cnt;
			}
		}
		if (!f.count(t))
			f[t] = cnt;
		else
			f[t] = min(f[t], cnt);
	}

	for (int i = 0; i < (1 << (n - n / 2)); ++i) {
		ll t = 0;
		int cnt = 0;
		for (int j = 0; j < (n - n / 2); ++j) {
			if ((i >> j) & 1) {
				t ^= a[n / 2 + j];
				++cnt;
			}
		}
		if (f.count(((1ll << n) - 1) ^ t))
			ans = min(ans, cnt + f[((1ll << n) - 1) ^ t]);
	}

	cout << ans;
	return 0;
}
