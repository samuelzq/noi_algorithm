/**
 * The Marriage Interview :-) UVA - 10446
 * https://vjudge.net/problem/UVA-10446
 *
 * 将观察发现：
 *      f(n) = 1    n < 2 or b = 0
 *      f(n) = f(n-1) + f(n-2) + ... + f(n-b)    n >= 2
 *
 * @File:   uva10446.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-12
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 66;
const int L = 12;
const int MAXN = 1e9;
int step[N][2 * N][L];

void add(int a[], int b[], int c[])
{
	int d = 0, i, sum = 0;
	for (i = 0; i < L; i++) {
		sum = a[i] + b[i] + d;
		d = sum / MAXN;
		sum %= MAXN;
		c[i] = sum;
	}
}

void output(int a[])
{
	int i = L - 1;
	while (!a[i])
		i--;
	printf("%d", a[i--]);
	while (i >= 0)
		printf("%09d", a[i--]);
	printf("\n");
}

void init(void)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2 * N; j++)
			step[i][j][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = N + 1; j < 2 * N; j++) {
			for (int k = 1; k <= i; k++)
				add(step[i][j], step[i][j - k], step[i][j]);
		}
	}
}

int main(void)
{
	int n, b, k;
	init();
	k = 1;

	while (scanf("%d %d", &n, &b) != EOF) {
		if (n >= 61 || b >= 61)
			break;
		if (n < 2)
			printf("Case %d: 1\n", k++);
		else {
			printf("Case %d: ", k++);
			output(step[b][n + N - 1]);
		}
	}
	return 0;
}
