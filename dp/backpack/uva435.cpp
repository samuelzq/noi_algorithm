/**
 * Block Voting UVA - 435
 * https://vjudge.net/problem/UVA-435
 * 
 * 0-1背包解法。
 * 首先计算每一party被排除之外后，所有票数的拼凑方法。
 * 然后统计所有加上该党派票数后超过半数的投票方式。
 *
 * @File:   uva435.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-03
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int w[23], p[23], c[1005];

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		int n, sum;
		cin >> n;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> w[i];
			sum += w[i];
		}

		sum = (sum + 1) / 2;

		memset(p, 0, sizeof(p));
		for (int k = 1; k <= n; k++) {
			memset(c, 0, sizeof(c));
			c[0]  = 1;
			for (int i = 1; i <= n; i++) {
				if (i == k)
					continue;
				for (int j = sum; j >= w[i]; j--) {
					c[j] += c[j - w[i]];
				}
			}

			for (int i = max(sum - w[k], 0); i < sum; i++)
				p[k] += c[i];
		}
		for (int i = 1; i <= n; i++) {
			cout << "party " << i << " has power index " << p[i] << '\n';
		}
		cout << '\n';
	}
	return 0;
}
