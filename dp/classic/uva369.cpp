/**
 * Combinations UVA - 369
 * https://vjudge.net/problem/UVA-369
 *
 * a[i][j] = a[i-1][j-1] + a[i-1][j]
 *
 * @File:   uva369.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-02
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 105;
#define LL long long

LL a[N][N];

void init(void)
{
	for (int i = 0; i < N; i++) {
		a[0][i] = 0;
		a[i][0] = 1;
	}
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
}

int main(void)
{
	int n, m;

	init();
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			break;
		cout << n << " things taken " << m << " at a time is " << a[n][m] << " exactly.\n";
	}
	return 0;
}
