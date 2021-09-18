#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double ESP = 1e-5;

int main(void)
{
	int x, y, n;
	double l, r, mid, p, t;

	scanf("%d %d %d", &x, &y, &n);
	l = 0.0;
	r = 10.0;

	while (r - l >= ESP) {
		mid = l + (r - l) / 2;
		p = 1 + mid;
		t = 0.0;
		for (int i = 0; i < n; i++) {
			t += 1 / p;
			p = p * (1 + mid);
		}
		t = t * y;

		if (t >= x)
			l = mid;
		else
			r = mid;
	}
	printf("%.1lf", mid * 100);
	return 0;
}
