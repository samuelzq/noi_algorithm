/**
 * History Grading UVA - 111
 * https://vjudge.net/problem/UVA-111
 *
 * 本题的难点是对于输入的理解。
 * 输入的每一行都是rank。rank的意思是：该事件在历史时间线上的位置。
 * 第一行是标准的答案。后续每一行是同学给出的答案。
 * 因此首先需要将输入转换成事件的排列。然后将同学的输入转换成order
 * 序列。
 *
 * @File:   uva111.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-06
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 25;
int s[N];
int a[N];
int c[N];
int l[N];

#define cmp(x, y)  a[x] < a[y]

int LIS(int len)
{
	for (int i = 1; i <= len; i++)
		l[i] = 1;

	for (int i = 1; i <= len; i++) {
		for (int j = 1; j < i; j++) {
			if (c[j] < c[i])
				l[i] = max(l[j] + 1, l[i]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= len; i++)
		ans = max(ans, l[i]);
	return ans;
}

// 将同学提交的答案转换成order序列
void order(int l)
{
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			if (a[i] == s[j]) {
				c[i] = j;
				break;
			}
		}
	}
}

int get_num(void)
{
	int t, n = 0;
	string str;
	stringstream ss;

	if (getline(cin, str)) {
		ss << str << ' ' << '0';
		do {
			n++;
			ss >> t;
			s[t] = n;
		} while(t);
	}
	return n;
}

int get_num2(void)
{
	bool f = true;
	int t, m, n = 0;
	string str;
	stringstream ss;

	if (getline(cin, str)) {
		ss << str << ' ' << '0';
		do {
			n++;
			ss >> t;
			if (f) {
				m = t;
				f = false;
			}
			a[t] = n;
		} while(t);
	}

	if (n <= 2)
		a[0] = m;
	return n;
}

int main(void)
{
	int n, t;

	while (t = get_num2()) {
		if (t == 2) {
			n = a[0];
			get_num();
			continue;
		}
		order(n);
		cout << LIS(n) << '\n';
	}
	return 0;
}
