/**
 * Counting Rectangles UVA - 10502
 * https://vjudge.net/problem/UVA-10502
 *
 * 统计每一个格点左侧以及上侧所有可能的矩形数量。
 * 如果一个格点左侧可达最远距离为l，则可以有l个不同的矩形包含该格点。
 *
 * @File:   uva10502.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-06
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char mp[N][N];
int wl[N][N];
int h[N];

int main(void)
{
	int n, m, ans;

	while (cin >> n && n) {
		cin >> m;

		memset(mp, 0, sizeof(mp));
		memset(wl, 0, sizeof(wl));
		memset(h, 0, sizeof(h));

		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> mp[i][j];
				if (mp[i][j] == '1') {
					wl[i][j] = wl[i][j - 1] + 1;
  	 				// 首先统计面积为1的矩形数量
					ans += 1;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (mp[i][j] == '1')
					h[j] = h[j] + 1;
				else
					h[j] = 0;

				// 接下来统计面积大于1的矩形数量
				int l = wl[i][j];
				for (int k = 0; k < h[j]; k++) {
					l = min(l, wl[i - k][j]);
					ans += (l - 1);
				}
	 			// 补上宽度为1，竖直方向上矩阵的数量
				if (h[j] > 1)
					ans += h[j] - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
