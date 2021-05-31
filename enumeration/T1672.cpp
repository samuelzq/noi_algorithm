#include <iostream>
#include <algorithm>

using namespace std;

int p[1005];

int main(void)
{
	int m, n, d, g, idx, ans = 0;

	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	sort(&p[1], &p[n+1]);

	for (int i = 1; i <= n; i++) {
		d = (n - i + 1);
		d = m > d ? d : m;
		g = p[i] * d;
		if (g > ans) {
			idx = i;
			ans = g;
		}
	}
	cout << p[idx] << ' ' << ans << endl;
	return 0;
}
