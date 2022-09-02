/**
 * Maximum sum on a torus UVA - 10827
 * https://vjudge.net/problem/UVA-10827
 *
 * 将二维的数组压缩成一维，然后求一维中的最大连续子集。
 * 本题需要考虑到队列的环绕。
 *
 * @File:   uva10827.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-31
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 80;
int aa[N][N];
int ss[N];

int max1D(int a[], int len)
{
	int sum = 0, ans = -0x3f3f3f;
	for (int i = 0; i < len; i++) {
		sum = 0;
		for (int j = i; j < len + i; j++) {
			int k = j;
			if (j >= len)
				k -= len;
			if (sum > 0)
				sum += a[k];
			else
				sum = a[k];
			ans = max(ans, sum);
		}
	}
	return ans;
}

int max2D(int a[][N], int c, int r)
{
	int ans = -0x3f3f3f3f;
	for (int i = 0; i < c; i++) {
		memset(ss, 0, sizeof(ss));
		for (int j = 0, st = i; j < c; j++, st++) {
			if (st == c)
				st = 0;
			for (int l = 0; l < r; l++)
				ss[l] += a[st][l];
			ans = max(ans, max1D(ss, r));
		}
	}
	return ans;
}

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> aa[i][j];

		cout << max2D(aa, n, n) << '\n';
	}
	return 0;
}
