#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2;

#if 0
int dp[2][N];
int a[N], b[N];
int *cdp;
int *pdp;

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		cin >> b[i];

	for (int i = 1; i <= n; i++) {
		pdp = dp[(i+1) & 1];
		cdp = dp[i & 1];
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j])
				cdp[j] = max(cdp[j], pdp[j-1] + 1);
			else
				cdp[j] = max(pdp[j], cdp[j-1]);
		}
	}
	cout << cdp[n];
	return 0;
}
#else
int n,len,a[N],b[N],f[N];
int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		b[x] = i;
	}

	for (int i=1;i<=n;i++) {
		int x;
		cin >> x;
		a[i] = b[x];
	}
	len = 1;
	f[1] = a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] > f[len]) {
			f[++len] = a[i];
		} else {
			int mid, l = 1, r = len;
			while (l < r) {
				mid = (l + r) / 2;
				if (f[mid] > a[i])
					r = mid;
				else
					l = mid + 1;
			}
			if (f[l] > a[i])
				f[l] = a[i];
		}
	}
	cout << len;
	return 0;
}
#endif
