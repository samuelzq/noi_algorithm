/**
 * Take the Land UVA - 10074
 * https://vjudge.net/problem/UVA-10074
 * 
 * max subarray基础题。
 * 将地图横向分割。穷举每条地带上每个坐标左右可以到达的距离，
 * 接着从此坐标向上延伸直到无法继续为止，然后在上边界检测左右
 * 边界。
 *
 * @File:   uva10074.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-05
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 103;

int mp[N][N];
int wl[N];   // 每一横带内各坐标往左可延伸的長度
int wr[N];   // 每一横带内各坐标往右可延伸的長度

int h[N];    // 每一横带内各坐标往上可延伸的高度

// 注意：以下两个数组记录的是截至到当前行的纵向最小值
int l[N];    // 矩形往上延伸到底后，往左可延伸的距離。
int r[N];    // 矩形往上延伸到底后，往右可延伸的距離。

int largest_area(int m, int n)
{
	int max_area = 0;
	memset(wl, 0, sizeof(wl));
	memset(wr, 0, sizeof(wr));
	memset(h, 0, sizeof(h));
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	for (int i = 1; i <= m; i++) {
		// 首先计算当前点位，左右可极范围
		for (int j = 1; j <= n; j++) {
			if (!mp[i][j])
				wl[j] = wl[j - 1] + 1;
			else
				wl[j] = 0;
		}

		for (int j = n; j > 0; j--) {
			if (!mp[i][j])
				wr[j] = wr[j + 1] + 1;
			else
				wr[j] = 0;
		}

		// 接着计算向上可达到的高度
		for (int j = 1; j <= n; j++) {
			if (!mp[i][j])
				h[j] = h[j] + 1;
			else
				h[j] = 0;
		}

		// 最后更新纵向左右可及范围
		for (int j = 1; j <= n; j++) {
			if (l[j] == 0)
				l[j] = wl[j];
			else
				l[j] = min(l[j], wl[j]);
		}

		for (int j = 1; j <= n; j++) {
			if (r[j] == 0)
				r[j] = wr[j];
			else
				r[j] = min(r[j], wr[j]);
		}

		// 遍历当前行每个点位可得到的矩形面积
		for (int j = 1; j <= n; j++)
			max_area = max(max_area, (l[j] + r[j] - 1) * h[j]);
	}
	return max_area;
}

int largest_area2(int m, int n)
{
	int max_area = 0;
	stack<pair<int, int>> hh;
	memset(h, 0, sizeof(h));

	for (int i = 1; i <= m; i++) {
		// 接着计算向上可达到的高度
		for (int j = 1; j <= n; j++) {
			if (!mp[i][j])
				h[j] = h[j] + 1;
			else
				h[j] = 0;
		}
		for (int j = 1; j <= n; j++) {
			int l = 0;
			bool ps;
			pair<int, int> t;
			t.first = h[j];
			t.second = j;
			max_area = max(max_area, h[j]);

			ps = true;
			l = 0;
			while (!hh.empty()) {
				pair<int, int> tmp;
				tmp = hh.top();
				if (tmp.first == h[j]) {
					max_area = max(max_area, (j - tmp.second + 1) * h[j]);
					ps = false;
					l = 0;
					break;
				} else if (tmp.first > h[j]) {
					max_area = max(max_area, (j - tmp.second) * tmp.first);
					hh.pop();
					l = tmp.second;
				} else {
					break;
				}
			}

			if (l) {
				pair<int, int> tmp;
				tmp.first = h[j];
				tmp.second = l;
				hh.push(tmp);
				max_area = max(max_area, (j - l + 1) * h[j]);
			} else if (ps == true)
				hh.push(t);
		}

		int w = 0;
		if (!hh.empty())
			w = hh.top().second;

		stack<pair<int, int>> s;
		while (!hh.empty()) {
			s.push(hh.top());
			hh.pop();
		}

		while (!s.empty()) {
			pair<int, int> tmp = s.top();
			max_area = max(max_area, (w - tmp.second + 1) * tmp.first);
			s.pop();
		}
	}
	return max_area;
}

int main(void)
{
	int n, m;

	while (cin >> m >> n) {
		if (m == 0 && n == 0)
			break;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				cin >> mp[i][j];

		cout << largest_area2(m, n) << '\n';
	}
	return 0;
}
