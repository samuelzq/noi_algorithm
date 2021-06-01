#include <iostream>

using namespace std;

int cub[42][42] = {0, };

int main(void)
{
	int n, t, x, y, m;
	cin >> n;
	t = (2 * n - 1) * (2 * n - 1);

	x = 1;
	y = n;
	m = 2 * n - 1;
	cub [x][y] = 1;
	for (int i = 2; i <= t; i++) {
		int nx, ny;

		if (x == 1 && y == m) {
			nx = x + 1;
			while (cub[nx][y] != 0) {
				x++;
				nx = x;
				if (nx > m) {
					cout << "Err!";
					return -1;
				}
			}
			cub[nx][y] = i;
			x = nx;
			continue;
		}

		if (x > 1)
			nx = x - 1;
		else
			nx = m;
		if (y == m)
			ny = 1;
		else
			ny = y + 1;

		while (cub[nx][ny] != 0) {
			x++;
			ny = y;
			nx = x;
			if (nx > m) {
				cout << "Err!";
				return -1;
			}
		}
		cub[nx][ny] = i;
		x = nx;
		y = ny;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cout << cub[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
