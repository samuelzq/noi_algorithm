#include <bits/stdc++.h>

using namespace std;

const int N = 202;
char p[N][N];
int visited[N][N];
int n = 0;
int dd[6][2] = {
	{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}
};
int win = 0;

void check(int x, int y)
{
	if (y == n - 1) {
		win = 1;
		return;
	}

	visited[x][y] = 1;
	for (int i = 5; i >= 0; i--) {
		int nx, ny;
		nx = x + dd[i][0];
		ny = y + dd[i][1];

		if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[nx][ny] && p[nx][ny] == 'w')
			check(nx, ny);
	}
}

int main(void)
{
	int kase = 1;
	while (scanf("%d", &n) && n != 0) {
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++)
			scanf("%s", p[i]);
		win = 0;
		for (int i = 0; i < n; i++) {
			if (!win && p[0][i] == 'w' && !visited[i][0])
				check(i, 0);
		}
		if (win == 0)
			printf("%d B\n", kase++);
		else
			printf("%d W\n", kase++);
	}
	return 0;
}