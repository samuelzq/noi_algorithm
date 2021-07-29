#include <iostream>
#include <cmath>

using namespace std;

const int H = 45005;
const int N = 5005;
int dp[H] = {0, };
int w[N];

int main(void)
{
	int h, n;

	cin >> h >> n;

	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		for (int j = h; j >= w[i]; j--)
			dp[j] = max(dp[j - w[i]] + w[i], dp[j]);
	}
	cout << dp[h];
	return 0;
}
