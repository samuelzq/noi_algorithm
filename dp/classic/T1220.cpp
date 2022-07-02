#include <iostream>

using namespace std;

int a[10005];
int dp[10005][102] = {0, };

int main(void)
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			if (dp[i - 1][(j + k - a[i] % k) % k] || dp[i - 1][(j + a[i]) % k])
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}
	if (dp[n][0])
		cout << "YES";
	else
		cout << "NO";
	return 0;
}