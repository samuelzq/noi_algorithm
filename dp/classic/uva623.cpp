/**
 * 500! UVA - 623
 * https://vjudge.net/problem/UVA-623
 *
 * 大数乘法
 *
 * @File:   uva623.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-11
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int ret[400];


int big_p(int a[], int b, int len)
{
	int c, i;
	c = 0;
	for (i = 0; i < len; i++) {
		int t = a[i] * b + c;
		if (t > MAXN) {
			c = t / MAXN;
			t = t % MAXN;
		} else {
			c = 0;
		}
		a[i] = t;
	}
	if (c)
		a[i++] = c;
	return i;
}

int factorial(int a)
{
	int l = 1;
	memset(ret, 0, sizeof(ret));
	ret[0] = 1;
	if (a != 0) {
		for (int i = 1; i <= a; i++)
			l = big_p(ret, i, l);
	}
	return l;
}

int main(void)
{
	int a;

	while (scanf("%d", &a) != EOF) {
		int n = factorial(a);
		printf("%d!\n", a);
		printf("%d", ret[n - 1]);

		// 需注意余下每一位的位宽
		for (int i = n - 2; i >= 0; i--)
			printf("%05d", ret[i]);
		printf("\n");
	}
}
