/**
 * https://vjudge.net/problem/UVA-598
 *
 * 在基础子集查找算法的基础上增加一个参数来控制子集的大小。
 *
 * @File:   uva598.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-01
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int used;
vector<string> np;
vector<string> res;
int n, k;

int str2i(string s, int p)
{
	int x = 0;
	for (int i = 0; i < p; i++)
		x = x * 10 + s[i] - '0';
	return x;
}

void dfs(int p, int s)
{
	if (p >= n)
		return;

	if (s == k) {
		int r = 0;
		for (int i = 0; i < s; i++) {
			if (r)
				cout << ", " << res[i];
			else
				cout << res[i];
			r = 1;
		}
		cout << "\n";
		return;
	}

	for (int i = p + 1; i < n; i++) {
		res.push_back(np[i]);
		dfs(i, s + 1);
		res.pop_back();
	}
}

int main(void)
{
	string str;
	string nps;
	int c, a, b;

	getline(cin, str);
	c = str2i(str, str.size());
	getline(cin, str);
	
	while (c--) {
		std::size_t t;
		getline(cin, str);
		np.clear();
		while (getline(cin, nps) && !nps.empty())
			np.push_back(nps);

		if (str[0] == '*') {
			a = 1;
			b = np.size();
		} else {
			t= str.find(' ');
			if (t == std::string::npos) {
				a = b = str2i(str, str.size());
			} else {
				a = str2i(str, t);
				b = 0;
				for (int i = t + 1; i < str.size(); i++)
					b = b * 10 + str[i] - '0';
			}
		}

		n = np.size();
		for (int i = a; i <= b; i++) {
			cout << "Size " << i << '\n';
			k = i;
			res.clear();
			dfs(-1, 0);

			if (i != b)
				cout << '\n';
		}
		if (c)
			cout << "\n\n";
	}
	cout << endl;
	return 0;
}
