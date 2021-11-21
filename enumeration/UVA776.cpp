#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
char forest[N][N];
char s[N];
int dd[N];
int families[N][N];
int w, l, f;
int adj[8][2] = {
	{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}
};

void output(int w, char *s, int d)
{
	switch (w) {
		case 1:
			printf("%d", d);
			break;
		case 2:
			printf("%2d", d);
			break;
		case 3:
			printf("%3d", d);
			break;
		case 4:
			printf("%4d", d);
			break;
		case 5:
		default:
			printf("%5d", d);
			break;
	}
	printf("%s", s);
}

int get_line(void)
{
	char c;

	w = 0;
	while (c = getchar()) {
		if ((c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z') || c == '%')
			forest[l][w++] = c;
		else if (c != ' ')
			break;
	}
	forest[l][w] = 0;
	return w;
}

bool valid(int x, int y)
{
	if (x < 0 || x >= l)
		return false;
	if (y < 0 || y >= w)
		return false;
	if (forest[x][y] == ' ')
		return false;
	return true;
}

void check(int x, int y, char c)
{
	if (!valid(x, y))
		return;
	if (forest[x][y] != c)
		return;
	families[x][y] = f;
	dd[y] = max(dd[y], f);
	forest[x][y] = ' ';
	for (int i = 0; i < 8; i++) {
		int xx = x + adj[i][0];
		int yy = y + adj[i][1];
		check(xx, yy, c);
	}
}

int main(void)
{
	do {
		int c;
		c = w = l = f = 0;
		while (gets(s)) {
			int i;
			if (s[0] == '%')
				break;
			w = 0;
			for (i = 0; s[i] != 0; i++) {
				if (s[i] != ' ')
					forest[l][w++] = s[i];
			}
			l++;
		}
		f = 1;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < w; j++) {
				if (forest[i][j] == ' ')
					continue;
				check(i, j, forest[i][j]);
				f++;
			}
		}
		for (int i = 0; i < w; i++) {
			int d = 0;
			f = dd[i];
			while (f) {
				d++;
				f /= 10;
			}
			dd[i] = d;
		}
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < w - 1; j++)
				output(dd[j], (char *)" ", families[i][j]);
			output(dd[w - 1], (char *)"\n", families[i][w - 1]);
		}
		printf("%s\n", "%");
	} while (s[0] == '%');
	return 0;
}