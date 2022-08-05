/**
 * A-Sequence UVA - 10930
 * https://vjudge.net/problem/UVA-10930
 *
 * 0-1背包，求某一个值是否能由其前面的数值凑成。
 * dp[i]表示i是否可以由其前面的几个数值凑成。
 *
 * @File:   uva10930.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-29
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int pre_sum[40];
int dp[3005];
int p[40];

int main(void)
{
	int d, k = 1;
	while (cin >> d) {

		int ans = 0;
		memset(dp, 0, sizeof(dp));

		cout << "Case #" << k++ << ":";
		for (int i = 1; i <= d; i++) {
			int tmp;
			cin >> tmp;
			// 首先检测数组的大小顺序是否满足要求
			for (int j = 1; j < i; j++) {
				if (tmp <= p[j])
					ans = 1;
			}
			p[i] = tmp;
			cout << " " << p[i];
		}

		if (ans == 0) {
			// 检测每一个数值是否可由其前面的数值拼凑成
			dp[0] = 0;
			for (int i = 1; i <= d; i++) {
				for (int k = p[d]; k >= p[i]; k--) {
					if ((k - p[i]) && !dp[k - p[i]])
						continue;
					dp[k] = max(dp[k], dp[k - p[i]] + 1);
				}
			}
			
			for (int i = 1; i <= d; i++) {
				if (dp[p[i]] > 1) {
					ans = 1;
					break;
				}
			}
		}
		cout << "\n";
		if (ans > 0)
			cout << "This is not an A-sequence.\n";
		else
			cout << "This is an A-sequence.\n";
	}
	return 0;
}
