#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char buf[100005];

void check(char *str, int len)
{
	int i, j;
	for (i = 0, j = len - 1; i < j && str[i] == str[j]; i++, j--)
		;
	if (i > j)
		check(str, len / 2);
	else
		cout << len;
}

int main(void)
{
	int l;
	scanf("%s", buf);
	l = strlen(buf);
	check(buf, l);
	return 0;
}
