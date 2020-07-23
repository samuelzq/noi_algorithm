// Euclidean algorithm


// recursive
int regcd(int a, int b)
{
	if (b == 0)
		return a;
	return regcd(b, a % b);
}

// iteration
int itgcd(int a, int b)
{
	while (b != 0) {
		int i = b;
		b = a % b;
		a = i;
	}
	return a;
}

// extended euclid
int re_exgcd(int a, int b, int &x, int &y)
{
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int r = re_exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return r;
}

int it_exgcd(int m, int n, int &x, int &y)
{
	if (n == 0) {
		x = 1;
		y = 0;
		return m;
	}
	int a, a1, b, b1, c, d, q, r, t;
	a1 = b = 1;
	a = b1 = 0;
	c = m; d = n;

	q = c/d;
	r = c%d;
	while (r) {
		c = d;
		d = r;
		t = a1;
		a1 = a;
		a = t - q * a;
		t = b1;
		b1 = b;
		b = t - q * b;
		q = c/d;
		r = c%d;
	}
	x = a;
	y = b;
	return d;
}

#include <iostream>

using namespace std;
int main(void)
{
	int x, y;
	it_exgcd(1398, 324, x, y);
	cout << x << ' ' << y << endl;
	return 0;
}
