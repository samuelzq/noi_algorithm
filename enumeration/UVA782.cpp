#include <bits/stdc++.h>

using namespace std;

const int R = 31;
const int C = 85;
char grid[R][C];
char s[C];
int vis[R][C];
int adj[4][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int r, l, u, d, sx, sy;

void get_line(void)
{
	int len;
	r = d = 0;
	u = -1;
	l = 81;

	while (gets(s)) {
		if (s[0] == '_')
			break;
		len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (s[i] == '*') {
				sy = i, sx = d;
				s[i] = ' ';
			} else if (s[i] == 'X') {

				l = min(l, i);
				r = max(r, i);
				if (u == -1)
					u = d;
			}
			grid[d][i] = s[i];
		}
		d++;
	}
	r += 2;
}

bool valid(int x, int y)
{
	if (x + 1 <= d && grid[x + 1][y] == 'X')
		return true;

	if (x - 1 >= 0 && grid[x - 1][y] == 'X')
		return true;

	if (y + 1 <= r + 1 && grid[x][y + 1] == 'X')
		return true;

	if (y - 1 >= 0 && grid[x][y - 1] == 'X')
		return true;

	return false;
}

bool next_move(int x, int y)
{
	if (x > d || y > r + 1 || x < 0 || y < 0)
		return false;
	if (grid[x][y] == 'X')
		return false;
	if (vis[x][y])
		return false;
	return true;
}

void output()
{
	for (int i = d - 1; i >= 0; i--) {
		int j;
		for (j = C - 4; j >= 0; j--) {
			if (grid[i][j] != ' ')
				break;
		}
		grid[i][j + 1] = 0;
	}
	for (int i = 0; i < d; i++)
		printf("%s\n", grid[i]);
	printf("%s\n", s);
}

void dfs(int x, int y)
{
	vis[x][y] = 1;
	if (valid(x, y))
		grid[x][y] = '#';

	for (int i = 0; i < 4; i++) {
		int xx, yy;
		xx = x + adj[i][0];
		yy = y + adj[i][1];
		if (next_move(xx, yy))
			dfs(xx, yy);
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t--) {
		memset(grid, ' ', sizeof(grid));
		memset(vis, 0, sizeof(vis));
		get_line();
		dfs(sx, sy);
		output();
	}
	return 0;
}