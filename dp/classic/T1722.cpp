#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e5+5;
int dp[N];
int a[N];

int main(void)
{
	int n, ans;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	dp[0] = a[0];
	ans = a[0];
	for (int i = 1; i < n; i++) {
		if (dp[i - 1] > 0)
			dp[i] = dp[i - 1] + a[i];
		else
			dp[i] = a[i];
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
