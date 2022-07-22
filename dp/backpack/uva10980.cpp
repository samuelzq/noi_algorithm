/**
 * Lowest Price in Town UVA - 10980
 * https://vjudge.net/problem/UVA-10980
 *
 * 完全背包问题。
 * 将打包销售的每一组商品视为放入背包的一类物品。每组中商品的数目
 * 为物品重量，总价为物品价值。这样转换成完全背包求最小值。本题中
 * 的一个变化是：为了省钱可以多买，因此需要向上取最小值。
 *
 * @File:   uva10980.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-22
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 205;
int dp[N] = {0, };

int main(void)
{
	int a, b, n, w, v, q;
	int i, j, k;
	char c;
	int cases = 0;

	while (scanf("%d.%d %d", &a, &b ,&n) == 3) {
		int m = a * 100 + b;

		// 初始化：假设以单品价格购买不同数目的商品
		for (i = 1; i < N; i++)
			dp[i] = i * m;

		// 将捆绑的物品一次装包
		for (i = 0; i < n; i++) {
			scanf("%d %d.%d", &w, &a, &b);
			v = a * 100 + b;
			for (j = w; j < N; j++)
				dp[j] = min(dp[j], dp[j - w] + v);
		}

		for (j = N - 2; j >= 0; j--)
			dp[j] = min(dp[j], dp[j + 1]);

		printf("Case %d:\n", ++cases);
		while(getchar() != '\n');
		string line;
		getline(cin, line);
		stringstream sin(line);
		while(sin >> q) {
			printf("Buy %d for $%d.%02d\n", q, dp[q]/100, dp[q]%100);
		}
	}
	return 0;
}
