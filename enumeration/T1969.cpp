#include <cstdio>

int main(void)
{
	int c, ans = 8;
	char r;

	scanf("%c%d", &r, &c);

	if (c - 2 < 1  || r - 2 < 'A')
			ans --;

	if (c - 2 < 1  || r - 1 < 'A')
			ans --;

	if (c - 2 < 1  || r + 1 > 'H')
			ans --;

	if (c - 2 < 1  || r + 2 > 'H')
			ans --;

	if (c + 1 > 8  || r - 1 < 'A')
			ans --;
	if (c + 2 > 8  || r - 2 < 'A')
			ans --;
	if (c + 1 > 8  || r + 1 > 'H')
			ans --;
	if (c + 2 > 8  || r + 2 > 'H')
			ans --;
	printf("%d", ans);
	return 0;
}
