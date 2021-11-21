#include <bits/stdc++.h>

using namespace std;
const int N = 90;
const int MAXN = 0x3f3f3f3f;
char bd[N][N];
char vis[N][N];
char use[N][N];
int dd[4][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
int n;
int wwin, bwin;
enum {
	WHITE = 0,
	BLACK,
};

bool in_range(int x, int y)
{
	if (x < 1 || x > n)
		return false;
	if (y < 1 || y > n)
		return false;

	return true;
}

void check(int x, int y, char c, int u)
{
	int xx, yy, k;
	vis[x][y] = 1;

	if (y == n && c == 'W') {
		wwin = 1;
		return;
	}
	if (x == n && c == 'B') {
		bwin = 1;
		return;
	}

	for (k = 0; k < 4; k++) {
		xx = x + dd[k][0];
		yy = y + dd[k][1];
		if (false == in_range(xx, yy))
			continue;

		if (u == -1) {
			if (vis[xx][yy] || bd[xx][yy] != c)
				continue;
			check(xx, yy, c, u);
		} else {
			use[x][y] = u;
			if (vis[xx][yy] && u >= use[xx][yy])
				continue;
			if (bd[xx][yy] == c)
				check(xx, yy, c, u);
			else if (bd[xx][yy] == 'U' && u == 0)
				check(xx, yy, c, 1);
		}
	}
}

bool white_win(void)
{
	int i;
	// 检查边界
	i = 1;
	while (i <= n && bd[i][1] != 'W')
		i++;
	if (i > n)
		return false;
	i = 1;
	while (i <= n && bd[i][n] != 'W')
		i++;
	if (i > n)
		return false;

	wwin = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		if (vis[i][1] || bd[i][1] != 'W')
			continue;
		check(i, 1, 'W', -1);
		if (wwin)
			return true;
	}
	return false;
}

bool black_win(void)
{
	int i;
	// 检查边界
	i = 1;
	while (i <= n && bd[1][i] != 'B')
		i++;
	if (i > n)
		return false;
	i = 1;
	while (i <= n && bd[n][i] != 'B')
		i++;
	if (i > n)
		return false;

	bwin = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		if (vis[1][i] || bd[1][i] != 'B')
			continue;
		check(1, i, 'B', -1);
		if (bwin)
			return true;
	}
	return false;
}

bool white_win_one(void)
{
	wwin = 0;
	memset(vis, 0, sizeof(vis));
	memset(use, 0, sizeof(use));
	for (int i = 1; i <= n; i++) {
		if (bd[i][1] == 'B')
			continue;
		else {
			int u;
			if (bd[i][1] == 'W')
				u = 0;
			else
				u = 1;
			if (vis[i][1] && u >= use[i][1])
				continue;
			check(i, 1, 'W', u);
		}
		if (wwin)
			return true;
	}
	return false;
}

bool black_win_one(void)
{
	bwin = 0;
	memset(vis, 0, sizeof(vis));
	memset(use, 0, sizeof(use));
	for (int i = 1; i <= n; i++) {
		if (bd[1][i] == 'W')
			continue;
		else {
			int u;
			if (bd[1][i] == 'B')
				u = 0;
			else
				u = 1;
			if (vis[1][i] && u >= use[1][i])
				continue;
			check(1, i, 'B', u);
		}
		if (bwin)
			return true;
	}
	return false;
}

int readi()
{
	char c;
	int n = 0;

	c = getchar();
	while (c < '0' || c > '9')
		c = getchar();

	do {
		n = n * 10 + (c - '0');
		c = getchar();
	} while (c > '0' && c < '9');
	return n;
}

int main()
{
	while (1) {
		n = readi();
		if (!n)
			break;
		getchar();
		for (int i = 1; i <= n; i++)
			gets(bd[i] + 1);

		if (white_win())
			printf("White has a winning path.\n");
		else if (black_win())
			printf("Black has a winning path.\n");
		else if (white_win_one())
			printf("White can win in one move.\n");
		else if (black_win_one())
			printf("Black can win in one move.\n");
		else
			printf("There is no winning path.\n");
		getchar();
	}
	return 0;
}