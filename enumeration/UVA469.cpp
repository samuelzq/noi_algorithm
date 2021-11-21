#include <bits/stdc++.h>

using namespace std;

const int N = 100;
char mp[N][N];
char s[N];
int cnt[N][N];
int dd[8][2] = {
	{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}
};
int xx, yy, ans;

void check(int x, int y, int c)
{
	if (x < 0 || x >= xx || y < 0 || y >= yy)
		return;

	if (mp[x][y] != 'W' || cnt[x][y] == c)
		return;

	ans++;
	cnt[x][y] = c;
	for (int i = 0; i < 8; i++) {
		int dx, dy;
		dx = x + dd[i][0];
		dy = y + dd[i][1];
		check(dx, dy, c);
	}
}

int main(void)
{
	int t, c;
	int x, y, i;
	scanf("%d", &t);
	getchar();
	getchar();
	c = 0;
	while (--t) {

		i = 0;
		while (gets(s) && strlen(s) > 0) {
			if (s[0] == 'L' || s[0] == 'W') {
				strcpy(mp[i++], s);
				yy = strlen(s);
				xx = i;
			} else {
				i = 0;
				sscanf(s, "%d %d", &x, &y);
				ans = 0;
				check(x - 1, y - 1, ++c);
				printf("%d\n", ans);
			}
		}
		printf("\n");
	}
	i = 0;
	while (gets(s) && strlen(s) > 0) {
		if (s[0] == 'L' || s[0] == 'W') {
			strcpy(mp[i++], s);
			yy = strlen(s);
			xx = i;
		} else {
			i = 0;
			sscanf(s, "%d %d", &x, &y);
			ans = 0;
			check(x - 1, y - 1, ++c);
			printf("%d\n", ans);
		}
	}
	return 0;
}