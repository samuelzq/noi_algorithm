#include <iostream>

using namespace std;

int r[5005] = {0, };
int c[5005] = {0, };

int main(void)
{
	int n, m, b, g, i, j;
	long long ans = 0;

	cin >> n >> m >> b >> g;

	for (i = 0; i < b; i++) {
		int x, y;
		cin >> x >> y;
		for (j = x; j <= y; j++)
			r[j] = 1;
	}

	for (i = 0; i < g; i++) {
		int x, y;
		cin >> x >> y;
		for (j = x; j <= y; j++)
			c[j] = 1;
	}

	for (i = 1; i <= n; i++) {
		if (r[i] == 1)
			continue;
		for (j = 1; j <= m; j++) {
			if (c[j] == 0)
				ans++;
		}
	}
	cout << n * m - ans;
	return 0;
}
