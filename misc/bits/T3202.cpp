#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int cur[N];
int xorsum[N];

int main(void)
{
	int n, m, a;

	cin >> n >> m;

	xorsum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		xorsum[i] = xorsum[i - 1] ^ a;
	}

	while (m--) {
		int l, r, ans;
		cin >> l >> r;
		ans = 0;
		memset(cur, 0, sizeof(cur));
		for (int i = l; i <= r; i++) {
			ans += cur[xorsum[i]];
			cur[xorsum[i]]++;
		}
		cout << ans << '\n';
	}
	return 0;
}
