#include <iostream>

using namespace std;

long long map[2005][4] = {0, };

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> map[i][0] >> map[i][1] >> map[i][2] >> map[i][3];
	}

	for (int i = 1; i <= m; i++) {
		long long x, y;
		int c, l = 0;
		cin >> x >> y;

		c = 0;
		for (int j = n; j > 0; j--) {
			if (x >= map[j][0] && x <= map[j][2] &&
				y >= map[j][1] && y <= map[j][3]) {
				c++;
				if (l == 0)
					l = j;
			}
		}
		if (c == 0)
			cout << "NO\n";
		else
			cout << "YES " << c << ' ' << l << '\n';
	}
	return 0;
}
