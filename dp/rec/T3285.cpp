#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int minx = -0x3f3f3f3f;
const int N = 1005;
int mp[N][N];
int n, m;

#if 0
// 由于数据量很大，使用递归算法会超时
int ap[N][N];
int f(int i, int j)
{
	int left, up, down;

	left = up = down = minx;

	if (i == 1 && j == 1)
		return mp[i][j];

	if (i == 1)
		up = minx;
	else {
		if (ap[i - 1][j] == 0) {
			ap[i - 1][j] = 1;
			up = f(i - 1, j);
			ap[i - 1][j] = 0;
		}
	}


	if (j == 1)
		left = minx;
	else {
		if (ap[i][j - 1] == 0) {
			ap[i][j - 1] = 1;
			left = f(i, j - 1);
			ap[i][j - 1] = 0;
		}
	}

	if (i == n)
		down = minx;
	else {
		if (ap[i + 1][j] == 0) {
			ap[i + 1][j] = 1;
			down = f(i + 1, j);
			ap[i + 1][j] = 0;
		}
	}

	return max(up, max(left, down)) + mp[i][j];
}

int main(void)
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
			memo[i][j] = minx;
		}

	cout << f(n, m);
	return 0;
}
#else

// 使用动态规划
long long dp[N][N][3];
enum {
	UP = 0, LEFT, DOWN
};

int main(void)
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <=m; j++)
			cin >> mp[i][j];

	memset(dp, -0x3f, sizeof(dp));
	dp[1][1][UP] = dp[1][1][DOWN] = dp[1][1][LEFT] = mp[1][1];

	for (int i = 1; i <= m; i++) { // 由于横向只有一个方向可以选择，因此先枚举列
		// 再从上往下、从下往上更新dp数组
		for (int j = 1; j <= n; j++) {
			dp[i][j][LEFT] = max(dp[i][j][LEFT],
					     max(dp[i - 1][j][UP],
						 max(dp[i - 1][j][DOWN],
						     dp[i - 1][j][LEFT])) + mp[j][i]);
			dp[i][j][UP] = max(dp[i][j][UP],
					   max(dp[i][j - 1][LEFT],
					       dp[i][j - 1][UP]) + mp[j][i]);
		}
		for (int j = n; j >= 1; j--)
			dp[i][j][DOWN] = max(dp[i][j][DOWN],
					     max(dp[i][j + 1][LEFT],
						 dp[i][j + 1][DOWN]) + mp[j][i]);
	}
	cout << max(dp[m][n][LEFT], dp[m][n][UP]);
	return 0;
}
#endif
