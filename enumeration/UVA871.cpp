#include <bits/stdc++.h>

using namespace std;

const int N = 30;
char grid[N][N];
int h, w;
int adj[8][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1},
	{1, 1}, {-1, 1}, {1, -1}, {-1, -1}
};

void get_lines(void)
{
	w = 0;
	h = 0;
	while (gets(grid[h]) && grid[h][0] != 0)
		h++;
	w = strlen(grid[0]);
}

bool valid(int x, int y)
{
	if (x < 0 || x >= h || y < 0 || y >= w || grid[x][y] == '0')
		return false;
	return true;
}

int dfs(int x, int y)
{
	int ans = 0;
	if (valid(x, y) == false)
		return 0;
	ans = 1;
	grid[x][y] = '0';
	for (int i = 0; i < 8; i++) {
		int xx, yy;
		xx = x + adj[i][0];
		yy = y + adj[i][1];
		ans += dfs(xx, yy);
	}
	return ans;
}

int main(void)
{
	int t;
	int ans;

	scanf("%d", &t);
	getchar();
	getchar();
	while (t-- > 1) {
		ans = 0;
		get_lines();
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				ans = max(ans, dfs(i, j));

		printf("%d\n\n", ans);
	}
	ans = 0;
	get_lines();
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			ans = max(ans, dfs(i, j));

	printf("%d\n", ans);
	return 0;
}