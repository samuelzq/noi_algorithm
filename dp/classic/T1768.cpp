#include <iostream>
#include <cmath>

using namespace std;

const int N = 50004;
const int maxn = 0x3f3f3f3f;
int w[N], v[N];
int dp[N];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		w[i] = i;
		cin >> v[i];
		dp[i] = maxn;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = w[i]; j <= v[n]; j++) {
			dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[n];
	return 0;
}

