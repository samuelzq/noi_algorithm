#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int N = 1e4+4;
const double EPS = 1e-5;
const double PI=acos(-1.0);
double v[N];

int main(void)
{
	int n, f, mx = 0;
	double l, r, m, tv = 0.0;

	scanf("%d %d", &n, &f);
	for (int i = 0; i < n; i++) {
		int r;
		scanf("%d", &r);
		v[i] = r * r * PI;
		if (mx < r)
			mx = r;
		tv += v[i];
	}
	f++;
	l = 0.0;
	r = mx * mx * PI;
	while (r - l >= EPS) {
		int p = 0;
		m = l + (r - l) / 2;
		for (int i = 0; i < n; i++) {
			p += v[i] /m;
		}
		if (p >= f)
			l = m;
		else
			r = m;
	}
	printf("%0.3lf\n", l);
	return 0;
}

