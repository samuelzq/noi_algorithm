#include <iostream>

using namespace std;

int map[110][110] = {0, };

void fire(int x, int y)
{
	map[x - 2][y] = map[x - 1][y] = map[x][y] =
	map[x][y - 2] = map[x][y - 1] = map[x][y + 1] =
	map[x + 2][y] = map[x + 1][y] = map[x][y + 2] =
	map[x + 1][y + 1] = map[x - 1][y - 1] = map[x + 1][y - 1] =
	map[x - 1][y + 1] = 1;
}

void stone(int x, int y)
{
	for (int i = x - 2; i <= x+2; i++)
		for (int j = y - 2; j <= y + 2; j++)
			map[i][j] = 1;
}

int main(void)
{
	int n, m, r, ans;
	int x, y;
	cin >> n >> m >> r;

	while (m--) {
		cin >> x >> y;
		fire(x + 1, y + 1);
	}

	while (r--) {
		cin >> x >> y;
		stone(x + 1, y + 1);
	}

	ans = 0;
	for (int i = 2; i < n + 2; i++)
		for (int j = 2; j < n + 2; j++)
			if (map[i][j] == 0)
				ans++;

	cout << ans;
	return 0;
}
