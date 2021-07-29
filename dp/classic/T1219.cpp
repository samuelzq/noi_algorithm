#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int a[104];
int dp[104][104];

int main(void)
{
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset(dp, -0x3f3f3f3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][(j + k - a[i] % k) % k] + a[i]);
		}
	}
	cout << dp[n][0];
	return 0;
}