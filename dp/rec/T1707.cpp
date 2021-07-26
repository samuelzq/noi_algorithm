#include <iostream>
#include <algorithm>

using namespace std;

int dp[18][18] = {0, };

int main(void)
{
	int a, b, n, x, y;

	cin >> a >> b;

	fill(&dp[0][0], &dp[0][0]+sizeof(dp)/sizeof(int), 0);

	dp[1][1] = 1;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		dp[y][x] = -1;
	}

	for (int i = 1; i <= b; i++)
		for (int j = 1; j <= a; j++) {
			if (dp[i][j] == -1)
				dp[i][j] = 0;
			else
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
		}
	cout << dp[b][a];
}