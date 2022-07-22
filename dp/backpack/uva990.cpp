/**
 * Diving for Gold UVA - 990
 * https://vjudge.net/problem/UVA-990
 *
 * 0-1背包求最佳方案。
 * 本题的变化是物品的重量需要转换。
 * 氧气瓶的使用时间是背包容量，每艘沉船的深度是物品重量（需要转换）。
 * 本题解不唯一，输出其中一组即可。
 *
 * @File:   uva990.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-15
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 33, W = 1010;
int cost[N], weight[N], weight2[N];
int c[W + 1];
int cnt, ret[N];
bool p[N][W + 1];   // 記錄放還是不放，false為不放，true為放。

void knapsack(int n, int w)
{
	memset(c, 0, sizeof(c));
	memset(p, false, sizeof(p));    // 初始化為false

	for (int i = 0; i < n; ++i) {
		for (int j = w; j >= weight[i]; --j) {
			if (c[j - weight[i]] + cost[i] > c[j]) {
				c[j] = c[j - weight[i]] + cost[i];
				p[i][j] = true; // 有放
			}
		}
	}

	cout << c[w] << '\n';

	// 往回逆推，求出背包內的所有物品。
	cnt = 0;
	for (int i = n-1, j = w; i >= 0; --i) {
		if (p[i][j]) { // 背包有該物品
			ret[cnt++] = i;
			j -= weight[i];
		}
	}
	cout << cnt << '\n';
	for (int i = cnt - 1; i >= 0; i--) {
		cout << weight2[ret[i]] << ' ' << cost[ret[i]] << '\n';
	}
	return;
}

int main(void)
{
	int t, w, k = 0;

	while (cin >> t >> w) {
		if (k)
			cout << '\n';
		k = 1;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> weight2[i] >> cost[i];
			weight[i] = 3 * w * weight2[i];
		}

		knapsack(n, t);
	}
	return 0;
}
