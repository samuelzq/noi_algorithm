#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
int a[N][N], dp[N][N];

int main(void)
{
	int n, m, ans;

	cin >> n >> m;

	memset(dp, 0x3, sizeof(dp));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int j = 0; j < m; j++)
		dp[0][j] = a[j][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int l = (j == 0) ? m - 1 : j - 1;
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][l]) + a[j][i];
		}
	}
	ans = dp[n - 1][0];

	for (int i = 1; i < m; i++)
		ans = min(ans, dp[n - 1][i]);
	cout << ans;
	return 0;
}
