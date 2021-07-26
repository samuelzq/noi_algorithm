#include <cstdio>
#include <algorithm>

using namespace std;

const long long mod = 998244353;
const long long N = 1e5+5;
long long a[N] = {0, };
long long b[N] = {0, };
long long s[N] = {0, };

int main(void)
{
	long long n, m, ans;

	scanf("%lld %lld", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &b[i]);
	sort(b + 1, b + m + 1);
	ans = 0;

	// 分别计算东西和南北两个方向上的总长度。
	// 在两个方向上分别选两个边分别有C(n, 2)=n(n-1)和C(m, 2)=m(m-1)种选法
	// s[i-1]=a1+a2+...+ai-1
	for (int i = 1; i <= n; i++) {
		s[i] = a[i] + s[i - 1];
		ans = (((i - 1) * a[i] - s[i - 1]) % mod * (m * (m - 1) % mod) + ans) % mod;
	}
	for (int i = 1; i <= m; i++) {
		s[i] = b[i] + s[i - 1];
		ans = (((i - 1) * b[i] - s[i - 1]) % mod * (n * (n - 1) % mod) + ans) % mod;
	}
	printf("%lld", ans);
	return 0;
}
