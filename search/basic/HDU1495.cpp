#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int N = 105;
int v[N][N][N] = {0, };

struct node {
	int x, y, z, s;
	node(int a, int b, int c):x(a), y(b), z(c) {}
	node(int a, int b, int c, int s):x(a), y(b), z(c), s(s) {}
};

int a, b, c, ans;

bool ok(int x, int y, int z)
{
	if (x >= 0 && x <= a && y >= 0 && y <= b && z >= 0 && z <= c &&
		v[x][y][z] == 0)
		return true;
	return false;
}

bool bfs(void)
{
	queue<node> q;
	q.push(node(a, 0, 0));
	v[a][0][0] = 0;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		int x = now.x, y = now.y, z = now.z;
		if (x == a / 2 || y == a / 2 || z == a / 2) {
			ans = v[x][y][z];
			if (x && y && z) ans++;  //并不是已经有两杯都为k/2的情况
			return true;
		}
		// a->b
		int nx, ny, nz;  //局部变量，以免“引起误会”。
		nz = z;
		nx = max(0, x - (b - y));
		ny = a - nz - nx;
		if (ok(nx, ny, nz)) {
			q.push(node(nx, ny, nz));
			v[nx][ny][nz] = v[x][y][z] + 1;
		}

		// a->c
		ny = y;
		nx = max(0, x - (c - z));
		nz = a - ny - nx;
		if (ok(nx, ny, nz)) {
			q.push(node(nx, ny, nz));
			v[nx][ny][nz] = v[x][y][z] + 1;
		}
		// b->c
		nx = x;
		ny = max(0, y - (c - z));
		nz = a - nx - ny;
		if (ok(nx, ny, nz)) {
			q.push(node(nx, ny, nz));
			v[nx][ny][nz] = v[x][y][z] + 1;
		}
		// b->a
		nz = z;
		ny = max(0, y - (a - x));
		nx = a - ny - nz;
		if (ok(nx, ny, nz)) {
			q.push(node(nx, ny, nz));
			v[nx][ny][nz] = v[x][y][z] + 1;
		}
		// c->b
		nx = x;
		nz = max(0, z - (b - y));
		ny = a - nx - nz;
		if (ok(nx, ny, nz)) {
			q.push(node(nx, ny, nz));
			v[nx][ny][nz] = v[x][y][z] + 1;
		}
		// c->a
		ny = y;
		nz = max(0, z - (a - x));
		nx = a - ny - nz;
		if (ok(nx, ny, nz)) {
			q.push(node(nx, ny, nz));
			v[nx][ny][nz] = v[x][y][z] + 1;
		}
	}
	return false;
}

int main(void)
{
	while (cin >> a >> b >> c) {
		if (c == 0 && b == 0 && c == 0)
			break;
		memset(v, 0, sizeof(v));
		if (a % 2) {
			cout << "NO\n";
			continue;
		}
		if (bfs())
			cout << ans << '\n';
		else
			cout << "NO\n";
	}
	return 0;
}
