#include <bits/stdc++.h>

using namespace std;

const int N = 52;
char bd[N][N];
int die[N*N];
int adj[4][2] = {
	{-1, 0}, {0, 1}, {1, 0}, {0, -1}
};
queue<pair<int, int>> mq;
int r, c;
int ans;

bool valid(int x, int y)
{
	if (x < 0 || x >= r)
		return false;
	if (y < 0 || y >= c)
		return false;
	if (bd[x][y] == '.')
		return false;
	return true;
}

void check_x(int x, int y)
{
	if (false == valid(x, y))
		return;
	if (bd[x][y] == '*')
		return;
	mq.push(pair<int, int>(x, y));
	while (!mq.empty()) {
		pair<int, int> p = mq.front();
		mq.pop();
		bd[p.first][p.second] = '*';
		for (int i = 0; i < 4; i++) {
			int xx, yy;
			xx = p.first + adj[i][0];
			yy = p.second + adj[i][1];
			if (false == valid(xx, yy))
				continue;
			if (bd[xx][yy] == 'X')
				mq.push(pair<int, int>(xx, yy));
		}
	}
}

void check(int x, int y)
{
	if (false == valid(x, y))
		return;
	if (bd[x][y] == 'X') {
		ans++;
		check_x(x, y);
	}
	bd[x][y] = '.';
	for (int i = 0; i < 4; i++) {
		int xx, yy;
		xx = x + adj[i][0];
		yy = y + adj[i][1];
		if (false == valid(xx, yy))
			continue;
		if (bd[xx][yy] == 'X') {
			ans++;
			check_x(xx, yy);
		}
		check(xx, yy);
	}
}

int main(void)
{
	int n, k = 0;
	while (scanf("%d %d", &c, &r) && r && c) {
		getchar();
		for (int i = 0; i < r; i++)
			gets(bd[i]);

		n = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (bd[i][j] == 'X') {
					ans = 1;
					check_x(i, j);
					check(i, j);
					die[n++] = ans;
				} else if (bd[i][j] == '*') {
					ans = 0;
					check(i, j);
					die[n++] = ans;
				}
			}
		}
		sort(die, die + n);
		printf("Throw %d\n", ++k);
		printf("%d", die[0]);
		for (int i = 1; i < n; i++)
			printf(" %d", die[i]);
		printf("\n\n");
		//getchar();
	}
	return 0;
}