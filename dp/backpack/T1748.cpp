#include <iostream>
#include <cmath>

using namespace std;

const int C = 50005;
const int H = 5005;
int dp[C];

int main(void)
{
	int c, h, w;

	cin >> c >> h;

	for (int i = 1; i <= h; i++) {
		cin >> w;
		for (int j = c; j >= w; j--)
			dp[j] = max(dp[j - w] + w, dp[j]);
	}
	cout << dp[c];
	return 0;
}
