/**
 * Walking on the Safe Side UVA - 825
 * https://vjudge.net/problem/UVA-825
 *
 *
 * @File:   uva825.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-06-28
 *
 **/
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

const int N = 200;

#define LL long long

LL dp[N][N];
char mp[N][N];
char buf[512];

int get_line(void)
{
	char c;
	int i = 0;

	c = getchar();
	while (c != '\n') {
		buf[i++] = c;
		c = getchar();
	}
	buf[i] = 0;
	return i;
}

int main(void)
{
	int t;

	scanf("%d", &t);
	getchar();
	while(t--) {
		int x, y;
		get_line();
		scanf("%d %d", &x, &y);
		getchar();

		memset(dp, 0, sizeof(dp));
		memset(mp, 0, sizeof(mp));

		for (int i = 1; i <= x; i++) {
			int t;
			char *p;
			get_line();
			p = strtok(buf, " ");
			t = atoi(p);
			while (1) {
				p = strtok(NULL, " ");
				if (!p)
					break;
				t = atoi(p);
				dp[i][t] = 0;
				mp[i][t] = 1;
			}
		}

		for (int i = 1; i <= y && mp[1][i] != 1; i++)
			dp[1][i] = 1;

		for (int i = 1; i <= x && mp[i][1] != 1; i++)
			dp[i][1] = 1;

		for (int i = 2; i <= x; i++) {
			for (int j = 2; j <= y; j++) {
				if (mp[i][j] == 0)
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		printf("%lld\n", dp[x][y]);
		if (t)
			printf("\n");
	}
	return 0;
}

