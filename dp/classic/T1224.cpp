#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int dp[102];
int m[102], p[102];

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		int n, k, l;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> m[i];
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			dp[i] = p[i];
		}
		for (int i = 2; i <= n; i++) {
			for (int j = i - 1; j >= 1; j--) {
				if (m[i] - m[j] > k) {
					dp[i] = max(dp[i - 1], dp[j] + p[i]);
					break;
				} else {
					dp[i] = max(dp[i], dp[j]);
				}
			}
		}
		cout << dp[n] << '\n';
	}
}
