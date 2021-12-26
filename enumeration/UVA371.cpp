#include <bits/stdc++.h>

using namespace std;

inline long long collatz(long long x, long long y, long long &xx)
{
	long long steps;

	steps = 0;
	xx = x;
	for (long long i = (x < y / 2) ? y / 2 : x; i <= y; i++) {
		long long s = 0, n;
		n = i;
		do {
			if (n & 1)
				n = n * 3 + 1;
			else
				n /= 2;
			s++;
		} while (n > 1);
		if (s > steps) {
			steps = s;
			xx = i;
		}
	}
	return steps;
}

int main(void)
{
	long long a, b;
	while (scanf("%lld%lld", &a, &b)) {
		if (!a && !b)
			break;
		long long s, x, y, maxx;
		if (a > b) {
			x = b;
			y = a;
		} else {
			x = a;
			y = b;
		}
		s = collatz(x, y, maxx);
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",
			   x, y, maxx, s);
	}
	return 0;
}