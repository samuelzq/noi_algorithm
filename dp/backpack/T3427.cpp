#include <iostream>
#include <cmath>

using namespace std;

int dp[1005][1005];
int s[1005], m[1005], h[1005];

int main(void)
{
	int n, b, c;

	cin >> n >> b >> c;

	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> m[i] >> h[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = b; j >= s[i]; j--) {
			for (int k = c; k >= m[i]; k--) {
				dp[j][k] = max(dp[j][k], dp[j - s[i]][k - m[i]] + h[i]);
			}
		}
	}

	cout << dp[b][c];
	return 0;
}
