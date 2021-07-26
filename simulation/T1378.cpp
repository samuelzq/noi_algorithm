#include <cstdlib>
#include <cstdio>

int main(void)
{
	int n;
	int t, y, m, d;
	char dum[6];

	scanf("%d", &n);
	while (n--) {
		scanf("%6d%4d%2d%2d%4c", &t, &y, &m, &d, dum);
		printf("%04d-%02d-%02d\n", y, m, d);
	}
	return 0;
}
