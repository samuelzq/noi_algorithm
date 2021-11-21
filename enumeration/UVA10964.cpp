#include <bits/stdc++.h>

using namespace std;

const int N = 51;
char room[N][N];
int vis[N][N];
char c[26];
int cnt[26];
int h, w;
int adj[4][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
struct stats {
	int cnt;
	char c;
};
struct stats ss[N*N];
bool cmp(struct stats s1, struct stats s2)
{
	if (s1.cnt == s2.cnt)
		return s1.c < s2.c;
	return s1.cnt > s2.cnt;
}

int dfs(int x, int y)
{
	int ans = 1;
	if (vis[y][x])
		return 0;
	vis[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int xx, yy;
		xx = x + adj[i][0];
		yy = y + adj[i][1];
		if (xx < 0 || xx >= w || yy < 0 || yy >= h)
			continue;
		if (room[yy][xx] == room[y][x])
			ans += dfs(xx, yy);
	}
	room[y][x] = '.';
	return ans;
}

int main(void)
{
	int t;
	int k, l;
	l = 0;
	while (scanf("%d %d", &h, &w) && h && w) {
		l++;
		k = 0;
		memset(vis, 0, sizeof(vis));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < h; i++)
			scanf("%s", room[i]);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (room[i][j] != '.') {
					ss[k].c = room[i][j];
					ss[k].cnt = dfs(j, i);
					k++;
				}
			}
		}

		sort(ss, ss + k, cmp);
		printf("Problem %d:\n", l);
		for (int i = 0; i < k; i++)
			printf("%c %d\n", ss[i].c, ss[i].cnt);
	}
	return 0;
}