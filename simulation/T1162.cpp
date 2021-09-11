#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int v1[105][105];
int v2[105][105];
int (*v)[105];

void c90(int &m, int &n)
{
	int i, j;
	int (* vb)[105];
	unsigned char t;

	if (v == v1)
		vb = v2;
	else
		vb = v1;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			vb[j][m - i - 1] = v[i][j];
		}
	}
	i = m;
	m = n;
	n = i;
	v = vb;
}

void r90(int &m, int &n)
{
	int i, j;
	unsigned char t;
	int (* vb)[105];

	if (v == v1)
		vb = v2;
	else
		vb = v1;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			vb[n - 1 - j][i] = v[i][j];
		}
	}
	i = m;
	m = n;
	n = i;
	v = vb;
}

void rl(int m, int n)
{
	unsigned char t;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n / 2; j++) {
			t = v[i][j];
			v[i][j] = v[i][n - 1 - j];
			v[i][n - 1 - j] = t;
		}
}

void ud(int m, int n)
{
	unsigned char t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m / 2; j++) {
			t = v[j][i];
			v[j][i] = v[m - 1 - j][i];
			v[m - 1 - j][i] = t;
		}
}

int main(void)
{
	int m, n, i, j;
	char op;

	cin >> m >> n;
	v = v1;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			cin >> v[i][j];

	while (cin.get(op) && op != EOF) {
		if (op == 'A')
			c90(m, n);
		else if (op == 'B')
			r90(m, n);
		else if (op == 'C')
			rl(m, n);
		else if (op == 'D')
			ud(m, n);
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
