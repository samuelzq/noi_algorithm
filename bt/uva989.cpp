/**
 * https://vjudge.net/problem/UVA-989
 * @File:   uva989.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 9;

int mp[N][N];
int res[N][N];
int v[N + 1][N + 1], h[N + 1][N + 1], xy[N + 1][N + 1];
int a, n;
int solved;
void dfs(int xx, int yy)
{
	if (xx == n - 1 && yy == n) {
		solved = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++)
				printf("%d ", res[i][j]);
			printf("%d\n", res[i][n - 1]);
		}
		return;
	}

	if (yy == n) {
		yy = 0;
		xx++;
	}

	if (mp[xx][yy]) {
		res[xx][yy] = mp[xx][yy];
		dfs(xx, yy + 1);
	} else {
		for (int i = 1; i <= n; i++) {
			int j, x, y, t;
			x = xx / a;
			y = yy / a;
			t = y + a * x;
			if (v[xx][i] || h[yy][i] || xy[t][i])
				continue;

			v[xx][i] = 1;
			h[yy][i] = 1;
			xy[t][i] = 1;
			res[xx][yy] = i;
			dfs(xx, yy + 1);
			if (solved)
				return;
			res[xx][yy] = 0;
			xy[t][i] = 0;
			h[yy][i] = 0;
			v[xx][i] = 0;
		}
	}
}

int main(void)
{
	int f = 0;
	while (scanf("%d", &a) != EOF) {
		if (f)
			printf("\n");
		f = 1;
		n = a * a;
		memset(res, 0, sizeof(res));
		memset(v, 0, sizeof(v));
		memset(h, 0, sizeof(h));
		memset(xy, 0, sizeof(xy));
		solved = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &mp[i][j]);
				if (mp[i][j]) {
					int x, y, t;
					v[i][mp[i][j]] = 1;
					h[j][mp[i][j]] = 1;
					x = i / a;
					y = j / a;
					t = y + a * x;
					xy[t][mp[i][j]] = 1;
				}
			}
		dfs(0, 0);

		if (!solved)
			printf("NO SOLUTION\n");
	}
	return 0;
}
