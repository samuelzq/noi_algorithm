#include <bits/stdc++.h>

using namespace std;

const int R = 33;
const int C = 85;
char grid[R][C];
char s[C];
char con = ' ';
int vis[R][C];
int adj[4][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

struct mark {
	int sx, sy;
	char c;
};

int d;

queue<struct mark> marks;

bool get_line(void)
{
	bool ret = false;
	int len;
	d = 0;

	while (gets(s)) {
		ret = true;
		if (s[0] == '_')
			return ret;
		len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (con == ' ')
				con = s[i];
			else if (s[i] != con && s[i] != ' ') {
				struct mark m;
				m.sx = d;
				m.sy = i;
				m.c = s[i];
				marks.push(m);
				s[i] = ' ';
			}
			grid[d][i] = s[i];
		}
		grid[d][len] = 0;
		d++;
	}
	return ret;
}

bool valid(int x, int y)
{
	if (x < d && x >= 0 && y < 85 && y >= 0 && grid[x][y] == ' ')
		return true;

	return false;
}

void output()
{
	for (int i = 0; i < d; i++)
		printf("%s\n", grid[i]);
	printf("%s\n", s);
}

void dfs(int x, int y, char c)
{
	vis[x][y] = 1;
	grid[x][y] = c;

	for (int i = 0; i < 4; i++) {
		int xx, yy;
		xx = x + adj[i][0];
		yy = y + adj[i][1];
		if (valid(xx, yy))
			dfs(xx, yy, c);
	}
}

int main(void)
{
	int t;
	memset(grid, ' ', sizeof(grid));
	memset(vis, 0, sizeof(vis));
	while (get_line()) {
		while (!marks.empty()) {
			struct mark m;
			m = marks.front();
			marks.pop();
			if (valid(m.sx, m.sy))
				dfs(m.sx, m.sy, m.c);
		}
		output();
		memset(grid, ' ', sizeof(grid));
		memset(vis, 0, sizeof(vis));
		con = ' ';
	}
	return 0;
}