#include <iostream>

using namespace std;

long long aa[104][104] = {0, };

int main(void)
{
	int n, m;
	long long x;
	long long ans = 0;

	cin >> n >> m >> x;

	for (int i = 1; i <= m; i++) {
		int r, c;
		long long v;
		cin >> r >> c >> v;
		aa[r][c] = v;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (aa[i + 1][j] == 0 &&
				aa[i][j + 1] == 0)
				ans += aa[i][j];
			else if (aa[i][j] > x)
				ans += (aa[i][j] - x);
		}
	}
	cout << ans;
	return 0;
}
