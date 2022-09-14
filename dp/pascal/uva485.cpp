/**
 * Pascal's Triangle of Death UVA - 485
 * https://vjudge.net/problem/UVA-485
 *
 * 难点在大数计算。
 * 使用string来记录计算结果，类似于0-1背包空间压缩。
 * 利用以为string vector记录每一行的结果。
 *
 * @File:   uva485.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-05
 *
 **/
#include <bits/stdc++.h>

using namespace std;

string strAdd(string &a, string &b)
{
	int x, y, z, c;
	int la, lb;

	la = a.length();
	lb = b.length();
	string s(la, 0);

	z = c = 0;
	int i;
	for (i = 0; i < lb; i++) {
		z = c + (a[i] - '0') + (b[i] - '0');
		if (z >= 10)
			c = 1;
		else
			c = 0;
		z -= c * 10;
		s[i] = z + '0';
	}
	
	for (; i < la; i++) {
		z = c + (a[i] - '0');
		if (z >= 10)
			c = 1;
		else
			c = 0;
		z -= c * 10;
		s[i] = z + '0';
	}

	if (c)
		s += (c + '0');
	return s;
}

void sout(string &s)
{
	int l = s.length() - 1;

	while (s[l] == '0')
		l--;

	while (l >= 0) {
		cout << s[l--];
	}
}

int main(void)
{
	bool flag = true;
	int j = 0, i = 0;
	string s;
	vector<string> p;

	p.push_back("1");

	while (flag) {
		for (int i = j; i > 0; i--) {
			if (p[i].length() > p[i - 1].length())
				s = strAdd(p[i], p[i - 1]);
			else
				s = strAdd(p[i - 1], p[i]);
			p[i] = s;
		}
		cout << 1;
		for (int i = 1; i <= j; i++) {
			if (p[i].length() > 60)
				flag = false;
			cout << ' ';
			sout(p[i]);
		}
		cout << '\n';
		j++;
		p.push_back("0");
	}
	return 0;
}
