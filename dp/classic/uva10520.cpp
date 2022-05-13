/**
 * Determine it UVA - 10520
 * https://vjudge.net/problem/UVA-10520
 *
 * 按照题意之间从上到下递归即可。
 *
 * @File:   uva10520.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-13
 *
 **/
#include <bits/stdc++.h>
using namespace std;

long long a[25][25] = {0};
int n;

long long calc(int i, int j)
{
	if (a[i][j] != -1)
		return a[i][j];
	if (i < j) {
		long long m1 = 0;
		for (int k = i; k < j; k++)
			m1 = max(m1, calc(i, k) + calc(k + 1, j));
		return a[i][j] = m1;
	}

	long long m1 = 0, m2 = 0;
	if (i < n) {
		for (int k = i + 1; k <= n; k++)
			m1 = max(m1, calc(k, 1) + calc(k, j));
	}

	if (j > 0) {
		for (int k = 1; k < j; k++)
			m2 = max(m2, calc(i, k) + calc(n, k));
	}
	return a[i][j] = m1 + m2;
}

int main(void)
{
	int an1;
	while (cin >> n >> an1) {
		memset(a, -1, sizeof(a));
		a[n][1] = an1;
		a[1][n] = calc(1, n);
		cout << a[1][n] << endl;
	}
	return 0;
}
