/**
 * Longest Run on a Snowboard UVA - 10285
 * https://vjudge.net/problem/UVA-10285
 *
 * 在每一个坐标点上遍历每一种可能的移动，选取最大的值
 *
 * @File:   uva10285.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-12
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 102;
int height[N][N];
int pth[N][N];
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dp(int x, int y)
{
	int ans = 1;
	for (int i = 0; i < 4; i++) {
		int xx, yy;
		xx = mv[i][0] + x;
		yy = mv[i][1] + y;
		if (height[xx][yy] > 0 && height[xx][yy] < height[x][y])
			ans = max(dp(xx, yy) + 1, ans);
	}
	return ans;
}

int main(void)
{
	int k;

	scanf("%d", &k);
	while (k--) {
		char field[256];
		int r, c, ans;
		memset(height, -1, sizeof(height));
		scanf("%s %d %d", field, &r, &c);
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				scanf("%d", &height[i][j]);

		ans = 0;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++) {
				ans = max(ans, dp(i, j));
			}
		printf("%s: %d\n", field, ans);
	}
	return 0;
}
