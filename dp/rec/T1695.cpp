// 到达每一个旅馆的方案数依赖于位于它前面A～B公里
// 的所有旅馆的到达方案数。到达第一家旅馆的方案总
// 是1。

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 40;
int d[N] = {0, 990, 1010, 1970, 2030, 2940, 3060,
            3930, 4060, 4970, 5030, 5990, 6010, 7000};
int dp[N];

int main(void)
{
	int a, b, n;

	cin >> a >> b >> n;

	for (int i = 0; i < n; i++)
		cin >> d[i + 14];

	n += 14;
	sort(d, d + n);

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int dt = d[i] - d[j];
			if (dt >= a && dt <= b)
				dp[i] += dp[j];
		}
	}
	cout << dp[n - 1];
	return 0;
}
