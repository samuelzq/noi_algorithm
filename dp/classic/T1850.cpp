#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 203;
int dp[N][N]; // dp[i][j]表示前j个物品中选了i个物品的最小值
struct BOOK{
	int h, w;
} book[N];

bool cmp(struct BOOK b1, struct BOOK b2)
{
	return b1.h < b2.h;
}

int main(void)
{
	int n, m, ans;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> book[i].h >> book[i].w;
	sort(book + 1, book + n + 1, cmp);
	memset(dp, 0x3f, sizeof(dp));

	dp[0][0] = 0;
	// 从前i个里选1个，所求值为0
	for (int i = 1; i <= n; i++)
		dp[1][i] = 0;

	for (int i = 2; i <= n - m; i++) {
		for (int j = i; j <= n; j++) {
			for (int p = i - 1; p <= j - 1; p++) {
				// 前j个里选了i个的最小值，由前p个中选i-1个加上
				// 当前搭配的值更新
				dp[i][j] = min(dp[i][j],
					       dp[i - 1][p] + abs(book[j].w - book[p].w));
			}
		}
	}

	ans = 0x3f3f3f3f;
	for (int i = n - m; i <= n; i++)
		ans = min(ans, dp[n - m][i]);
	cout << ans;
	return 0;
}
