/**
 * 购物 计蒜客 - T3017
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T3017
 *
 * 完全背包问题。
 * 背包负重是每个商店要买的商品的总价，物品是使用的前l个硬币。
 * 本题的变化是有多个背包和不同种类的物品。
 *
 * @File:   T3017.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-06
 *
 **/
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int dp[10004];
int v[2002];

int main(void)
{
	int n, m;

	scanf("%d%d", &n, &m);
//	cin >> n >> m;

	memset(dp, 0x3f3f3f3f, sizeof(dp));
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);//cin >> v[i];

	while (m--) {
		int c, l;

		scanf("%d%d", &c, &l);//cin >> c >> l;
		memset(dp, 0x3f3f3f3f, c+1);
		dp[0] = 0;
		for (int i = 1; i <= l; i++) {
			for (int j = v[i]; j <= c; j++) {
				dp[j] = min(dp[j], dp[j - v[i]] + 1);
			}
		}
		if (dp[c] != 0x3f3f3f3f)
			printf("%d\n", dp[c]);//cout << dp[c] << '\n';
		else
			printf("%d\n", -1);//cout << -1 << '\n';
	}
	return 0;
}
