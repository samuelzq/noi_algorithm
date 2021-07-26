// 状态转移方程推导如下：
// 设l[i]，r[i]，u[i]分别为第 i 步向西、东、北的方案数，f[i]为总方案数。
// l[i] = l[i - 1]+u[i - 1]， r[i] = r[i-1] + u[i-1]，u[i] = l[i - 1] + r[i - 1] + u[i - 1]；
// f[i]=l[i] + r[i] + u[i]
//     =2 * l[i - 1] + 2 * r[i - 1] + 3 * u[i - 1]
//     =2 * f[i - 1] + u[i - 1]   (u[i-1]=l[i-2]+r[i-2]+u[i-2]=f[i-2])
//     =2 * f[i - 1] + f[i - 2]
#include <iostream>

using namespace std;
int dp[20] = {0, };

int main(void)
{
	int n, i, j;

	cin >> n;

	dp[0] = 0;
	dp[1] = 3;
	dp[2] = 7;

	for (i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] * 2 + dp[i - 2];
	}
	cout << dp[n];
	return 0;
}