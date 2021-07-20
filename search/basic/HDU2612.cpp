#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

const int N = 205;
int v1[N][N];
int v2[N][N];
char map[N][N];
int mv[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, kfc = 0;

void bfs(int x, int y, int v[N][N])
{
	queue<pair<int, int>> q;
	pair<int, int> p(x, y);
	q.push(p);
	v[x][y] = 1;

	while (q.size()) {
		p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx, ny;
			nx = p.first + mv[i][0];
			ny = p.second + mv[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if (map[nx][ny] != '#') {
				if (!v[nx][ny]) {
					v[nx][ny] = v[p.first][p.second] + 1;
					q.push(pair<int, int>(nx, ny));
				} else {
					if (v[p.first][p.second] + 1 < v[nx][ny])
						v[nx][ny] = v[p.first][p.second] + 1;
				}
			}
		}
	}
}

int main(void)
{
	int x1, y1, x2, y2, t, ans = 0x7fffffff;
	while (cin >> n >> m) {
		memset(map, '#', sizeof(map));
		memset(v1, 0, sizeof(v1));
		memset(v2, 0, sizeof(v2));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'Y') {
					x1 = i;
					y1 = j;
				}
				if (map[i][j] == 'M') {
					x2 = i;
					y2 = j;
				}
				if (map[i][j] == '@')
					kfc++;
			}
		}
		bfs(x1, y1, v1);
		bfs(x2, y2, v2);
		ans = 0x7fffffff;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == '@' && v1[i][j] && v2[i][j]) {
					t = v1[i][j] + v2[i][j];
					if (t < ans)
						ans = t;
				}
			}
		}
		cout << (ans - 2) * 11 << '\n';
	}
}
