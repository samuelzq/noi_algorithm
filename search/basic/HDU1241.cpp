#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;
char p[N][N];
int mov[8][2] = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1},
	{-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};
int m, n;


void dfs(int x, int y)
{
	if (x < 1 || x > m || y < 1 || y > n)
		return;
	if (p[x][y] != '@')
		return;
	p[x][y] = 'l';
	for (int i = 0; i < 8; i++)
		dfs(x + mov[i][0], y + mov[i][1]);
	return;
}

int main(void)
{
	int ans;
	while (cin >> m >> n) {
		if (n == 0 || m == 0)
			break;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				cin >> p[i][j];
		ans = 0;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				if (p[i][j] == '@') {
					dfs(i, j);
					ans++;
				}
			}
		cout << ans << '\n';
	}
	return 0;
}
