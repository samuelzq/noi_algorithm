#include <iostream>

using namespace std;

int f[102][102]= {0, };

int main(void)
{
	int r, c, i, j;
	long long ans;

	cin >> r >> c;

	for (i = 1; i <= r; i++) {
		for (j = 1; j <= c; j++) {
			cin >> f[i][j];
		}
	}

	ans = 0;
	i = j = 1;
	while (1) {
		int t, x, y;
		ans += f[i][j];
		if (i == r && j == c)
			break;
		t = f[i][j] = 0;
		if (f[i + 1][j] > t) {
			x = i + 1;
			y = j;
			t = f[i + 1][j];
		}
		if (f[i][j + 1] > t) {
			x = i;
			y = j + 1;
			t = f[i][j + 1];
		}
		if (f[i - 1][j] > t) {
			x = i - 1;
			y = j;
			t = f[i - 1][j];
		}
		if (f[i][j - 1] > t) {
			x = i;
			y = j - 1;
			t = f[i][j - 1];
		}
		i = x;
		j = y;
	}
	cout << ans;
	return 0;
}
