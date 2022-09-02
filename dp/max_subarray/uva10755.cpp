/**
 * Garbage Heap UVA - 10755
 * https://vjudge.net/problem/UVA-10755
 *
 * 先将3D压缩成2D，再压缩成1D，然后求最大连续子集和。
 *
 * @File:   uva10755.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-31
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 21;
const long long minN = -0x7ffffffffff;
long long g[N][N][N];
long long m[N][N];
long long  s[N];

long long max1D(long long a[], int len)
{
	long long ans = minN, sum = 0;

	for (int i = 0; i < len; i++) {
		if (sum > 0)
			sum += a[i];
		else
			sum = a[i];
		ans = max(ans, sum);
	}
	return ans;
}

long long max2D(long long a[][N], int c, int r)
{
	long long ans = minN;

	for (int i = 0; i < c; i++) {
		memset(s, 0, sizeof(s));
		for (int j = i; j < c; j++) {
			for (int k = 0; k < r; k++)
				s[k] += a[j][k];
			ans = max(ans, max1D(s, r));
		}
	}
	return ans;
}

long long max3D(long long a[][N][N], int h, int c, int r)
{
	long long ans = minN;

	for (int i = 0; i < h; i++) {
		memset(m, 0, sizeof(m));
		for (int j = i; j < h; j++) {
			for (int k = 0; k < c; k++)
				for (int l = 0; l < r; l++)
					m[k][l] += a[j][k][l];
			ans = max(ans, max2D(m, c, r));
		}
	}
	return ans;
}

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		int l, w, h;

		cin >> l >> w >> h;
		for (int i = 0; i < l; i++)
			for (int j = 0; j < w; j++)
				for (int k = 0; k < h; k++)
					cin >> g[i][j][k];
		cout << max3D(g, l, w, h) << '\n';
		if (t)
			cout << '\n';
	}
	return 0;
}
