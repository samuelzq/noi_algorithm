/**
 * https://vjudge.net/problem/UVA-10957
 *
 * @File:   uva10957.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 9;

int mp[N][N];
int v[N + 1][N + 1], h[N + 1][N + 1], xy[N + 1][N + 1];
int solved;
char str[2 * N + 2];

int square_idx(int x, int y)
{
	return x / 3 * 3 + y / 3;
}

void dfs(int xx, int yy)
{
	if (xx == N - 1 && yy == N) {
		solved += 1;
		return;
	}

	if (yy == N) {
		yy = 0;
		xx++;
	}

	if (mp[xx][yy]) {
		dfs(xx, yy + 1);
	} else {
		for (int i = 1; i <= N; i++) {
			int j, t;
			t = square_idx(xx, yy);
			if (v[xx][i] || h[yy][i] || xy[t][i])
				continue;

			v[xx][i] = 1;
			h[yy][i] = 1;
			xy[t][i] = 1;
			dfs(xx, yy + 1);
			if (solved > 1)
				return;
			xy[t][i] = 0;
			h[yy][i] = 0;
			v[xx][i] = 0;
		}
	}
}

int main(void)
{
	int kase, f;
	kase = f = 0;
	while (scanf("%d", &mp[0][0]) != EOF) {
		kase++;

		v[0][mp[0][0]] = 1;
		h[0][mp[0][0]] = 1;
		xy[0][mp[0][0]] = 1;
		
		for (int i = 1; i < 81; i++) {
			int x, y, k, t;
			scanf("%d", &k);
			x = i / 9;
			y = i % 9;
			t = square_idx(x, y);
			if (k && (v[x][k] || h[y][k] || xy[t][k])) {
					solved = -1;
			}
			mp[x][y] = k;
			v[x][k] = 1;
			h[y][k] = 1;
			xy[t][k] = 1;
		}
		printf("Case %d: ", kase);
		if (solved == -1) {
			printf("Illegal.\n");
		} else {
			solved = 0;
			dfs(0, 0);
			if (solved == 0)
				printf("Impossible.\n");
			else if (solved == 1)
				printf("Unique.\n");
			else if (solved > 1)
				printf("Ambiguous.\n");
		}
		solved = 0;
		memset(mp, 0, sizeof(mp));
		memset(v, 0, sizeof(v));
		memset(h, 0, sizeof(h));
		memset(xy, 0, sizeof(xy));
	}
	return 0;
}
