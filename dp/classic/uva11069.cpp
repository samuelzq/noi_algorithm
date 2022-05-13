/**
 * A Graph Problem UVA - 11069
 * https://vjudge.net/problem/UVA-11069
 *
 * @File:   uva11069.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-12
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int ans[100];

void init(void)
{
	ans[0] = ans[1] = 1;
	ans[2] = 2;
	for (int i = 3; i < 77; i++)
		ans[i] = ans[i - 2] + ans[i - 3];
}

int main(void)
{
	int t;
	init();
	while (scanf("%d", &t) != EOF)
		printf("%d\n", ans[t]);
	return 0;
}
