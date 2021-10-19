#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int a[N];

int josephus(int a[], int n, int k, int pos, bool cc)
{
	int m, c;

	m = 0;
	c = pos;
	if (cc) {
		while (m < k - 1) {
			if (a[c++] == 0)
				m++;
			c %= n;
		}
		while (a[c] == 1) {
			c = (c + 1) % n;
		}
	//	printf("Deque %d\n", c);
		a[c] = 1;
		while (a[c] == 1) {
			c = (c + 1) % n;
		}
	} else {
		while (m < k - 1) {
			if (a[c--] == 0)
				m++;
			c = (c + n) % n;
		}
		while (a[c] == 1)
			c = (c - 1 + n) % n;
		a[c] = 1;
	//	printf("Deque %d\n", c);
		while (a[c] == 1)
			c = (c - 1 + n) % n;
	}
	return c;
}

int main(void)
{
	int n, k;

	while (scanf("%d %d", &n, &k) != EOF && n != 0 && k != 0) {
		int cnt, r, pos;
		memset(a, 0, sizeof(int) * (n + 2));
		pos = 0;
		cnt = 0;
		r = 0;
		while (cnt++ < n - 1) {
			if (r == 0) {
				pos = josephus(a, n, k, pos, true);
				r = 1;
			} else {
				pos = josephus(a, n, k, pos, false);
				r = 0;
			}
		}
		printf("%d\n", pos + 1);
	}
	return 0;
}
