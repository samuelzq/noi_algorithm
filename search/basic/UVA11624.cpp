#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;

struct node {
	int x, y, step;
	node(int x, int y, int step): x(x), y(y), step(step) {}
};

const int N = 1003;
char maze[N][N] = {0, };
int f[N][N] = {0, };
int v[N][N] = {0, };
int mov[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int r, c;

bool fire(int x, int y, int step)
{
	if (v[x][y])
		return true;
	if (f[x][y])
		return f[x][y] <= step + 1;
	else
		return false;
}

void bsf_f(void)
{
	node m(1, 1, 0);
	queue<node> q;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (maze[i][j] == 'F') {
				m.x = i;
				m.y = j;
				q.push(m);
				f[i][j] = 1;
			}
		}
	}

	while (q.size()) {
		m = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x, y;
			x = m.x + mov[i][0];
			y = m.y + mov[i][1];
			if (x < 1 || x > r || y < 1 || y > c)
				continue;
			else if (!f[x][y] && maze[x][y] != '#') {
				node d(x, y, 0);
				f[x][y] = f[m.x][m.y] + 1;
				q.push(d);
			}
		}

	}
}

void bsf(int x, int y)
{
	node m(x, y, 1);
	queue<node> q;

	v[x][y] = 1;
	q.push(m);

	while (q.size()) {
		int a, b, s;
		m = q.front();
		q.pop();
		if (m.x > r || m.y > c || m.x == 0 || m.y == 0) {
			cout << m.step - 1 << '\n';
			return;
		}
		a = m.x;
		b = m.y;
		s = m.step;
		m.step = s + 1;
		m.x = a - 1;
		if (!fire(m.x, m.y, s) && maze[m.x][m.y] == '.') {
			v[m.x][m.y] = 1;
			q.push(m);
		}
		m.x = a + 1;
		if (!fire(m.x, m.y, s) && maze[m.x][m.y] == '.') {
			v[m.x][m.y] = 1;
			q.push(m);
		}
		m.x = a;
		m.y = b - 1;
		if (!fire(m.x, m.y, s) && maze[m.x][m.y] == '.') {
			v[m.x][m.y] = 1;
			q.push(m);
		}
		m.y = b + 1;
		if (!fire(m.x, m.y, s) && maze[m.x][m.y] == '.') {
			v[m.x][m.y] = 1;
			q.push(m);
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main(void)
{
	char ch;
	int n, jx, jy;
	cin >> n;
#if DEBUG==1
	ofstream out("out.txt");
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
#endif
	while (n--) {
		memset(maze, '.', sizeof(maze));
		memset(f, 0, sizeof(f));
		memset(v, 0, sizeof(f));
		cin >> r >> c;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cin >> maze[i][j];
				if (maze[i][j] == 'J') {
					jx = i;
					jy = j;
				}
			}
		}

		bsf_f();
		bsf(jx, jy);
	}
#if DEBUG==1
	cout << endl;
	cout.rdbuf(coutbuf);
#endif
	return 0;
}
