/**
 * Largest Submatrix UVA - 836
 * https://vjudge.net/problem/UVA-836
 *
 * 两种算法：
 * 1、求最大的矩形面积；
 * 2、求2维最大子集和。统计连续的k行中，1重复的次数。
 *
 * @File:   uva836.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-30
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int max1D(vector<int> &s)
{
	int sum = 0, ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 0)
			sum = 0;
		else
			sum += s[i];

		ans = max(ans, sum);
	}
	return ans;
}

int max2D(vector<string> &ss)
{
	int sum = 0, ans = 0;
	vector<int> s(ss[0].length());
	vector<int> c(ss[0].length());

	for (int i  = 0; i < ss.size(); i++) {
		fill(s.begin(), s.end(), 1);
		for (int j = i; j < ss.size(); j++) {
			// 首先统计从j行到i行之间，1连续的次数。
			for (int k = 0; k < s.size(); k++) {
				s[k] &= ss[j][k];
				c[k] = s[k] * (j - i + 1);
			}
			ans = max(ans, max1D(c));
		}
	}
	return ans;
}

int main(void)
{
	int n;
	string s;
	vector<string> ss;

	getline(cin, s);
	stringstream sm(s);
	sm >> n;
	while (n--) {
		int l;
		ss.clear();
		s.clear();
		while (s.length() == 0)
			getline(cin, s);
		ss.push_back(s);
		l = s.length();
		for (int i = 1; i < l; i++) {
			getline(cin, s);
			ss.push_back(s);
		}
		cout << max2D(ss) << '\n';
		if (n)
			cout << '\n';
	}
	return 0;
}
