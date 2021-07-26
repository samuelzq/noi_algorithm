#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int mod = 10007;
int dp[2000] = {0, };

int main(void)
{
	int a, b, c, d;

	cin >> a >> b;
	c = sqrt(a * a + b * b);
	if (a > b)
		d = sqrt(a * a - b * b);
	else
		d = sqrt(b * b - a * a);
	dp[1] = 1;
	dp[2] = 2;
	if (c * c == a * a + b * b) {
		for (int i = 3; i <= c; i++)
			dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
		cout << dp[c];
	} else {
		for (int i = 3; i <= d; i++)
			dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
		cout << dp[d];
	}
	return 0;
}