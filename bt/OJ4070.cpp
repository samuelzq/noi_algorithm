/**
 * http://bailian.openjudge.cn/practice/4070?lang=en_US
 * https://vjudge.net/problem/OpenJ_Bailian-4070
 *
 * @File:   OJ4070.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-07
 *
 **/

#include <bits/stdc++.h>

using namespace std;
int visit[8];
int num[8];
int n;

void p(int m)
{
	if (!m) {
		for (int i = 0; i < n - 1; i++)
			cout << num[i] << ' ';
		cout << num[n - 1] << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			num[n - m] = i + 1;
			p(m - 1);
			visit[i] = 0;
		}
	}
}
int main(void)
{
	while (cin >> n && n) {
		p(n);
	}
	return 0;
}
