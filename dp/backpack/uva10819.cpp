/**
 * Trouble of 13-Dots UVA - 10819
 * https://vjudge.net/problem/UVA-10819
 *
 * 0-1背包。
 * 本题的难点是200元的折扣。当花费超过1800时可能会买入超过原价2000元的物品。
 * 当预算超过1800时，可以再加上200。但是需要注意如下的例子：
 * 1900 3
 * 2000 5
 * 1950 2
 * 101 1
 * 以上输入中，只能选1950+101而无法选择2000。如果直接使用0-1背包的递推公式，
 * 则所得结果是2000。因此原递推公式需要做出修改，dp[i][j]中不再是当前容量之内
 * 可以获得的最大值，而是当前容量下恰好可以装入的值。在本题中，j代表所购物品
 * 的总价值，在上例中dp数组中仅在j恰好是2000、1950、101之和的位置上有值，因为
 * 只可能花费这些钱数。其余位置可令其为0。这样最终结果是数组中找最值。不过需要
 * 注意当预算t在1800~1999之间时，t~2000之间的结果需要被忽略，因为这是由于增加200
 * 而引入的空洞。
 *
 * @File: uva10819.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-19
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int M = 12004;
int p[105], f[105];
int dp[M];

int main(void)
{
	int m, n;

	while (cin >> m >> n) {
		for (int i = 0; i < n; i++) {
			cin >> p[i] >> f[i];
		}
		memset(dp, 0, sizeof(dp));
		if (m > 1800)
			m += 200;
		for (int i = 0; i < n; i++) {
			for (int j = m; j >= p[i]; j--) {
				if (dp[j - p[i]] > 0 || j == p[i])
					dp[j] = max(dp[j], dp[j - p[i]] + f[i]);
			}
		}

		int t;
		if (m > 2200)
			t = 2000;
		else if (m > 2000)
			t = m - 200;
		else
			t = m;

		int ans = -1;

		for (int i = t; i >= 0; i--)
			ans = max(ans, dp[i]);

		for (int i = m; i > 2000; i--)
			ans = max(ans, dp[i]);

		cout << ans << '\n';
	}

	return 0;
}
