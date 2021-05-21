#include <iostream>

using namespace std;
int f[10905][10905] = {0,};
int main(void)
{
	int n, m, r, t, ans = 0;

	cin >> n >> m >> r >> t;

	for (int i = 0; i < r; i++) {
		int x, y;
		cin >> x >> y;
		if (f[x][y] == 1)
			ans--;
		f[x][y] = 1;
		for (int j = 1; j < t; j++) {
			int x1, x2, y1, y2;
			x1 = x - j;
			x2 = x + j;
			y1 = y - j;
			y2 = y + j;
			if (x1 > 0) {
				if (y1 > 0) {
					if (f[x1][y1] == 0)
						ans++;
					f[x1][y1] = 1;
				}
				if (f[x1][y] == 0)
					ans++;
				f[x1][y] = 1;
				if (y2 <= m) {
					if (f[x1][y2] == 0)
						ans++;
					f[x1][y2] = 1;
				}

			}
			if (x2 <= n) {
				if (y1 > 0) {
					if (f[x2][y1] == 0)
						ans++;
					f[x2][y1] = 1;
				}
				if (f[x2][y] == 0)
					ans++;
				f[x2][y] = 1;
				if (y2 <= m) {
					if (f[x2][y2] == 0)
						ans++;
					f[x2][y2] = 1;
				}
			}
			if (y1 > 0) {
				if (f[x][y1] == 0)
					ans++;
				f[x][y1] = 1;
			}
			if (y2 <= m) {
				if (f[x][y2] == 0)
					ans++;
				f[x][y2] = 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
