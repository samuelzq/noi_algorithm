/**
 * Testing the CATCHER UVA - 231
 * https://vjudge.net/problem/UVA-231
 *
 * LIS数值递减
 *
 * @File:   uva231.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-06
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int LIS(vector<int> &a)
{
	int ans = 0;
	vector<int> c(a.size(), 1);

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] <= a[j]) {
				c[i] = max(c[j] + 1, c[i]);
			}
		}
	}

	for (int i = 0; i < c.size(); i++)
		ans = max(ans, c[i]);
	return ans;
}

int main(void)
{
	int b, cnt, k = 0;
	vector<int> a;

	cnt = 0;
	while (1) {
		cin >> b;
		if (b == -1) {
			cnt++;
			if (cnt == 2)
				break;
			if (k)
				cout << '\n';
			cout << "Test #" << ++k << ":\n";
			cout << "  maximum possible interceptions: " << LIS(a) << '\n';
			a.clear();
		} else {
			cnt = 0;
			a.push_back(b);
		}
	}
	return 0;
}
