#include <bits/stdc++.h>

using namespace std;

int josephus(int n)
{
	int b, t = n;
	b = -1;

	while (t) {
		b++;
		t >>= 1;
	}
	return ((n ^ (1 << b)) << 1) + 1;
}

int main(void)
{
	int t;

	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int suv, n, c = -1;
		scanf("%d", &n);
		suv = n;
		do {
			c++;
			n = suv;
			suv = josephus(n);
		} while (suv != n);
		printf("Case %d: %d %d\n", i, c, suv);
	}
	return 0;
}
