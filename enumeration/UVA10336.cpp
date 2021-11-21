#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
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
struct stats ss[26];
bool cmp(struct stats s1, struct stats s2)
{
	if (s1.cnt == s2.cnt)
		return s1.c < s2.c;
	return s1.cnt > s2.cnt;
}

void dfs(int x, int y)
{
	if (vis[y][x])
		return;
	vis[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int xx, yy;
		xx = x + adj[i][0];
		yy = y + adj[i][1];
		if (xx < 0 || xx >= w || yy < 0 || yy >= h)
			continue;
		if (room[yy][xx] == room[y][x])
			dfs(xx, yy);
	}
	room[y][x] = 0;
}

int main(void)
{
	int t;
	int k;
	scanf("%d", &t);
	for (int l = 1; l <= t; l++) {

		scanf("%d %d", &h, &w);
		k = 0;
		memset(vis, 0, sizeof(vis));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < h; i++)
			scanf("%s", room[i]);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (room[i][j]) {
					cnt[room[i][j] - 'a']++;
					dfs(j, i);
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i]) {
				ss[k].c = 'a' + i;
				ss[k].cnt = cnt[i];
				k++;
			}
		}
		sort(ss, ss + k, cmp);
		printf("World #%d\n", l);
		for (int i = 0; i < k; i++)
			printf("%c: %d\n", ss[i].c, ss[i].cnt);
	}
	return 0;
}