// 每一个'o'即孔代表1， ' '即空白代表0 '|'和'_'表示纸袋边界，
// '.'代表同步孔

#include <cstdio>

int main(void)
{
	char a, c;
	int i = 0;
	while ((c = getchar()) != EOF) {
		if (i == 8) {
			printf("%c", a);
			i = 0;
		} else {
			if (c == 'o') {
				a = a * 2 + 1;
				i++;
			} else if (c == ' ') {
				a = a * 2;
				i++;
			}
		}
	}
	return 0;
}