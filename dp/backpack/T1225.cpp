#include <iostream>
#include <cmath>

using namespace std;

const int N = 1105;
int v[4] = {10, 20, 50, 100};
int dp[N] = {0, };

int main(void)
{
	int n;

	cin >> n;

	if (n % 10) {
		cout << 0;
		return 0;
	}

	dp[100] = 1;

	n += 100;
	for (int j = 0; j < 4; j++) {
		for (int i = 100; i <= n; i += 10) {
			dp[i] = dp[i - v[j]] + dp[i];
		}
	}
	cout << dp[n];
	return 0;
}
