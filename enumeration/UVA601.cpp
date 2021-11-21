#include <bits/stdc++.h>

using namespace std;
const int N = 90;
const int MAXN = 0x3f3f3f3f;
char bd[N][N];
char vit[N][N];
int dd[4][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
int n;
int check(int x, int y, int wb)
{
	queue<pair<int, int>> mq;
	char c;
	int u, a, ans = MAXN;

	u = 0;

	if (bd[x][y] == 'U')
		u = 1;
	vit[x][y] = '-';

	if (wb == 1) {
		c = 'W';
		if (y == n)
			return u;
	} else {
		c = 'B';
		if (x == n)
			return u;
	}

	for (int i = 0; i < 4; i++) {
		int nx, ny;
		nx = x + dd[i][0];
		ny = y + dd[i][1];

		if (nx == 0 || nx > n || ny == 0 || ny > n || vit[nx][ny] == '-')
			continue;
		if (bd[nx][ny] == c)
			ans = min(ans, u + check(nx, ny, wb));
		else if (bd[nx][ny] == 'U')
			mq.push(pair<int, int>(nx, ny));
		else
			continue;
	}
	while (!mq.empty()) {
		pair<int, int> pix = mq.front();
		mq.pop();
		ans = min(ans, u + check(pix.first, pix.second, wb));
	}
	return ans;
}

int readi()
{
	char c;
	int n = 0;

	c = getchar();
	while (c < '0' || c > '9')
		c = getchar();

	do {
		n = n * 10 + (c - '0');
		c = getchar();
	} while (c > '0' && c < '9');
	return n;
}

int main()
{
	int ux, uy;
	while (1) {
		n = readi();
		if (!n)
			break;
		getchar();
		for (int i = 1; i <= n; i++)
			gets(bd[i] + 1);

		ux = uy = MAXN;
		for (int i = 1; i <= n; i++) {
			memset(vit, 0, sizeof(vit));
			if (bd[i][1] == 'B' || bd[i][2] == 'B')
				continue;
			ux = min(ux, check(i, 1, 1));
		}
		for (int i = 1; i <= n; i++) {
			memset(vit, 0, sizeof(vit));
			if (bd[1][i] == 'W' || bd[2][i] == 'W')
				continue;
			uy = min(uy, check(1, i, 0));
		}
		if (ux == 0)
			printf("White has a winning path.\n");
		else if (uy == 0)
			printf("Black has a winning path.\n");
		else if (ux == 1)
			printf("White can win in one move.\n");
		else if (uy == 1)
			printf("Black can win in one move.\n");
		else
			printf("There is no winning path.\n");
		getchar();
	}
	return 0;
}