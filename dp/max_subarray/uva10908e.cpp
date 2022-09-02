/**
 * Largest Square UVA - 10908
 * https://vjudge.net/problem/UVA-10908
 *
 * 首先统计以每个坐标点为右下角的正方形变长。
 * 然后遍历所有可能的正方形，直到找到最大值。
 *
 * @File:   uva10908.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-08
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 102;
char board[N][N];
int side[N][N];
int n, m;

void largest_side(void)
{
	int s;
	memset(side, 0, sizeof(side));
	s = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
#if 1   // 此处有两种计算最大正方形的方法
			char a, b, c, d;
			a = board[i - 1][j];
			b = board[i][j - 1];
			c = board[i - 1][j - 1];
			d = board[i][j];
			if (a == d && b == d && c == d)
				side[i][j] = min(side[i-1][j], min(
						side[i][j - 1],
						side[i - 1][j - 1])) + 1;
			else
				side[i][j] = 1;
#else
			if (board[i][j] != board[i - 1][j] || board[i][j] != board[i][j - 1])
				side[i][j] = 1;
			else {
				side[i][j] = 1 + min(side[i][j - 1], side[i - 1][j]);
				int t = side[i][j];
				if (board[i][j] != board[i - t + 1][j - t + 1])
					side[i][j]--;
			}
#endif
		}
	}
}

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		int q;
		cin >> n >> m >> q;
		memset(board, 0, sizeof(board));
		getchar();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				board[i][j] = getchar();
			getchar();
		}

		largest_side();
		cout << n << ' ' << m << ' ' << q << '\n';
		while (q--) {
			char c;
			int a, b, s;
			cin >> a >> b;
			a++;
			b++;
			c = board[a][b];
			s = side[a][b];
			int ro, co, ans = 1, i = 1;
			ro = b;
			co = a;
			while (1) {
				if (ro > m || co > n)
					break;
				if (c != board[a][b])
					break;
				if (side[co][ro] < 2 * i - 1)
					break;
				ans = 2 * i - 1;
				ro++;
				co++;
				i++;
			}

			cout << ans << '\n';
		}
	}
	return 0;
}
