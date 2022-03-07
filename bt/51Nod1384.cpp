/**
 * https://www.51nod.com/Challenge/Problem.html#problemId=1384
 * https://vjudge.net/problem/51Nod-1384
 *
 * @File:   51Nod1384.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;

char str[10];
int visit[10];
char bt[10];
int len;

void perm(int n)
{
	if (n == 0) {
		cout << bt << '\n';
		return;
	}

	for (int i = 0; i < len; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			bt[len - n] = str[i];
			perm(n - 1);
			visit[i] = 0;
			while (i < len - 1 && str[i] == str[i + 1])
				i++;
		}
	}
}

int main(void)
{
	while (cin >> str) {
		len = strlen(str);
		memset(bt, 0, sizeof(bt));
		sort(str, str + len);
		perm(len);
	}

	return 0;
}
