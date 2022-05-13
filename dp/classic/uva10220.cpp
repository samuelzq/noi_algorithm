/**
 * I Love Big Numbers ! UVA - 10220
 * https://vjudge.net/problem/UVA-10220
 *
 * @File:   uva10220.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-12
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int f[1010][10100];

int mul(int a[], int b, int len, int d[])
{
	int c, t, i;

	c = 0;
	for (i = 0; i < len; i++) {
		t = a[i] * b + c;
		c = t / 10;
		t = t % 10;
		d[i] = t;
	}
	while (c) {
		t = c % 10;
		c /= 10;
		d[i++] = t;
	}
	return i;
}

void fact(void)
{
	int l;

	memset(f, 0, sizeof(f));
	f[0][0] = f[1][0] = 1;

	l = 1;
	for (int i = 2; i <= 1000; i++) {
		l = mul(f[i - 1], i, l, f[i]);
		if (l >= 10100) {
			printf("Overflow\n");
			exit(0);
		}
	}
}

int main(void)
{
	int t;
	fact();

	while (scanf("%d", &t) != EOF) {
		int ans = 0;
		for (int i = 0; i < 10100; i++)
			ans += f[t][i];
		printf("%d\n", ans);
	}
	return 0;
}
