/**
 * Forests UVA - 10227
 * https://vjudge.net/problem/UVA-10227
 *
 * 先将每个人的观点生成集合，然再统计成一个大的集合。
 *
 * @File:   uva10227.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-02
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 100;

set<int> pop[100];    // 每个人的观点
set<set<int>> ops;    // 所有人的观点

int main(void)
{
	int k;
	string str;
	stringstream ss;

	getline(cin, str);
	ss << str;
	ss >> k;
	getline(cin, str);
	while (k--) {
		int p, t;
		ss.clear();
		getline(cin, str);
		ss << str;
		ss >> p >> t;
		while (getline(cin, str) && str[0] != 0) {
			int i, j;
			ss.clear();
			ss << str;
			ss >> i >> j;
			pop[i].insert(j);
		}
		ops.clear();
		for (int i = 1; i <= p; i++) {
			ops.insert(pop[i]);
			pop[i].clear();
		}
		cout << ops.size() << '\n';
		if (k != 0)
			cout << '\n';
	}
	return 0;
}