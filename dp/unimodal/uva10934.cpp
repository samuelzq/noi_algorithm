/**
 * Dropping water balloons UVA - 10934
 * https://vjudge.net/problem/UVA-10934
 *
 * 假设dp[i][j]为i个气球仍j次可以测得的最高楼层。
 * 抛完一次后，还可以抛j-1次。此后会有两种情况：
 * 气球破了，则需要剩下i-1个气球；
 * 气球未破，则剩余i个气球。
 * 因此dp[i][j] = dp[i-1][j-1]+dp[i][j-1]+1。
 *
 * @File:   uva10934.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-13
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 65;
long long dp[N][N];

void max_drop(void)
{
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i < 64; i++)
		for(int j = 1; j < 64; j++)
			dp[i][j] = dp[i-1][j-1]+dp[i][j-1]+1;
}

int main()
{
	long long k, n;

	max_drop();
	while(scanf("%llu %llu", &k, &n) == 2 && k) {
		if (k > 63)
			k = 63;

		int i;
		for(i = 1; i < 64; i++) {
			if(dp[k][i] >= n)
				break;
		}
		if(i > 63)
			puts("More than 63 trials needed.");
		else
			printf("%d\n", i);
	}
	return 0;
}
