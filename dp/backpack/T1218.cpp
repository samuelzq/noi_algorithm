#include <iostream>

using namespace std;
int dp[1005] = {0, };

int main(void)
{
	int n, t;

	cin >> n >> t;

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		for (int k = t; k >= a; k--) {
			dp[k] += dp[k - a];
		}
	}
	cout << dp[t];
	return 0;
}
