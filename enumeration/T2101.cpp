// 本题检测全排列

#include <iostream>

using namespace std;

bool f = false;
int a, b, c;
int d[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void check(void)
{
	int x, y, z, k, l, m;
	x = 100 * d[0] + 10 * d[1] + d[2];
	y = 100 * d[3] + 10 * d[4] + d[5];
	z = 100 * d[6] + 10 * d[7] + d[8];
	k = a * x;
	l = b * y;
	m = c * z;

	if (k == l && l == m) {
		cout << x << ' ' << y << ' ' << z << '\n';
		f = true;
	}
}

void perm(int a[], int k, int n)
{
	if (k == n - 1) {
#if 0
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
#endif
		check();
		return;
	}

	for (int i = k; i < n; i++) {
		int t;
		t = a[k];
		a[k] = a[i];
		a[i] = t;
		perm(a, k + 1, n);
		t = a[k];
		a[k] = a[i];
		a[i] = t;
	}
}

int main(void)
{
	int p, l, m, n;
	l = 1;
	m = 2;
	n = 3;
	a = m * n;
	b = l * n;
	c = l * m;

	perm(d, 0, 9);

	if (f == false)
		cout << "No!!!";
	return 0;
}
