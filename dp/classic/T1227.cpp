#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 1e5+2;
int dp[N], a[N];

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		int n, ans;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = a[0];
		dp[1] = max(a[0], a[1]);
		
		for (int i = 2; i < n; i++) {
			dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
		}
		cout << dp[n - 1] << '\n';
	}
	return 0;
}
