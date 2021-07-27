#include <iostream>
#include <cstring>

using namespace std;

int v[105];
int w[105];
int dp[1005][505];
//int mx = 0x7f7f7f7f;
int main(void)
{
	int n, m, k;

	cin >> n >> m >> k;
	//memset(dp, mx, sizeof(dp));
	for (int i = 1; i <= k; i++)
		cin >> v[i] >> w[i];

	for (int i = 1; i <= k; i++) {
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