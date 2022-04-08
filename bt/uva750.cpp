/**
 * https://vjudge.net/problem/UVA-750
 *
 * 相比经典8皇后问题，变化有两点：
 * 	1、其中一个皇后的位置已经指定；
 * 	2、输出的格式。
 *
 * @File:   uva750.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-06
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 8;
int v[N + 1], h[N + 1], xy[2 * N + 2], yx[2 * N + 2];
int out[N + 1];
int no, x, y;

void dfs(int d)
{
	if (d > N) {
		printf("%2d      %d", no++, out[1]);
		
		for (int i = 2; i <= N; i++)
			printf(" %d", out[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (h[i] || xy[d + i] || yx[N + d - i])
			continue;
		if (d == y && i != x)
			continue;
		v[d] = h [i] = xy[d + i] = yx[N + d - i] = 1;
		out[d] = i;
		dfs(d + 1);
		v[d] = h [i] = xy[d + i] = yx[N + d - i] = 0;
	}
}

int main(void)
{
	int k;

	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &x, &y);
		no = 1;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		dfs(1);
		if (k)
			printf("\n");
	}
	return 0;
}
