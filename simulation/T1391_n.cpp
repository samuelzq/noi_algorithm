#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int n, ans;
	scanf("%d", &n);
	ans = n - (n / 3 + n / 5 + n / 7) + 2 * (n / 15 + n / 21 + n / 35) - (n / 105) * 4;
	printf("%d", ans);
	return 0;
}
