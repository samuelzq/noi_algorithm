// 用快速幂算出n个人的所有方案数, 为2^n,
// 再用0-1背包的思想求出所有能力值小于k的方案数
// 二者之差就是最终答案

#include <iostream>
#include <cmath>

using namespace std;

const int mod = 10007;
int dp[105][10105] = {0, };
int a[105];

int q(int base, int p)
{
	int r = 1;

	for (int i = 1; i <= p; i++)
		r = (base * r) % mod;

	return r;
}

int main(void)
{
	int n, k, p, ans;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for (int i = 0; i <= k - 1; i++)
		dp[0][i] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			if (j >= a[i])
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - a[i]]) % mod;
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << (q(2, n) - dp[n][k - 1] + mod) % mod;
	return 0;
}
