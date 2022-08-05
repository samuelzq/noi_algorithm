/**
 * Package Pricing UVA - 233
 * https://vjudge.net/problem/UVA-233
 *
 * 4维无限背包。
 * 使用静态数组导致TLE。
 *
 * @File:   uva233.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-31
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 52, M = 100;
int dp[M][M][M][M];
int package[N][4];
int price[N], id[N];
char buf[512];
int req[4];

int get_line(void)
{
	char c;
	int i = 0;

	c = getchar();
	while (c != '\n' && i < 511) {
		buf[i++] = c;
		c = getchar();
	}
	buf[i] = 0;
	return i;
}

void resolve(int n, int kase)
{
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[0][0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= req[0]; j++) {
			for (int k = 0; k <= req[1]; k++) {
				for (int l = 0; l <= req[2]; l++) {
					for (int m = 0; m <= req[3]; m++) {
						int s0, s1, s2, s3;
						s0 = j - package[i][0];
						s1 = k - package[i][1];
						s2 = l - package[i][2];
						s3 = m - package[i][3];
						s0 = s0 > 0 ? s0: 0;
						s1 = s1 > 0 ? s1: 0;
						s2 = s2 > 0 ? s2: 0;
						s3 = s3 > 0 ? s3: 0;
						dp[j][k][l][m] = min(dp[j][k][l][m], dp[s0][s1][s2][s3] + price[i]);
					}
				}
			}
		}
	}

	int a, b;
	a = dp[req[0]][req[1]][req[2]][req[3]];
	b = a % 100;
	a = a / 100;
	printf("%d:%5d.%02d", kase, a, b);

	map<int, int> ans;
	int s0, s1, s2, s3;
	s0 = req[0], s1 = req[1], s2 = req[2], s3 = req[3];
	for (int i = 0; i < n;) {
		int t0, t1, t2, t3;
		t0 = s0 - package[i][0];
		t1 = s1 - package[i][1];
		t2 = s2 - package[i][2];
		t3 = s3 - package[i][3];
		t0 = t0 > 0 ? t0 : 0;
		t1 = t1 > 0 ? t1 : 0;
		t2 = t2 > 0 ? t2 : 0;
		t3 = t3 > 0 ? t3 : 0;

		if (dp[s0][s1][s2][s3] - dp[t0][t1][t2][t3] == price[i]) {
			s0 = t0;
			s1 = t1;
			s2 = t2;
			s3 = t3;
			ans[id[i]]++;
		} else {
			i++;
		}
	}

	for (map<int,int>::iterator it = ans.begin(); it != ans.end(); it++) {
		if (it->second > 1)
			printf(" %d(%d)", it->first, it->second);
		else if (it->second == 1)
			printf(" %d", it->first);
	}
	printf("\n");
}


int main(void)
{
	int n, m, t = 0;;

	while (scanf("%d", &n) != EOF) {
		if (t)
			printf("\n");
		t = 1;
		memset(dp, 0, sizeof(dp));
		memset(package, 0, sizeof(package));
		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d.%d", &id[i], &a, &b);
			price[i] = a * 100 + b;
			get_line();

			char *p;
			p = strtok(buf, " ");
			while (p) {
				int idx = *p - 'a';
				p = strtok(NULL, " ");

				int cnt = atoi(p);
				package[i][idx] += cnt;
				p = strtok(NULL, " ");
			}
		}

		get_line();
		m = atoi(buf);

		for (int i = 0; i < m; i++) {
			req[0] = req[1] = req[2] = req[3] = 0;
			get_line();

			char *p;
			p = strtok(buf, " ");
			while (p) {
				int idx = *p - 'a';
				p = strtok(NULL, " ");

				int cnt = atoi(p);
				req[idx] += cnt;
				p = strtok(NULL, " ");
			}
			resolve(n, i+1);
		}

	}

}
