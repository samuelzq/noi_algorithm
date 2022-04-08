/**
 * Network Connections UVA - 793
 * https://vjudge.net/problem/UVA-793
 *
 * 并查集。
 *
 * @File:   uva793.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-03
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
int p[N];
//queue<pair<int, int>> questions;

void initialize(void)
{
	for (int x = 0; x < N; x++)
		p[x] = x;
}

int find(int x)
{
	return x == p[x] ? x : (p[x] = find(p[x]));
	//return x == p[x] ? x : find(p[x]);
}

bool equivalence(int x, int y)
{
	return find(x) == find(y);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;
	p[x] = y;
}

int main(void)
{
	string str;
	stringstream ss;
	int t;

	getline(cin, str);
	ss << str;
	ss >> t;
	getline(cin, str);
	while (t--) {
		int n;
		initialize();
		getline(cin, str);
		ss.clear();
		ss << str;
		ss >> n;

		int s, us;
		s = us = 0;
		while (getline(cin, str) && str[0]) {
			int i, j;
			char op;
			ss.clear();
			ss << str;
			ss >> op >> i >> j;
			if (op == 'q') {
				if (equivalence(i, j))
				s++;
			else
				us++;
			}else
				merge(i, j);
		}
		cout << s << ',' << us << '\n';
		if (t != 0)
			cout << '\n';
	}
	return 0;
}