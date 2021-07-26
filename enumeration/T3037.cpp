#include <iostream>

using namespace std;

long long x[1005], y[1005], a[1005], b[1005];

int main(void)
{
	int m, n;
	long long ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> a[i] >> b[i];

	for (int i = 0; i < m; i++) {
		int idx;
		long long l, t = 0x7fffffffffffff;
		for (int j = 0; j < n; j++) {
			if (x[j] == -1)
				continue;
			l = (a[i] - x[j]) * (a[i] - x[j]) + (b[i] - y[j]) * (b[i] - y[j]);
			if (l < t) {
				idx = j;
				t = l;
			}
		}
		ans += t;
		x[idx] = -1;
	}
	cout << ans;
	return 0;
}
