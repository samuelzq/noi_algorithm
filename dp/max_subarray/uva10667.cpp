/**
 * Largest Block UVA - 10667
 * https://vjudge.net/problem/UVA-10667
 *
 * 求地图内最大的矩形。
 * 依次计算当每一个格点作为矩形右下角时可以获得的最大矩形面积。
 * 由于矩形是等高线组成的区域，因此类似字符串匹配可使用堆栈，在一段连续的区间内找寻等高区间。
 * 依次检测每一个位置可以到达的高度。高度增加时则压栈，降低时则计算矩形面积并出栈。
 * 
 * @File:   uva10667.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 102;

int board[N][N];
int h[N];

int larget_area(int n, int m)
{
	int area = 0;
	stack<pair<int, int>> hh;
	memset(h, 0, sizeof(h));
	for (int i = 1; i <= n; i++) {
		int w = 0;
		for (int j = 1; j <= m; j++) {
			if (!board[i][j])
				h[j] = h[j] + 1;
			else
				h[j] = 0;

			pair<int, int> t(h[j], j);
			pair<int, int> tmp;
			bool ps = true;
			while (!hh.empty()) {
				tmp = hh.top();
				if (tmp.first < h[j]) // 当前高度较前一个大，则入栈
					break;
				else if (tmp.first == h[j]) {
					// 当前高度和栈顶相同，说明可以向右组成更大的矩形。该位置的高度不需要重复入栈。  
					ps = false;
					area = max(area, (j - tmp.second + 1) * h[j]);
					break;
				} else { // 遇到较低的高度，将前面高于本高度的记录出栈，并计算可以组成的矩形面积。			  	   	
					area = max(area, (j - tmp.second) * tmp.first);
					t.second = tmp.second; // 此时需以当前高度更新前面第一个超过当前高度的记录，这样才能够保存矩形的连续
					hh.pop();
				}
			}

			if (!t.first)
				continue;

			if (t.second == tmp.second)
				area = max(area, (j - tmp.second + 1) * h[j]);
			if (ps)
				hh.push(t);
		}
		if (!hh.empty()) { // 尾部有递增区间
			stack<pair<int, int>> s;
			w = n;
			while (!hh.empty()) {
				s.push(hh.top());
				hh.pop();
			}

			while (!s.empty()) {
				pair<int, int> tmp;
				tmp = s.top();
				area = max(area, (w - tmp.second + 1) * tmp.first);
				s.pop();
			}
		}
	}
	return area;
}

int main(void)
{
	int p;

	cin >> p;
	while (p--) {
		int s, n;
		cin >> s >> n;
		memset(board, 0, sizeof(board));

		while (n--) {
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			for (int i = r1; i <= r2; i++)
				for (int j = c1; j <= c2; j++)
					board[i][j] = 1;
		}
		cout << larget_area(s, s) << '\n';
	}
	return 0;
}
