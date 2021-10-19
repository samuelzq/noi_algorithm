#include <bits/stdc++.h>

using namespace std;

int josephus(int n, int k)
{
	int f = 0;

	for (int i = 2; i <= n; i++) {
		if (f == 0)
			f = k % i;
		else if (f <= k - 1)
			f = (k - 1 - f) % i;
		else if (f > k - 1)
			f = ((i - 1 + k) - f) % i;
	}
	return f;
}

int main(void)
{
	int n, k;

	while (scanf("%d %d", &n, &k) != EOF && n && k) {
		printf("%d\n", josephus(n, k) + 1);
	}
	return 0;
}
