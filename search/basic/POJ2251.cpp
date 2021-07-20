#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

typedef struct {
	int x, y, z, t;
} COOR;

char maze[33][33][33] = {0, };
int  t[33][33][33] = {0, };
int  mv[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int l, r, c, sx, sy, sz;

void bfs(int x, int y, int z)
{
	COOR c;
	queue<COOR> mq;

	while (!mq.empty())
		mq.pop();
	c.x = x;
	c.y = y;
	c.z = z;
	c.t = 0;
	t[x][y][z] = 0;
	mq.push(c);

	while (!mq.empty()) {
		c = mq.front();
		mq.pop();

		if (maze[c.x][c.y][c.z] == 'E') {
			printf("Escaped in %d minute(s).\n", c.t);
			return;
		}

		for (int i = 0; i < 6; i++) {
			COOR d;
			d.x = c.x + mv[i][0];
			d.y = c.y + mv[i][1];
			d.z = c.z + mv[i][2];
			d.t = c.t + 1;

			if (maze[d.x][d.y][d.z] == '.' || maze[d.x][d.y][d.z] == 'E') {
				t[d.x][d.y][d.z] = t[c.x][c.y][c.z] + 1;
				if (maze[c.x][c.y][c.z] == '.')
					maze[c.x][c.y][c.z] = 'D';
				mq.push(d);
			}
		}
	}
	printf("Trapped!\n");
}

int main(void)
{
	while (cin >> l >> r >> c) {
		if (l == 0 && r == 0 && c == 0)
			break;
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				for (int k = 1; k <= c; k++) {
					cin >> maze[i][j][k];
					if (maze[i][j][k] == 'S') {
						sx = i;
						sy = j;
						sz = k;
					}
				}
			}
		}
		bfs(sx, sy, sz);

#if 0
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				printf("%s\n", &maze[i][j][1]);
			}
		}
#endif
	}
	return 0;
}
