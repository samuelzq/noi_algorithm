#include <iostream>
#include <cmath>

using namespace std;

const int M = 10004;
const int N = 10004;
int dp[M];
int p[N], t[N];

int main(void)
{
	int m, n;

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> t[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = t[i]; j <= m; j++) {
			dp[j] = max(dp[j - t[i]] + p[i], dp[j]);
		}
	}
	cout << dp[m];
	return 0;
}
