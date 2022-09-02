/**
 * Maximum Sum UVA - 108
 * https://vjudge.net/problem/UVA-108
 *
 * 依次将合并相邻的行。求合并后每一行中的最大的连续区间和。
 *
 * @File:   uva108.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-30
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 102;
int a[N][N];

int max1D(int a[], int l)
{
	int ans = -1e9;
	int s = 0;

	for (int i = 0; i < l; ++i) {
		if (s >= 0)
			s += a[i];
		else
			s = a[i];
		ans = max(ans, s);
	}
	return ans;
}

int max2D(int a[][N], int c, int r)
{
	int ans = -1e9;
	int s[N];

	for (int i = 0; i < c; ++i) {
		memset(s, 0, sizeof(s));
		for (int j = i; j < c; ++j) {
			for (int k = 0; k < r; ++k)
				s[k] += a[j][k];
				ans = max(ans, max1D(s, r));
		}
	}
	return ans;
}

int main(void)
{
	int n;

	while (cin >> n) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		cout << max2D(a, n, n) << '\n';
	}
	return 0;
}
