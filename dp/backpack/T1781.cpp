#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX = 0x3f3f3f3f;
const int M = 100005;
int dp[M];

int main(void)
{
	int n, m, v;

	memset(dp, MAX, sizeof(dp));

	dp[0] = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> v;
		for (int j = 1; j <= m; j++) {
			if (j >= v)
				dp[j] = min(dp[j - v] + 1, dp[j]);
		}
	}
	if (dp[m] != MAX)
		cout << dp[m];
	else
		cout << -1;
	return 0;
}
