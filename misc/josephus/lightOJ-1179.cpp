#include <bits/stdc++.h>

using namespace std;

int joseph(int n, int m)
{
	int i;
	int x = 0;

	for (i = 2; i <= n; i++)
		x = (x + m) % i;
	return x;
}

int main(void)
{
	int n, t, k;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int x;
		scanf("%d %d", &n, &k);
		x = joseph(n, k) + 1;
		printf("Case %d: %d\n", i + 1, x);
	}
	return 0;
}
