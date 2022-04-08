/**
 * https://vjudge.net/problem/UVA-524
 *
 * @File:   uva524.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-04-20
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int is_prime[100];
int out[17];
int used[17];
int n;

void primes(void)
{
	for (int i = 2; i * i <= 100; i++) {
		if (!is_prime[i]) {
			for (int j = i + i; j <= 100; j += i)
				is_prime[j] = 1;
		}
	}
}

void dfs(int d)
{
	if (d >= n) {
		for (int i = 0; i < n - 1; i++)
			printf("%d ", out[i]);
		printf("%d\n", out[n - 1]);
	}

	for (int i = 1; i <= n; i++) {
		if (d == 0 && i > 1)
			break;
		if (!used[i]) {
			if (is_prime[i + out[d - 1]])
				continue;
			if (d == n - 1) {
				if (is_prime[i + out[0]])
					continue;
			}
			used[i] = 1;
			out[d] = i;
			dfs(d + 1);
			out[d] = 0;
			used[i] = 0;
		}
	}
}

int main(void)
{
	int t = 1;
	primes();
	while (scanf("%d", &n) != EOF) {
		if (t > 1)
			printf("\n");
		memset(out, 0, sizeof(out));
		printf("Case %d:\n", t++);
		dfs(0);
	}
	return 0;
}
