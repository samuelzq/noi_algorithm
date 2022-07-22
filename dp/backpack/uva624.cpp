/**
 * CD UVA - 624
 * https://vjudge.net/problem/UVA-624
 *
 * 0-1背包，求放置的最佳方案(放了哪些物品)。
 * 本题cost和weight等值。
 * 解不唯一。
 *
 * @File:   uva624.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-15
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 30, W = 10050;
int cost[N], weight[N];
int c[W + 1];
int p[N][W + 1];    // 0為不放，1為放，2為放與不放都可以。

int cnt, output[N], ret[N];

void find_path(int n, int w, int k)
{
	if (n < 0) { // 找完了
		if (k < cnt)
			return;

		cnt = k;
		for (int i = 0; i < k; ++i)
			ret[k - i - 1] = output[i];
		return;
	}

	// 不放比較好：背包裡面沒有第n個物品
	if (p[n][w] == 0) {
		find_path(n-1, w, k);
	} else if (p[n][w] == 1) {
		// 放了比較好：背包裡面有第n個物品
		output[k] = n;
		find_path(n-1, w-weight[n], k+1);
	} else if (p[n][w] == 2) {
		// 可放可不放
		// 背包裡面有第n個物品
		output[k] = n;
		find_path(n-1, w-weight[n], k+1);

		// 背包裡面沒有第n個物品
		find_path(n-1, w, k);
	}
}

void knapsack(int n, int w)
{
	memset(c, 0, sizeof(c));
	memset(p, 0, sizeof(p));

	for (int i = 0; i < n; ++i) {
		for (int j = w; j >= weight[i]; --j) {
			// 不放比較好
			if (c[j - weight[i]] + cost[i] < c[j]) {
				p[i][j] = 0;
			} else if (c[j - weight[i]] + cost[i] > c[j]) {
				// 放了比較好
				c[j] = c[j - weight[i]] + cost[i];
				p[i][j] = 1;
			} else { // 可放可不放
				p[i][j] = 2;
			}
		}
	}

	// 往回逆推，求出背包內的所有物品。
	cnt = 0;
	find_path(n-1, c[w], 0);

	for (int i = 0; i < cnt; i++)
		cout << weight[ret[i]] << ' ';
	cout << "sum:" << c[w] << '\n';
}

int main(void)
{
	int n, t;

	while (cin >> n >> t) {
		for (int i = 0; i < t; i++) {
			cin >> cost[i];
			weight[i] = cost[i];
		}

		knapsack(t, n);
	}
	return 0;
}
