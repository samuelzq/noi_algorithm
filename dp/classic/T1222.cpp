// f[i][j]表示在剩余精灵球i，剩余体力j时抓到的最大精灵数量，
// v是需要的精灵球个数，w是消耗的体力量，那么
//    f[i][j] = max(f[i][j], f[i-v][j-w]+1)
// 抓当前的精灵时，需要考虑抓了上一个精灵时的体力值和精灵球值，
// 此时有两种方案，抓与不抓当前精灵，比较两种方案哪个更好。
// 所以f[i][j], f[i-v][j-w]+1里取一个最大的数。

#include <iostream>
#include <cstring>

using namespace std;

int v[105];
int w[105];
int dp[1005][505];

int main(void)
{
	int n, m, k;

	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		cin >> v[i] >> w[i];

		for (int j = n; j >= v[i]; j--) {
			for (int h = m - 1; h >= w[i]; h--) {
				if (dp[j][h] < dp[j-v[i]][h-w[i]] + 1)
					dp[j][h] = dp[j-v[i]][h-w[i]] + 1;
			}
		}
	}
	cout << dp[n][m - 1];
	int i;
	for (i = m - 1; i > 0; i--)
		if (dp[n][m-1] != dp[n][i-1])
			break;
	cout << ' ' << m - i;
	return 0;
}
