#include <cstdio>
#include <cstring>

char str[2005];

int main(void)
{
	int t;

	scanf("%d", &t);

	while (t--) {
		int j, i;
		scanf("%s", str);
		i = strlen(str) - 1;
		while(i) {
			j = i;
			if (str[i] == ',') {
				printf("%s,", str + i + 1);
				str[i] = 0;
			}
			i--;
		}
		printf("%s\n", str);
	}
	return 0;
}
