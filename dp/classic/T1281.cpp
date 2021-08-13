#include <iostream>

using namespace std;

long long dp[101];
const int mod = 1e9+7;
#if 1
int fp(int n)
{
	int r = 1;
	if (n < 1)
		return 1;

	for (int i = 1; i <= n; i++)
		r = (r * 2) % mod;
	return r;
}

int main(void)
{
	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
		dp[i] = ((dp[i - 1] + dp[i - 2]) % mod + fp(i - 2)) % mod;
	cout << dp[n];

	return 0;
}
#else
int f[102];
int main(void)
{
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 3;
	dp[4] = 8;
	f[2] = 1;
	f[3] = 1;
	f[4] = 2;
	for (int i = 5; i <= n; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % mod;
		dp[i] = (dp[i - 1] * 2 + f[i]) % mod;
	}
	cout << dp[n];
	return 0;
}
#endif
