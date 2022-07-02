#include <iostream>
#include <cmath>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e5+5;
int n, ans = 0x3f3f3f3f;
int a[N];
int dp[N][N];

#if 1
int f(int x)
{
	if (x > n)
		return 0;
	return min(f(a[x]), f(x + 5)) + 2;
	
}

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << f(1) << endl;
	return 0;
}
#else
int main(void)
{
	int mx;
	cin >> n;
	mx=0;
	for (int i=1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	mx = max(mx, n + 5);
	for (int i=1; i <= mx; i++) {
		for (int j = 1; j <= mx; j++)
			dp[i][j]=INF;
		dp[i][i]=0;
		dp[i][i+5]=2;
		dp[i][a[i]]=2;
	}

	for (int i = 1; i <= mx; i++)
		for (int j=1;j<=n;j++)
			dp[1][i] = min(dp[1][i], dp[1][j] + dp[j][i]);
	for (int i = n+1; i <= mx; i++)
		if (dp[1][i] != INF)
			ans = min(ans, dp[1][i]);
	cout << ans;
	return 0;
}
#endif
