/**
 * 纪念品 计蒜客 - T3229
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T3229
 * 
 * 本质上多重背包问题，只是背包的容量会增大。
 *
 * 实际上无需考虑手上有多少物品。每天的获利由与前一天的价格差决定，而手头有多少物
 * 品完全可以等价为手头的金币，然后我们只需要确定卖多少物品即可得到在这一天能获利
 * 多少，然后可能会考虑到某天买或者不买，实际上这也是不需要考虑的，因为如果我们计
 * 算出每天能获得的最大价值W，那么下一天手上的金币数量就是[0 , W]，因为我们会枚举
 * 金币数目，这也就能从手头所有可能的金币数目。
 *
 * 总的来说，是将手头的金币看做背包容量，物品当天的价值看做物品体积，和下一天的差
 * 价看做物品价值。
 *
 * @File:   T3229.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-06
 *
 **/
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int maxn = 2e5+10;

int a[105][105];
int d[maxn] = {0, };

int main(void)
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m, t;
	cin >> t >> n >> m;

	for (int i = 1; i <= t; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 1; i < t; i++) { //天数
		memset(d, 0, sizeof(d));
		for (int j = 1; j <= n; j++) //物品
			for (int k = a[i][j]; k <= m; k++) //本金
				d[k] = max(d[k], d[k-a[i][j]] + a[i+1][j]-a[i][j]);
		m+=d[m];
	}
	cout << m;
	return 0;
}
