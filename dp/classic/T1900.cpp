#include <bits/stdc++.h>

using namespace std;

long long dp[11];

int main(void)
{
	int r, n, p;

	cin >> n >> r;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= r; j++)
			dp[j] = j * dp[j] + dp[j - 1];
	}
	p = 1;
	for (int i = 1; i <= r; i++)
		p *= i;
	cout << dp[r] * p;
	return 0;
}
