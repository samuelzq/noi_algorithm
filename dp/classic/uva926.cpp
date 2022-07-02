/**
 * Walking Around Wisely UVA - 926
 * https://vjudge.net/problem/UVA-926
 *
 * @File:   uva926.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-06-29
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 35;
char mp[N][N];
long long dp[N][N];

#define UP       1
#define LEFT     2
#define INACCESS (UP | LEFT)
#define ORIG     4

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		int x1, y1, x2, y2;
		int x, y;
		int b;

		cin >> x;
		y = x;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cin >> b;
		memset(mp, 0, sizeof(mp));
		memset(dp, 0, sizeof(dp));
		while (b--) {
			int x3, y3;
			char d;
			cin >> x3 >> y3 >> d;
			if (d == 'W')
				mp[x3][y3] |= UP;
			else if (d == 'S')
				mp[x3][y3] |= LEFT;
			else if (d == 'E')
				mp[x3 + 1][y3] |= UP;
			else if (d == 'N')
				mp[x3][y3 + 1] |= LEFT;
		}
		dp[x1][y1] = 1;
		mp[x1][y1] = ORIG;

		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				if (mp[i][j] == UP)
					dp[i][j] = dp[i][j - 1];
				else if (mp[i][j] == LEFT)
					dp[i][j] = dp[i - 1][j];
				else if (mp[i][j] == INACCESS)
					dp[i][j] = 0;
				else if (mp[i][j] != ORIG)
					dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
		cout << dp[x2][y2] << '\n';
	}
	return 0;
}
