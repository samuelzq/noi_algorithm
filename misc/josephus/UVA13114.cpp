#include <bits/stdc++.h>

using namespace std;
const int N = 104;
int ans[N];

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
	return f + 1;
}

int main(void)
{
	int n;

	memset(ans, 0x3f, sizeof(ans));
	for (int i = 1; i <= 1000; i++) {
		int j = josephus(100, i);

		ans[j] = min(i, ans[j]);
	}

	while (scanf("%d", &n) != EOF && n) {
		printf("%d\n", ans[n]);
	}
	return 0;
}
