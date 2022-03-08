/**
 * https://nanti.jisuanke.com/t/139
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-139
 *
 * @File:   T139.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;
int a[11] = {0};
char b[11];
char c[12];
string s;
int l;
int fst = 1;

void dfs(int n)
{
	int j = 0;
	if (n == 0) {
		if (fst != 1)
			printf(" %s", b);
		else
			printf("%s", b);
		fst = 0;
		return;
	}

	for (int i = 0; i < l; i++) {
		if(a[i] == 1)
			continue;
		if(c[i] == j)
			continue;

		a[i] = 1;
		j = b[l-n] = c[i];
		dfs(n-1);
		a[i] = 0;
	}
}

int main()
{
	scanf("%s",c);
	l = strlen(c) - 1;
	sort(c, c+l);
	dfs(l);
	printf("\n");
	return 0;
}
