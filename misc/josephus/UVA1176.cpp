#include <bits/stdc++.h>

using namespace std;

int josephus(int n)
{
	int t, b = 0;
	t = n;
	b = -1;
	while (t) {
		b++;
		t >>= 1;
	}
	return ((n ^ (1 << b)) << 1) + 1;
}

int main(void)
{
	int n, suv, ans;

	while (scanf("%d", &n) != EOF) {
		ans = 0;
		suv = n;
		do {
			n = suv;
			suv = josephus(n);
			ans += n - suv;
		} while (n != suv);
		ans += 2 * suv;
		printf("%d\n", ans);
	}
	return 0;
}
