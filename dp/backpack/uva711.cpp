/**
 * Dividing up UVA - 711
 * https://vjudge.net/problem/UVA-711
 *
 * 多重背包凑整问题。 数据量比较大，需要考虑优化算法。
 * dp[i]表示i是否能凑成。如果dp[i]可以凑成，则dp[i+j]也可以凑成，j表示
 * 下一枚硬币面值。每次选一种面值的硬币，将其可以拼凑成的面值全部标识出来。
 * 此时需要一个额外的标识cnt[i],记录拼凑i时所使用某一面值的硬币的数目。
 *
 * @File:   uva711.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-01
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 80005;
bool dp[N];
int cnt[N];

int main(void)
{
	int n[7], t = 0;

	while (cin >> n[1] >> n[2] >> n[3] >> n[4] >> n[5] >> n[6]) {
		if (n[6] == 0 && n[1] == 0 && n[2] == 0 && n[3] == 0 &&
			n[4] == 0 && n[5] == 0)
			break;
		t++;
		cout << "Collection #" << t << ":\n";

		int sum, half;
		sum = 0;
		for (int i = 1; i <= 6; i++)
			sum += n[i] * i;
		half = (sum + 1) / 2;
		//cout << sum << ' ' << half << '\n';

		bool ans = false;
		if (sum & 1)
			ans = false;
		else {
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			for (int i = 1; i <= 6; i++) {
				// 统计每一种面值的使用的情况
				memset(cnt, 0, sizeof(cnt));
				for (int j = 0; j <= half; j++) {
					if (cnt[j] == n[i]) // 该面值使用完毕，需要遍历下一面值
						break;
					if (dp[j] && !dp[j + i] && cnt[j] < n[i]) {
						dp[j + i] = 1;
						cnt[j + i] = cnt[j] + 1;
					}
				}
			}

			if (dp[half])
				ans = true;
			else
				ans = false;
		}
		if (ans)
			cout << "Can be divided.\n\n";
		else
			cout << "Can't be divided.\n\n";
	}
	return 0;
}
