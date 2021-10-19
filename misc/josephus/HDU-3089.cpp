#include <bits/stdc++.h>

using namespace std;

long long joseph(long long n, long long m)
{
	long long i;
	long long x = 0;

	if (m == 1)
		return n - 1;

	for (i = 2; i <= n;) {
		if (x + m < i) {
			long long tmp = (i - 1 - x) % (m - 1) ? (i - 1 - x) / (m - 1) : (i - 1 - x) / (m - 1) - 1;

			if (i + tmp > n) {
				x += (n - i + 1) * m;
				break;
			}
			x += tmp * m;
			i += tmp;
		} else {
			x = (x + m) % i;
			i++;
		}
	}
	return x;
}

int main(void)
{
	long long n, k;

	while (scanf("%lld %lld", &n, &k) != EOF) {
		long long x;
		x = joseph(n, k) + 1;
		printf("%lld\n", x);
	}
	return 0;
}
