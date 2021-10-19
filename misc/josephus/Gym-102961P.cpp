#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N];

int main(void)
{
	int n, b, p, i, j;

	scanf("%d", &n);

	if (n == 1) {
		printf("%d\n", 1);
		return 0;
	}

	b = 0;
	j = 0;
	printf("%d", 2);
	i = 2;
	a[i] = 1;
	p = 0;
	j = 1;
	while (j < n) {
		for (; i <= n; i++) {
			if (a[i] == 0)
				p++;

			if (p == 2) {
				a[i] = 1;
				printf(" %d", i);
				j++;
				p = 0;
			}
		}
		i %= n;
	}
	printf("\n");
	return 0;
}
