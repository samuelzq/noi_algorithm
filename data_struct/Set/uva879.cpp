/**
 * Circuit Nets UVA - 879
 * https://vjudge.net/problem/UVA-879
 *
 * 并查集。
 *
 * @File:   uva879.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-03
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
int p[N];
int groups = 0;

void initialize(int n)
{
	for (int x = 0; x < N; x++) {
		p[x] = x;
	}

	groups = n;
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
	groups--;
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
		getline(cin, str);
		ss.clear();
		ss << str;
		ss >> n;
		initialize(n);

		while (getline(cin, str) && str[0]) {
			ss.clear();
			ss << str;
			int i, j;
			while (ss >> i >> j) {
				merge(i, j);
			}
		}
		cout << groups << '\n';
		if (t != 0)
			cout << '\n';
	}
	return 0;
}