#include <bits/stdc++.h>

using namespace std;

const int N = 252;
char bd[N][N];
char s[128];
int vis[N][N];
int m, n;

int adj[4][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

char * geti(char *s, int &i)
{
	int k;
	while (*s < '0' || *s > '9')
		s++;
	k = 0;
	while (*s >= '0' && *s <= '9') {
		k = k * 10 + (int)(*s - '0');
		s++;
	}
	i = k;
	return s;
}

void clear(void)
{
	memset(bd, 'O', sizeof(bd));
}

void creat_table(int m, int n)
{
	clear();
	m = m;
	n = m;
	for (int i = 0; i < n; i++)
		bd[i][m] = 0;
}

void paint(int x, int y, char c)
{
	bd[y][x] = c;
}

void vdraw(int x, int y1, int y2, char c)
{
	if (y1 > y2)
		swap(y1, y2);
	for (int i = y1; i <= y2; i++)
		bd[i][x] = c;
}

void hdraw(int x1, int x2, int y, char c)
{
	if (x1 > x2)
		swap(x1, x2);
	for (int i = x1; i <= x2; i++)
		bd[y][i] = c;
}

void fill(int x1, int x2, int y1, int y2, char c)
{
	if (y1 > y2)
		swap(y1, y2);
	if (x1 > x2)
		swap(x1, x2);
	for (int i = y1; i <= y2; i++)
		for (int j = x1; j <= x2; j++)
			bd[i][j] = c;
}

void rfill(int x, int y, char c)
{
	if (vis[y][x] || x < 0 || x >= m || y < 0 || y >= n)
		return;
	vis[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int xx, yy;
		xx = x + adj[i][0];
		yy = y + adj[i][1];
		if (bd[yy][xx] == bd[y][x])
			rfill(xx, yy, c);
	}
	bd[y][x] = c;
}

void out_put(char *name)
{
	printf("%s\n", name);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%c", bd[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int x1, x2, y1, y2;
	char c, *buf;

	while(gets(s) && s[0] != 'X') {
		switch(s[0]) {
			case 'I':
				buf = geti(&s[1], m);
				geti(buf, n);
				creat_table(m, n);
				break;
			case 'C':
				clear();
				break;
			case 'L':
				buf = geti(s + 1, x1);
				buf = geti(buf, y1);
				paint(x1 - 1, y1 - 1, *(buf + 1));
				break;
			case 'V':
				buf = geti(s + 1, x1);
				buf = geti(buf, y1);
				buf = geti(buf, y2);
				vdraw(x1 - 1, y1 - 1, y2 - 1, buf[1]);
				break;
			case 'H':
				buf = geti(s + 1, x1);
				buf = geti(buf, x2);
				buf = geti(buf, y1);
				hdraw(x1 - 1, x2 - 1, y1 - 1, buf[1]);
				break;
			case 'K':
				buf = geti(s + 1, x1);
				buf = geti(buf, y1);
				buf = geti(buf, x2);
				buf = geti(buf, y2);
				fill(x1 - 1, x2 - 1, y1 - 1, y2 - 1, buf[1]);
				break;
			case 'F':
				buf = geti(s + 1, x1);
				buf = geti(buf, y1);
				memset(vis, 0, sizeof(vis));
				rfill(x1 - 1, y1 - 1, buf[1]);
				break;
			case 'S':
				out_put(s + 2);
			default:
				break;
		}
	}
	return 0;
}