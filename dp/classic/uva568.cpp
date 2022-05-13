/**
 * Just the Facts UVA - 568
 * https://vjudge.net/problem/UVA-568
 *
 * @File:   uva568.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-11
 *
 **/
#include <bits/stdc++.h>

using namespace std;
int f[10010];

void init(void)
{
	long long t = 1;
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		t = t * i;
		while (t % 10 == 0)
			t /= 10;
		t %= 10000000;
		f[i] = t % 10;
	}
}

int main(void)
{
	int t;
	init();
	while (scanf("%d", &t) != EOF) {
		printf("%5d -> %d\n", t, f[t]);
	}
	return 0;
}
