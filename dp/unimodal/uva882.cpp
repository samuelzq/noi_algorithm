/**
 * The Mailbox Manufacturers Problem UVA - 882
 * https://vjudge.net/problem/UVA-882
 *
 * 高楼抛鸡蛋变形。
 * dp[i][s][e]记录i个邮箱，测试[s,e]区间内可承受的爆竹时，所需要的
 * 最小爆竹数量。假设k为区间[s,e]内一数值，如果取k个爆竹时箱子被损，
 * 则箱子个数减少到i-1，新的检测区间为[start,i-1]；如果箱子未受损，
 * 则箱子个数不变，新的检测区间为[i+1,e]。
 * 因此状态转移公式为：
 * dp[i][s][e]=min(dp[i][s][e], k + max(dp[i][k+1][e], dp[i-1][s][k-1]))。
 *
 * @File:   uva882.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-13
 *
 **/
#include <bits/stdc++.h>

using namespace std;

#define LL long long

LL dp[12][102][102];

LL dfs(int k, int start, int end)
{
	if (dp[k][start][end])
		return dp[k][start][end];
	if (start > end)
		return 0;

	LL ans = 0x7ffffffffffffff;
	for (int i = start; i <= end; i++)
		ans = min(ans,
			  i + max(dfs(k, i + 1, end), dfs(k - 1, start, i - 1)));
	return dp[k][start][end] = ans;
}

int main(void)
{
	for (int i = 1; i <= 99; i++)
		for (int j = i; j <= 100; j++)
			dp[1][i][j] = (i + j) * (j - i + 1) / 2;
	for (int i = 1; i <= 11; i++)
		dfs(i, 1, 100);

	int t;
	cin >> t;
	while (t--) {
		int k, m;
		cin >> k >> m;
		cout << dp[k][1][m] << '\n';
	}
	return 0;
}
