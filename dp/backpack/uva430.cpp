/**
 * Swamp County Supervisors UVA - 430
 * https://vjudge.net/problem/UVA-430
 *
 * 0-1背包变形。
 * 依次计算出不包含某一种物品时组成某一重量的所有可能方案数。假设
 * 某一物品重量为w[i]，目标重量是v，接下来统计[v-w[i], v-1]区间内
 * 的方案数。
 * 
 * @File:   uva430.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-02
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int w[30], p[30];

int main(void)
{
	string str;

	while (getline(cin, str)) {
		stringstream ss;
		ss << str << ' ' << 0;
		int tmp, v, n = 0;

		ss >> v;

		// dp[i]：数值i的拼凑方案    
		vector<int> dp(v + 10, 0);

		n = 0;
		ss >> tmp;
		while (tmp) {
			w[n++] = tmp;
			ss >> tmp;
		}

		memset(p, 0, sizeof(p));
		for (int i = 0; i < n; i++) {
			dp[0] = 1;
			// 统计将第i类排之外的拼凑方案数
			for (int k = 0; k < n; k++) {
				if (k == i)
					continue;
				for (int j = v - 1; j >= w[k]; j--)
					dp[j] += dp[j - w[k]];
			}
			p[i] = 0;
			for (int j = max(v - w[i], 0); j < v; j++)
				p[i] += dp[j];
			dp.assign(v + 10, 0);
		}

		for (int i = 0; i < n - 1; i++)
			cout << p[i] << ' ';
		cout << p[n - 1] << '\n';
	}
	return 0;
}
