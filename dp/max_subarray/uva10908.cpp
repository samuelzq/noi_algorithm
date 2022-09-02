/**
 * Largest Square UVA - 10908
 * https://vjudge.net/problem/UVA-10908
 *
 * 首先计算每个位置左边最长距离。然后检测[a-j, b+j]到[a+j, b+j]区间内，所有位置的字符以及向左的距离。
 * 注意j的取值范围。
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
	char a, b, c, d;
	memset(side, 0, sizeof(side));
	s = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == board[i][j - 1])
				side[i][j] = side[i][j - 1] + 1;
			else
				side[i][j] = 1;
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
			int ans = 1;
			for (int j = 1; j < n || j < m; j++) {
				if (a - j<= 0 || b - j <= 0 || a + j > n || b + j > m)
					break;
				int flag = 1;
				for (int k = a - j; k <= a + j; k++) {
					if (board[k][b+j] != board[a][b] || side[k][b+j] < 1+j+j) {
						flag = 0;
						break;
					}
				}
				if (flag)
					ans = 2 * j + 1;
				else
					break;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
