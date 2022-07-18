/**
 * 购物 计蒜客 - T3017
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T3017
 *
 * 完全背包问题。
 * 背包负重是每个商店要买的商品的总价，物品是使用的前l个硬币。
 * 本题的变化是有多个背包和不同种类的物品。
 *
 * 取背包最大值，不进行存储空间压缩，可以一次递推出所有结果。但是TLE！！
 *
 * @File:   T3017.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-06
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int dp[2002][10004];
int v[2002];
int c[N], l[N], maxc, maxl;

int main(void)
{
	int n, m;

	scanf("%d%d", &n, &m);

	memset(dp, 0x3f3f3f3f, sizeof(dp));
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &c[i], &l[i]);
		maxc = max(maxc, c[i]);
		maxl = max(maxl, l[i]);
		
	}

	for (int i = 0; i < 2002; i++)
		dp[i][0] = 0;
	for (int i = 1; i <= maxl; i++) {
		for (int j = 1; j <= maxc; j++) {
			if (j >= v[i])
				dp[i][j] = min(dp[i - 1][j], dp[i][j - v[i]] + 1);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	for (int i = 0; i < m; i++) {
		if (dp[l[i]][c[i]] != 0x3f3f3f3f)
			printf("%d\n", dp[l[i]][c[i]]);
		else
			printf("%d\n", -1);
	}
	return 0;
}
