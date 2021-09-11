#include <iostream>

using namespace std;

long long ss[100005] = {0, };
long long s2[100005] = {0, };
const long long mod = 1e9+7;

int main(void)
{
	int n, q;
	long long s = 0;
	long long ans;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long t;
		cin >> t;
		s = s + t;
		ss[i] = s;
	}
	s = 0;
	for (int i = 1; i <= n; i++) {
		s = (s + ss[i]);
		s2[i] = s;
	}

	cin >> q;
	ans = 0;
	for (int i = 0; i < q; i++) {
		int l, r;
		long long d;
		cin >> l >> r;
		d = (s2[r] - s2[l - 1] - (r - l + 1) * ss[l - 1]) % mod;
		ans = (ans + d) % mod;
	}
	cout << ans << '\n';
	return 0;
}
